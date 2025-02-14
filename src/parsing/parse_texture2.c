/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_texture2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 10:49:30 by amysiv        #+#    #+#                 */
/*   Updated: 2025/02/14 11:34:19 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*new_mem(char *str, t_root *data)
{
	char	*new;

	new = NULL;
	if (!str)
		return (new);
	new = ft_strdup(str);
	if (!new)
		error_bye_data(data, "Failed to allocate memory\n");
	return (new);
}

void	check_val(char **val, t_root *data)
{
	if (!are_digits(val[1]) || !are_digits(val[2]) || !are_digits(val[3]))
	{
		free_data_arr(data, "Incorrect color val: Only digits allowed\n", val);
	}
	if (ft_strlen(val[1]) > 3 || ft_strlen(val[2]) > 3 || \
		ft_strlen(val[3]) > 3)
		free_data_arr(data, ERR_OUT_OF_RANGE_C, val);
}

void	ceiling_rgb(char *str, t_root *data)
{
	char	**c_arg;

	c_arg = splitbywhite(str, ',');
	if (c_arg == NULL)
		return ;
	check_val(c_arg, data);
	data->map.ceiling.r = ft_atoi(c_arg[1]);
	data->map.ceiling.g = ft_atoi(c_arg[2]);
	data->map.ceiling.b = ft_atoi(c_arg[3]);
	if (data->map.ceiling.r > 255 || \
		data->map.ceiling.g > 255 || \
		data->map.ceiling.b > 255)
		error_bye_data(data, ERR_OUT_OF_RANGE_C);
	ft_free_array(c_arg);
}

void	floor_rgb(char *str, t_root *data)
{
	char	**f_arg;

	f_arg = splitbywhite(str, ',');
	if (f_arg == NULL)
		return ;
	check_val(f_arg, data);
	data->map.floor.r = ft_atoi(f_arg[1]);
	data->map.floor.g = ft_atoi(f_arg[2]);
	data->map.floor.b = ft_atoi(f_arg[3]);
	if (data->map.floor.r > 255 || \
		data->map.floor.g > 255 || \
		data->map.floor.b > 255)
	{
		free_data_arr(data, ERR_OUT_OF_RANGE_F, f_arg);
	}
	ft_free_array(f_arg);
}

bool	is_full(t_map map)
{
	if (is_c_full(map.ceiling) && is_f_full(map.floor) && \
			map.no_path != NULL && map.so_path != NULL && \
			map.ea_path != NULL && map.we_path != NULL)
		return (true);
	else
		return (false);
}
