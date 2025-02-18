/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcruz-me <hcruz-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:00:01 by hcruz-me          #+#    #+#             */
/*   Updated: 2024/10/03 15:19:55 by hcruz-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	char	*setptr;
	char	*s1ptr;

	i = 0;
	s1ptr = (char *)s1;
	setptr = (char *)set;
	end = ft_strlen(s1ptr);
	while (ft_strchr(setptr, s1ptr[i]))
		i++;
	if (i == end)
		return ("");
	while (ft_strchr(setptr, s1ptr[end - 1]))
		end--;
	return (ft_substr(s1ptr, i, end - i));
}
