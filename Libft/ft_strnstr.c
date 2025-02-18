/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcruz-me <hcruz-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:00:02 by hcruz-me          #+#    #+#             */
/*   Updated: 2024/10/06 10:35:39 by hcruz-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;
	char	*l;

	i = 0;
	b = (char *)big;
	l = (char *)little;
	if (*little == '\0')
		return (b);
	while (b[i] != '\0' && i < len)
	{
		if (b[i] == l[0])
		{
			j = 0;
			while (b[j] != '\0' && b[i + j] == l[j] && (i + j) < len)
			{
				j++;
				if (l[j] == '\0')
					return (&b[i]);
			}
		}
		i++;
	}
	return (NULL);
}
