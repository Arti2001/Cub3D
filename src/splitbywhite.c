#include "../include/cub3d.h"


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

static char	*ft_wl(const char *str)
{
	char	*wl;
	int		i;

	i = 0;
	while (str[i] && !is_white_space_nline(str[i]))
		i++;
	wl = (char *)malloc(sizeof(char) * (i + 1));
	if (!wl)
		return (NULL);
	i = 0;
	while (str[i] && !is_white_space_nline(str[i]))
	{
		wl[i] = str[i];
		i++;
	}
	wl[i] = '\0';
	return (wl);
}
//    NO     ./PARD/LSASD    
static int	ft_wrdcnt(char const *str)
{
	int	w;
	int i;

	w = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_white_space_nline(str[i]))
			i++;
		if (str[i] != '\0')
			w++;
		while (str[i] && (!is_white_space_nline(str[i])))
			i++;
	}
	return (w);
}
char	**splitbywhite(char const *s)
{
	char	**ptr_words;
	int		words;
	int		i;

	if (s == NULL)
		return (NULL);
	words = ft_wrdcnt(s);
	ptr_words = (char **)malloc(sizeof(char *) * (words + 1));
	if (ptr_words == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && is_white_space_nline(*s))
			s++;
		ptr_words[i] = ft_wl(s);
		if (ptr_words[i] == NULL)
			return (free_words(i, ptr_words), NULL);
		while (*s && !is_white_space_nline(*s))
			s++;
		i++;
	}
	ptr_words[i] = NULL;
	return (ptr_words);
}

//      NO     ./PATH/HA        

// int main()
//{
//	int i;
//	char **arr;
//	i = 0;
//	//arr = ft_split("        hello     world ja ", ' ');
//	arr = splitbywhite("hello!		\n	lol");
//	while (arr[i])
//	{
//		printf("%s\n", arr[i]);
//		i++;
//	}
// }
