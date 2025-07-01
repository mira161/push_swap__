/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:13:10 by miwehbe           #+#    #+#             */
/*   Updated: 2025/07/01 11:37:27 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*copy_word(const char *start, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **words, int i)
{
	while (i--)
		free(words[i]);
	free(words);
}

static int	fill_words(char **result, const char *s, char c)
{
	int	i;
	int	word_index;
	int	len;

	i = 0;
	word_index = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				len++;
			result[word_index] = copy_word(&s[i], len);
			if (!result[word_index])
				return (free_all(result, word_index), 0);
			i += len;
			word_index++;
		}
	}
	result[word_index] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	if (!fill_words(result, s, c))
		return (NULL);
	return (result);
}

/*int main()
{
    char const *c = "hello mira mmm";
    char **resultt = ft_split(c, ' ');
    char **tmp = resultt;  

    while (*resultt) {
        printf("%s\n", *resultt);
        free(*resultt);
        resultt++;
    }
    free(tmp); 
    return 0;
}*/
