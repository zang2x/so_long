#include "include/so_long.h"

void    put_image(void *img, int y, int j, s_list *vars)
{
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, img, SIZE * y, SIZE * j);
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
                put_image(vars->floorimg, i, j, vars);
			if (vars->splitmap[i][j] == '2' || vars->splitmap[i][j] == '0'
				|| vars->splitmap[i][j] == 'P')
				put_image(vars->wallimg, i, j, vars);
			if (vars->splitmap[i][j] == 'c' || vars->splitmap[i][j] == 'C')
                put_image(vars->coinimg, i, j, vars);
			if (vars->splitmap[i][j] == 'e')
                put_image(vars->doorimg, i, j, vars);
			j++;
		}
		i++;
	}
    put_image(vars->playerimg, i, j, vars);
}
