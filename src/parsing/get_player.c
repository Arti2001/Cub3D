/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:21:15 by mstencel          #+#    #+#             */
/*   Updated: 2025/02/11 15:59:17 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_directions(double dir[4][4])
{
	dir[0][0] = 0.66;
	dir[0][1] = 0;
	dir[0][2] = 0;
	dir[0][3] = -1;
	dir[1][0] = -0.66;
	dir[1][1] = 0;
	dir[1][2] = 0;
	dir[1][3] = 1;
	dir[2][0] = 0;
	dir[2][1] = -0.66;
	dir[2][2] = -1;
	dir[2][3] = 0;
	dir[3][0] = 0;
	dir[3][1] = 0.66;
	dir[3][2] = 1;
	dir[3][3] = 0;
}

static void	give_direction(t_root *data, char ch_dir)
{
	char		dirs[4];
	double		dir[4][4];
	int			i;

	init_directions(dir);
	dirs[0] = 'N';
	dirs[1] = 'S';
	dirs[2] = 'W';
	dirs[3] = 'E';
	i = 0;
	while (i < 4 && dirs[i] != ch_dir)
		i++;
	data->p.plane_x = dir[i][0];
	data->p.plane_y = dir[i][1];
	data->p.x_dir = dir[i][2];
	data->p.y_dir = dir[i][3];
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
