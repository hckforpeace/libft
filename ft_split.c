/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 00:22:57 by pierre            #+#    #+#             */
/*   Updated: 2024/04/15 00:31:38 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	n;
	int	words;

	words = 0;
	n = 0;
	while (s[n])
	{
		if (n != 0)
		{
			if (s[n] == c && s[n - 1] != c)
				words++;
		}
		n++;
	}
	if (n != 0)
	{
		if (s[n - 1] != c)
			words++;
	}
	return (words);
}

static int	alloc(int idx_ptr, int size, char const *s, char **strs)
{
	int	n;

	n = 0;
	strs[idx_ptr] = (char *)malloc(sizeof(char) * (size + 1));
	if (strs[idx_ptr] == NULL)
		return (0);
	while (n < size)
	{
		strs[idx_ptr][n] = s[n];
		n++;
	}
	strs[idx_ptr][n] = '\0';
	return (1);
}

static void	ft_alloc_words(char const *s, char c, char **strs)
{
	int	idx_ptr;
	int	n;
	int	len;

	idx_ptr = 0;
	n = 0;
	len = 0;
	while (s[n])
	{
		if (n != 0 && s[n] == c && s[n - 1] != c)
		{
			alloc(idx_ptr, len, &s[n - len], strs);
			idx_ptr++;
			len = 0;
		}
		if (s[n] != c)
			len++;
		n++;
	}
	if (s[n - 1] != c)
		alloc(idx_ptr, len, &s[n - len], strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;

	words = ft_count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (words + 1));
	if (strs == NULL)
		return (NULL);
	if (words != 0)
		ft_alloc_words(s, c, strs);
	strs[words] = 0;
	return (strs);
}
