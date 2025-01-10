/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 11:03:03 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/10 15:20:08 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	fill_map(t_cublist *map_list, t_cube *data)
{
	int	y;
	t_cublist	*current;

	y = 0;
	data->texmap->height = node_count(map_list);
	current = map_list;
	data->texmap->map = malloc(sizeof(char **) * data->texmap->height + 1);
	if (!data->texmap->map)
		//update the error handling
		list_error(map_list, data, ERR_MAP_MALLOC);
	while (y < data->texmap->height)
	{
		data->texmap->map[y] = ft_strdup(current->line);
		if (!data->texmap->map[y])
			list_error(map_list, data, ERR_LINE_DUP);
		y++;
		current = current->next;
	}
	data->texmap->map[y] = NULL;
	del_list(map_list);
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
