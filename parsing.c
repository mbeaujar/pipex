/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeaujar <mbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:31:19 by mbeaujar          #+#    #+#             */
/*   Updated: 2021/06/09 16:00:02 by mbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void free_tab(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void putendl(char *str)
{
    write(1, str, ft_strlen(str));
    write(1, "\n", 1);
}

void print_tab(char **str)
{
    int i;

    i = 0;
    while(str[i])
        printf("%s\n", str[i++]);
}

int display_file(char *str)
{
    write(1, str, ft_strlen(str));
    write(1, " ", 1);
    return (1);
}