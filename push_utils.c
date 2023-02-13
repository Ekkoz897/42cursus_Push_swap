/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:01:09 by apereira          #+#    #+#             */
/*   Updated: 2023/02/13 14:07:15 by apereira         ###   ########.fr       */
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
	temp = (*a)->next;
	nbr = *(*a)->content;
	i = 1;
	while (temp->content)
	{
		if (!temp->next)
			break ;
		if (nbr < *temp->content)
		{
			nbr = *temp->content;
			bigpos = i;
		}
		i++;
		temp = temp->next;
	}
	push_highest_numbers(a, b, bigpos);
}
