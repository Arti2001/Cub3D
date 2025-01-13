/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:52:36 by amysiv            #+#    #+#             */
/*   Updated: 2025/01/13 16:57:06 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*skipspace(char *line)
{
	while (*line && *line == ' ')
	{
		line++;
	}
	return (line);
}

bool	is_full(t_texmap *texmap)
{
	if (is_cf_full(texmap->ceiling, NULL) && \
		is_cf_full(NULL, texmap->floor) && \
		texmap->no_path != NULL && texmap->so_path != NULL && \
		texmap->ea_path != NULL && texmap->we_path != NULL)
		return (true);
	else
		return (false);
}

bool	is_cf_full(t_ceiling *ceiling, t_floor *floor)
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
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
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
	while (str[i] == ' ' || str[i] == '\t')
	{
		i++;
	}
	if (ft_isdigit(str[i]))
		return (0);
	return (1);
}
