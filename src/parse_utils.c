/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 13:23:45 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/08 14:51:05 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	list_error(t_map *map_list, t_texmap *texmap, char *str)
{
	del_list(map_list);
	error_bye_texmap(texmap, str);
}

void	del_list(t_map *map)
{
	t_map	*current;
	
	while (map->next != NULL)
	{
		ft_free_string(&map->line);
		current = map->next;
		free(map);
		map = current;
	}
	free(map);
}

t_map	*add_node(char *line)
{
	t_map	*new_node;

	new_node = malloc(sizeof(t_map));
	if (!new_node)
		return (NULL);
	new_node->line = ft_strdup(line);
	// printf("dupped: %s\n", new_node->line);
	new_node->next = NULL;
	return (new_node);
}

long	node_count(t_map *map)
{
	t_map	*current;
	long	i;
	
	current = map;
	i = 0;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	// printf("i in the node_count: %ld\n", i);
	return (i);
}