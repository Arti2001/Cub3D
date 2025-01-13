/* ************************************************************************** */
/*                                                                            */
<<<<<<< HEAD
/*                                                        :::      ::::::::   */
/*   parse_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:52:36 by amysiv            #+#    #+#             */
/*   Updated: 2025/01/11 17:24:21 by amysiv           ###   ########.fr       */
=======
/*                                                        ::::::::            */
/*   parse_texture_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 10:52:36 by amysiv        #+#    #+#                 */
/*   Updated: 2025/01/13 07:27:57 by mstencel      ########   odam.nl         */
>>>>>>> 80da9fa26fe5e2ba7784c67060630dd4a7bbc8e6
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"



char* skipspace(char* line)
{
	while (*line && *line == ' ')
	{
		line++;
	}
	return (line);
}

bool	is_full(t_texmap *texmap)
{
	if (	is_struct_full(texmap->ceiling, NULL) &&
			is_struct_full(NULL, texmap->floor) &&
			texmap->no_path != NULL && texmap->so_path != NULL &&
			texmap->ea_path != NULL && texmap->we_path != NULL)
			return (true);
	else
		return(false);
}


bool	is_struct_full(t_ceiling *ceiling, t_floor *floor)
{
	if (ceiling != NULL)
	{
		if (ceiling->r == -1 && ceiling->g == -1 && ceiling->b == -1)
		{
			return (false);
		}
	}
	if (floor != NULL)
	{
		if (floor->r == -1 && floor->g == -1 && floor->b == -1)
		{
			return (false);
		}
	}
	return (true);
}

int	are_digits(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(!ft_isdigit(str[i]))
		{
			return (0);
		}
			
		i++;
	}
	return (1);

}

int	first_digit(char *str)
{
	int	i;

	i = 0;

	while(str[i] == ' ' || str[i] == '\t')
	{
		i++;
	}
	if(ft_isdigit(str[i]))
		return (0);

	return (1);

}