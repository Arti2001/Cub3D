/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 12:30:08 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/28 07:57:22 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
