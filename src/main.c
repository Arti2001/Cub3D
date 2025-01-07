/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:07:53 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/07 21:16:33 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"




int	open_texmapfile(char *file)
{
	int	fd;
	
	if (!file)
	{
		return (1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

char* skipspace(char* line)
{
	while (*line && *line == ' ')
	{
		line++;
	}
	return (line);
}
void	free_db_array(char **array)
{
	int i;
	
	i = 0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	free_texmap(t_texmap *texmap)
{
	free(texmap->no_path);
	free(texmap->so_path);
	free(texmap->we_path);
	free(texmap->ea_path);
	free(texmap->ceiling);
	free(texmap->floor);
}
void	valid_textures(char *line, t_texmap *tex_map)
{
	char	**splited_line;
	
	splited_line = splitbywhite(line);
	if (ft_strncmp(splited_line[0], "NO", 3) == 0 && (!tex_map->no_path))
		tex_map->no_path = splited_line[1];
	else if(ft_strncmp(splited_line[0], "SO", 3) == 0 && (!tex_map->so_path))
		tex_map->so_path = splited_line[1];
	else if (ft_strncmp(splited_line[0], "WE", 3) == 0 && (!tex_map->we_path))
		tex_map->we_path = splited_line[1];
	else if (ft_strncmp(splited_line[0], "EA", 3) == 0 && (!tex_map->ea_path))
		tex_map->ea_path = splited_line[1];
	else if (ft_strncmp(splited_line[0], "C", 2) == 0 && (!tex_map->ceiling))
		tex_map->ceiling = splited_line[1];
	else if (ft_strncmp(splited_line[0], "F", 2) == 0 && (!tex_map->floor))
		tex_map->floor = splited_line[1];
	//free_db_array(splited_line);
}

void	if_valid_add(char *line, t_texmap* texmap)
{
	if (*line == '\n' || line == NULL)
	{
		return ;
	}
	if (*line == '\t' || *line == ' ' || *line == '\v' || *line == '\r')
	{
		int length = ft_strlen(line);
		int i = 0;
		while (i < length)
		{
			if (!ft_isalnum(line[i]))
				return ;
			i++;
		}
	}
	valid_textures(line, texmap);
}

void	validate_taxmap(char *file, t_texmap *texmap)
{
	char*	file_content;
	int		fd;

	fd = open_texmapfile(file);
	file_content = get_next_line(fd);

	if (!file_content)
	{
		return ;
	}
	while(file_content)
	{
		if_valid_add(file_content, texmap);
		free(file_content);
		file_content = get_next_line(fd);
	}
	printf("%s\n", texmap->no_path);
	printf("%s\n", texmap->so_path);

	printf("%s\n", texmap->ea_path);

	printf("%s\n", texmap->we_path);

	printf("%s\n", texmap->ceiling);

	printf("%s\n", texmap->floor);

}


void	pars_texmap(char* arg)
{
	t_texmap	textmap;

	ft_memset(&textmap, 0, sizeof(textmap));
	
	validate_taxmap(arg, &textmap);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "ERROR!\n", 7);
		return (1);
	}
	else
		pars_texmap(argv[1]);
	return (0);
}