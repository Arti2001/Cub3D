/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 08:08:09 by amysiv            #+#    #+#             */
/*   Updated: 2025/01/23 12:45:46 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"


static double	to_radiance(double angle)
{
	return (angle * (M_PI / 180.0));
}
static void	init_angle_data(t_root *data)
{
	data->p->most_l = to_radiance((ANG / -2) + data->p->pos);
	data->p->most_r = to_radiance((ANG / 2) + data->p->pos);
	data->p->abr = to_radiance((float)ANG / (RAYS_NUMB - 1));
}

void	handel_angel(t_root *data)
{
	init_angle_data(data);
}