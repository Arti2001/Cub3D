/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 12:07:53 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/09 11:58:03 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

	//TODO free all (in respective functions!)
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
