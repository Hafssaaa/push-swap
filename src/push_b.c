/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:15:10 by hherba            #+#    #+#             */
/*   Updated: 2022/07/08 15:21:01 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	keep_a(t_stack *s)
{
	t_list	*temp;

	temp = s->head;
	while (temp)
	{
		if (!temp->keep_in_a)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	push_to_b(t_stack *a, t_stack*b)
{
	while (a->size > 0 && !keep_a(a))
	{
		if (a->head->keep_in_a)
			rx(a, "ra");
		else
			px(a, b, "pb");
	}
}

void	push_b(t_stack *a, t_stack *b)
{
	int		min;
	int		i;
	int		n;

	i = stack_min(a, &min);
	n = 0;
	while (a->head->data != min)
	{
		if (i <= ((a->size / 2)))
			(rx(a, NULL), n++);
		else
			(rrx(a, NULL), n--);
	}
	lis(a);
	while (n != 0)
	{
		if (n > 0)
			(rrx(a, NULL), n--);
		else
			(rx(a, NULL), n++);
	}
	push_to_b(a, b);
}
