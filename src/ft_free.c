#include "../cub3d.h"

void    ft_free(char **str)
{
	free(*str);
	*str = NULL;
}
