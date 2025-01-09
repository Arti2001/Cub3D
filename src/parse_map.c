/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   parse_map.c	:+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: amysiv <amysiv@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2025/01/06 12:07:53 by mstencel	  #+#	#+#	 */
/*   Updated: 2025/01/09 10:51:17 by amysiv	   ###   ########.fr	   */
/*	*/
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

int is_struct_full(t_ceiling *ceiling, t_floor *floor)
{
	if (ceiling!= NULL)
	{
		if (ceiling->r == 0 || ceiling->g == 0 || ceiling->b == 0)
		{
		return 0;
		}
	}
	if (floor != NULL)
	{
		if (floor->r == 0 || floor->g == 0 || floor->b == 0)
		{
		return 0;
		}
	}

	return 1;
}

void	ceiling_rgb(char* str, t_texmap *texmap)
{
	char**	ceiling_arg;
	
	ceiling_arg = splitbywhite(str, ',');
	texmap->ceiling->r = ft_atoi(ceiling_arg[1]);
	texmap->ceiling->g = ft_atoi(ceiling_arg[2]);
	texmap->ceiling->b = ft_atoi(ceiling_arg[3]);
	if (texmap->ceiling->r > 255 ||
		texmap->ceiling->g > 255 ||
		texmap->ceiling->b > 255)
	{
		error_bye_texmap(texmap, ERR_OUT_OF_RANGE_C);
	}

}

void	floor_rgb(char* str, t_texmap *texmap)
{
	char**	floor_arg;

	floor_arg = splitbywhite(str, ',');
	
	
	texmap->floor->r = ft_atoi(floor_arg[1]);
	texmap->floor->g = ft_atoi(floor_arg[2]);
	texmap->floor->b = ft_atoi(floor_arg[3]);

	
	if (texmap->floor->r > 255 ||
		texmap->floor->g > 255 ||
		texmap->floor->b > 255)
	{
		error_bye_texmap(texmap, ERR_OUT_OF_RANGE_F);
	}
	
}
void	valid_textures(char *line, t_texmap *texmap)
{
	char	**splited_line;
	
	splited_line = splitbywhite(line, '\0');
	if (splited_line [0] == NULL)
		return ;
	else if (splited_line[1] == NULL)
		error_bye_texmap(texmap, ERR_NO_PATH_FOUND);
	else if (ft_strncmp(splited_line[0], "NO", 3) == 0 && !texmap->no_path)
		texmap->no_path = splited_line[1];
	else if(ft_strncmp(splited_line[0], "SO", 3) == 0 && !texmap->so_path)
		texmap->so_path = splited_line[1];
	else if (ft_strncmp(splited_line[0], "WE", 3) == 0 && !texmap->we_path)
		texmap->we_path = splited_line[1];
	else if (ft_strncmp(splited_line[0], "EA", 3) == 0 && !texmap->ea_path)
		texmap->ea_path = splited_line[1];
	else if (ft_strncmp(splited_line[0], "C", 2) == 0 && texmap->ceiling != NULL)
	{
		ft_free_array(splited_line);	
		ceiling_rgb(line, texmap);
	}
	else if (ft_strncmp(splited_line[0], "F", 2) == 0 && texmap->floor != NULL)
	{
		ft_free_array(splited_line);
		floor_rgb(line, texmap);
	}
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
	printf("%s\n", texmap->no_path);
	printf("%s\n", texmap->so_path);
	printf("%s\n", texmap->ea_path);
	printf("%s\n", texmap->we_path);
	printf("ceiling value r: %d\n", texmap->ceiling->r);
	printf("ceiling value g: %d\n", texmap->ceiling->g);
	printf("ceiling value b: %d\n", texmap->ceiling->b);
	printf("floor value r: %d\n", texmap->floor->r);
	printf("floor value g: %d\n", texmap->floor->g);
	printf("floor value b: %d\n", texmap->floor->b);
	

}


void	pars_texmap(char* arg)
{
	t_texmap	textmap;

	ft_memset(&textmap, 0, sizeof(textmap));
	textmap.ceiling = (t_ceiling*)malloc(sizeof(t_ceiling));
	textmap.floor = (t_floor*)malloc(sizeof(t_floor));

	validate_taxmap(arg, &textmap);
}
