#include "include/so_long.h"
#include <stdio.h>

void    check_sizemap(s_list *vars)
{
    int x;
    int i;
    i = 0;
    x = 0;
    while(vars->splitmap[i] != NULL)
        i++;
    while(vars->splitmap[0][x] != '\0')
    {
        if(vars->splitmap[0][x] != '1')
            vars->validmap = 0;
        x++;       
    }
    x = 0;
    while(vars->splitmap[x] != NULL)
    {
        if(vars->splitmap[x][0] != '1' || vars->splitmap[x][ft_strlen(vars->splitmap[x]) - 1] != '1')
            vars->validmap = 0;
        x++;       
    }
    x = 0;
    while(vars->splitmap[x] || x < i)
    {
        if(vars->splitmap[x][0] != '1' || vars->splitmap[x][ft_strlen(vars->splitmap[x]) - 1] != '1')
            vars->validmap = 0;
        x++;       
    }
}

void    check_map(int playery, int playerx, s_list *vars)
{
    if(playery < 0 || playerx < 0 || vars->splitmap[playery] == NULL || vars->splitmap[playery][playerx] == '\0')
        return;
    if(vars->splitmap[playery][playerx] == 'E')
    {
        vars->validmap = 1;
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
                mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floorimg, SIZE * j, SIZE * i);
            if(vars->splitmap[i][j] == 'P')
                mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->wallimg, SIZE * j, SIZE * i);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->playerimg, SIZE * vars->playerx, SIZE * vars->playery);
    mlx_string_put(vars->mlx, vars->mlx_win, 100, 100, 87, ft_itoa(vars->coins));
}

void    init_vars(s_list *vars)
{
    int fd;
    char map[1024];
    fd = open("map1.ber", O_RDONLY);
    read(fd, map, 1024);
    vars->splitmap = ft_split(map, '\n');
    vars->mlx = mlx_init();
    vars->mlx_win = mlx_new_window(vars->mlx, 840, 840, "PERROWS VIDIOGAME");
    vars->height = 64;
    vars->width = 64;
    vars->playerimg = mlx_xpm_file_to_image(vars->mlx, "sprites/spriteplayer.xpm", &vars->width, &vars->height);
    vars->floorimg = mlx_xpm_file_to_image(vars->mlx, "sprites/spritefloor.xpm", &vars->width, &vars->height);
    vars->wallimg = mlx_xpm_file_to_image(vars->mlx, "sprites/wall.xpm", &vars->width, &vars->height);
    vars->playery = 1;
    vars->playerx = 1;
    vars->coins = 0;
}

void player_move(s_list *vars, int x, int y)
{
    if(vars->splitmap[vars->playery + y][vars->playerx + x] != '1')
    {
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->wallimg, SIZE * vars->playerx, SIZE * vars->playery);
        vars->playerx += x;
        vars->playery += y;
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->playerimg, SIZE * vars->playerx, SIZE * vars->playery);
        if(vars->splitmap[vars->playery][vars->playerx] == 'c')
        {
            vars->coins -= 1;
            ft_printf("Faltan %d monedas wey\n", vars->coins);
            vars->splitmap[vars->playery][vars->playerx] = '2';
        }
        if(vars->splitmap[vars->playery][vars->playerx] == 'E')
        {
            if(vars->coins > 0)
            {
                ft_printf("Aun te faltan %d monedas, no te vayas\n", vars->coins);
            }
            else
            {
                mlx_destroy_window(vars->mlx, vars->mlx_win);
                ft_printf("Lo tenemos, brutal\n");
                exit(0);
            }
        }    
    }
    mlx_clear_window(vars->mlx, vars->mlx_win);
    fill_map(vars);
}

int closewin(s_list *vars)
{
    mlx_destroy_window(vars->mlx, vars->mlx_win);
    exit(0);
}

int key_hook(int keycode, s_list *vars)
{
    if(keycode == 100) // D
        player_move(vars, 1, 0);
    if(keycode == 97) // A
        player_move(vars, -1, 0);
    if(keycode == 115) // S
        player_move(vars, 0, 1);
    if(keycode == 119) // W
        player_move(vars, 0, -1);
    return(0);
}

int main()
{
    s_list vars;
    init_vars(&vars);
    check_map(vars.playery, vars.playerx, &vars);
    check_sizemap(&vars);
    fill_map(&vars);
    mlx_key_hook(vars.mlx_win, key_hook, &vars);
    mlx_hook(vars.mlx_win, 17, 0, closewin, &vars);
    mlx_loop(vars.mlx);
}