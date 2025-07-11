/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:53:49 by aaugusto          #+#    #+#             */
/*   Updated: 2025/05/14 15:51:19 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((s[i] != '\0') && (s[i] != (char)c))
		i++;
	if (s[i] != (char)c)
		return (NULL);
	else
		return ((char *)&s[i]);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*sub_s;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strjoin("", ""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub_s = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

void	*ft_free(char **ptr)
{
	if (ptr != NULL)
	{
		if (*ptr != NULL)
		{
			free(*ptr);
			*ptr = NULL;
		}
	}
	return (NULL);
}
