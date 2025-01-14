/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 12:30:12 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/14 07:51:49 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/// @brief 
/// @param c 
/// @param flag if flag is 0, it will check all the values, 
//			if 1 only the player possible position
/// @return 
static bool	valid_char(char c, int flag)
{
	const char	check[] = "NSEW01";
	const char	player_check[] = "NSEW";
	int			i;

	i = 0;
	if (flag == 0)
	{
		while (check[i])
		{
			if (c == check[i])
				return (true);
			i++;
		}
	}
	else if (flag == 1)
	{
		while (player_check[i])
		{
			if (c == player_check[i])
				return (true);
			i++;
		}
	}
	return (false);
}

/// @brief checks all the fields next to the 0 in question
/// @return true if the map is correct and false if there is an issue
static bool	space_wall_check(t_cube *data, int y, int x)
{
	int			i;
	int			new_y;
	int			new_x;
	int			len;
	const int	dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, \
		{1, -1}, {1, 0}, {1, 1}};

	i = 0;
	len = ft_strlen(data->texmap->map[y]);
	while (i < 8)
	{
		new_y = y + dir[i][0];
		new_x = x + dir[i][1];
		if (new_x < 0 || new_x > len || new_y < 0
			|| new_y >= data->texmap->height
			|| !valid_char(data->texmap->map[new_y][new_x], 0))
			return (false);
		i++;
	}
	return (true);
}

static void	player_found(t_cube *data, long y, long x, bool *position)
{
	if (*position == false)
	{
		data->p->x_pos = x;
		data->p->y_pos = y;
		*position = true;
		data->p->pos = data->texmap->map[y][x];
		data->texmap->map[y][x] = '0';
	}
	else
		error_bye_data(data, ERR_TOO_MANY_PLAYERS);
}

void	map_check(t_cube *data)
{
	int		x;
	int		y;
	bool	position;

	position = false;
	y = 0;
	while (y < data->texmap->height)
	{
		x = 0;
		while (data->texmap->map[y][x])
		{
			if (!valid_char(data->texmap->map[y][x], 0)
				&& data->texmap->map[y][x] != ' ')
				error_bye_data(data, ERR_GARBAGE_IN_THE_MAP);
			if (valid_char(data->texmap->map[y][x], 1))
				player_found(data, y, x, &position);
			if (data->texmap->map[y][x] == '0'
				&& !space_wall_check(data, y, x))
				error_bye_data(data, ERR_OPEN_MAP);
			x++;
		}
		y++;
	}
	if (position == false)
		error_bye_data(data, ERR_PLAYER_MISSING);
}
