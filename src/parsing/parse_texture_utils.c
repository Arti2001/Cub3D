/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_texture_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 10:52:36 by amysiv        #+#    #+#                 */
/*   Updated: 2025/01/30 07:46:53 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char* skipspace(char* line)
{
	while (*line && *line == ' ')
	{
		line++;
	}
	return (line);
}

bool	is_f_full(t_floor floor)
{
	if (floor.r == -1 && floor.g == -1 && floor.b == -1)
	{
		return (false);
	}
	return (true);
}

bool	is_c_full(t_ceiling ceiling)
{
	if (ceiling.r == -1 && ceiling.g == -1 && ceiling.b == -1)
	{
		return (false);
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
