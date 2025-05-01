#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdio.h>

#ifndef SIZE
#define SIZE 64
#endif

typedef struct t_list
{
    char **splitmap;
    void *mlx;
    void *mlx_win;
    void *playerimg;
    void *floorimg;
    void *wallimg;
    void *coinimg;
    void *doorimg;
    int height;
    int width;
    int playery;
    int playerx;
    int validmap;
    int coins;
    int steps;
} s_list;

void  fill_map(s_list *vars);
void  check_map(int playery, int playerx, s_list *vars);
void  check_mapwalls(s_list *vars);
void  free_all(s_list *vars);
void  init_vars(s_list *vars);
void player_move(s_list *vars, int x, int y);
int closewin(s_list *vars);
int key_hook(int keycode, s_list *vars);
void    check_mapsize(s_list *vars);
void    check_weirdthings(s_list *vars);