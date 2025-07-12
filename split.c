/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:40:21 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/11 16:43:23 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	inside_word = false;
	while (*s)
	{
		if (*s != c && !inside_word)
		{
			inside_word = true;
			count++;
		}
		else if (*s == c)
			inside_word = false;
		s++;
	}
	return (count);
}

static char	*extract_word(char *s, char c, int *start)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[*start] == c)
		(*start)++;
	while (s[*start + len] && s[*start + len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[*start + i];
		i++;
	}
	word[i] = '\0';
	*start += len;
	return (word);
}

static char	**alloc_and_fill_split(char *s, char c, int words_count)
{
	char	**result;
	int		i;
	int		start;

	i = 0;
	start = 0;
	result = malloc(sizeof(char *) * (words_count + 1));
	if (!result)
		return (NULL);
	while (i < words_count)
	{
		result[i] = extract_word(s, c, &start);
		if (!result[i])
		{
			while (i > 0)
				free(result[--i]);
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char *s, char c)
{
	int		words_count;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	if (words_count == 0)
		return (NULL);
	return (alloc_and_fill_split(s, c, words_count));
}
