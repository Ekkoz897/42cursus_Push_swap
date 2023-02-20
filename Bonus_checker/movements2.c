/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:05:25 by apereira          #+#    #+#             */
/*   Updated: 2023/02/20 13:16:46 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * It takes a pointer to a pointer to a list, and a flag, and rotates 
 * the list to the right
 */
void	ra(t_list **a)
{
	t_list	*temp;

	temp = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	ft_lstadd_back(a, temp);
	go_back(a);
}

/**
 * It takes a pointer to a pointer to a linked list, and rotates the 
 * list to the right
 */
void	rb(t_list **b)
{
	t_list	*temp;

	temp = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	ft_lstadd_back(b, temp);
	go_back(b);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}

/**
 * It takes the last element of the list and adds it to the front of the list
 */
void	rra(t_list **a)
{
	t_list	*temp;
	t_list	*temp2;

	if ((*a)->next == NULL)
		return ;
	temp2 = *a;
	while (temp2->next->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp = temp2->next;
	temp->next = *a;
	temp->prev = NULL;
	*a = temp;
	temp2->next = NULL;
	go_back(a);
}

/**
 * It takes the last element of the list and adds it to the front of the list
 */
void	rrb(t_list **b)
{
	t_list	*temp;
	t_list	*temp2;

	if ((*b)->next == NULL)
		return ;
	temp2 = *b;
	while (temp2->next->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp = temp2->next;
	temp->next = *b;
	temp->prev = NULL;
	*b = temp;
	temp2->next = NULL;
	go_back(b);
}
