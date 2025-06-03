/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obmedina <obmedina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:29:22 by obmedina          #+#    #+#             */
/*   Updated: 2025/06/03 16:43:26 by obmedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	put_image(void *img, int y, int j, t_list *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img, SIZE * j, SIZE * y);
}

void	fill_map(t_list *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->splitmap[i] != NULL)
	{
		j = 0;
		while (vars->splitmap[i][j])
		{
			if (vars->splitmap[i][j] == 'C')
				vars->validmap = 1;
			if (vars->splitmap[i][j] == '3' || vars->splitmap[i][j] == '1')
				put_image(vars->floorimg, i, j, vars);
			if (vars->splitmap[i][j] == '2' || vars->splitmap[i][j] == '0'
				|| vars->splitmap[i][j] == 'P')
				put_image(vars->wallimg, i, j, vars);
			if (vars->splitmap[i][j] == 'c')
				put_image(vars->coinimg, i, j, vars);
			if (vars->splitmap[i][j] == 'e')
				put_image(vars->doorimg, i, j, vars);
			j++;
		}
		i++;
	}
	put_image(vars->playerimg, vars->playery, vars->playerx, vars);
}
