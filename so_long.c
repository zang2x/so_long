#include "include/so_long.h"
void    destroyimages(s_list *vars)
{
    if(vars->wallimg)
        mlx_destroy_image(vars->mlx, vars->wallimg);
    if(vars->doorimg)
        mlx_destroy_image(vars->mlx, vars->doorimg);
    if(vars->floorimg)
        mlx_destroy_image(vars->mlx, vars->floorimg);
    if(vars->playerimg)
        mlx_destroy_image(vars->mlx, vars->playerimg);
    if(vars->coinimg)
        mlx_destroy_image(vars->mlx, vars->coinimg);
}
void free_all(s_list *vars)
{
    int i;
    i = 0;
    if(vars->validmap != 0 || vars->exitable > 1)
        ft_printf("Error");
    if(vars->splitmap)
    {   
        while(vars->splitmap[i] != NULL)
        {
            free(vars->splitmap[i]);
            i++;
        }
        free(vars->splitmap);
    }
    destroyimages(vars);
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
    close(fd);
    vars->mlx = mlx_init();
    check_weirdthings(vars);
    check_map(vars->playerx, vars->playery, vars);
    if(vars->reachablecoin != vars->coins || vars->exitable != 1 || vars->door != 1)
        vars->validmap = 1;
    validchecker(vars);
    vars->mlx_win = mlx_new_window(vars->mlx, vars->mapsizex * SIZE, vars->mapsizey * SIZE, "PERROWS VIDIOGAME");
    vars->height = 64;
    vars->width = 64;
    vars->playerimg = mlx_xpm_file_to_image(vars->mlx, "textures/spriteplayer.xpm", &vars->width, &vars->height);
    vars->floorimg = mlx_xpm_file_to_image(vars->mlx, "textures/spritefloor.xpm", &vars->width, &vars->height);
    vars->wallimg = mlx_xpm_file_to_image(vars->mlx, "textures/wall.xpm", &vars->width, &vars->height);
    vars->coinimg = mlx_xpm_file_to_image(vars->mlx, "textures/coin.xpm", &vars->width, &vars->height);
    vars->doorimg = mlx_xpm_file_to_image(vars->mlx, "textures/door.xpm", &vars->width, &vars->height);
}

void player_move(s_list *vars, int x, int y)
{
    if(vars->splitmap[vars->playery + y][vars->playerx + x] == 'e' && vars->reachablecoin != 0)
        ft_printf("There is %d bananas left, don't leave ⛔️\n", vars->reachablecoin);
    if((vars->splitmap[vars->playery + y][vars->playerx + x] != '3' && vars->splitmap[vars->playery + y][vars->playerx + x] != 'e') || (vars->splitmap[vars->playery + y][vars->playerx + x] == 'e' && vars->reachablecoin == 0))
    {
        vars->playerx += x;
        vars->playery += y;
        vars->steps++;
        ft_printf("%d steps.🦶\n", vars->steps);
        if(vars->splitmap[vars->playery][vars->playerx] == 'c')
        {
            vars->reachablecoin -= 1;
            ft_printf("There is %d bananas homie 🍌\n", vars->reachablecoin);
            vars->splitmap[vars->playery][vars->playerx] = '2';
        }
        if(vars->splitmap[vars->playery][vars->playerx] == 'e')
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
    if(keycode == 65307)
        closewin(vars);
    return(0);
}

int main()
{
    s_list vars;
    ft_memset(&vars,0,sizeof(vars));
    init_vars(&vars);
    check_mapwalls(&vars);
    check_mapsize(&vars);
    fill_map(&vars);
    mlx_key_hook(vars.mlx_win, key_hook, &vars);
    mlx_hook(vars.mlx_win, 17, 0, closewin, &vars);
    mlx_loop(vars.mlx);
}