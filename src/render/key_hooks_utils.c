/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:36:53 by mstencel          #+#    #+#             */
/*   Updated: 2025/02/11 17:56:02 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	can_move(t_root *data, double new_x, double new_y)
{
	if ((data->map.map[(int)(new_y - HB)][(int)(new_x)] == '0')
		&& (data->map.map[(int)(new_y)][(int)(new_x - HB)] == '0')
		&& (data->map.map[(int)(new_y + HB)][(int)(new_x)] == '0')
		&& (data->map.map[(int)(new_y)][(int)(new_x + HB)] == '0')
		&& (data->map.map[(int)(new_y)][(int)(new_x)] == '0'))
		return (true);
	return (false);
}
