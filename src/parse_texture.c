/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_texture.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 12:07:53 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/10 12:30:55 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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


