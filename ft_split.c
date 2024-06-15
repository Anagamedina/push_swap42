/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:59:42 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/15 20:59:55 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

static int	ft_wcount(const char *s, char separator)
{
	int	num_words;
	int i;

	num_words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while(s[i] == separator && s[i] != '\0')
			i++;
		if(s[i] != separator && s[i] != '\0')
			num_words++;
		while (s[i] != separator && s[i] != '\0')
			i++;
	}
	return(num_words);
}




static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while(str[cursor] == separator)
		++cursor;
	while(((str[cursor + len]) != separator) && str[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if(!next_word)
		return(NULL);
	while((str[cursor] != separator) && str[cursor])
		next_word[i++] = str[cursor++];
	next_word[i] = '\0';
	return(next_word);
}


char	**ft_split(char *str, char separator)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = ft_wcount(str, separator);
	if (!words_number)
		exit(1);
	vector_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (!vector_strings)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (i == 0)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (!vector_strings[i])
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word(str, separator);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}
