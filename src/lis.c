/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:54:14 by hherba            #+#    #+#             */
/*   Updated: 2022/07/08 14:54:18 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_ones(int t[], int l)
{
	int	i;

	i = 0;
	while (i < l)
		t[i++] = 1;
}

int	ft_maxi(int t[], int len)
{
	int	i;
	int	max;

	i = len;
	max = len - 1;
	while (--i >= 0)
	{
		if (t[i] > t[max])
			max = i;
	}
	return (max);
}

int	*ft_fill(t_list *lst, int size)
{
	int	*arr;
	int	i;

	arr = ft_calloc(size, sizeof(int));
	i = 0;
	while (i < size)
	{
		arr[i++] = lst->data;
		lst = lst->next;
	}
	return (arr);
}

void	fill_keeps(t_stack *a, int *arr, int *length, int *sub)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = ft_maxi(length, a->size);
	tmp = a->tail;
	j = length[i];
	while (j > 0)
	{
		while (tmp->data != arr[i])
			tmp = tmp->prev;
		tmp->keep_in_a = 1;
		i = sub[i];
		j--;
	}
	free(arr);
	free(length);
	free(sub);
}

void	lis(t_stack *a)
{
	int	*arr;
	int	*length;
	int	*sub;
	int	i;
	int	j;

	arr = ft_fill(a->head, a->size);
	length = ft_calloc(a->size, sizeof(int));
	sub = ft_calloc(a->size, sizeof(int));
	ft_ones(length, a->size);
	i = 0;
	while (++i < a->size)
	{
		j = -1;
		while (++j < i)
		{
			if ((arr[j] < arr[i]) && (length[j] + 1 >= length[i]))
			{
					length[i] = length[j] + 1;
					sub[i] = j;
			}
		}
	}
	fill_keeps(a, arr, length, sub);
}
