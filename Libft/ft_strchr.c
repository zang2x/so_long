/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcruz-me <hcruz-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:57:42 by hcruz-me          #+#    #+#             */
/*   Updated: 2024/10/04 11:24:52 by hcruz-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		count;
	char	*sptr;

	sptr = (char *)s;
	count = 0;
	while (sptr[count] != '\0')
	{
		if ((char)sptr[count] == (char)c)
			return (&sptr[count]);
		count++;
	}
	if ((char)c == '\0')
		return (&sptr[count]);
	return (NULL);
}
