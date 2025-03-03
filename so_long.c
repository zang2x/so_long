#include "include/so_long.h"
#include <stdio.h>

void    fill_map(s_list *vars)
{
    int fd;
    int i = 0;
    int j = 0;
    vars->playerx = 0;
    char map[1024];
    char **splitmap;
    fd = open("map1.ber", O_RDONLY);
    read(fd, map, 1024);
    splitmap = ft_split(map, '\n');
    printf("%s\n", splitmap[0]);
    printf("%s\n", splitmap[1]);
    printf("%s\n", splitmap[2]);
    printf("%s\n", splitmap[3]);
    printf("%s\n", splitmap[4]);
    printf("%s", splitmap[5]);
    while(splitmap[i] != NULL)
    {
        j = 0;     
        while(splitmap[i][j])
        {
            if(splitmap[i][j] == '0')
            {
                mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floorimg, SIZE * i, SIZE * j);
            }
            j++;
        }
        i++;
    }
}

void    init_vars(s_list *vars)
{
    vars->mlx = mlx_init();
    vars->mlx_win = mlx_new_window(vars->mlx, 640, 640, "PERROWS VIDIOGAME");
    vars->height = 64;
    vars->width = 64;
    vars->playerimg = mlx_xpm_file_to_image(vars->mlx, "spriteplayer.xpm", &vars->width, &vars->height);
    vars->floorimg = mlx_xpm_file_to_image(vars->mlx, "spritefloor.xpm", &vars->width, &vars->height);
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->playerimg, 0, 0);
    vars->playery = 0;
    vars->playerx = 0;
}

void player_move(s_list *vars, int x, int y)
{
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floorimg, vars->playerx, vars->playery);
    vars->playerx += x;
    vars->playery += y;
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->playerimg, vars->playerx, vars->playery);
}

int key_hook(int keycode, s_list *vars)
{
    if(keycode == 100) // D
        player_move(vars, 64, 0);
    if(keycode == 97) // A
        player_move(vars, -64, 0);
    if(keycode == 115) // S
        player_move(vars, 0, 64);
    if(keycode == 119) // W
        player_move(vars, 0, -64);
    return(0);
}

int main()
{
    s_list vars;
    fill_map(&vars);
//    init_vars(&vars);
//    mlx_key_hook(vars.mlx_win, key_hook, &vars);
//    mlx_loop(vars.mlx);
}