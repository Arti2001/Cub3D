/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:23:45 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/10 14:55:28 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	list_error(t_cublist *map_list, t_cube *data, char *str)
{
	del_list(map_list);
	error_bye_data(data, str);
}

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
	//const size_t	len = ft_strlen(line);

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
void	read_taxmap(char *file, t_cube *data)
{
	char*       file_content;
	int         fd;
	t_cublist   *current;
	
	fd = open_texmapfile(file);
	file_content = get_next_line(fd);
	if (file_content == NULL)
		return ; // to be changed!
		//free data, close fd & exit
	data->cub_file = add_node(file_content);
	current = data->cub_file;
	current->height = 0;
	while (1)
	{
		ft_free_string(&file_content);
		file_content = get_next_line(fd);
		if (file_content == NULL)
			break ;
		current->next = add_node(file_content);
		if (current->next == NULL)
			break ; //to be changed!
			//free data, close fd & exit
		current = current->next;
	}
	close(fd);
}