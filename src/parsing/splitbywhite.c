/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   splitbywhite.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstencel <mstencel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 15:21:44 by mstencel      #+#    #+#                 */
/*   Updated: 2025/01/14 10:10:31 by mstencel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	is_white_space_nline(char c)
{
	return (c == '\n' || c == ' ' || c == '\t' || c == '\v' || c == '\r');
}

static void	free_words(int i, char **ptr)
{
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
}

static char	*ft_wl(const char *str, char delim)
{
	char	*wl;
	int		i;

	i = 0;
	while (str[i] && str[i] != delim && !is_white_space_nline(str[i]))
		i++;
	wl = (char *)malloc(sizeof(char) * (i + 1));
	if (!wl)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != delim && !is_white_space_nline(str[i]))
	{
		wl[i] = str[i];
		i++;
	}
	wl[i] = '\0';
	return (wl);
}

static int	ft_wrdcnt(char const *str , char delim)
{
	int	w;
	int	i;

	w = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (is_white_space_nline(str[i]) || str[i] == delim))
			i++;
		if (str[i] != '\0')
			w++;
		while(str[i] && str[i] != delim && !is_white_space_nline(str[i]))
			i++;
	}
	return (w);
}

char	**splitbywhite(char const *s, char delim)
{
	char	**ptr_words;
	int		words;
	int		i;

	if (s == NULL)
		return (NULL);
	words = ft_wrdcnt(s, delim);
	ptr_words = (char **)malloc(sizeof(char *) * (words + 1));
	if (ptr_words == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && (is_white_space_nline(*s) || *s == delim))
			s++;
		ptr_words[i] = ft_wl(s, delim);
		if (ptr_words[i] == NULL)
			return (free_words(i, ptr_words), NULL);
		while (*s && *s != delim && !is_white_space_nline(*s))
			s++;
		i++;
	}
	ptr_words[i] = NULL;
	return (ptr_words);
}
