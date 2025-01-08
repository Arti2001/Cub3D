/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 12:30:12 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/08 14:51:39 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	map_check(t_texmap *tmap, long i)
// {
// 	while ()
	/*
	check if the input of the map is correct:
	->the walls are around the map-"The map must be closed/surrounded by walls"
	--> 1 as the first and last place in the line
	--> 1
	->it consists of 0, 1, & one of: N or S or E or W
	->spaces are handled
	*/
// }

void	name_check(char *file)
{
	int	name_len;

	name_len = ft_strlen(file) - 4;
	if (name_len <= 0 || (ft_strncmp(file + name_len, ".cub", 4) != 0))
	{
		error_p(ERR_MAP_NAME);
		exit (EXIT_FAILURE);
	}
// 	else //to delete
// 		printf("format correct - working\n");
}
