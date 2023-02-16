/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:01:09 by apereira          #+#    #+#             */
/*   Updated: 2023/02/15 11:51:47 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vars_init(t_vars *vars)
{
	vars->i = 1;
	vars->tmp = NULL;
}

void	clear_stacks(t_list **a, t_list **b)
{
	if (*a)
		ft_lstclear(a, free);
	if (*b)
		ft_lstclear(b, free);
}

void	go_back(t_list **lst)
{
	while ((*lst)->prev)
	{
		*lst = (*lst)->prev;
	}
}

void	find_highest_numbers(t_list **a, t_list **b)
{
	int		bigpos;
	t_list	*temp;
	int		nbr;
	int		i;

	bigpos = 0;
	temp = (*a);
	nbr = *(*a)->content;
	i = 0;
	while (temp->content)
	{
		i++;
		if (nbr < *temp->content)
		{
			nbr = *temp->content;
			bigpos = i;
		}
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	push_highest_numbers(a, b, bigpos);
}
