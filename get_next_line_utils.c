/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:29:27 by paperez-          #+#    #+#             */
/*   Updated: 2024/05/16 13:59:26 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void    *ft_calloc(size_t count, size_t size)
{
        char    *res;
	int	c;

        c = (int) count;
	res = malloc(count * size);
        while (c >= 0)
        {
                res[c] = 0;
                c--;
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
//	printf("s2: %s \n", s1);
        while (s1[i])
                i++;
        while (s2[j])
                j++;
        str = (char *)malloc(sizeof(char) * (i + j + 1));
        if (!str)
                return (NULL);
        i = 0;
        while (s1[i] != '\0')
	{
                str[i] = s1[i];
		i++;
        }
	j = 0;
        while (s2[j] != '\0')
	{
                str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
//	printf("esta es el textjoin: %s\n", str);
	return (str);
}

size_t  ft_strlen(const char *s)
{
        const char      *p = s;

        while (*p)
                ++p;
        return (p - s);
}

