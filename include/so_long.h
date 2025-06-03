/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obmedina <obmedina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:41:37 by obmedina          #+#    #+#             */
/*   Updated: 2025/05/27 11:47:02 by obmedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>

# ifndef SIZE
#  define SIZE 64
# endif

typedef struct s_list
{
	char	**splitmap;
	void	*mlx;
	void	*mlx_win;
	void	*playerimg;
	void	*floorimg;
	void	*wallimg;
	void	*coinimg;
	void	*doorimg;
	int		height;
	int		width;
	int		playery;
	int		playerx;
	int		validmap;
	int		coins;
	int		steps;
	int		mapsizex;
	int		mapsizey;
	int		exitable;
	int		reachablecoin;
	int		player;
	int		door;
	char	*map;
}			t_list;

void		fill_map(t_list *vars);
void		put_image(void *img, int y, int j, t_list *vars);
void		check_map(int playery, int playerx, t_list *vars);
void		check_mapwalls(t_list *vars);
int			free_all(t_list *vars);
void		init_vars(t_list *vars);
void		player_move(t_list *vars, int x, int y);
int			closewin(t_list *vars);
int			key_hook(int keycode, t_list *vars);
void		check_mapsize(t_list *vars);
void		check_weirdthings(t_list *vars);
void		validchecker(t_list *vars);
void		destroyimages(t_list *vars);
void		check_position(int playery, int playerx, t_list *vars);
void		check_extrathings(int i, int j, t_list *vars);
void		init_imgs(t_list *vars);
#endif