/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 13:23:45 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/11 09:32:21 by mstencel      ########   odam.nl         */
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
