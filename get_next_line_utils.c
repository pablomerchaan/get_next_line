/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:29:27 by paperez-          #+#    #+#             */
/*   Updated: 2024/05/16 12:34:56 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *ft_calloc(size_t count, size_t size)
{
        char    *res;

        res = malloc(count * size);
        while (count >= 0)
        {
                res[count] = 0;
                count--;
        }
        return (res);
}

char    *ft_strchr(const char *s, int c)
{
        while (*s != '\0')
        {
                if (*s == (char)c)
                {
                        return ((char *)s);
                }
                s++;
        }
        if ((char)c == '\0')
        {
                return ((char *)s);
        }
        return (0);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *str;
        int             i;
        int             j;

        i = 0;
        j = 0;
        while (s1[i])
                i++;
        while (s2[j])
                j++;
        str = (char *)malloc(sizeof(char) * (i + j + 1));
        if (!str)
                return (NULL);
        i = -1;
        while (s1[++i])
                str[i] = s1[i];
        j = -1;
        while (s2[++j])
                str[i + j] = s2[j];
        str[i + j] = '\0';
        return (str);
}

size_t  ft_strlen(const char *s)
{
        const char      *p = s;

        while (*p)
                ++p;
        return (p - s);
}

