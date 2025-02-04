/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 12:30:12 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/04 08:05:44 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	direction_2(t_root *data)
{
	data->p.plane_x = 0;
	data->p.plane_y = 0.66;
	data->p.x_dir = 1;
	data->p.y_dir = 0;
}

static void	give_direction(t_root *data, char ch_dir)
{
	if(ch_dir == 'N')
	{
		data->p.plane_x = 0.66;
		data->p.plane_y = 0;
		data->p.x_dir = 0;
		data->p.y_dir = -1;
	}
	else if(ch_dir == 'S')
	{
		data->p.plane_x = -0.66;
		data->p.plane_y = 0;
		data->p.x_dir = 0;
		data->p.y_dir = 1;
	}
	else if(ch_dir == 'W')
	{
		data->p.plane_x = 0;
		data->p.plane_y = -0.66;
		data->p.x_dir = -1;
		data->p.y_dir = 0;
	}
	else if(ch_dir == 'E')
		direction_2(data);
}

bool	valid_char(char c)
{
	const char	check[] = "NSEW01";
	int			i;

	i = 0;
	while (check[i])
	{
		if (c == check[i])
			return (true);
		i++;
	}
	return (false);
}

/// @brief checks all the fields next to the 0 in question
/// @return true if the map is correct and false if there is an issue
bool	space_wall_check(t_root *data, int y, int x)
{
	int			i;
	int			new_y;
	int			new_x;
	int			len;
	const int	dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, \
		{1, -1}, {1, 0}, {1, 1}};

	i = 0;
	while (i < 8)
	{
		new_y = y + dir[i][0];
		new_x = x + dir[i][1];
		len = ft_strlen(data->map.map[new_y]);
		if (new_x < 0 || new_x > len || new_y < 0
			|| new_y > data->map.height
			|| !valid_char(data->map.map[new_y][new_x]))
			return (false);
		i++;
	}
	return (true);
}

void	player_found(t_root *data, long y, long x, bool *position)
{
	if (*position == false)
	{
		data->p.x_pos = x + 0.5;
		data->p.y_pos = y + 0.5;
		*position = true;
		give_direction(data, data->map.map[y][x]);
		data->map.map[y][x] = '0';
	}
	else
		error_bye_data(data, ERR_TOO_MANY_PLAYERS);
}

static int	player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	map_check(t_root *data)
{
	int		x;
	int		y;
	bool	position;

	position = false;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (!valid_char(data->map.map[y][x])
				&& data->map.map[y][x] != ' ')
				error_bye_data(data, ERR_GARBAGE_IN_THE_MAP);
			if (player_char(data->map.map[y][x]))
				player_found(data, y, x, &position);
			if (data->map.map[y][x] == '0'
				&& !space_wall_check(data, y, x))
				error_bye_data(data, ERR_OPEN_MAP);
			x++;
		}
		y++;
	}
	if (position == false)
		error_bye_data(data, ERR_PLAYER_MISSING);
}
