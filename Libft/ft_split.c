/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcruz-me <hcruz-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:04:20 by hcruz-me          #+#    #+#             */
/*   Updated: 2024/10/06 10:01:28 by hcruz-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static void	ft_free(char **w, int x)
{
	int	count;

	count = 0;
	while (count < x)
		free(w[count++]);
	free(w);
}

static char	*ft_fillsplit(const char *s, int end, int start)
{
	int		count;
	char	*strcp;

	count = 0;
	strcp = malloc(((end - start) + 1) * sizeof(char));
	if (!strcp)
		return (NULL);
	while (start < end)
	{
		strcp[count] = s[start];
		start++;
		count++;
	}
	strcp[count] = '\0';
	return (strcp);
}

static int	ft_div_s(const char *s, char c, char **str, int *x)
{
	int	i;
	int	start;

	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			str[*x] = ft_fillsplit(s, i, start);
			if (!str)
				return (0);
			(*x)++;
		}
	}
	str[*x] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		x;
	char	**str;

	x = 0;
	if (!s)
		return (NULL);
	words = ft_countwords((char *)s, c);
	str = malloc ((words + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	if (!ft_div_s(s, c, str, &x))
		return (ft_free(str, x), NULL);
	return (str);
}
