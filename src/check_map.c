/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   check_map.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amysiv <amysiv@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/06 12:30:12 by mstencel		  #+#	#+#			 */
/*   Updated: 2025/01/10 14:54:18 by amysiv		   ###   ########.fr	   */
/*																			*/
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
bool	space_wall_check(t_cube *data, long y, long x)
{
	int		 i;
	long		new_y;
	long		new_x;
	const int   dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, \
		{1, -1}, {1, 0}, {1, 1}};
	long		len;
	i = 0;
	while (i < 8)
	{
		len = (long)ft_strlen(data->texmap->map[new_y]);
		new_y = y + dir[i][0];
		new_x = x + dir[i][1];
		if (new_x < 0 || new_x > len || new_y < 0 || new_y > data->cub_file->height
			|| !valid_char(data->texmap->map[new_y][new_x]))
			return (false);
		i++;
	}
	return (true);
}

void	player_found(t_cube *data, long y, long x, bool *position)
{
	if (*position == false)
	{
		data->p->x_pos = x;
		data->p->y_pos = y;
		*position = true;
		data->p->pos = data->texmap->map[y][x];
		data->texmap->map[y][x] = '0';
	}
	else
		error_bye_data(data, ERR_TOO_MANY_PLAYERS);
}

void	map_check(t_cube *data)
{
	long	x;
	long	y;
	bool	position;
	position = false;
	y = 0;
	while (y < data->cub_file->height)
	{
		x = 0;
		while (data->texmap->map[y][x])
		{
			if (!valid_char(data->texmap->map[y][x]) && data->texmap->map[y][x] != ' ')
				error_bye_data(data, ERR_GARBAGE_IN_THE_MAP);
			if (data->texmap->map[y][x] == 'N' || data->texmap->map[y][x] == 'S' ||
				data->texmap->map[y][x] == 'E' || data->texmap->map[y][x] == 'W')
				player_found(data, y, x, &position);
			if (data->texmap->map[y][x] == '0' && !space_wall_check(data, y, x))
				error_bye_data(data, ERR_OPEN_MAP);
			x++;
		}
		y++;
	}
	if (position == false)
		error_bye_data(data, ERR_PLAYER_MISSING);
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
