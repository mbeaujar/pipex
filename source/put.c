/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:50:02 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/07/09 15:23:51 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		write(fd, "-", 1);
		nb = -n;
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}

int	normi_main(char **argv, char **envp)
{
	char	**leaks;
	char	*tmp;
	int		i;

	i = 0;
	leaks = ft_split(argv[2], ' ');
	tmp = search_path(leaks[0], envp);
	while (leaks[++i])
		tmp = ft_strjoin_gnl(ft_strjoin_gnl(tmp, " "), leaks[i]);
	free_tab(leaks);
	argv[2] = tmp;
	if (!argv[2])
		return (1);
	i = 0;
	leaks = ft_split(argv[3], ' ');
	tmp = search_path(leaks[0], envp);
	while (leaks[++i])
		tmp = ft_strjoin_gnl(ft_strjoin_gnl(tmp, " "), leaks[i]);
	free_tab(leaks);
	argv[3] = tmp;
	if (!argv[3])
		return (free_argv(argv, 2, 0) + 1);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i]
		&& i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i])
		i++;
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
