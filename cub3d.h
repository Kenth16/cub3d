#ifndef CUB3D_H
#define CUB3D_H

#define SUCCESS 0
#define ERROR 1
#define ERROR2 -1

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

/*****************************************************************/

typedef struct s_player
{
	double		x;
	double		y;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;

	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;

	bool		left_rotate;
	bool		right_rotate;
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


void    ft_free(char **str);
void	free_struct(t_game *data);

#endif