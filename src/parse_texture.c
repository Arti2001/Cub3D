/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_texture.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 15:21:28 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/10 15:21:35 by mstencel      ########   odam.nl         */
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

bool	is_struct_full(t_ceiling *ceiling, t_floor *floor)
{
	if (ceiling!= NULL)
	{
		if (ceiling->r == -1 || ceiling->g == -1 || ceiling->b == -1)
		{
			return (false);
		}
	}
	if (floor != NULL)
	{
		if (floor->r == -1 || floor->g == -1 || floor->b == -1)
		{
			return (false);
		}
	}
	return (true);
}

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




void	valid_textures(char *line, t_cube *data)
{
	char	**splited_line;
	
	splited_line = splitbywhite(line, '\0');
	if (splited_line [0] == NULL)
		return ;
	else if (splited_line[1] == NULL)
		error_bye_data(data, ERR_NO_PATH_FOUND);
	//else if (splited_line[2] != NULL)
	//	error_bye_data(data, "Invalid amount of texture's paths values");
	else if (ft_strncmp(splited_line[0], "NO", 3) == 0 && !data->texmap->no_path)
		data->texmap->no_path = splited_line[1];
	else if(ft_strncmp(splited_line[0], "SO", 3) == 0 && !data->texmap->so_path)
		data->texmap->so_path = splited_line[1];
	else if (ft_strncmp(splited_line[0], "WE", 3) == 0 && !data->texmap->we_path)
		data->texmap->we_path = splited_line[1];
	else if (ft_strncmp(splited_line[0], "EA", 3) == 0 && !data->texmap->ea_path)
		data->texmap->ea_path = splited_line[1];
	else if (ft_strncmp(splited_line[0], "C", 2) == 0 && data->texmap->ceiling != NULL)
	{
		ft_free_array(splited_line);	
		ceiling_rgb(line, data);
	}
	else if (ft_strncmp(splited_line[0], "F", 2) == 0 && data->texmap->floor != NULL)
	{
		ft_free_array(splited_line);
		floor_rgb(line, data);
	}
}


void	if_valid_add(t_cube *data)
{
	t_cublist	*curr;

	curr = data->cub_file;

	while(curr != NULL && !is_full(data->texmap))
	{
		if(curr->line[0] != '\n')
		{
			valid_textures(curr->line, data);
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



