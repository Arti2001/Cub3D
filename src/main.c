/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:07:53 by mstencel          #+#    #+#             */
/*   Updated: 2025/01/08 10:20:25 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		error_p(ERR_NO_ARG);
		return (1);
	}
	name_check(argv[1]);
	pars_texmap(argv[1]);
	return (0);
}