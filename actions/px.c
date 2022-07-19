/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:43:18 by hherba            #+#    #+#             */
/*   Updated: 2022/07/08 14:44:28 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	px(t_stack *from, t_stack *to, char *mesg)
{
	int	n;

	if (from->size == 0)
		return ;
	n = ft_pop(from);
	ft_push(to, n);
	if (mesg)
	{
		write (1, mesg, 2);
		write (1, "\n", 1);
	}
}
