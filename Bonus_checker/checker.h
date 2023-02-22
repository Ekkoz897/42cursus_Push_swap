/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:00:19 by apereira          #+#    #+#             */
/*   Updated: 2023/02/22 12:23:36 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "Get_next_line/get_next_line.h"

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

// Initialize stack_A

int		nbr_is_valid(t_list *a, char *str, int nbr, int index);
void	stack_a_init(char **argv, t_list **a, t_vars *var, int argc);

// Movement Functions

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **b, t_list **a);

// Utility Functions

void	print_stacks(t_list *a, char c);
void	vars_init(t_vars *vars);
void	clear_stacks(t_list **a, t_list **b);
void	go_back(t_list **a);
int		are_already_in_order(t_list *a);

#endif