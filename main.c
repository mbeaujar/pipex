/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:19:35 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/09 17:08:37 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int refill_std(int *std, int len, int argc, char **argv)
{
    int fd[2];
    int i;

    std[0] = open(argv[1], O_RDWR);
    if (std[0] == -1)
        return (display_file(argv[1]));
    i = 1;
    while (i < ((len - 2) * 2 - 1))
    {
        if (pipe(fd) == -1)
            return (1);
        std[i] = fd[1];
        i++;
        std[i] = fd[0];
        i++;
    }
    std[((len - 2) * 2) - 1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (std[((len - 2) * 2) - 1] == -1)
        return (display_file(argv[i + 1]));
    return (0);
}

int init_malloc(t_var *var, int argc, char **argv, char **envp)
{
    int len;
    int *std;
    int *pid;
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
    var->len = len;
    //printf("struct len :%d\n", len);
    var->pid = pid;
    var->std = std;
    var->envp = envp;
    var->argv = argv;
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    t_var var;

    errno = 0;
    if (argc < 5)
        return (1);
    if (init_malloc(&var, argc, argv, envp) == 1)
        return (1);
    if (refill_std(var.std, var.len, argc, argv))
    {
        free(var.std);
        putendl(strerror(errno));
        return (1);
    }
    exec_pipe(&var);
    free(var.std);
    return (0);
}