/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/23 14:44:43 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/24 13:32:04 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

//calculate the distance of the player to the first full point on the grid

//calculate the distance to the wall - 
//check each intersection using the angle & trigonometrical functions - angle 
//should be adjusted to < 90 degrees, depending on where it goes, so e.g. 
//angle between 270-360 -> angle = 360 - angle or angle = angle - 270; 
//between 180-270 -> angle = angle - 180 or angle = 270 - angle
//between 90 - 180 -> angle = angle - 90 or angle = 180 - angle
//between 0 - 90 -> angle = angle - 90 or angle = 90 - angle


void	find_offset(t_root *data)
{
	int	i;

	i = 1;
	while (i <= RAYS_NUMB)
	{
		if (data->p->most_l + data->p->abr * i >= 0 && data->p->most_l + data->p->abr * i <= 90)
		{
			data->p->x_offset = ceil(data->p->x_pos) * TW - data->p->x_pos * TW;
			data->p->y_offset = ceil(data->p->y_pos) * TH - data->p->y_pos * TH;
		}
		else if (data->p->most_l + data->p->abr * i >= 90 && data->p->most_l + data->p->abr * i  <= 180)
		{
			data->p->x_offset = data->p->x_pos * TH - floor(data->p->x_pos * TW);
			data->p->y_offset = ceil(data->p->y_pos) * TH - data->p->y_pos * TH;
		}
		else if (data->p->most_l + data->p->abr * i >= 180 && data->p->most_l + data->p->abr * i  <= 270)
		{
			data->p->x_offset = data->p->x_pos * TH - floor(data->p->x_pos * TW);
			data->p->y_offset = data->p->y_pos * TH - floor(data->p->y_pos * TH);
		}
		else if (data->p->most_l + data->p->abr * i >= 270 && data->p->most_l + data->p->abr * i  <= 360)
		{
			data->p->x_offset = ceil(data->p->x_pos) * TH - data->p->x_pos * TW;
			data->p->y_offset = data->p->y_pos * TH - floor(data->p->y_pos * TH);
		}
		i++;
	}
	printf("y = %f x = %f", data->p->y_pos, data->p->x_pos);
}