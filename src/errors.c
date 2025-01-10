/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:38:20 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/10 14:55:28 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	error_bye()
// {
// 	free_all
// 	error_p(....)
// 	exit(EXIT_FAILURE);
// }

void    free_data(t_cube *data)
{
    if (data->p)
        free (data->p);
    if (data->cub_file)
        del_list(data->cub_file);
    if (data->texmap->map)
        ft_free_array(data->texmap->map);
    if (data->texmap->ceiling)
        free (data->texmap->ceiling);
    if (data->texmap->floor)
        free (data->texmap->floor);
    if (data->texmap->no_path)
        ft_free_string(&data->texmap->no_path);
    if (data->texmap->so_path)
        ft_free_string(&data->texmap->so_path);
    if (data->texmap->ea_path)
        ft_free_string(&data->texmap->ea_path);
    if (data->texmap->we_path)
        ft_free_string(&data->texmap->ea_path);
}

void	error_bye_data(t_cube *data, char *str)
{
	free_data(data);
	error_p(str);
	exit(EXIT_FAILURE);
}

void	error_p(char *str)
{
	char	*msg;

	msg = ft_strjoin("Error\n", str);
	if (!msg)
	{
		write(2, "Error\nError with ft_strjoin in error_p()\n", 42);
		return ;
	}
	write(2, msg, ft_strlen(msg));
	ft_free_string(&msg);
}
