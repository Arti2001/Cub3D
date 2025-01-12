/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gosia <gosia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:03:03 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/12 11:59:16 by gosia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static ft_isspace(char c)
{
	return (c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == ' ');
}

static char	*skip_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (line[i]);
		i++;
	}
	return (line[i]);
}

static t_cublist	*find_map_start(t_cube *data)
{
	t_cublist	*current;
	char		*line;
	int			i;

	current = data->end_texture;
	while (current != NULL)
	{
		line = skip_space(current->line);
		if (line[0] && line[0] == '1')
			return (current);
		if (line[0] && line[0] != '\n')
			error_bye_data(data, ERR_GARBAGE_BEFORE_MAP);
		current = current->next;
	}
	return (NULL);
}

void	fill_map(t_cube *data)
{
	int	y;
	int	size;
	int	len;
	t_cublist	*current;

	y = 0;
	current = find_map_start(data);
	if (current == NULL)
		error_bye_data(data, ERR_NO_MAP);
	size = data->texmap->height - current->height + 1;
	data->texmap->map = malloc(sizeof(char **) * size);
	if (!data->texmap->map)
		error_bye_data(data, ERR_MAP_MALLOC);
	while (y < data->texmap->height)
	{
		len = ft_strlen(current->line);
		if (current->line[len] == '\n')
		{
			data->texmap->map[y] = malloc(sizeof(char) * len);
			ft_strlcpy(data->texmap->map[y], current->line, len - 1);
		}
		else
			data->texmap->map[y] = ft_strdup(current->line);
		if (!data->texmap->map[y])
			error_bye_data(data, ERR_MALLOC_MAP_LINE);
		y++;
		current = current->next;
	}
	data->texmap->map[y] = NULL;
}

// void	fill_list(char **line, int fd, t_cube *data)
// {
// 	t_cublist	*map;
// 	t_cublist	*current;

// 	map = add_node(*line);
// 	ft_free_string(line);
// 	if (!map)
// 		error_bye_data(tmap, ERR_NEW_NODE);
// 	current = map;
// 	while (1)
// 	{
// 		*line = get_next_line(fd);
// 		if (*line != NULL && ft_strchr(*line, '1') == NULL
// 			&& ft_strchr(*line, '0') == NULL)
// 			list_error(map, tmap, ERR_GARBAGE_AFTER_MAP);
// 		if (*line == NULL)
// 			break ;
// 		current->next = add_node(*line);
// 		ft_free_string(line);
// 		if (!current->next)
// 			list_error(map, tmap, ERR_NEW_NODE);
// 		current = current->next;
// 	}
	// fill_map(map, tmap);
// }

// void	get_cublist(int fd, t_texmap *texmap)
// {
// 	char	*line;

// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (ft_strchr(line, '1') != NULL)
// 		{
// 			fill_list(&line, fd, texmap);
// 			break ;
// 		}
// 	}
// 	map_check(texmap);
// 	printf("the map works!!!!!\n");
// }
