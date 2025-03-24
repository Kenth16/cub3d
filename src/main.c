#include "../cub3d.h"

int init_player(t_player *player)
{
    if (!player)
        return (ERROR);
    player->x = 0;
    player->y = 0;
    player->dirX = -1;
    player->dirY = 0;
    player->planeX = 0;
    player->planeY = 0.66; // FOV standard pour raycasting

    player->key_up = false;
    player->key_down = false;
    player->key_left = false;
    player->key_right = false;
    player->left_rotate = false;
    player->right_rotate = false;
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
		return (printf("Error : mlx_xpm_to_img.\n"), ERROR);
	img->addr = mlx_get_data_addr(mlx, &img->bpp, &img->line_len, &img->endian);
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
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (printf("Error : mlx_init.\n"), ERROR);
	// if (init_textures(data->mlx_ptr, data->game_info, &data->NO_data, "NO") != SUCCESS)
	// 	return (ERROR);
	// if (init_textures(data->mlx_ptr, data->game_info, &data->SO_data, "SO") != SUCCESS)
	// 	return (ERROR);
	// if (init_textures(data->mlx_ptr, data->game_info, &data->WE_data, "WE") != SUCCESS)
	// 	return (ERROR);
	// if (init_textures(data->mlx_ptr, data->game_info, &data->EA_data, "EA") != SUCCESS)
	// 	return (ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 600, "Cub3d");
	if (!data->win_ptr)
		return (printf("Error : mlx_new_window.\n"), ERROR);
	
	return (SUCCESS);
}

/**********************************************************************************************/






int	cub3d(t_game *data)
{
	// mlx_hook(data->win_ptr, KeyPress, KeyPressMask, close_window, data);
	// mlx_hook(data->win_ptr, DestroyNotify, 0, close_cross, data);

	mlx_loop(data->mlx_ptr);
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
	printf("NO = %s\nSO = %s\nWE = %s\nEA = %s\n", data.game_info.NO_file, data.game_info.SO_file, data.game_info.WE_file, data.game_info.EA_file);
	printf("F = %d, C = %d\n", data.game_info.floor[0], data.game_info.cell[0]);
	printf("F = %d, C = %d\n", data.game_info.floor[1], data.game_info.cell[1]);
	printf("F = %d, C = %d\n*-------------------------*\n", data.game_info.floor[2], data.game_info.cell[2]);
	// print_tab(data.game_info.map);
	if (cub3d(&data) != SUCCESS)
		return (ERROR);
	free_struct(&data);
	return (SUCCESS);
}

/*
mlx_init() = Initialise la connexion avec le serveur graphique.
mlx_new_window(mlx, largueur, hauteur, titre) = creer une nouvelle fenetre.
int mlx_hook(void *win_ptr, int event, int mask, int (*f)(), void *param) = 
		Permet de detecter une touche pressee?relachee 2/3
		Permet de detecter la fermeture d'une fenetre 17
		Permet de detecter le clqique de la souris 4
		Permet de detecter le relachement de la souris 5
		Permet de detecter le mouvement de la souris 6
mlx_destroy_window(mlx, win) = ferme la fenetre et libere les ressources
mlx_loop(mlx) =  boucle principale qui gere les evenements.




mettre les donnees dans structures player.



*/


