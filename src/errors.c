/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 14:38:20 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/08 10:10:49 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	error_bye()
// {
// 	free_all
// 	error_p(....)
// 	exit(EXIT_FAILURE);
// }


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
