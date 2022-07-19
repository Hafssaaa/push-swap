/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <hherba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:41:05 by hherba            #+#    #+#             */
/*   Updated: 2022/07/08 16:12:07 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define PA 1
# define PB 2
# define SA 3
# define SB 4
# define SS 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_ij
{
	int	i;
	int	j;
}				t_ij;

typedef struct s_node
{
	int				data;
	int				keep_in_a;
	struct s_node	*prev;
	struct s_node	*next;

}t_list;

typedef struct s_stack
{
	t_list	*head;
	t_list	*tail;
	int		size;
}t_stack;

void	push_b(t_stack *a, t_stack *b);
void	ft_error(t_stack *s);
int		stack_min(t_stack *stack, int *min);
int		stack_max(t_stack *stack, int *max);
int		ft_nmoves(int a, int b);
int		ft_move(int t[]);
void	ft_clear(t_stack *s);
void	rr(t_stack *a, t_stack *b, char *mesg);
void	lis(t_stack *a);
void	fill_keeps(t_stack *a, int *arr, int *length, int *sub);
t_stack	*ft_stack(void);
void	ft_push(t_stack *s, int n);
int		ft_pop(t_stack *s);
void	push_a(t_stack *a, t_stack *b);
void	px(t_stack *from, t_stack *to, char *mesg);
void	rrx(t_stack *s, char *mesg);
void	rrr(t_stack *a, t_stack *b, char *mesg);
void	rx(t_stack *s, char *mesg);
void	rr(t_stack *a, t_stack *b, char *mesg);
void	sx(t_stack *s, char *mesg);
void	ss(t_stack *a, t_stack *b, char *mesg);
void	ft_memerr(void);
char	**ft_split(char const *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(char *str);
char	**get_arg(char **tab, int l);
void	ft_parser(int ac, char **av, int **tab, int *size);
int		check_dup(int t[], int size);
void	ft_sort(t_stack *a, t_stack *b);
void	*ft_calloc(size_t count, size_t size);
void	*ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_abs(int nbr);
int		check_dup(int t[], int size);
void	ft_error(t_stack *s);
#endif
