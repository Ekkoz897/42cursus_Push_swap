/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:36:52 by apereira          #+#    #+#             */
/*   Updated: 2023/02/22 18:21:01 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * It takes a pointer to a pointer to a list, and a flag, and rotates 
 * the list to the right
 * 
 * @param a the address of the pointer to the first element of the list
 * @param flag 0 = print the command, 1 = don't print the command
 */
void	ra(t_list **a, int flag)
{
	t_list	*temp;

	temp = *a;
	*a = (*a)->next;
	ft_lstadd_back(a, temp);
	if (flag == 0)
		ft_printf("ra\n");
}

/**
 * It takes a pointer to a pointer to a linked list, and rotates the 
 * list to the right
 * 
 * @param b the list to be rotated
 * @param flag 0 = print, 1 = don't print
 */
void	rb(t_list **b, int flag)
{
	t_list	*temp;

	temp = *b;
	*b = (*b)->next;
	ft_lstadd_back(b, temp);
	if (flag == 0)
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a, 1);
	rb(b, 1);
	ft_printf("rr\n");
}

/**
 * It takes the last element of the list and adds it to the front of the list
 * 
 * @param a the list to be rotated
 * @param flag 0 if you want to print the command, 1 if you don't
 */
void	rra(t_list **a, int flag)
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
	*a = temp;
	temp2->next = NULL;
	if (flag == 0)
		ft_printf("rra\n");
}

/**
 * It takes the last element of the list and adds it to the front of the list
 * 
 * @param b the list to be rotated
 * @param flag 0 = no print, 1 = print
 */
void	rrb(t_list **b, int flag)
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
	*b = temp;
	temp2->next = NULL;
	if (flag == 0)
		ft_printf("rrb\n");
}
