/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:36:52 by apereira          #+#    #+#             */
/*   Updated: 2023/02/22 18:50:30 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * It takes a pointer to a pointer to a list, and a flag, and rotates 
 * the list to the right
 * 
 * @param a the address of the pointer to the first element of the list
 * @param flag 0 = print the command, 1 = don't print the command
 */
void	ra(t_list **a)
{
	t_list	*temp;

	if (ft_lstsize(*a) < 2)
		return ;
	temp = *a;
	*a = (*a)->next;
	ft_lstadd_back(a, temp);
}

/**
 * It takes a pointer to a pointer to a linked list, and rotates the 
 * list to the right
 * 
 * @param b the list to be rotated
 * @param flag 0 = print, 1 = don't print
 */
void	rb(t_list **b)
{
	t_list	*temp;

	if (ft_lstsize(*b) < 2)
		return ;
	temp = *b;
	*b = (*b)->next;
	ft_lstadd_back(b, temp);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}

/**
 * It takes the last element of the list and adds it to the front of the list
 * 
 * @param a the list to be rotated
 * @param flag 0 if you want to print the command, 1 if you don't
 */
void	rra(t_list **a)
{
	t_list	*temp;
	t_list	*last;

	if (ft_lstsize(*a) < 2)
		return ;
	temp = *a;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	last->next = *a;
	*a = last;
	temp->next = NULL;
}

/**
 * It takes the last element of the list and adds it to the front of the list
 * 
 * @param b the list to be rotated
 * @param flag 0 = no print, 1 = print
 */
void	rrb(t_list **b)
{
	t_list	*temp;
	t_list	*last;

	if (ft_lstsize(*b) < 2)
		return ;
	temp = *b;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	last->next = *b;
	*b = last;
	temp->next = NULL;
}
