/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 12:30:08 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/10 15:25:41 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	open_texmapfile(char *file)
{
	int	fd;
	
	if (!file)
	{
		return (1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

//TODO -> add error msg & exit if no file_content?
void	read_taxmap(char *file, t_cube *data)
{
	char*		file_content;
	int			fd;
	t_cublist	*current;
	
	fd = open_texmapfile(file);
	file_content = get_next_line(fd);
	if (file_content == NULL)
		return ; // to be changed!
		//free data, close fd & exit
	data->cub_file = add_node(file_content);
	current = data->cub_file;
	data->cub_file->height = 0;
	while (1)
	{
		ft_free_string(&file_content);
		file_content = get_next_line(fd);
		if (file_content == NULL)
			break ;
		current->next = add_node(file_content);
		if (current->next != NULL)
			return ; //to be changed!
			//free data, close fd & exit
		current = current->next;
	}
	close(fd);
}
