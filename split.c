/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwehbe <miwehbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:13:10 by miwehbe           #+#    #+#             */
/*   Updated: 2025/07/11 13:25:03 by miwehbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*malloc_word(const char *s, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **split, int i)
{
	while (--i >= 0)
		free(split[i]);
	free(split);
}

static int	fill_split(char **split, const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			split[i] = malloc_word(s, len);
			if (!split[i])
			{
				free_all(split, i);
				return (0);
			}
			s += len;
			i++;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (NULL);
	if (!fill_split(split, s, c))
		return (NULL);
	return (split);
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
