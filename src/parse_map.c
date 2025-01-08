/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:07:53 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/08 19:37:11 by amysiv           ###   ########.fr       */
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

void	free_texmap(t_texmap *texmap)
{
	ft_free_string(&texmap->no_path);
	ft_free_string(&texmap->so_path);
	ft_free_string(&texmap->we_path);
	ft_free_string(&texmap->ea_path);
}


int	is_full(t_texmap *texmap)
{
	if (texmap->ceiling != NULL && texmap->floor != NULL &&
			texmap->no_path != NULL && texmap->so_path != NULL &&
			texmap->ea_path != NULL && texmap->we_path != NULL)
			return (0);
		else
			return(1);
}
//int	are_alldigit(char *str)
//{
//	int	i;

//	i = 0;
//	while (ft_isdigit(str[i]) || str[i] == ,)
//	{
//		/* code */
//	}
	
//}

void	ceiling_rgb(char* str)
{
	char**	no_comma;

	no_comma = ft_split(str, ',');
	printf("%s\n", no_comma[0]);
	printf("%s\n", no_comma[0]);
	printf("%s\n", no_comma[0]);
}

void	floor_rgb(char* str)
{
	char**	no_comma;

	no_comma = ft_split(str, ',');
	
	printf("%s\n", no_comma[0]);
	printf("%s\n", no_comma[0]);
	printf("%s\n", no_comma[0]);
}
void	valid_textures(char *line, t_texmap *texmap)
{
	char	**splited_line;
	
	splited_line = splitbywhite(line, '\0');
	if (splited_line [0] == NULL)
		return ;
	else if (splited_line[1] == NULL)
		error_bye_texmap(texmap, NO_PATH_FOUND);
	else if (ft_strncmp(splited_line[0], "NO", 3) == 0 && !texmap->no_path)
		texmap->no_path = splited_line[1];
	else if(ft_strncmp(splited_line[0], "SO", 3) == 0 && !texmap->so_path)
		texmap->so_path = splited_line[1];
	else if (ft_strncmp(splited_line[0], "WE", 3) == 0 && !texmap->we_path)
		texmap->we_path = splited_line[1];
	else if (ft_strncmp(splited_line[0], "EA", 3) == 0 && !texmap->ea_path)
		texmap->ea_path = splited_line[1];
	else if (ft_strncmp(splited_line[0], "C", 2) == 0 && !texmap->ceiling)
		ceiling_rgb(splited_line[1]);
	else if (ft_strncmp(splited_line[0], "F", 2) == 0 && !texmap->floor)
		floor_rgb(splited_line[1]);
}


void	if_valid_add(char *line, t_texmap* texmap)
{
	if (*line == '\n' || line == NULL)
	{
		return ;
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
		return ;
	while(file_content && is_full(texmap))
	{
		if_valid_add(file_content, texmap);
		ft_free_string(&file_content);
		file_content = get_next_line(fd);
	}
	
	//printf("%s\n", texmap->no_path);
	//printf("%s\n", texmap->so_path);
	//printf("%s\n", texmap->ea_path);
	//printf("%s\n", texmap->we_path);
	//printf("%s\n", texmap->ceiling);
	//printf("%s\n", texmap->floor);
}


void	pars_texmap(char* arg)
{
	t_texmap	textmap;

	ft_memset(&textmap, 0, sizeof(textmap));
	
	validate_taxmap(arg, &textmap);
}
