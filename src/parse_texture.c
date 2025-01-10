/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   parse_map.c	:+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: amysiv <amysiv@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2025/01/06 12:07:53 by mstencel	  #+#	#+#	 */
/*   Updated: 2025/01/09 10:51:17 by amysiv	   ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "../include/cub3d.h"

int	open_texmapfile(char *file)
{
	int	fd;
	
	if (!file)
	{
		return (1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

//int	are_alldigit(char *str)
//{
//	int	i;

//	i = 0;
//	while (ft_isdigit(str[i]) || str[i] == ,)
//	{
//		/* code */
//	}
	
//}


//	return 1;
//}

//int	comma_checker(char *str)
//{
//	int	i;
//	int	comma_count;

//	F 244       ,       1 ,  100;
//	comma_count = 0;
//	i = 0;
//	while(ft_isdigit(str[i]))
//		i++;

//}
void	tex_paths_valid(char **splited_line, t_cube *data)
{
	if (ft_strncmp(splited_line[0], "NO", 3) == 0)
	{
		if(data->texmap->no_path)
			error_bye_data(data, "NO: Is definied more then one time");
		data->texmap->no_path = splited_line[1];
	}
	else if(ft_strncmp(splited_line[0], "SO", 3) == 0)
	{
		if (data->texmap->so_path)
			error_bye_data(data, "SO: Is definied more then one time");
		data->texmap->so_path = splited_line[1];
	}
	else if (ft_strncmp(splited_line[0], "WE", 3) == 0)
	{
		if (data->texmap->we_path)
			error_bye_data(data, "WE: Is definied more then one time");
		data->texmap->we_path = splited_line[1];
	}
	else if (ft_strncmp(splited_line[0], "EA", 3) == 0)
	{
		if (data->texmap->ea_path)
			error_bye_data(data, "EA: Is definied more then one time");
		data->texmap->ea_path = splited_line[1];
	}
}

void	ceiling_floor_valid(char **splited_line, char *line, t_cube *data)
{
	if (ft_strncmp(splited_line[0], "C", 2) == 0)
	{
		ft_free_array(splited_line);
		if (data->texmap->ceiling)
		{
			if(!is_struct_full(data->texmap->ceiling, data->texmap->floor))
				error_bye_data(data, "C: does not have all values defined");
			else
				error_bye_data(data, "C: Is definied more then one time");
		}
		ceiling_rgb(line, data);
	}
	else if (ft_strncmp(splited_line[0], "F", 2) == 0)
	{
		ft_free_array(splited_line);
		if (!data->texmap->floor)
		{
			if(!is_struct_full(data->texmap->ceiling, data->texmap->floor))
				error_bye_data(data, "F: does not have all values defined");
			else
				error_bye_data(data, "F: Is definied more then one time");
		}
		floor_rgb(line, data);
	}
}

void	tex_validation(char *line, t_cube *data)
{
	char	**splited_line;
	
	splited_line = splitbywhite(line, '\0');
	if (splited_line [0] == NULL)
		return ;
	else if (splited_line[1] == NULL)
		error_bye_data(data, ERR_NO_PATH_FOUND);
	tex_paths_valid(splited_line, data);
	ceiling_floor_valid(splited_line, line, data);
}


void	if_valid_add(t_cube *data)
{
	t_cublist	*curr;

	curr = data->cub_file;
	while(curr != NULL && !is_full(data->texmap))
	{
		if(curr->line[0] != '\n')
		{
			tex_validation(curr->line, data);
		}
		curr = curr->next;
	}

	printf("%s\n",data->texmap->no_path);
	printf("%s\n",data->texmap->so_path);
	printf("%s\n",data->texmap->ea_path);
	printf("%s\n",data->texmap->we_path);
	printf("ceiling value r: %d\n",data->texmap->ceiling->r);
	printf("ceiling value g: %d\n",data->texmap->ceiling->g);
	printf("ceiling value b: %d\n",data->texmap->ceiling->b);
	printf("floor value r: %d\n",data->texmap->floor->r);
	printf("floor value g: %d\n",data->texmap->floor->g);
	printf("floor value b: %d\n",data->texmap->floor->b);

}



