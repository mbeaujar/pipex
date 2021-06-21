/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:19:35 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/21 10:53:25 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	select_open(char *path)
{
	int	fd;

	if (BONUS)
		fd = open(path, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	else
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	return (fd);
}

int	refill_std(int *std, int len, t_var *var, char **argv)
{
	int	fd[2];
	int	i;

	i = 1;
	if (BONUS == 0)
		std[0] = open(argv[1], O_RDWR);
	else
		std[0] = var->std_in;
	while (std[0] != -1 && i < ((len - 2) * 2 - 1))
	{
		if (pipe(fd) == -1)
			return (display_file("Bash: ", std, i));
		std[i] = fd[1];
		i++;
		std[i] = fd[0];
		i++;
	}
	std[((len - 2) * 2) - 1] = select_open(argv[var->argc - 1]);
	if (std[((len - 2) * 2) - 1] == -1)
		return (display_file(argv[i + 1], std, i));
	if (std[0] == -1)
		return (display_file(argv[1], std, i));
	return (0);
}

int	init_malloc(t_var *var, int argc, char **argv, char **envp)
{
	int	len;
	int	*std;
	int	*pid;

	len = argc - 1;
	std = malloc(sizeof(int) * ((len - 2) * 2));
	if (!std)
		return (1);
	pid = malloc(sizeof(int) * (len - 2));
	if (!pid)
	{
		free(std);
		return (1);
	}
	var->std_in = 0;
	var->std_out = 1;
	var->len = len;
	var->pid = pid;
	var->std = std;
	var->envp = envp;
	var->argv = argv;
	var->str = NULL;
	var->argc = argc;
	return (0);
}

int	free_argv(char **argv, int state)
{
	if (state == 1 || state == 3)
		free(argv[3]);
	if (state == 2 || state == 3)
		free(argv[2]);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_var	var;

	errno = 0;
	if (argc < 5 || (argc > 5 && BONUS == 0))
		return (1);
	if (normi_main(argv, envp))
		return (1);
	if (!argv[3] || (init_malloc(&var, argc, argv, envp)))
		return (free_argv(argv, 2));
	if (BONUS)
		create_here_document(&var);
	if (refill_std(var.std, var.len, &var, argv))
	{
		free(var.std);
		free(var.pid);
		putendl(strerror(errno));
		return (free_argv(argv, 3) + 1);
	}
	exec_pipe(&var);
	free(var.std);
	free(var.pid);
	return (free_argv(argv, 3));
}
