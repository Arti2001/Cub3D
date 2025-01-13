/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gosia <gosia@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 13:23:45 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/13 08:40:28 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_cublist	*add_node(char *line, t_cube *data)
{
	t_cublist			*new_node;

	new_node = malloc(sizeof(t_cublist));
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
	new_node->height = data->texmap->height + 1;
	data->texmap->height = new_node->height;
	if (new_node->height > 350)
	{
		error_p(ERR_TOO_MANY_LINES);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

			/*to delete*/
void	print_texmap(t_texmap *texmap)
{
	int	i;

	i = 0;
	printf("NO: %s\n", texmap->no_path);
	printf("SO: %s\n", texmap->so_path);
	printf("EA: %s\n", texmap->ea_path);
	printf("WE: %s\n", texmap->we_path);
	if (texmap->map)
	{
		while (texmap->map[i])
		{
			printf("%s\n", texmap->map[i]);
			i++;
		}
	}
	else
		printf("no map yet!\n");
}
