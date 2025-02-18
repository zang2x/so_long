/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcruz-me <hcruz-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:59:40 by hcruz-me          #+#    #+#             */
/*   Updated: 2024/10/02 12:56:02 by hcruz-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1p;
	unsigned char	*s2p;

	s1p = (unsigned char *) s1;
	s2p = (unsigned char *) s2;
	if (n == 0)
	{
		return (0);
	}
	while (n)
	{
		if (*s1p != *s2p)
		{
			return (*s1p - *s2p);
		}
		s1p++;
		s2p++;
		n--;
	}
	return (0);
}
