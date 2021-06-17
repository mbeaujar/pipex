/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:39:32 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/17 13:10:17 by mbeaujar         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin_gnl(ft_strjoin_gnl(path[i], "/"), str);
		if (access(path[i], R_OK) != -1)
			return (path[i]);
		free(path[i]);
		i++;
	}
	if (str[0] == '/' || (str[0] == '.' && str[0] == '/'))
		return (ft_strdup(str));
	return (NULL);
}

char	*search_path(char *str, char **envp)
{
	char	**new_path;
	char	*path;

	path = search_var_path(envp);
	if (!path)
		return (NULL);
	new_path = ft_split(path + 5, ':');
	if (!new_path)
		return (NULL);
	path = finding_path(str, new_path);
	return (path);
}
