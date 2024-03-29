/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:39:32 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/07/09 15:30:03 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_var_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}

char	*finding_path(char *str, char **path)
{
	int		i;
	char	*std;

	i = 0;
	if (!str)
		return (NULL);
	while (path[i])
	{
		std = ft_strjoin_gnl(ft_strjoin_gnl(ft_strdup(path[i]), "/"), str);
		if (access(std, R_OK) != -1)
			return (std);
		free(std);
		i++;
	}
	if (access(str, R_OK) != -1)
		return (ft_strdup(str));
	write(1, "pipex: '", 8);
	write(1, str, ft_strlen(str));
	write(1, "' : command not found\n", 22);
	return (NULL);
}

char	*search_path(char *str, char **envp)
{
	char	**new_path;
	char	*path;

	path = search_var_path(envp);
	if (!path)
		return (NULL);
	if (ft_strlen(path) <= 5)
		return (NULL);
	new_path = ft_split(path + 5, ':');
	if (!new_path)
		return (NULL);
	path = finding_path(str, new_path);
	free_tab(new_path);
	return (path);
}
