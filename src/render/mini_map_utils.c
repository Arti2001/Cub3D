/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mini_map_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/18 09:22:55 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/18 09:56:12 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t	ft_my_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
