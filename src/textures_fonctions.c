#include "../cub3d.h"

int	is_valid_textures(char *line)
{
    int			fd;
    char		*file;
    const char	*prefix = "includes/textures"; //changement icic ausssi

    file = malloc(ft_strlen(prefix) + ft_strlen(line + 1) + 1);
    if (!file)
        return (ERROR);
    ft_strcpy(file, prefix);
	strcat(file, line + 1); // Refaire ft
	if (!file)
		return (ERROR);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_free(&file);
		return (ERROR);
	}
	ft_free(&file);
	close(fd);
	return (SUCCESS);
}

int	textures_function(char **file, char *line, int i)
{
	char	*new_line;

	new_line = NULL;
	if (*file == NULL)
	{
		new_line = ft_strcopy_until(line + i + 2, ' ');
		if (!new_line)
			return (ERROR);
		if (is_valid_textures(new_line) != SUCCESS)
		{
			printf("Error : unable to open the texture [%s].\n", line);
			return (ERROR);
		}
		*file = new_line;
		return (SUCCESS);
	}
	printf("Error : %s duplicates\n", *file);
	return (ERROR);
}