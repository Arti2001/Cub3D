/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gosia <gosia@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/08 11:03:03 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/14 10:32:22 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*skip_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '\t' && line[i] != '\v' && line[i] != '\f' &&
			line[i] != '\r' && line[i] != ' ')
			return (line + i);
		i++;
	}
	return (line);
}

static t_cublist	*find_map_start(t_cube *data)
{
	t_cublist	*current;
	char		*line;

	current = data->end_texture;
	while (current != NULL)
	{
		line = skip_space(current->line);
		if (line[0] && line[0] == '1')
			return (current);
		if (line[0] && line[0] != '\n')
			error_bye_data(data, ERR_GARBAGE_BEFORE_MAP);
		current = current->next;
	}
	return (NULL);
}

static bool	valid_char(char c)
{
	const char	check[] = "NSWE01 ";
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

static void	get_line(t_cube *data, t_cublist *current, int y, int len)
{
	if (current->line[0] && valid_char(current->line[0]) == false)
	{
		error_bye_data(data, ERR_GARBAGE_AFTER_MAP);
	}
	if (current->line[len - 1] == '\n')
	{
		data->texmap->map[y] = malloc(sizeof(char) * len);
		ft_strlcpy(data->texmap->map[y], current->line, len);
	}
	else
		data->texmap->map[y] = ft_strdup(current->line);
	if (!data->texmap->map[y])
		error_bye_data(data, ERR_MALLOC_MAP_LINE);
}

void	fill_map(t_cube *data)
{
	int			y;
	int			size;
	int			len;
	t_cublist	*current;

	y = 0;
	current = find_map_start(data);
	if (current == NULL)
		error_bye_data(data, ERR_NO_MAP);
	size = data->texmap->height - current->height + 2;
	data->texmap->map = ft_calloc(size, sizeof(char **));
	if (!data->texmap->map)
		error_bye_data(data, ERR_MAP_MALLOC);
	while (current && (current->height <= data->texmap->height))
	{
		len = ft_strlen(current->line);
		if (len > 300)
			error_bye_data(data, ERR_TOO_LONG_LINE);
		get_line(data, current, y, len);
		y++;
		current = current->next;
	}
	data->texmap->height = y;
	data->texmap->map[y] = NULL;
}
