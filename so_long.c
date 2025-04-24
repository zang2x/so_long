#include "include/so_long.h"

void free_all(s_list *vars)
{
    int i;
    i = 0;
    if(vars->splitmap)
    {   
        while(vars->splitmap[i] != NULL)
        {
            free(vars->splitmap[i]);
            i++;
        }
        free(vars->splitmap);
    }
    if(vars->playerimg)
        mlx_destroy_image(vars->mlx, vars->playerimg);
    if(vars->wallimg)
        mlx_destroy_image(vars->mlx, vars->wallimg);
    if(vars->floorimg)
        mlx_destroy_image(vars->mlx, vars->floorimg);
    if(vars->mlx && vars->mlx_win)
    {
        mlx_destroy_window(vars->mlx, vars->mlx_win);
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
    }
    exit(0);
}

void    init_vars(s_list *vars)
{
    int fd;
    int rbytes;
    char map[1024];
    fd = open("map1.ber", O_RDONLY);
    rbytes = read(fd, map, 1024);
    map[rbytes] = '\0';
    vars->splitmap = ft_split(map, '\n');
    vars->mlx = mlx_init();
    vars->mlx_win = mlx_new_window(vars->mlx, 840, 840, "PERROWS VIDIOGAME");
    vars->height = 64;
    vars->width = 64;
    vars->playerimg = mlx_xpm_file_to_image(vars->mlx, "textures/spriteplayer.xpm", &vars->width, &vars->height);
    vars->floorimg = mlx_xpm_file_to_image(vars->mlx, "textures/spritefloor.xpm", &vars->width, &vars->height);
    vars->wallimg = mlx_xpm_file_to_image(vars->mlx, "textures/wall.xpm", &vars->width, &vars->height);
    vars->coinimg = mlx_xpm_file_to_image(vars->mlx, "textures/coin.xpm", &vars->width, &vars->height);
    vars->doorimg = mlx_xpm_file_to_image(vars->mlx, "textures/door.xpm", &vars->width, &vars->height);
    vars->playery = 1;
    vars->playerx = 1;
    vars->coins = 0;
    vars->steps = 0;
}

void player_move(s_list *vars, int x, int y)
{
    if(vars->splitmap[vars->playery + y][vars->playerx + x] == 'E' && vars->coins != 0)
        ft_printf("There is %d bananas left, don't leave ⛔️\n", vars->coins);
    if((vars->splitmap[vars->playery + y][vars->playerx + x] != '1' && vars->splitmap[vars->playery + y][vars->playerx + x] != 'E') || (vars->splitmap[vars->playery + y][vars->playerx + x] == 'E' && vars->coins == 0))
    {
        vars->playerx += x;
        vars->playery += y;
        vars->steps++;
        ft_printf("%d steps.🦶\n", vars->steps);
        if(vars->splitmap[vars->playery][vars->playerx] == 'c')
        {
            vars->coins -= 1;
            ft_printf("There is %d bananas homie 🍌\n", vars->coins);
            vars->splitmap[vars->playery][vars->playerx] = '2';
        }
        if(vars->splitmap[vars->playery][vars->playerx] == 'E')
        {

            ft_printf("We got it in %d steps, brutal 🏆\n", vars->steps);
            free_all(vars);
        }    
    }
    mlx_clear_window(vars->mlx, vars->mlx_win);
    fill_map(vars);
}

int closewin(s_list *vars)
{
    free_all(vars);
    return(0);
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
    ft_memset(&vars,0,sizeof(vars));
    init_vars(&vars);
    check_map(vars.playery, vars.playerx, &vars);
    ft_printf(", 7 El mapa es = %d", vars.validmap);
    check_mapwalls(&vars);
    ft_printf(", 8 El walls es = %d", vars.validmap);
    check_mapsize(&vars);
    ft_printf(",El mapsize es = %d,", vars.validmap);
    fill_map(&vars);
    mlx_key_hook(vars.mlx_win, key_hook, &vars);
    mlx_hook(vars.mlx_win, 17, 0, closewin, &vars);
    mlx_loop(vars.mlx);
}