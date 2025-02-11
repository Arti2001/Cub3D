/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: amysiv <amysiv@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 14:38:20 by mstencel      #+#    #+#                 */
/*   Updated: 2025/02/11 08:09:16 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void	free_data_arr(t_root *data, char *str, char **arr)
{
	free_data(data);
	if (arr)
		ft_free_array(arr);
	error_p(str);
	exit(EXIT_FAILURE);
}

void	err_fd_data_bye(t_root *data, int fd, int flag)
{
	if (flag == 1)
		error_p(ERR_EMPTY_MAP);
	close(fd);
	free_data(data);
	exit(EXIT_FAILURE);
}

void	error_bye_data(t_root *data, char *str)
{
	free_data(data);
	error_p(str);
	exit(EXIT_FAILURE);
}

void	error_bye_mlx_data(t_root *data, char *str)
{
	free_mlx(data);
	free_data(data);
	error_p(str);
	exit(EXIT_FAILURE);
}