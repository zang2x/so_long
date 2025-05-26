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

void	fill_map(s_list *vars)
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
				mlx_put_image_to_window(vars->mlx, vars->mlx_win,
					vars->floorimg, SIZE * j, SIZE * i);
			if (vars->splitmap[i][j] == '2' || vars->splitmap[i][j] == '0'
				|| vars->splitmap[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->wallimg,
					SIZE * j, SIZE * i);
			if (vars->splitmap[i][j] == 'c' || vars->splitmap[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->coinimg,
					SIZE * j, SIZE * i);
			if (vars->splitmap[i][j] == 'e')
				mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->doorimg,
					SIZE * j, SIZE * i);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->playerimg, SIZE
		* vars->playerx, SIZE * vars->playery);
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
