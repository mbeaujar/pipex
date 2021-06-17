/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:30:06 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/17 13:41:17 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	putstr(t_var *var, int i)
{
	write(1, "\nbash: avertissement :« here-document » à la ligne ", 55);
	ft_putnbr_fd(i, 1);
	write(1, " délimité par la fin du fichier (au lieu de « ", 50);
	write(1, var->argv[1], ft_strlen(var->argv[1]));
	write(1, " »)\n", 6);
}

void	create_pipe(t_var *var)
{
	int		fd[2];
	char	*str;

	errno = 0;
	if (pipe(fd) == -1)
	{
		str = strerror(errno);
		write(1, str, ft_strlen(str));
	}
	var->std_in = fd[0];
	var->std_out = fd[1];
	if (var->str)
	{
		write(fd[1], var->str, ft_strlen(var->str));
		free(var->str);
	}
}

void	create_here_document(t_var *var)
{
	int		ret;
	char	*line;
	int		i;

	ret = 1;
	i = 0;
	while (ret)
	{
		write(1, "> ", 2);
		ret = get_next_line(0, &line);
		if (ret == -1)
			break ;
		if (ft_strcmp(line, var->argv[1]) == 0)
			break ;
		else
			var->str = ft_strjoin_gnl(var->str, line);
		if (ret == 0)
			break ;
		free(line);
		i++;
	}
	free(line);
	if (ret == 0)
		putstr(var, i);
	create_pipe(var);
}
