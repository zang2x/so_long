/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obmedina <obmedina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:29:59 by obmedina          #+#    #+#             */
/*   Updated: 2025/06/03 16:57:31 by obmedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	validchecker(t_list *vars)
{
	if (vars->validmap != 0)
		free_all(vars);
}

void	destroyimages(t_list *vars)
{
	if (vars->wallimg)
		mlx_destroy_image(vars->mlx, vars->wallimg);
	if (vars->doorimg)
		mlx_destroy_image(vars->mlx, vars->doorimg);
	if (vars->floorimg)
		mlx_destroy_image(vars->mlx, vars->floorimg);
	if (vars->playerimg)
		mlx_destroy_image(vars->mlx, vars->playerimg);
	if (vars->coinimg)
		mlx_destroy_image(vars->mlx, vars->coinimg);
}

void	init_imgs(t_list *vars)
{
	vars->playerimg = mlx_xpm_file_to_image(vars->mlx, "textures/player.xpm",
			&vars->width, &vars->height);
	vars->floorimg = mlx_xpm_file_to_image(vars->mlx, "textures/floor.xpm",
			&vars->width, &vars->height);
	vars->wallimg = mlx_xpm_file_to_image(vars->mlx, "textures/wall.xpm",
			&vars->width, &vars->height);
	vars->coinimg = mlx_xpm_file_to_image(vars->mlx, "textures/coin.xpm",
			&vars->width, &vars->height);
	vars->doorimg = mlx_xpm_file_to_image(vars->mlx, "textures/door.xpm",
			&vars->width, &vars->height);
}

void	check_mapsize(t_list *vars)
{
	int	x;
	int	sizex;

	x = 0;
	sizex = ft_strlen(vars->splitmap[x]);
	while (vars->splitmap[x])
	{
		if (ft_strlen(vars->splitmap[x]) != (size_t)sizex)
			vars->validmap = 1;
		ft_printf("%s\n", vars->splitmap[x]);
		x++;
	}
	vars->mapsizey = x;
	vars->mapsizex = sizex;
	validchecker(vars);
}
