#include "include/so_long.h"

void	validchecker(s_list *vars)
{
	if (vars->validmap != 0)
		free_all(vars);
}

void	destroyimages(s_list *vars)
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

void	init_imgs(s_list *vars)
{
	vars->playerimg = mlx_xpm_file_to_image(vars->mlx,
			"textures/spriteplayer.xpm", &vars->width, &vars->height);
	vars->floorimg = mlx_xpm_file_to_image(vars->mlx,
			"textures/spritefloor.xpm", &vars->width, &vars->height);
	vars->wallimg = mlx_xpm_file_to_image(vars->mlx, "textures/wall.xpm",
			&vars->width, &vars->height);
	vars->coinimg = mlx_xpm_file_to_image(vars->mlx, "textures/coin.xpm",
			&vars->width, &vars->height);
	vars->doorimg = mlx_xpm_file_to_image(vars->mlx, "textures/door.xpm",
			&vars->width, &vars->height);
}

void	check_mapsize(s_list *vars)
{
	int	x;
	int	sizex;

	x = 0;
	sizex = ft_strlen(vars->splitmap[x]);
	while (vars->splitmap[x + 1] != NULL)
	{
		x++;
		if (ft_strlen(vars->splitmap[x]) != (size_t)sizex)
			vars->validmap = 1;
		sizex = ft_strlen(vars->splitmap[x]);
	}
	vars->mapsizey = x + 1;
	vars->mapsizex = sizex;
}
