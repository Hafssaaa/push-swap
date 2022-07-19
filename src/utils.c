/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:27:55 by hherba            #+#    #+#             */
/*   Updated: 2022/07/08 16:04:56 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_nmoves(int a, int b)
{
	int	n;

	n = 0;
	if (a * b <= 0)
		return (ft_abs(a) + ft_abs(b) + 1);
	a = ft_abs(a);
	b = ft_abs(b);
	return (ft_max(a, b) + 1);
}

int	ft_move(int t[])
{
	if (t[0] == 0 && t[1] == 0)
		return (PA);
	else if (t[0] > 0)
	{
		t[0]--;
		if (t[1] > 0)
			return (t[1]--, RR);
		return (RA);
	}
	else if (t[0] < 0)
	{
		t[0]++;
		if (t[1] < 0)
			return (t[1]++, RRR);
		return (RRA);
	}
	else if (t[1] > 0)
		return (t[1]--, RB);
	t[1]++;
	return (RRB);
}

void	ft_clear(t_stack *s)
{
	while (s->size > 0)
		ft_pop(s);
}
