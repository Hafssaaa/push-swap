/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:35:25 by hherba            #+#    #+#             */
/*   Updated: 2022/07/08 16:09:37 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_memerr(void)
{
	write(2, "Can't allocate memory.\n", 23);
	exit(1);
}

void	ft_freetab(char **tab, int i)
{
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i++]);
	}
	free(tab);
}

char	*get_arg2(int *i)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = ' ';
	str[1] = '\0';
	*i = 1;
	return (str);
}

char	**get_arg(char **tab, int l)
{
	char	*str;
	char	*tmp;
	char	**args;
	int		i;

	str = get_arg2(&i);
	while (i < l)
	{
		tmp = str;
		str = ft_strjoin(str, tab[i]);
		if (tmp)
			free(tmp);
		if (!str)
			ft_memerr();
		tmp = str;
		str = ft_strjoin(str, " ");
		free(tmp);
		if (!str)
			ft_memerr();
		i++;
	}
	args = ft_split(str, ' ');
	free(str);
	return (args);
}

void	ft_parser(int ac, char **av, int **tab, int *size)
{
	char	**args;
	int		i;

	args = get_arg(av, ac);
	if (!args)
		ft_memerr();
	i = 0;
	*size = 0;
	while (args[*size])
		(*size)++;
	*tab = ft_calloc(*size, sizeof(int));
	if (!*tab)
		(ft_freetab(args, 0), ft_memerr());
	while (i <= *size - 1)
	{
		(*tab)[i] = ft_atoi(args[i]);
		free(args[i++]);
	}
	free(args);
}
