/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:24:57 by pierre            #+#    #+#             */
/*   Updated: 2024/04/08 15:40:07 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *set, int c, size_t n)
{
	unsigned char	v;
	unsigned char	*ptr;

	v = (unsigned char) c;
	ptr = (unsigned char *) set;
	while (n > 0)
	{
		*ptr++ = v;
		n--;
	}
	return (ptr);
}
