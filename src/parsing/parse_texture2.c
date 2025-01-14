/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:49:30 by amysiv            #+#    #+#             */
/*   Updated: 2025/01/14 12:27:42 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/cub3d.h"


void	ceiling_rgb(char* str, t_cube *data)
{
	char**	c_arg;
	
	c_arg = splitbywhite(str, ',');
	if (c_arg == NULL)
		return ;
	if (!c_arg[1] || !c_arg[2] || !c_arg[3])
		error_bye_data(data, ERR_TO_FEW_PARAM_C);
	if (c_arg[4] != NULL)
		error_bye_data(data, ERR_TO_MANY_PARAM_C);
	if (!are_digits(c_arg[1]) || !are_digits(c_arg[2]) || !are_digits(c_arg[3]))
		error_bye_data(data, "Incorrect color value: Only digits allowed");
	if (ft_strlen(c_arg[1]) > 3 || ft_strlen(c_arg[2]) > 3 || ft_strlen(c_arg[3]) > 3)
		error_bye_data(data, ERR_OUT_OF_RANGE_C);
	data->texmap->ceiling->r = ft_atoi(c_arg[1]);
	data->texmap->ceiling->g = ft_atoi(c_arg[2]);
	data->texmap->ceiling->b = ft_atoi(c_arg[3]);
	if (data->texmap->ceiling->r > 255 ||
		data->texmap->ceiling->g > 255 ||
		data->texmap->ceiling->b > 255)
	{
		error_bye_data(data, ERR_OUT_OF_RANGE_C);
	}
}

void	floor_rgb(char* str, t_cube *data)
{
	char**	f_arg;

	f_arg = splitbywhite(str, ',');
	if (f_arg == NULL)
		return ;
	if (!f_arg[1] || !f_arg[2] || !f_arg[3])
		error_bye_data(data, ERR_TO_FEW_PARAM_F);
	if (f_arg[4] != NULL)
		error_bye_data(data, ERR_TO_MANY_PARAM_C);
	if (!are_digits(f_arg[1]) || !are_digits(f_arg[2]) || !are_digits(f_arg[3]))
		error_bye_data(data, "Incorrect color value: Only digits allowed");
	if (ft_strlen(f_arg[1]) > 3 || ft_strlen(f_arg[2]) > 3 || ft_strlen(f_arg[3]) > 3)
		error_bye_data(data, ERR_OUT_OF_RANGE_F);
	data->texmap->floor->r = ft_atoi(f_arg[1]);
	data->texmap->floor->g = ft_atoi(f_arg[2]);
	data->texmap->floor->b = ft_atoi(f_arg[3]);
	if (data->texmap->floor->r > 255 ||
		data->texmap->floor->g > 255 ||
		data->texmap->floor->b > 255)
	{
		error_bye_data(data, ERR_OUT_OF_RANGE_F);
	}
}