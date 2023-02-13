/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:48:33 by apereira          #+#    #+#             */
/*   Updated: 2023/02/13 14:07:45 by apereira         ###   ########.fr       */
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

// Sorting Functions

void	three_or_less(t_list **a);

// Hard coded five or less
void	five_or_less(t_list **a, t_list **b);
void	find_highest_numbers(t_list **a, t_list **b);
void	push_highest_numbers(t_list	**a, t_list **b, int bigpos);

// Over 5 numbers
void	quicksort(t_list **stack_a, t_list **stack_b, int size);

#endif