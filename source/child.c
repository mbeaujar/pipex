/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:36:10 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/10 18:09:46 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	add_child(char **argv, int in, int out, t_var *var)
{
	int	pid;

	errno = 0;
	pid = fork();
	if (pid == -1)
		putendl(strerror(errno));
	if (pid == 0)
	{
		dup2(in, 0);
		dup2(out, 1);
		close(in);
		close(out);
		if (var->std_out != 1)
			close(var->std_out);
		execve(argv[0], argv, var->envp);
		putendl(strerror(errno));
		exit(125 + errno);
	}
	return (pid);
}

void	fct_wait(t_var *var)
{
	int	i;
	int	fd;

	i = 0;
	while (i < var->len - 2)
	{
		waitpid(var->pid[i], &fd, 0);
		i++;
	}
}

void	exec_pipe(t_var *var)
{
	int		i;
	int		fd;
	char	**str;

	i = 0;
	fd = 0;
	while (i < var->len - 2)
	{
		str = ft_split(var->argv[2 + i], ' ');
		var->pid[i] = add_child(str, var->std[fd], var->std[fd + 1], var);
		if (BONUS)
		{
			close(var->std_out);
			var->std_out = 1;
		}
		close(var->std[fd]);
		close(var->std[fd + 1]);
		fd += 2;
		free_tab(str);
		i++;
	}
	fct_wait(var);
}