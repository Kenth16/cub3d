#include "../cub3d.h"

int init_player(t_player *player)
{
    if (!player)
        return (ERROR);
    player->x = 0;
    player->y = 0;
    player->key_up = false;
    player->key_down = false;
    player->key_left = false;
    player->key_right = false;
    player->left_rotate = false;
    player->right_rotate = false;

	player->radius = 0;
	player->rot_angle = 0;
	player->turn_dir = 0;
	player->walk_dir = 0;

	return (SUCCESS);
}


int	init_info(t_game_info *info)
{
	int i;
	
	i = 0;
	if (!info)
	{
		printf("Error : info not initialized\n.");
		return (ERROR);
	}
	info->NO_file = NULL;
	info->SO_file = NULL;
	info->WE_file = NULL;
	info->EA_file = NULL;
	while (i < 3)
	{
		info->floor[i] = -1;
		info->cell[i] = -1;
		i++;
	}
	info->map = NULL;
	info->map_list = NULL;
	info->lock = 0;
	info->lock_valid_map_lines = 0;
	info->lock_NEWS = 0;
	return (SUCCESS);
}

int	init_textures(void *mlx, t_game_info info, t_texture *img, char *file)
{
	if (file[0] == 'N')
		img->img_ptr = mlx_xpm_file_to_image(mlx, info.NO_file, &img->width, &img->height);
	else if (file[0] == 'S')
		img->img_ptr = mlx_xpm_file_to_image(mlx, info.SO_file, &img->width, &img->height);
	else if (file[0] == 'W')
		img->img_ptr = mlx_xpm_file_to_image(mlx, info.WE_file, &img->width, &img->height);
	else if (file[0] == 'E')
		img->img_ptr = mlx_xpm_file_to_image(mlx, info.EA_file, &img->width, &img->height);
	if (!img->img_ptr)
		return (printf("Error : mlx_xpm_to_img. [%s]\n", file), ERROR);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len, &img->endian);
	return (SUCCESS);
}

int init_struct(t_game *data)
{
	if (!data)
		return (printf("Error: data not initialized.\n"), ERROR);
	if (init_info(&data->game_info) != SUCCESS)
		return (ERROR);
	if (init_player(&data->player) != SUCCESS)
		return (ERROR);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->NO_data.img_ptr = NULL;
	data->NO_data.addr = NULL;
	data->SO_data.img_ptr = NULL;
	data->SO_data.addr = NULL;
	data->WE_data.img_ptr = NULL;
	data->WE_data.addr = NULL;
	data->EA_data.img_ptr = NULL;
	data->EA_data.addr = NULL;
	return (SUCCESS);
}

/**********************************************************************************************/

int	init_mlx(t_game *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (printf("Error : mlx_init.\n"), ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3d");
	if (!data->win_ptr)
		return (printf("Error : mlx_new_window.\n"), ERROR);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bpp,
		&data->line_len, &data->endian);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	if (init_textures(data->mlx_ptr, data->game_info, &data->NO_data, "NO") != SUCCESS)
		return (ERROR);
	if (init_textures(data->mlx_ptr, data->game_info, &data->SO_data, "SO") != SUCCESS)
		return (ERROR);
	if (init_textures(data->mlx_ptr, data->game_info, &data->WE_data, "WE") != SUCCESS)
		return (ERROR);
	if (init_textures(data->mlx_ptr, data->game_info, &data->EA_data, "EA") != SUCCESS)
		return (ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3d");
	if (!data->win_ptr)
		return (printf("Error : mlx_new_window.\n"), ERROR);
	int i = 0;

	//partie a rajouter facilement dans le parsing prendra moins de place.
	while (data->game_info.map[i])
	{
		int j = 0;
		while (data->game_info.map[i][j])
		{
			if (ft_strchr("NWES", data->game_info.map[i][j]))
			{
				data->player.x = j * TILE + TILE / 2;
				data->player.y = i * TILE + TILE / 2;
			}
			if (data->game_info.map[i][j] == 'N')
				data->player.rot_angle = N;
			if (data->game_info.map[i][j] == 'S')
				data->player.rot_angle = S;
			if (data->game_info.map[i][j] == 'E')
				data->player.rot_angle = E;
			if (data->game_info.map[i][j] == 'W')
				data->player.rot_angle = W;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	cub3d(t_game *data)
{
	if (init_mlx(data) != SUCCESS)
		return (ERROR);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_press, &data->player);
	mlx_hook(data->win_ptr, 3, 1L << 1, key_release, &data->player);
	mlx_loop_hook(data->mlx_ptr, start_game, data);
	
	mlx_loop(data->mlx_ptr);
	// if (init_textures_pixels() != SUCCESS)
	// 	return (ERROR);
	return (SUCCESS);
}

/**********************************************************************************************/


int main(int ac, char **av)
{
	t_game	data;

	if (ac != 2)
		return (printf("Use :\t./Programme + Map\n"), ERROR);

	if (init_struct(&data) != SUCCESS)
		return (ERROR);
	if (opening_parsing(&data.game_info, av[1]) != SUCCESS)
	{
		free_struct(&data);
		return (ERROR);
	}
	if (cub3d(&data) != SUCCESS)
		return (ERROR);
	free_struct(&data);
	return (SUCCESS);
}

