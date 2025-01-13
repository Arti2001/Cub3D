/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:38:20 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/13 16:48:49 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	err_fd_data_bye(t_cube *data, int fd, int flag)
{
	if (flag == 1)
		error_p(ERR_EMPTY_MAP);
	close(fd);
	free_data(data);
	exit(EXIT_FAILURE);
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

void	free_data_arr(t_cube *data, char *str, char **arr)
{
	free_data(data);
	if (arr)
		ft_free_array(arr);
	error_p(str);
	exit(EXIT_FAILURE);
}
