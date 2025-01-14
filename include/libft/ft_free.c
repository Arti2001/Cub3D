/* ************************************************************************** */
/*                                                                            */
<<<<<<< HEAD
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:21:27 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/13 14:53:19 by amysiv           ###   ########.fr       */
=======
/*                                                        ::::::::            */
/*   ft_free.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 11:21:27 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/14 07:50:18 by mstencel      ########   odam.nl         */
>>>>>>> c54d1e5f8285f0b9b5a678bba22d00f69b65a43b
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **str)
{
	int	i;

	i = 0;
	if (*str)
	{
		while (str[i])
		{
			free(str[i]);
			str[i] = NULL;
			i++;
		}
	}
	if (str)
		free(str);
	str = NULL;
}

void	ft_free_string(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

void	ft_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
