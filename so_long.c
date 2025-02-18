#include "include/so_long.h"
#include <stdio.h>
void    init_vars(struct t_list *vars)
{
    vars->mlx = mlx_init();
    vars->mlx_win = mlx_new_window(vars->mlx, 500, 500, "PERROWS");
    vars->height = 64;
    vars->width = 64;
    vars->playerimg = mlx_xpm_file_to_image(vars->mlx, "spriteplayer.xpm", &vars->width, &vars->height);
    vars->floorimg = mlx_xpm_file_to_image(vars->mlx, "spritefloor.xpm", &vars->width, &vars->height);
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->playerimg, 0, 0);
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floorimg, 64, 0);
    vars->playery = 0;
    vars->playerx = 0;
}

void player_move(struct t_list *vars, int x, int y)
{
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->floorimg, vars->playerx, vars->playery);
    vars->playerx += x;
    vars->playery += y;
    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->playerimg, vars->playerx, vars->playery);
}
int key_hook(int keycode, struct t_list *vars)
{
    if(keycode == 100)
    {
        printf("el keycode es %d", keycode);
        player_move(vars, 64, 0);
        return(0);
    }
    return(0);
}

int main()
{
    struct t_list vars;
    init_vars(&vars);
    mlx_key_hook(vars.mlx_win, key_hook, &vars);
    mlx_loop(vars.mlx);
}