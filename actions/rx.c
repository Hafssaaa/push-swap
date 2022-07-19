/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:38:14 by hherba            #+#    #+#             */
/*   Updated: 2022/07/08 14:43:10 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rx(t_stack *s, char *mesg)
{
	t_list	*tmp;

	if (s->size == 2)
		sx(s, NULL);
	else if (s->size > 2)
	{
		tmp = s->head->next;
		tmp->prev = NULL;
		s->head->next = NULL;
		s->head->prev = s->tail;
		s->tail->next = s->head;
		s->tail = s->head;
		s->head = tmp;
	}
	if (mesg && (s->size >= 2))
	{
		write (1, mesg, 2);
		write (1, "\n", 1);
	}
}

void	rr(t_stack *a, t_stack *b, char *mesg)
{
	rx(a, NULL);
	rx(b, NULL);
	if (mesg)
	{
		write(1, mesg, 2);
		write(1, "\n", 1);
	}
}
