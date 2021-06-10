/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:31:19 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/10 18:22:48 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	secure_free(char *str)
{
	if (str)
		free(str);
}

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	putendl(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

int	display_file(char *str, int *std, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (std[i] != -1 && std[i] != 0 && std[i] != 1)
			close(std[i]);
		i++;
	}
	write(1, str, ft_strlen(str));
	write(1, " ", 1);
	return (1);
}
