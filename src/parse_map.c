/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gosia <gosia@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 12:30:08 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/13 08:39:13 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	open_texmapfile(char *file, t_cube *data)
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

void	read_taxmap(char *file, t_cube *data)
{
	char		*file_content;
	int			fd;
	t_cublist	*current;

	fd = open_texmapfile(file, data);
	file_content = get_next_line(fd);
	if (file_content == NULL)
		err_fd_data_bye(data, fd, 1);
	data->cub_file = add_node(file_content, data);
	ft_free_string(&file_content);
	current = data->cub_file;
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
