/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 12:30:12 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/09 11:47:16 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/// @brief 
/// @param c 
/// @return 
bool	valid_char(char c)
{
	const char	check[] = "NSEW01";
	int			i;

	i = 0;
	while (check[i])
	{
		if (c == check[i])
			return (true);
		i++;
	}
	return (false);
}

/// @brief checks all the fields next to the 0 in question
/// @param t_map 
/// @param x 
/// @param y 
/// @return true if the map is correct and false if there is an issue
bool	space_wall_check(t_texmap *tmap, long y, long x)
{
	int			i;
	long		new_y;
	long		new_x;
	const int	dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, \
		{1, -1}, {1, 0}, {1, 1}};

	i = 0;
	while (i < 8)
	{
		new_y = y + dir[i][0];
		new_x = x + dir[i][1];
		if (new_x < 0 || new_x > (long)ft_strlen(tmap->map[new_y]) || new_y < 0
			|| new_y > tmap->map_height || !valid_char(tmap->map[new_y][new_x]))
			return (false);
		i++;
	}
	return (true);
}

void	player_found(t_texmap *tmap, long y, long x, bool *position)
{
	if (*position == false)
	{
		tmap->p.x_pos = x;
		tmap->p.y_pos = y;
		*position = true;
		tmap->p.pos = tmap->map[y][x];
		tmap->map[y][x] = '0';
	}
	else
		error_bye_texmap(tmap, ERR_TOO_MANY_PLAYERS);
}

void	map_check(t_texmap *tmap)
{
	long	x;
	long	y;
	bool	position;

	position = false;
	y = 0;
	while (y < tmap->map_height)
	{
		x = 0;
		while (tmap->map[y][x])
		{
			if (!valid_char(tmap->map[y][x]) && tmap->map[y][x] != ' ')
				error_bye_texmap(tmap, ERR_GARBAGE_IN_THE_MAP);
			if (tmap->map[y][x] == 'N' || tmap->map[y][x] == 'S' ||
				tmap->map[y][x] == 'E' || tmap->map[y][x] == 'W')
				player_found(tmap, y, x, &position);
			else if (tmap->map[y][x] == '0' && !space_wall_check(tmap, y, x))
				error_bye_texmap(tmap, ERR_OPEN_MAP);
			x++;
		}
		y++;
	}
	if (position == false)
		error_bye_texmap(tmap, ERR_PLAYER_MISSING);
}

void	name_check(char *file)
{
	const int	name_len = ft_strlen(file) - 4;

	if (name_len <= 0 || (ft_strncmp(file + name_len, ".cub", 4) != 0))
	{
		error_p(ERR_MAP_NAME);
		exit (EXIT_FAILURE);
	}
}
