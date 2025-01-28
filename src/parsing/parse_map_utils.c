/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 13:23:45 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/28 07:56:48 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_maplist	*add_node(char *line, t_root *data)
{
	t_maplist			*new_node;

	new_node = malloc(sizeof(t_maplist));
	if (!new_node)
	{
		error_p(ERR_MAP_MALLOC);
		return (NULL);
	}
	new_node->line = ft_strdup(line);
	if (!new_node->line)
	{
		error_p(ERR_MALLOC_LINE);
		return (NULL);
	}
	new_node->height = data->map.height + 1;
	data->map.height = new_node->height;
	if (new_node->height > 350)
	{
		error_p(ERR_TOO_MANY_LINES);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

			/*to delete*/
void	print_map(t_map *map)
{
	int	i;

	i = 0;
	printf("NO: %s\n", map->no_path);
	printf("SO: %s\n", map->so_path);
	printf("EA: %s\n", map->ea_path);
	printf("WE: %s\n", map->we_path);
	if (map->map)
	{
		while (map->map[i])
		{
			printf("%s\n", map->map[i]);
			i++;
		}
	}
	else
		printf("no map yet!\n");
}
