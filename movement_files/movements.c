/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:03:28 by apereira          #+#    #+#             */
/*   Updated: 2023/02/01 18:36:48 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * The function takes a pointer to a pointer to a list, and a flag.
 * It swaps the first two elements of
 * the list, and if the flag is 0, it prints "sa" to the standard output
 * 
 * @param a the list
 * @param flag 0 = print the command, 1 = don't print the command
 */
void	sa(t_list **a, int flag)
{
	t_list	*temp;

	temp = (*a)->next;
	(*a)->next = temp->next;
	(*a)->prev = temp;
	temp->next = *a;
	temp->prev = NULL;
	(*a)->next->prev = *a;
	*a = (*a)->prev;
	if (flag == 0)
		ft_printf("sa\n");
}

/**
 * 
 * 
 * @param b the list to be swapped
 * @param flag 0 = print the command, 1 = don't print the command
 */
void	sb(t_list **b, int flag)
{
	t_list	*temp;

	temp = (*b)->next;
	(*b)->next = temp->next;
	(*b)->prev = temp->prev;
	temp->next = *b;
	temp->prev = (*b)->prev;
	*b = (*b)->prev;
	if (flag == 0)
		ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	sa(a, 1);
	if (*b)
		sb(b, 1);
	ft_printf("ss\n");
}

void	pa(t_list **a, t_list **b)
{
	if (b)
	{
		go_back(a);
		go_back(b);
		(*b)->next->prev = NULL;
		(*a)->prev = *b;
		(*b)->next = *a;
		(*b)->prev = NULL;
	}
	ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	if (a)
	{
		*a = (*a)->next;
		(*a)->prev = NULL;
		ft_lstadd_front(b, temp);
	}
	ft_printf("pb\n");
}
