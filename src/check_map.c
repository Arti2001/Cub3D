/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 12:30:12 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/06 14:54:35 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	name_check(char *name)
{
	int	name_len;

	name_len = ft_strlen(name) - 4;
	if (ft_strncmp(name + name_len, ".cub", 4) != 0)
	{
		error_p("Incorrect file extension. Use \".cub\" format");
		return (-1);
	}
	return (0);
}

int	map_check(char *file)
{
	if (name_check(file) == -1)
		return (-1);
	return (0);
}