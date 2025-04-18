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
    int height;
    int width;
    int playery;
    int playerx;
    int validmap;
    int coins;
    int steps;
} s_list;