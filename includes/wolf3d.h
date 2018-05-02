/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:05:59 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/02 14:29:38 by lguiller         ###   ########.fr       */
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
# define BLOCK_SIZE		64.0
# define CAM_HEIGHT		BLOCK_SIZE / 2
# define FOV			60.0
# define TO_RAD(x)		x * M_PI / 180.0
# define TO_DEG(x)		x / (M_PI / 180.0)
# define RAY_ANGLE		FOV / (double)FPX
# define WALL			'1'
# define FLOOR			' '
# define TO_MAP(x)		(int)x / 64
# define BLACK			0x0
# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define GREEN			0xFF00
# define BLUE			0xFF
# define GREY			0xCCCCCC
# define YELLOW			0xFFFF00
# define TOP			0x59809C
# define BOTTOM			0x613318
# define NORTH			M_PI / 2.0
# define SOUTH			3.0 * M_PI / 2.0
# define WEST			M_PI
# define EAST			0.0
# define EAST2			2.0 * M_PI
# define SPEED			10.0
# define HIT_BOX		20.0

# ifdef __linux__
#  define ESC			65307

#  define KEY_A			0
#  define KEY_D			2
#  define KEY_W			13
#  define KEY_S			1
# else
#  define ESC			53
#  define KEY_A			0
#  define KEY_D			2
#  define KEY_W			13
#  define KEY_S			1
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

typedef struct	s_all
{
	t_raycast	rc;
	t_player	p;
	t_img		info;
	t_img		fp;
	t_mlx		ptr;
}				t_all;

void			ft_init_player(char **map, t_player *p);
void			ft_check_map(char *buff, char *start);
void			ft_read_file(char *name, char ***map);
void			ft_free_map(char **map);
void			ft_draw(t_all all);
void			ft_fill_pixel(t_img *ptr, int x, int y, int col);
void			ft_algo(t_img *ptr, t_ray ray, t_player *p, int col);
void			ft_wall_dist(t_img *info, t_raycast *rc, t_player *p, double a);
void			ft_print_map(t_img *ptr, char **map);
int				ft_key_funct(int key, t_all *all);
void			ft_print_on_screen(t_raycast *rc, t_img *fp, int x);
void			ft_print_all(t_img *info, t_raycast *rc, t_player *p, t_img *fp);

#endif
