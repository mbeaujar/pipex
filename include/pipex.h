/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:35:10 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/17 14:16:08 by mbeaujar         ###   ########.fr       */
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
# include "get_next_line.h"

# ifndef BONUS
#  define BONUS 0
# endif

typedef struct s_var
{
	int		std_in;
	int		std_out;
	int		*std;
	int		argc;
	int		*pid;
	int		len;
	char	**envp;
	char	**argv;
	char	*str;
}			t_var;

int		ft_strlen(char *str);
void	putendl(char *str);
void	print_tab(char **str);
char	**ft_split(char const *s, char c);
void	exec_pipe(t_var *var);
void	free_tab(char **str);
void	secure_free(char *str);
int		display_file(char *str, int *std, int len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
void	ft_putnbr_fd(int n, int fd);
void	create_here_document(t_var *var);
char	*search_path(char *str, char **envp);
char	*ft_strdup(char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		free_argv(char **argv, int state);

#endif