/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:03:51 by hherba            #+#    #+#             */
/*   Updated: 2022/07/08 16:04:02 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_error(t_stack *s)
{
	if (s)
	{
		ft_clear(s);
		free(s);
	}
	write(2, "Error\n", 6);
	exit(1);
}

int	stack_min(t_stack *stack, int *min)
{
	int			i;
	int			min_index;
	t_list		*temp;

	min_index = 0;
	temp = stack->head;
	*min = temp->data;
	i = 1;
	while (temp)
	{
		if (temp->data < *min)
		{
			*min = temp->data;
			min_index = i;
		}
		temp = temp->next;
		i++;
	}
	return (min_index);
}

int	stack_max(t_stack *stack, int *max)
{
	int			i;
	int			max_index;
	t_list		*temp;

	max_index = 0;
	temp = stack->head;
	*max = temp->data;
	i = 1;
	while (temp)
	{
		if (temp->data < *max)
		{
			*max = temp->data;
			max_index = i;
		}
		temp = temp->next;
		i++;
	}
	return (max_index);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}
