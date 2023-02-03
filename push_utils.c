/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:01:09 by apereira          #+#    #+#             */
/*   Updated: 2023/02/03 12:09:39 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vars_init(t_vars *vars)
{
	vars->i = 0;
	vars->tmp = NULL;
}

void	clear_stacks(t_list **a, t_list **b)
{
	if (a)
		ft_lstclear(a, free);
	if (b)
		ft_lstclear(b, free);
}

void	go_back(t_list **lst)
{
	while ((*lst)->prev)
	{
		*lst = (*lst)->prev;
	}
}

int	get_a_size(t_list *a)
{
	int	i;

	i = 0;
	while (a->next)
		i++;
	return (i);
}
