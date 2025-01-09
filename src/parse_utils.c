/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:23:45 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/09 12:43:20 by amysiv           ###   ########.fr       */
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
	t_map			*new_node;
	const size_t	len = ft_strlen(line);

	new_node = malloc(sizeof(t_map));
	if (!new_node)
		return (NULL);
	if (ft_strchr(line, '\n') != NULL)
		new_node->line = ft_substr(line, 0, len - 1);
	else
		new_node->line = ft_strdup(line);
	if (!new_node->line)
		return (NULL);
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
	//printf("C: %s\n", texmap->ceiling);
	//printf("F: %s\n", texmap->floor);
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