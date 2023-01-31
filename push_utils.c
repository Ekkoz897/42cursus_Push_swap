/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:01:09 by apereira          #+#    #+#             */
/*   Updated: 2023/01/31 17:55:00 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vars_init(t_vars *vars)
{
	vars->i = 0;
	vars->count = 0;
	vars->tmp = NULL;
}

void	clear_stacks(t_list **a, t_list **b)
{
	if (a)
		ft_lstclear(a, free);
	if (b)
		ft_lstclear(b, free);
}
