/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 12:07:53 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/13 12:32:41 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	name_check(char *file)
{
	const int	name_len = ft_strlen(file) - 4;

	if (name_len <= 0 || (ft_strncmp(file + name_len, ".cub", 4) != 0))
	{
		error_p(ERR_MAP_NAME);
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_cube	data;
	
	if (argc != 2)
	{
		error_p(ERR_NO_ARG);
		return (1);
	}
	init_cube(&data);
	name_check(argv[1]);
	read_taxmap(argv[1], &data);
	if_valid_add(&data);
	fill_map(&data);
	map_check(&data);
	print_texmap(data.texmap); //to delete
	free_data(&data);
	return (0);
}
