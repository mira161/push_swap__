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

#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int	count = 0;
	int	in_word = 0;

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
	char	*word = malloc(len + 1);
	int		i = 0;

	if (!word)
		return (NULL);
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

char	**ft_split(const char *s, char c)
{
	char	**split;
	int		i = 0, len;

	if (!s || !(split = malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			if (!(split[i] = malloc_word(s, len)))
				return (free_all(split, i), NULL);
			s += len;
			i++;
		}
		else
			s++;
	}
	split[i] = NULL;
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
