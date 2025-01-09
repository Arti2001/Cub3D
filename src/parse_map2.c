/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 11:03:03 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/09 11:57:03 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	fill_map(t_map *map_list, t_texmap *tmap)
{
	long	y;
	t_map	*current;

	tmap->map_height = node_count(map_list);
	y = 0;
	current = map_list;
	tmap->map = malloc(sizeof(char **) * tmap->map_height + 1);
	if (!tmap->map)
		list_error(map_list, tmap, ERR_MAP_MALLOC);
	while (y < tmap->map_height)
	{
		tmap->map[y] = ft_strdup(current->line);
		if (!tmap->map[y])
			list_error(map_list, tmap, ERR_LINE_DUP);
		y++;
		current = current->next;
	}
	tmap->map[y] = NULL;
	del_list(map_list);
}

void	fill_list(char **line, int fd, t_texmap *tmap)
{
	t_map	*map;
	t_map	*current;

	map = add_node(*line);
	ft_free_string(line);
	if (!map)
		error_bye_texmap(tmap, ERR_NEW_NODE);
	current = map;
	while (1)
	{
		*line = get_next_line(fd);
		if (*line != NULL && ft_strchr(*line, '1') == NULL
			&& ft_strchr(*line, '0') == NULL)
			list_error(map, tmap, ERR_GARBAGE_AFTER_MAP);
		if (*line == NULL)
			break ;
		current->next = add_node(*line);
		ft_free_string(line);
		if (!current->next)
			list_error(map, tmap, ERR_NEW_NODE);
		current = current->next;
	}
	fill_map(map, tmap);
}

void	get_map(int fd, t_texmap *texmap)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (ft_strchr(line, '1') != NULL)
		{
			fill_list(&line, fd, texmap);
			break ;
		}
	}
	map_check(texmap);
	printf("the map works!!!!!\n");
}
