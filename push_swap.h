/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:48:33 by apereira          #+#    #+#             */
/*   Updated: 2023/01/31 17:59:28 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_vars
{
	int				count;
	int				i;
	int				*tmp;
}t_vars;

int		nbr_is_valid(t_list *a, char *str, int nbr, int index);
void	stack_a_init(char **argv, t_list **a, t_vars *var, int argc);

// Movement Functions
void	sa(t_list **a, int flag);
void	sb(t_list **b, int flag);
void	ss(t_list **a, t_list **b);

// Utility Functions
void	vars_init(t_vars *vars);
void	clear_stacks(t_list **a, t_list **b);

#endif