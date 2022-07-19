/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:22:31 by hherba            #+#    #+#             */
/*   Updated: 2022/07/08 15:27:43 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_stack(void)
{
	t_stack	*s;

	s = ft_calloc(1, sizeof(t_stack));
	if (!s)
	{
		ft_error(NULL);
	}
	return (s);
}

void	ft_push(t_stack *s, int n)
{
	t_list	*l;

	l = ft_calloc(1, sizeof(t_list));
	if (!l)
		ft_error(s);
	l->data = n;
	if (s->size == 0)
	{
		s->head = l;
		s->tail = l;
	}
	else
	{
		s->head->prev = l;
		l->next = s->head;
		s->head = l;
	}
	s->size++;
}

int	ft_pop(t_stack *s)
{
	int			n;
	t_list		*tmp;

	n = s->head->data;
	s->size--;
	tmp = s->head;
	s->head = s->head->next;
	if (s->size == 0)
		s->tail = NULL;
	free(tmp);
	return (n);
}
