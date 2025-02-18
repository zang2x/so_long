/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcruz-me <hcruz-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:58:12 by hcruz-me          #+#    #+#             */
/*   Updated: 2024/10/02 12:27:26 by hcruz-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	*sptr;

	count = ft_strlen(s);
	sptr = (char *)s;
	while (count >= 0)
	{
		if (sptr[count] == (char)c)
		{
			return (&sptr[count]);
		}
		count--;
	}
	return (NULL);
}
