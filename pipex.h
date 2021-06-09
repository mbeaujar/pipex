/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:35:10 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/09 15:27:30 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <string.h>


typedef struct s_var
{
    int *std;
    int *pid;
    int len;
    char **envp;
    char **argv;
}   t_var;

int ft_strlen(char *str);
void putendl(char *str);
void print_tab(char **str);
int display_file(char *str);
char	**ft_split(char const *s, char c);
void exec_pipe(t_var *var);
void free_tab(char **str);

#endif