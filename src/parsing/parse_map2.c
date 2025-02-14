/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:03:03 by mstencel          #+#    #+#             */
/*   Updated: 2025/02/13 13:00:26 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*skip_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '\t' && line[i] != '\v' && line[i] != '\f'
			&& line[i] != '\r' && line[i] != ' ')
			return (line + i);
		i++;
	}
	return (line);
}

static t_maplist	*find_map_start(t_root *data)
{
	t_maplist	*current;
	char		*line;

	current = data->map_search;
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

static void	get_line(t_root *data, t_maplist *current, int y, int len)
{
	if (current->line[0] && valid_char(current->line[0]) == false)
	{
		error_bye_data(data, ERR_GARBAGE_AFTER_MAP);
	}
	if (current->line[len - 1] == '\n')
	{
		data->map.map[y] = malloc(sizeof(char) * (len));
		if (!data->map.map[y])
			error_bye_data(data, ERR_MALLOC_MAP_LINE);
		ft_strlcpy(data->map.map[y], current->line, len);
		if (data->map.lenght < len - 1)
			data->map.lenght = len - 1;
	}
	else
	{
		data->map.map[y] = ft_strdup(current->line);
		if (data->map.lenght < len)
			data->map.lenght = len;
	}
	if (!data->map.map[y])
		error_bye_data(data, ERR_MALLOC_MAP_LINE);
}

void	fill_map(t_root *data)
{
	int			y;
	int			size;
	t_maplist	*current;

	y = 0;
	current = find_map_start(data);
	if (current == NULL)
		error_bye_data(data, ERR_NO_MAP);
	size = data->map.height - current->height + 2;
	data->map.map = ft_calloc(size, sizeof(char **));
	if (!data->map.map)
		error_bye_data(data, ERR_MAP_MALLOC);
	while (current && (current->height <= data->map.height))
	{
		current->line_len = ft_strlen(current->line);
		if (current->line_len > 300)
			error_bye_data(data, ERR_TOO_LONG_LINE);
		get_line(data, current, y, current->line_len);
		y++;
		current = current->next;
	}
	data->map.height = y;
	data->map.map[y] = NULL;
}
