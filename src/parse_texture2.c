/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:49:30 by amysiv            #+#    #+#             */
/*   Updated: 2025/01/13 17:02:18 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ceiling_rgb(char *str, t_cube *data)
{
	char	**arg;

	arg = NULL;
	if (comma_checker(str))
		arg = splitbywhite(str, ',');
	else
		free_data_arr(data, ERR_COMMA, arg);
	if (arg == NULL)
		return ;
	if (!arg[1] || !arg[2] || !arg[3])
		free_data_arr(data, ERR_TO_FEW_PARAM_C, arg);
	if (arg[4] != NULL)
		free_data_arr(data, ERR_TO_MANY_PARAM_C, arg);
	if (!are_digits(arg[1]) || !are_digits(arg[2]) || !are_digits(arg[3]))
		free_data_arr(data, ERR_COLOR_DIGIT, arg);
	if (ft_strlen(arg[1]) > 3 || ft_strlen(arg[2]) > 3 || ft_strlen(arg[3]) > 3)
		free_data_arr(data, ERR_OUT_OF_RANGE_C, arg);
	data->texmap->ceiling->r = ft_atoi(arg[1]);
	data->texmap->ceiling->g = ft_atoi(arg[2]);
	data->texmap->ceiling->b = ft_atoi(arg[3]);
	if (data->texmap->ceiling->r > 255 || \
		data->texmap->ceiling->g > 255 || \
		data->texmap->ceiling->b > 255)
		free_data_arr(data, ERR_OUT_OF_RANGE_C, arg);
	ft_free_array(arg);
}

void	floor_rgb(char *str, t_cube *data)
{
	char	**arg;

	arg = NULL;
	if (comma_checker(str))
		arg = splitbywhite(str, ',');
	else
		free_data_arr(data, ERR_COMMA, arg);
	if (arg == NULL)
		return ;
	if (!arg[1] || !arg[2] || !arg[3])
		free_data_arr(data, ERR_TO_FEW_PARAM_F, arg);
	if (arg[4] != NULL)
		free_data_arr(data, ERR_TO_MANY_PARAM_C, arg);
	if (!are_digits(arg[1]) || !are_digits(arg[2]) || !are_digits(arg[3]))
		free_data_arr(data, ERR_COLOR_DIGIT, arg);
	if (ft_strlen(arg[1]) > 3 || ft_strlen(arg[2]) > 3 || ft_strlen(arg[3]) > 3)
		free_data_arr(data, ERR_OUT_OF_RANGE_F, arg);
	data->texmap->floor->r = ft_atoi(arg[1]);
	data->texmap->floor->g = ft_atoi(arg[2]);
	data->texmap->floor->b = ft_atoi(arg[3]);
	if (data->texmap->floor->r > 255 || \
		data->texmap->floor->g > 255 || \
		data->texmap->floor->b > 255)
		free_data_arr(data, ERR_OUT_OF_RANGE_F, arg);
	ft_free_array(arg);
}
