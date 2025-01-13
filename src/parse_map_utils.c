/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gosia <gosia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:23:45 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/12 11:10:13 by gosia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	del_list(t_cublist *map)
{
	t_cublist	*current;

	while (map->next != NULL)
	{
		ft_free_string(&map->line);
		current = map->next;
		free(map);
		map = current;
	}
	free(map);
}

t_cublist	*add_node(char *line)
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
	new_node->height++;
	if (new_node->height > 350)
	{
		error_p(ERR_TOO_MANY_LINES);
		return (NULL);
	}
	// printf("line: \"%s\"\n", new_node->line);
	// printf("height: %d\n", new_node->height);
	new_node->next = NULL;
	return (new_node);
}

long	node_count(t_cublist *map)
{
	t_cublist	*current;
	long	i;

	current = map;
	i = 0;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

			/*to delete*/
void	print_texmap(t_texmap *texmap)
{
	int	i = 0;
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