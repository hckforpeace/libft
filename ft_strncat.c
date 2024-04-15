/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 00:24:05 by pierre            #+#    #+#             */
/*   Updated: 2024/04/15 00:24:05 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	while (*dest)
		dest++;
	while (*src && n > 0)
	{
		*dest++ = *src;
		n--;
	}
	*dest = '\0';
	return (dest);
}
