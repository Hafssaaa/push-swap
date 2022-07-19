/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:54:39 by hherba            #+#    #+#             */
/*   Updated: 2022/07/08 14:59:40 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			size;
	int			*t;

	if (ac == 1)
		return (0);
	t = NULL;
	ft_parser(ac, av, &t, &size);
	if (check_dup(t, size))
		(free(t), ft_error(NULL));
	stack_a = ft_stack();
	while (size > 0)
	{
		ft_push(stack_a, t[size - 1]);
		size--;
	}
	free(t);
	stack_b = ft_stack();
	ft_sort(stack_a, stack_b);
	(ft_clear(stack_a), free(stack_a));
	(ft_clear(stack_b), free(stack_b));
	return (0);
}
