/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_player.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/04 10:21:15 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/11 09:56:17 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// static void	direction_2(t_root *data)
// {
// 	data->p.plane_x = 0;
// 	data->p.plane_y = 0.66;
// 	data->p.x_dir = 1;
// 	data->p.y_dir = 0;
// }

// was in two functions (norm), now with this trick is only 1

static void	give_direction(t_root *data, char ch_dir)
{
	// TODO
	const double dir[4][4] = {{0.66, 0, 0, -1}, {-0.66, 0, 0, 1},\
		{0, -0.66, -1, 0}, {0, 0.66, 1, 0}};
	const char dirs[4] = "NSWE";
	int i = 0;
	while (i < 4 && dirs[i] != ch_dir)
		i++;
	data->p.plane_x = dir[i][0];
	data->p.plane_y = dir[i][1];
	data->p.x_dir = dir[i][2];
	data->p.y_dir = dir[i][3];
		
	

	// if (ch_dir == 'N')
	// {
	// 	data->p.plane_x = 0.66;
	// 	data->p.plane_y = 0;
	// 	data->p.x_dir = 0;
	// 	data->p.y_dir = -1;
	// }
	// else if (ch_dir == 'S')
	// {
	// 	data->p.plane_x = -0.66;
	// 	data->p.plane_y = 0;
	// 	data->p.x_dir = 0;
	// 	data->p.y_dir = 1;
	// }
	// else if (ch_dir == 'W')
	// {
	// 	data->p.plane_x = 0;
	// 	data->p.plane_y = -0.66;
	// 	data->p.x_dir = -1;
	// 	data->p.y_dir = 0;
	// }
	// else if (ch_dir == 'E')
	// 	direction_2(data);
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
