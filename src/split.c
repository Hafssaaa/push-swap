/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:21:54 by hherba            #+#    #+#             */
/*   Updated: 2022/07/08 15:22:25 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	count_word(const char	*str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && c != str[i])
			i++;
		while (c != '\0' && c == str[i])
			i++;
		count++;
	}
	return (count);
}

static char	*malloc_word(const char	*str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free(char **buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free (buf);
	return (0);
}

char	**ft_split(char const *str, char c)
{
	char	**arr;
	int		i;

	if (str == 0)
		return (0);
	i = 0;
	while (*str && *str == c)
		str++;
	arr = (char **)malloc(sizeof(char *) * (count_word(str, c) + 1));
	if (!arr)
		return (0);
	while (*str)
	{
		arr[i] = malloc_word (str, c);
		if (arr[i] == NULL)
			return (ft_free (arr));
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
