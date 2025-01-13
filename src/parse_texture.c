/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_texture.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 15:21:28 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/13 08:17:35 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
int	tex_paths_valid(char **splited_line, t_cube *data)
{
	if (ft_strncmp(splited_line[0], "NO", 3) == 0)
	{
		if(data->texmap->no_path)
			error_bye_data(data, "NO: Is definied more then one time");
		return(data->texmap->no_path = splited_line[1], 1);
	}
	else if(ft_strncmp(splited_line[0], "SO", 3) == 0)
	{
		if (data->texmap->so_path)
			error_bye_data(data, "SO: Is definied more then one time");
		return(data->texmap->so_path = splited_line[1], 1);
	}
	else if (ft_strncmp(splited_line[0], "WE", 3) == 0)
	{
		if (data->texmap->we_path)
			error_bye_data(data, "WE: Is definied more then one time");
		return(data->texmap->we_path = splited_line[1], 1);
	}
	else if (ft_strncmp(splited_line[0], "EA", 3) == 0)
	{
		if (data->texmap->ea_path)
			error_bye_data(data, "EA: Is definied more then one time");
		return(data->texmap->ea_path = splited_line[1], 1);
	}
	return (0);
}

int	ceiling_floor_valid(char **splited_line, char *line, t_cube *data)
{
	if (ft_strncmp(splited_line[0], "C", 2) == 0)
	{
		ft_free_array(splited_line);
		if (data->texmap->ceiling && !is_struct_full(data->texmap->ceiling, NULL))
		{
			ceiling_rgb(line, data);
			return (1);
		}
		else
			error_bye_data(data, "C: Is definied more then one time");
	}
	else if (ft_strncmp(splited_line[0], "F", 2) == 0)
	{
		ft_free_array(splited_line);
		if (data->texmap->floor && !is_struct_full(NULL, data->texmap->floor))
		{
			floor_rgb(line, data);
			return (1);
		}
		else
			error_bye_data(data, "F: Is definied more then one time");
	}
	return (0);
}

void	tex_validation(char *line, t_cube *data)
{
	char	**splited_line;
	
	splited_line = splitbywhite(line, '\0');
	if (splited_line [0] == NULL)
		return ;
	if (tex_paths_valid(splited_line, data)) 
	{
		return;
}
	if (ceiling_floor_valid(splited_line, line, data))
	{
		return;
	}
	error_bye_data(data, "Invalid information detected in '.cub' file");
}

void	if_valid_add(t_cube *data)
{
	t_cublist	*curr;

	curr = data->cub_file;
	while(curr != NULL && !is_full(data->texmap))
	{
		if(curr->line[0] != '\n' && !is_full(data->texmap))
		{
			tex_validation(curr->line, data);
		}
		curr = curr->next;
	}
<<<<<<< HEAD

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
=======
	data->end_texture = curr;
	// printf("%s\n",data->texmap->no_path);
	// printf("%s\n",data->texmap->so_path);
	// printf("%s\n",data->texmap->ea_path);
	// printf("%s\n",data->texmap->we_path);
	// printf("ceiling value r: %d\n",data->texmap->ceiling->r);
	// printf("ceiling value g: %d\n",data->texmap->ceiling->g);
	// printf("ceiling value b: %d\n",data->texmap->ceiling->b);
	// printf("floor value r: %d\n",data->texmap->floor->r);
	// printf("floor value g: %d\n",data->texmap->floor->g);
	// printf("floor value b: %d\n",data->texmap->floor->b);
>>>>>>> 80da9fa26fe5e2ba7784c67060630dd4a7bbc8e6
}
