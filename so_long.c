#include "include/so_long.h"

int	free_all(s_list *vars)
{
	int	i;

	i = 0;
	if (vars->validmap != 0 || vars->exitable > 1)
		ft_printf("Error");
	if (vars->splitmap)
	{
		while (vars->splitmap[i] != NULL)
		{
			free(vars->splitmap[i]);
			i++;
		}
		free(vars->splitmap);
	}
	destroyimages(vars);
	if (vars->mlx && vars->mlx_win)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(0);
}

void	init_vars(s_list *vars)
{
	int		fd;
	int		rbytes;
	char	map[1024];

	fd = open(vars->map, O_RDONLY);
	rbytes = read(fd, map, 1024);
	if (rbytes < 1)
		vars->validmap = 1;
	validchecker(vars);
	map[rbytes] = '\0';
	vars->splitmap = ft_split(map, '\n');
	close(fd);
	vars->mlx = mlx_init();
	check_weirdthings(vars);
	check_map(vars->playerx, vars->playery, vars);
        ft_printf("%d and %d", vars->reachablecoin, vars->coins);
	if (vars->reachablecoin != vars->coins || vars->exitable != 1
		|| vars->door != 1)
		vars->validmap = 1;
	validchecker(vars);
	vars->mlx_win = mlx_new_window(vars->mlx, vars->mapsizex * SIZE,
			vars->mapsizey * SIZE, "PERROWS VIDIOGAME");
	vars->height = 64;
	vars->width = 64;
	init_imgs(vars);
}

void	player_move(s_list *vars, int x, int y)
{
	if (vars->splitmap[vars->playery + y][vars->playerx + x] == 'e'
		&& vars->reachablecoin != 0)
		ft_printf("%d bananas left, don't leave ⛔️\n", vars->reachablecoin);
	if ((vars->splitmap[vars->playery + y][vars->playerx + x] != '3'
		&& vars->splitmap[vars->playery + y][vars->playerx + x] != 'e')
		|| (vars->splitmap[vars->playery + y][vars->playerx + x] == 'e'
		&& vars->reachablecoin == 0))
	{
		vars->playerx += x;
		vars->playery += y;
		vars->steps++;
		ft_printf("%d steps.🦶\n", vars->steps);
		if (vars->splitmap[vars->playery][vars->playerx] == 'c')
		{
			vars->reachablecoin -= 1;
			ft_printf("There is %d bananas homie 🍌\n", vars->reachablecoin);
			vars->splitmap[vars->playery][vars->playerx] = '2';
		}
		if (vars->splitmap[vars->playery][vars->playerx] == 'e')
		{
			ft_printf("We got it in %d steps, brutal 🏆\n", vars->steps);
			free_all(vars);
		}
	}
	fill_map(vars);
}

int	key_hook(int keycode, s_list *vars)
{
	if (keycode == 100)
		player_move(vars, 1, 0);
	if (keycode == 97)
		player_move(vars, -1, 0);
	if (keycode == 115)
		player_move(vars, 0, 1);
	if (keycode == 119)
		player_move(vars, 0, -1);
	if (keycode == 65307)
		free_all(vars);
	return (0);
}

int	main(int argc, char *argv[])
{
	s_list	vars;

	if (argc != 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_memset(&vars, 0, sizeof(vars));
	vars.map = argv[1];
	init_vars(&vars);
	check_mapwalls(&vars);
	check_mapsize(&vars);
	fill_map(&vars);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_hook(vars.mlx_win, 17, 0, free_all, &vars);
	mlx_loop(vars.mlx);
}
