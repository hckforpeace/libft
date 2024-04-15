/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 00:24:36 by pierre            #+#    #+#             */
/*   Updated: 2024/04/15 00:35:13 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_set(char c, char const *set)
{
	int	n;

	n = 0;
	while (set[n])
	{
		if (c == set[n])
			return (1);
		n++;
	}
	return (0);
}

int	ft_count_sets(char const *s1, char const *set)
{
	int	n;
	int	count;

	count = 0;
	n = 0;
	while (s1[n])
	{
		if (ft_is_set(s1[n], set))
			count++;
		n++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	len = ft_strlen(s1) - ft_count_sets(s1, set);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	*str = '\0';
	while (ft_is_set(s1[i], set))
		i++;
	if (len != 0)
		ft_strncpy(str, &s1[i], len);
	return (str);
}
