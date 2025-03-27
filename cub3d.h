#ifndef CUB3D_H
#define CUB3D_H

#define SUCCESS 0
#define ERROR 1
#define ERROR2 -1

#define PI 3.14159265359
#define MAX_MAP_SIZE 100
#define WIDTH 980
#define HEIGHT 620
#define TILE 32
#define FOV 66 * (PI / 180)
#define T 119 // w
#define B 115 // s
#define L 97  // a
#define R 100 // d
#define LEFT 65361
#define RIGHT 65363
#define N (3 * PI / 2)
#define S PI / 2
#define E 0
#define W PI

#define BUFFER_SIZE 5

#include "includes/minilibx-linux/mlx.h"
#include "includes/libft/libft.h"
#include <X11/X.h>
#include <X11/keysym.h>

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

/*****************************************************************/


typedef struct s_raycast
{
	bool		was_hit_vertical;
	double		v_hit_posx;
	double		v_hit_posy;
	double		v_hit_dist;
	double		h_hit_posx;
	double		h_hit_posy;
	double		h_hit_dist;
	double		wall_hitx;
	double		wall_hity;
	double		wall_hit_dist;
	double		wall_height;
	int			color;
}				t_raycast;

typedef struct s_player
{
	double		x;
	double		y;

	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;

	bool		left_rotate;
	bool		right_rotate;

	double		radius;
	double		rot_angle;
	int			turn_dir;
	int			walk_dir;
}				t_player;

typedef struct s_game_info
{
	char			*NO_file;
	char			*SO_file;
	char			*WE_file;
	char			*EA_file;
	int				floor[3];
	int				cell[3];
	t_list			*map_list;
	char			**map;
	int				lock;
	int				lock_valid_map_lines;
	int				lock_NEWS;
}				t_game_info;

typedef struct s_texture
{
	void			*img_ptr;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				line_len;
	int				endian;
}			t_texture;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;

	t_texture		NO_data;
	t_texture		SO_data;
	t_texture		WE_data;
	t_texture		EA_data;

	void			*img_ptr;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				line_len;
	int				endian;

	t_raycast		raycast_info;
	t_player		player;
	t_game_info		game_info;
}				t_game;

/*****************************************************************/


int 	transforms_list_to_tab(t_game_info *data);
int		map_parsing(char *line, t_game_info *data);
int 	opening_parsing(t_game_info *data, char *str);

int		textures_function(char **file, char *line, int i);
int		colors_function(int	(*tab)[3], char *line);



char	*get_next_line(int fd);

void	print_tab(char **tab);

void    ft_free(char **str);
void	free_struct(t_game *data);

int	start_game(t_game *game);
int	key_press(int keycode, t_player *player);
int	key_release(int keycode, t_player *player);


#endif