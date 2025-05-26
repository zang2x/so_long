#include "include/so_long.h"

void	check_map(int playery, int playerx, s_list *vars)
{
	if (playery < 0 || playerx < 0 || playerx >= vars->mapsizex
		|| playery >= vars->mapsizey)
		return ;
	if (vars->splitmap[playery][playerx] == '2'
		|| vars->splitmap[playery][playerx] == '3'
		|| vars->splitmap[playery][playerx] == 'e')
		return ;
	if (vars->splitmap[playery][playerx] == 'C')
		check_position(playery, playerx, vars);
	if (vars->splitmap[playery][playerx] == '1')
	{
		check_position(playery, playerx, vars);
		return ;
	}
	if (vars->splitmap[playery][playerx] == 'E')
		check_position(playery, playerx, vars);
	if (vars->splitmap[playery][playerx] != 'c'
		&& vars->splitmap[playery][playerx] != 'P'
		&& vars->splitmap[playery][playerx] != '3'
		&& vars->splitmap[playery][playerx] != 'e')
		vars->splitmap[playery][playerx] = '2';
	check_map(playery + 1, playerx, vars);
	check_map(playery, playerx + 1, vars);
	check_map(playery, playerx - 1, vars);
	check_map(playery - 1, playerx, vars);
}

void	check_position(int playery, int playerx, s_list *vars)
{
	if (vars->splitmap[playery][playerx] == 'C')
	{
		vars->splitmap[playery][playerx] = 'c';
		vars->reachablecoin++;
	}
	if (vars->splitmap[playery][playerx] == '1')
	{
		vars->splitmap[playery][playerx] = '3';
		return ;
	}
	if (vars->splitmap[playery][playerx] == 'E')
	{
		vars->splitmap[playery][playerx] = 'e';
		if (++vars->exitable > 1)
			validchecker(vars);
	}
}

void	check_weirdthings(s_list *vars)
{
	int		j;
	int		i;
	char	c;

	i = 0;
	while (vars->splitmap[i] != NULL && vars->validmap != 1)
	{
		j = 0;
		while (vars->splitmap[i][j])
		{
			c = vars->splitmap[i][j];
			if (c == 'P')
				check_extrathings(i, j, vars);
			if (c == 'C')
				check_extrathings(i, j, vars);
			if (c == 'E')
				check_extrathings(i, j, vars);
			if ((c != '1' && c != 'P' && c != 'E' && c != 'C' && c != '0'))
				check_extrathings(i, j, vars);
			j++;
		}
		i++;
	}
	check_mapsize(vars);
	validchecker(vars);
}
void	check_extrathings(int i, int j, s_list *vars)
{
	if (vars->splitmap[i][j] == 'P')
	{
		vars->playery = i;
		vars->playerx = j;
		vars->player++;
	}
	if (vars->splitmap[i][j] == 'C')
		vars->coins++;
	if (vars->splitmap[i][j] == 'E')
		vars->door++;
	if ((vars->splitmap[i][j] != '1' && vars->splitmap[i][j] != 'P'
			&& vars->splitmap[i][j] != 'E' && vars->splitmap[i][j] != 'C'
			&& vars->splitmap[i][j] != '0') || vars->player > 1)
		vars->validmap = 1;
}
void	check_mapwalls(s_list *vars)
{
	int	x;
	int	i;

	i = 0;
	x = -1;
	while (vars->splitmap[i] != NULL)
		i++;
	while (vars->splitmap[0][++x] != '\0')
	{
		if (vars->splitmap[0][x] != '1')
			vars->validmap = 0;
	}
	x = -1;
	while (vars->splitmap[++x] != NULL || (vars->splitmap[x] || x < i))
	{
		if (vars->splitmap[x][0] != '1'
			|| vars->splitmap[x][ft_strlen(vars->splitmap[x]) - 1] != '1')
			vars->validmap = 0;
	}
}
