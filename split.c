/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:40:21 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/06 15:55:31 by aaugusto         ###   ########.fr       */
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

	while (s[*start] == c)
		(*start)++;
	len = 0;
	while (s[*start + len] && s[*start + len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[*start + i];
		i++;
	}
	word[i] = '\0';
	*start += len;
	return (word);
}

static char	**alloc_result(int words_count)
{
	char	**result;

	result = malloc(sizeof(char *) * (words_count + 2));
	if (!result)
		return (NULL);
	result[0] = malloc(1);
	if (!result[0])
		return (NULL);
	result[0][0] = '\0';
	return (result);
}

char	**ft_split(char *s, char c)
{
	int		words_count;
	char	**result;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result = alloc_result(words_count);
	if (!result)
		return (NULL);
	start = 0;
	i = 1;
	while (i <= words_count)
	{
		result[i] = extract_word(s, c, &start);
		if (!result[i])
			return (NULL);
		i++;
	}
	result[i] = NULL;
	return (result);
}
