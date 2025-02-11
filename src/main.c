/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 12:07:53 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/11 08:01:00 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	name_check(char *file)
{
	const int	name_len = ft_strlen(file) - 4;

	if (name_len <= 0 || (ft_strncmp(file + name_len, ".cub", 4) != 0))
	{
		error_p(ERR_MAP_NAME);
		exit (EXIT_FAILURE);
	}
}

static void	file_parse(t_root *data, char *str)
{
	read_taxmap(str, data);
	if_valid_add(data);
	fill_map(data);
	map_check(data);
}

static void	init_root(t_root *data)
{
	ft_memset(data, 0, sizeof(t_root));
	data->map.floor.r = -1;
	data->map.floor.g = -1;
	data->map.floor.b = -1;
	data->map.ceiling.r = -1;
	data->map.ceiling.g = -1;
	data->map.ceiling.b = -1;
	data->map_list = NULL;
}

//to delete print_map
int	main(int argc, char **argv)
{
	t_root	data;

	if (argc != 2)
	{
		error_p(ERR_NO_ARG);
		return (1);
	}
	name_check(argv[1]);
	init_root(&data);
	file_parse(&data, argv[1]);
	run_mlx(&data);
	free_data(&data);
	return (0);
}
