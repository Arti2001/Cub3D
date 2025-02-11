/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:21:28 by mstencel          #+#    #+#             */
/*   Updated: 2025/02/11 15:43:21 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	comma_checker(char *str)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma_count++;
		i++;
	}
	if (comma_count == 2)
		return (true);
	return (false);
}

int	tex_paths_valid(char **split, t_root *data)
{
	if (ft_strncmp(split[0], "NO", 3) == 0)
	{
		if (data->map.no_path)
			error_bye_data(data, "NO: Is definied more then one time");
		return (data->map.no_path = new_mem(split[1], data), 1);
	}
	else if (ft_strncmp(split[0], "SO", 3) == 0)
	{
		if (data->map.so_path)
			error_bye_data(data, "SO: Is definied more then one time");
		return (data->map.so_path = new_mem(split[1], data), 1);
	}
	else if (ft_strncmp(split[0], "WE", 3) == 0)
	{
		if (data->map.we_path)
			error_bye_data(data, "WE: Is definied more then one time");
		return (data->map.we_path = new_mem(split[1], data), 1);
	}
	else if (ft_strncmp(split[0], "EA", 3) == 0)
	{
		if (data->map.ea_path)
			error_bye_data(data, "EA: Is definied more then one time");
		return (data->map.ea_path = new_mem(split[1], data), 1);
	}
	return (0);
}

int	ceiling_floor_valid(char **split_line, char *line, t_root *data)
{
	if (ft_strncmp(split_line[0], "C", 2) == 0)
	{
		if (!is_c_full(data->map.ceiling))
		{
			ceiling_rgb(line, data);
			return (1);
		}
		else
			error_bye_data(data, "C: Is definied more then one time");
	}
	else if (ft_strncmp(split_line[0], "F", 2) == 0)
	{
		if (!is_f_full(data->map.floor))
		{
			floor_rgb(line, data);
			return (1);
		}
		else
			error_bye_data(data, "F: Is definied more then one time");
	}
	return (0);
}

void	tex_validation(char *line, t_root *data)
{
	char	**split_line;

	split_line = splitbywhite(line, '\0');
	if (!split_line || split_line[0] == NULL)
	{
		free_data_arr(data, "Split failed", split_line);
	}
	if (tex_paths_valid(split_line, data))
	{
		ft_free_array(split_line);
		return ;
	}
	if (ceiling_floor_valid(split_line, line, data))
	{
		ft_free_array(split_line);
		return ;
	}
	free_data_arr(data, "Map is no valid!", split_line);
}

void	if_valid_add(t_root *data)
{
	t_maplist	*curr;

	curr = data->map_list;
	while (curr != NULL && !is_full(data->map))
	{
		if (curr->line[0] != '\n')
		{
			tex_validation(curr->line, data);
		}
		curr = curr->next;
	}
	data->map_search = curr;
}
