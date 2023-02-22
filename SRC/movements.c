/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:03:28 by apereira          #+#    #+#             */
/*   Updated: 2023/02/22 15:58:01 by apereira         ###   ########.fr       */
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

	if (!*a || !(*a)->next)
		return ;
	temp = (*a)->next;
	(*a)->next = temp->next;
	(*a)->prev = temp;
	temp->next = *a;
	temp->prev = NULL;
	(*a)->next->prev = *a;
	*a = temp;
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

	if (!*b || !(*b)->next)
		return ;
	temp = (*b)->next;
	(*b)->next = temp->next;
	(*b)->prev = temp;
	temp->next = *b;
	temp->prev = NULL;
	(*b)->next->prev = *b;
	*b = temp;
	if (flag == 0)
		ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	sa(a, 1);
	sb(b, 1);
	ft_printf("ss\n");
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!*b)
		return ;
	temp = (*b);
	*b = temp->next;
	temp->next = *a;
	if (*a)
		(*a)->prev = temp;
	if (*b)
		(*b)->prev = NULL;
	*a = temp;
	ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = temp->next;
	temp->next = *b;
	temp->prev = NULL;
	if (*b)
		(*b)->prev = temp;
	if (*a)
		(*a)->prev = NULL;
	*b = temp;
	ft_printf("pb\n");
}
