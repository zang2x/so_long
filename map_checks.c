#include "include/so_long.h"

void    check_mapwalls(s_list *vars)
{
    int x;
    int i;
    i = 0;
    x = -1;
    while(vars->splitmap[i] != NULL)
        i++;
    while(vars->splitmap[0][++x] != '\0')
    {
        if(vars->splitmap[0][x] != '1')
            vars->validmap = 0;      
    }
    x = -1;
    while(vars->splitmap[++x] != NULL)
    {
        if(vars->splitmap[x][0] != '1' || vars->splitmap[x][ft_strlen(vars->splitmap[x]) - 1] != '1')
            vars->validmap = 0;      
    }
    x = -1;
    while(vars->splitmap[++x] || x < i)
    {
        if(vars->splitmap[x][0] != '1' || vars->splitmap[x][ft_strlen(vars->splitmap[x]) - 1] != '1')
            vars->validmap = 0;      
    }
}

void    check_map(int playery, int playerx, s_list *vars)
{
    if(playery < 0 || playerx < 0 || vars->splitmap[playery] == NULL || vars->splitmap[playery][playerx] == '\0')
        return;
    if(vars->splitmap[playery][playerx] == 'E')
    {
        vars->validmap = 0;
        return;
    }
    if(vars->splitmap[playery][playerx] == 'C')
    {
        vars->splitmap[playery][playerx] = 'c';   
        vars->coins++;
    }
    if(vars->splitmap[playery][playerx] == '1' || vars->splitmap[playery][playerx] == '2' )
        return;
    if(vars->splitmap[playery][playerx] == 'P')
    {
        vars->playery = playery;
        vars->playerx = playerx;
    }
    if(vars->splitmap[playery][playerx] != 'c' && vars->splitmap[playery][playerx] != 'P')
        vars->splitmap[playery][playerx] = '2';
    check_map(playery + 1, playerx, vars);
    check_map(playery, playerx + 1, vars);
    check_map(playery, playerx - 1, vars);
    check_map(playery - 1, playerx, vars);
}

void    fill_map(s_list *vars)
{
    int i = 0;
    int j = 0;
    while(vars->splitmap[i] != NULL)
    {
        j = 0;     
        while(vars->splitmap[i][j])
        {
            if(vars->splitmap[i][j] == '1')
                mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floorimg, SIZE * j, SIZE * i);
            if(vars->splitmap[i][j] == '2')
                mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->wallimg, SIZE * j, SIZE * i);
            if(vars->splitmap[i][j] == 'c')
                mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->coinimg, SIZE * j, SIZE * i);
            if(vars->splitmap[i][j] == 'P')
                mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->wallimg, SIZE * j, SIZE * i);
            if(vars->splitmap[i][j] == 'E')
                mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->doorimg, SIZE * j, SIZE * i);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->playerimg, SIZE * vars->playerx, SIZE * vars->playery);
}

void    check_mapsize(s_list *vars)
{
    int x;
    int size;
    x = 0;
    size = ft_strlen(vars->splitmap[x]);
    while(vars->splitmap[x + 1] != NULL)
    {
        x++;
        if(ft_strlen(vars->splitmap[x]) != (size_t)size)
                vars->validmap = 1;
        size = ft_strlen(vars->splitmap[x]);
    }
}