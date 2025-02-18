/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcruz-me <hcruz-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:58:30 by hcruz-me          #+#    #+#             */
/*   Updated: 2024/10/02 12:39:36 by hcruz-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;
	unsigned char	*s1ptr;
	unsigned char	*s2ptr;

	s1ptr = (unsigned char *)s1;
	s2ptr = (unsigned char *)s2;
	count = 0;
	while ((s1ptr[count] != '\0' || s2ptr[count] != '\0') && count < n)
	{
		if (s1ptr[count] == s2ptr[count])
			count++;
		else
			return (s1ptr[count] - s2ptr[count]);
	}
	return (0);
}
