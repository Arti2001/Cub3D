/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:07:53 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/10 14:55:28 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_ceiling *init_ceiling(void)
{
	t_ceiling *ceiling = malloc(sizeof(t_ceiling));
	if (!ceiling)
		return NULL;
	//ft_memset(&ceiling, 0, sizeof(t_ceiling));
	ceiling->r = -1;
	ceiling->g = -1;
	ceiling->b = -1;
	return (ceiling);
}


t_floor *init_floor(void)
{
	t_floor *floor = malloc(sizeof(t_floor));
	if (!floor)
		return NULL;
	//ft_memset(&floor, 0, sizeof(t_floor));
	floor->r = -1;
	floor->g = -1;
	floor->b = -1;
	return (floor);
}

t_texmap	*init_texmap(void)
{
	t_texmap	*texmap;

	texmap = malloc(sizeof(t_texmap));
	if (!texmap)
		return (NULL);
	ft_memset(texmap, 0, sizeof(t_texmap));
	texmap->ceiling = init_ceiling();
	texmap->floor = init_floor();
	texmap->map = NULL;
	return (texmap);
}
void	init_cube(t_cube *data)
{	
	ft_memset(data, 0, sizeof(t_cube));
	
	data->texmap = init_texmap();
	data->cub_file = NULL;
	data->p = NULL;
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
	// pars_texmap(argv[1]);
	return (0);
}
