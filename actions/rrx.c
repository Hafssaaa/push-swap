/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:45:27 by hherba            #+#    #+#             */
/*   Updated: 2022/07/08 14:46:29 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rrx(t_stack *s, char *mesg)
{
	t_list	*tmp;

	if (s->size == 2)
		sx(s, NULL);
	else if (s->size > 2)
	{
		tmp = s->tail->prev;
		tmp->next = NULL;
		s->tail->next = s->head;
		s->tail->prev = NULL;
		s->head->prev = s->tail;
		s->head = s->tail;
		s->tail = tmp;
	}
	if (mesg && (s->size >= 2))
	{
		write (1, mesg, 3);
		write (1, "\n", 1);
	}
}

void	rrr(t_stack *a, t_stack *b, char *mesg)
{
	rrx(a, NULL);
	rrx(b, NULL);
	if (mesg)
	{
		write (1, mesg, 3);
		write (1, "\n", 1);
	}
}
