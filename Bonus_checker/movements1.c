/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:05:23 by apereira          #+#    #+#             */
/*   Updated: 2023/02/20 13:17:07 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * The function takes a pointer to a pointer to a list, and a flag.
 * It swaps the first two elements of the list
 */
void	sa(t_list **a)
{
	t_list	*temp;

	temp = (*a)->next;
	(*a)->next = temp->next;
	(*a)->prev = temp;
	temp->next = *a;
	temp->prev = NULL;
	(*a)->next->prev = *a;
	*a = (*a)->prev;
}

/**
 * @param b the list to be swapped
 */
void	sb(t_list **b)
{
	t_list	*temp;

	temp = (*b)->next;
	(*b)->next = temp->next;
	(*b)->prev = temp;
	temp->next = *b;
	temp->prev = NULL;
	(*b)->next->prev = *b;
	*b = (*b)->prev;
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	if (*b)
		sb(b);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *b;
	if (!temp)
		return ;
	*b = temp->next;
	temp->next = *a;
	temp->prev = NULL;
	if (*a)
		(*a)->prev = temp;
	*a = temp;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	if (!temp)
		return ;
	*a = temp->next;
	temp->next = *b;
	temp->prev = NULL;
	if (*b)
		(*b)->prev = temp;
	*b = temp;
}
