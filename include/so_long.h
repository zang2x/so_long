#include "ft_printf.h"
#include "libft.h"
#include "mlx.h"

typedef struct t_list
{
    void *mlx;
    void *mlx_win;
    void *playerimg;
    void *floorimg;
    int height;
    int width;
    int playery;
    int playerx;
} s_list;