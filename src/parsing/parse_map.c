/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 12:30:08 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/13 08:08:47 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_maplist	*add_node(char *line, t_root *data)
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

static int	open_mapfile(char *file, t_root *data)
{
	int	fd;

	if (!file)
	{
		error_bye_data(data, ERR_NO_MAP);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		free_data(data);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	read_taxmap(char *file, t_root *data)
{
	char		*file_content;
	int			fd;
	t_maplist	*current;

	fd = open_mapfile(file, data);
	file_content = get_next_line(fd);
	if (file_content == NULL)
		err_fd_data_bye(data, fd, 1);
	data->map_list = add_node(file_content, data);
	if (data->map_list == NULL)
		err_fd_data_bye(data, fd, 1);
	ft_free_string(&file_content);
	current = data->map_list;
	while (1)
	{
		file_content = get_next_line(fd);
		if (file_content == NULL)
			break ;
		current->next = add_node(file_content, data);
		ft_free_string(&file_content);
		if (current->next == NULL)
			err_fd_data_bye(data, fd, 0);
		current = current->next;
	}
	close(fd);
}
