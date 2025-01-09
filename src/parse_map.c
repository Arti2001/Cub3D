/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 12:07:53 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/09 09:59:44 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

			/*to delete*/
void	print_texmap(t_texmap *texmap)
{
	int	i = 0;
	printf("NO: %s\n", texmap->no_path);
	printf("SO: %s\n", texmap->so_path);
	printf("EA: %s\n", texmap->ea_path);
	printf("WE: %s\n", texmap->we_path);
	printf("C: %s\n", texmap->ceiling);
	printf("F: %s\n", texmap->floor);
	if (texmap->map)
	{
		while (texmap->map[i])
		{
			printf("%s\n", texmap->map[i]);
			i++;
		}
	}
	else
		printf("no map yet!\n");
	// printf("\n");
}

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
		//TODO -> error msg & exit?
		return ;
	}
	while(file_content)
	{
		if_valid_add(file_content, texmap);
		ft_free_string(&file_content);
		if (texmap->ceiling != NULL && texmap->floor != NULL &&
			texmap->no_path != NULL && texmap->so_path != NULL &&
			texmap->ea_path != NULL && texmap->we_path != NULL)
			break ;
		file_content = get_next_line(fd);
	}
	// printf("I got'em all\n");
	get_map(fd, texmap);
	print_texmap(texmap);
}


void	pars_texmap(char* arg)
{
	t_texmap	textmap;

	ft_memset(&textmap, 0, sizeof(textmap));
	
	validate_taxmap(arg, &textmap);
	free_texmap(&textmap); //to delete or move!
}
