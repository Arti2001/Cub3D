/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   angle_calc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 08:08:09 by amysiv        #+#    #+#                 */
/*   Updated: 2025/01/28 08:14:54 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"


double	to_radiance(double angle)
{
	return (angle * (M_PI / 180.0));
}
static void	init_angle_data(t_root *data)
{
	data->p.most_l = (FOV / -2) + data->p.pos;
	// data->p.most_l = to_radiance((FOV / -2) + data->p.pos);
	printf("the left side: %f\n", data->p.most_l);
	data->p.most_r = (FOV / 2) + data->p.pos;
	// data->p.most_r = to_radiance((FOV / 2) + data->p.pos);
	printf("the right side: %f\n", data->p.most_r);
	// data->p.abr = to_radiance((float)FOV / (RAYS_NUMB - 1));
	data->p.abr = (float)FOV / (RAYS_NUMB - 1);
	// printf("and this? %f\n", data->p.most_r);
}

void	handel_angel(t_root *data)
{
	init_angle_data(data);
}