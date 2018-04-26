/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:05:59 by lguiller          #+#    #+#             */
/*   Updated: 2018/04/26 15:51:09 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <limits.h>

# define MAPX			32
# define MAPY			32
# define INFOX			256
# define INFOY			WINY
# define FPX			960
# define FPY			600
# define WINX			FPX + INFOX
# define WINY			FPY
# define SCRNX			320
# define SCRNY			200
# define BLOCK_SIZE		64.0
# define CAM_HEIGHT		BLOCK_SIZE / 2
# define FOV			60.0
# define TO_RAD(x)		x * M_PI / 180.0
# define TO_DEG(x)		x / (M_PI / 180.0)
# define RAY_ANGLE		FOV / (double)SCRNX
# define WALL			'1'
# define FLOOR			' '
# define TO_MAP(x)		(int)x / 64
# define WALL_COLOR		0x888800

# ifdef __linux__
#  define ESC			65307
# else
#  define ESC			53
# endif

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_fcoord
{
	double		x;
	double		y;
}				t_fcoord;

typedef struct	s_player
{
	double		x;
	double		y;
	double		a;
}				t_player;

typedef struct	s_parse
{
	short		i;
	char		*buff;
	char		fd;
}				t_parse;

typedef struct	s_ray
{
	double		x;
	double		y;
	double		fx;
	double		fy;
	double		xa;
	double		ya;
	double		dx;
	double		dy;
}				t_ray;

typedef struct	s_raycast
{
	t_ray		r_hori;
	t_ray		r_vert;
	t_ray		ray;
	double		dist;
	char		**map;
}				t_raycast;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			sl;
	int			endian;
	int			bpp;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_img		info;
	t_img		fp;
}				t_mlx;

typedef struct s_algo_brez
{
	int			da;
	int			db;
	int			i;
	int			cpta;
	int			cptb;
	int			cumul;
	int			a;
	int			b;
}				t_algo_brez;

void			ft_init_player(char **map, t_player *p);
void			ft_check_map(char *buff, char *start);
void			ft_read_file(char *name, char ***map);
void			ft_free_map(char **map);
void			ft_draw(t_raycast rc, t_ray ray, t_player p);
void			ft_fill_pixel(t_img *ptr, int x, int y, int col);
void			ft_algo(t_img *ptr, t_ray ray, t_player p, int col);
void			ft_wall_dist(t_raycast *rc, t_player *p);
void			ft_print_map(t_img *ptr, char **map);
int				ft_key_funct(int key, void *x);
void			ft_print_on_screen(t_raycast rc, t_img *fp, int x);

#endif
