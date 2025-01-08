/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:30:12 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/08 10:06:38 by amysiv           ###   ########.fr       */
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
