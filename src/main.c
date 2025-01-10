/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 12:07:53 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/10 12:17:07 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	init_data(t_cube *data)
{
	ft_memset(data->texmap, 0, sizeof(t_texmap));
	ft_memset(data->cub_file, 0, sizeof(t_cublist));
	ft_memset(data->p, 0, sizeof(t_player));
}

	//TODO free all (in respective functions!)
int	main(int argc, char **argv)
{
	t_cube	data;

	if (argc != 2)
	{
		error_p(ERR_NO_ARG);
		return (1);
	}
	init_data(&data);
	name_check(argv[1]);
	read_taxmap(argv[1], &data);
	fill_map(data);
	// pars_texmap(argv[1]);
	return (0);
}
