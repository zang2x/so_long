#include "include/so_long.h"
void    check_map(int playery, int playerx, s_list *vars)
{
    if(playery < 0 || playerx < 0 || playerx >= vars->mapsizex || playery >= vars->mapsizey)
        return;
    if(vars->splitmap[playery][playerx] == '2' || vars->splitmap[playery][playerx] == '3' || vars->splitmap[playery][playerx] == 'e')
        return;
    if(vars->splitmap[playery][playerx] == 'C')
    {
        vars->splitmap[playery][playerx] = 'c';   
        vars->reachablecoin++;
    }
    if(vars->splitmap[playery][playerx] == '1')
    {
        vars->splitmap[playery][playerx] = '3';
        return;  
    }
    if(vars->splitmap[playery][playerx] == 'E')
    {
        vars->splitmap[playery][playerx] = 'e';
        if(++vars->exitable > 1)
            validchecker(vars);
    }
    if(vars->splitmap[playery][playerx] != 'c' && vars->splitmap[playery][playerx] != 'P' && vars->splitmap[playery][playerx] != '3' && vars->splitmap[playery][playerx] != 'e')
        vars->splitmap[playery][playerx] = '2';
    check_map(playery + 1, playerx, vars);
    check_map(playery, playerx + 1, vars);
    check_map(playery, playerx - 1, vars);
    check_map(playery - 1, playerx, vars);
}

void    check_weirdthings(s_list *vars)
{
    int j;
    int i;
    
    i = 0;
    j = 0;
    while(vars->splitmap[i] != NULL && vars->validmap != 1)
    {
        j = 0;     
        while(vars->splitmap[i][j])
        {
            if(vars->splitmap[i][j] == 'P')
            {
                vars->playery = i;
                vars->playerx = j;
                vars->player++;
            }
            if(vars->splitmap[i][j] == 'C')
                vars->coins++;
            if(vars->splitmap[i][j] == 'E') 
                vars->door++;
            if((vars->splitmap[i][j] != '1' && vars->splitmap[i][j] != 'P' && vars->splitmap[i][j] != 'E' && vars->splitmap[i][j] != 'C' && vars->splitmap[i][j] != '0') || vars->player > 1)
                vars->validmap = 1;
            j++;
        }
        i++;
    }
    check_mapsize(vars);
    validchecker(vars);
}
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

void    fill_map(s_list *vars)
{
    int i = 0;
    int j = 0;
    while(vars->splitmap[i] != NULL)
    {
        j = 0;     
        while(vars->splitmap[i][j])
        {
            if(vars->splitmap[i][j] == 'C')
                vars->validmap = 1;
            if(vars->splitmap[i][j] == '3' || vars->splitmap[i][j] == '1')
                mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floorimg, SIZE * j, SIZE * i);
            if(vars->splitmap[i][j] == '2' || vars->splitmap[i][j] == '0')
                mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->wallimg, SIZE * j, SIZE * i);
            if(vars->splitmap[i][j] == 'c' || vars->splitmap[i][j] == 'C')
                mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->coinimg, SIZE * j, SIZE * i);
            if(vars->splitmap[i][j] == 'P')
                mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->wallimg, SIZE * j, SIZE * i);
            if(vars->splitmap[i][j] == 'e')
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
    int sizex;
    x = 0;
    sizex = ft_strlen(vars->splitmap[x]);
    while(vars->splitmap[x + 1] != NULL)
    {
        x++;
        if(ft_strlen(vars->splitmap[x]) != (size_t)sizex)
                vars->validmap = 1;
        sizex = ft_strlen(vars->splitmap[x]);
    }
    vars->mapsizey = x + 1;
    vars->mapsizex = sizex;
}

void    validchecker(s_list *vars)
{
    if(vars->validmap != 0)
        free_all(vars);
}