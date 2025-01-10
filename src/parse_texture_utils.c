/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:52:36 by amysiv            #+#    #+#             */
/*   Updated: 2025/01/10 14:31:05 by amysiv           ###   ########.fr       */
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
	if (!is_struct_full(texmap->ceiling, texmap->floor))
		return (false);
	else if ( texmap->ceiling != NULL && texmap->floor != NULL &&
			texmap->no_path != NULL && texmap->so_path != NULL &&
			texmap->ea_path != NULL && texmap->we_path != NULL)
			return (false);
		else
			return(true);
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