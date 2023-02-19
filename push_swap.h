/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:48:33 by apereira          #+#    #+#             */
/*   Updated: 2023/02/18 21:29:57 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_vars
{
	int				i;
	int				*tmp;
}t_vars;

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}t_moves;

int		nbr_is_valid(t_list *a, char *str, int nbr, int index);
void	stack_a_init(char **argv, t_list **a, t_vars *var, int argc);

// Movement Functions

void	sa(t_list **a, int flag);
void	sb(t_list **b, int flag);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a, int flag);
void	rb(t_list **b, int flag);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a, int flag);
void	rrb(t_list **b, int flag);
void	rrr(t_list **b, t_list **a);

// Utility Functions
void	print_stacks(t_list *a, char c);
void	vars_init(t_vars *vars);
void	clear_stacks(t_list **a, t_list **b);
void	go_back(t_list **a);
int		are_already_in_order(t_list *a);
void	moves_reset(t_moves *moves);

// Sorting Functions

void	three_or_less(t_list **a);

// Hard coded five or less
void	five_or_less(t_list **a, t_list **b);
void	find_highest_numbers(t_list **a, t_list **b);
void	push_highest_numbers(t_list	**a, t_list **b, int bigpos);

// Over 5 numbers
void	sort_big(t_list **a, t_list **b);
t_list	*biggest(t_list *b);
int		bigger(t_list *element, t_list *b);
t_list	*smallest(t_list *b);
int		smaller(t_list *element, t_list *b);
void	fewer_moves_element(t_list *node,
			t_list *first, t_moves *moves, int sizea);
void	first_element(t_list *node, t_list *first, t_moves *moves, int sizea);

#endif