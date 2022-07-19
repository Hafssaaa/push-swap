/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:00:09 by hherba            #+#    #+#             */
/*   Updated: 2022/07/08 15:15:03 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_ps_a(t_stack *a, int n)
{
	t_list		*temp_a;
	t_ij		z;

	temp_a = a->head;
	if (n < a->head->data && n > a->tail->data)
		return (0);
	z.i = 0;
	while (++z.i < a->size / 2)
	{
		if (n > temp_a->data && n < temp_a->next->data)
			return (z.i);
		temp_a = temp_a->next;
	}
	temp_a = a->tail;
	z.i = a->size + 1;
	while (--z.i > a->size / 2)
	{
		if (n > temp_a->prev->data && n < temp_a->data)
			return (z.i - a->size - 1);
		temp_a = temp_a->prev;
	}
	z.i = stack_max(a, &z.j);
	if (z.i < a->size / 2)
		return (z.i - 1);
	return (z.i - a->size - 1);
}

void	first_half(t_stack *a, t_stack *b, int t[])
{
	int			i;
	int			j;
	t_list		*temp_b;

	temp_b = b->head;
	j = 0;
	t[0] = -a->size;
	t[1] = b->size;
	while (j < b->size / 2)
	{
		if (ft_nmoves(0, j) >= ft_nmoves (t[0], t[1]))
			break ;
		i = find_ps_a(a, temp_b->data);
		if (ft_nmoves(i, j) < ft_nmoves(t[0], t[1]))
		{
			t[0] = i;
			t[1] = j;
		}
		temp_b = temp_b->next;
		j++;
	}
}

void	second_half(t_stack *a, t_stack *b, int t[])
{
	int			i;
	int			j;
	t_list		*temp_b;

	temp_b = b->tail;
	j = b->size;
	while (j > b->size / 2)
	{
		if (ft_nmoves(0, j - b->size - 1) >= ft_nmoves(t[0], t[1]))
			break ;
		i = find_ps_a(a, temp_b->data);
		if (ft_nmoves(i, j - b->size - 1) < ft_nmoves(t[0], t[1]))
		{
			t[0] = i;
			t[1] = j - b->size -1;
		}
		temp_b = temp_b->prev;
		j--;
	}
}

void	move(t_stack *a, t_stack *b, int t[])
{
	int	m;

	m = ft_move(t);
	while (m != PA)
	{
		if (m == RA)
			rx(a, "ra");
		else if (m == RB)
			rx(b, "rb");
		else if (m == RR)
			rr(a, b, "rr");
		else if (m == RRA)
			rrx(a, "rra");
		else if (m == RRB)
			rrx(b, "rrb");
		else if (m == RRR)
			rrr(a, b, "rrr");
		m = ft_move(t);
	}
	px(b, a, "pa");
}

void	push_a(t_stack *a, t_stack *b)
{
	int	t[2];
	int	min;
	int	i;

	while (b->size > 0)
	{
		first_half(a, b, t);
		second_half(a, b, t);
		move(a, b, t);
	}
	i = stack_min(a, &min);
	while (a->head->data != min)
	{
		if (i <= a->size / 2)
			rx(a, "ra");
		else
			(rrx(a, "rra"));
	}
}
