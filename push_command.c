/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:52:26 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/17 23:00:25 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_push;
	if(*src == NULL)
		return;
	node_push = *src;
	*src = (*src)->next;
	if(*src)
		(*src)->prev = NULL;
	node_push->prev = NULL;
	if(*dest == NULL)
	{
		*dest = node_push;
		node_push->next = NULL;
	}
	else
	{
		node_push->next = *dest;
		node_push->next->prev = node_push;
		*dest = node_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
