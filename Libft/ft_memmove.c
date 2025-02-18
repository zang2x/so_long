/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcruz-me <hcruz-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:55:04 by hcruz-me          #+#    #+#             */
/*   Updated: 2024/10/03 12:01:19 by hcruz-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destp;
	char	*srcp;

	destp = (char *) dest;
	srcp = (char *) src;
	if (dest == src)
		return (dest);
	else if (dest > src)
	{
		destp += n;
		srcp += n;
		while (n)
		{
			destp--;
			srcp--;
			*destp = *srcp;
			n--;
		}
	}
	else
	{
		return (ft_memcpy(dest, src, n));
	}
	return (dest);
}
