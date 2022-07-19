/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:47:23 by hherba            #+#    #+#             */
/*   Updated: 2022/07/08 14:50:23 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sx(t_stack *s, char *mesg)
{
	int	nb;

	if (s->size >= 2)
	{
		nb = s->head->data;
		s->head->data = s->head->next->data;
		s->head->next->data = nb;
	}
	if (mesg && (s->size >= 2))
	{
		write (1, mesg, 2);
		write (1, "\n", 1);
	}
}

void	ss(t_stack *a, t_stack *b, char *mesg)
{
	sx(a, NULL);
	sx(b, NULL);
	if (mesg)
	{
		write (1, mesg, 2);
		write (1, "\n", 1);
	}
}
