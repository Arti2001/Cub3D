/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 11:03:03 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/08 14:51:59 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	fill_map(t_map *map_list, t_texmap *tmap)
{
	long	y;
	long	i;
	t_map	*current;
	
	i = node_count(map_list);
	// map_check(tmap, i);
	y = 0;
	current = map_list;
	tmap->map = malloc(sizeof(char**) * i + 1);
	if (!tmap->map)
		list_error(map_list, tmap, ERR_MAP_MALLOC);
	while (y < i)
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
	int		i;
	
	i = 1;
	map = add_node(*line);
	ft_free_string(line);
	if (!map)
		error_bye_texmap(tmap, ERR_NEW_NODE);
	current = map;
	while (1)
	{
		*line = get_next_line(fd);
		if (*line == NULL)
			break ;
		current->next = add_node(*line);
		ft_free_string(line);
		if (!current->next)
			list_error(map, tmap, ERR_NEW_NODE);
		current = current->next;
		i++;
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
	// printf("getting the map from %d\n", fd);
}
