/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:52:26 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/19 16:44:31 by anamedin         ###   ########.fr       */
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


/*int main()
{
	t_stack_node	*a;
	t_stack_node	*b;
	a = malloc(sizeof(t_stack_node)); // inicializa el primer nodo 
	a->next = malloc(sizeof(t_stack_node));//inicializa el segundo nodo 
	a->next->next = malloc(sizeof(t_stack_node));//inicializa el tercer nodo 
	a->value = 42;
	a->next->value  = 1337;
	a->next->next->value = -21;
	a->prev = NULL; //primer nodo 
	a->next->prev = a;
	a->next->next->prev = a->next;
	a->next->next->next = NULL;
	push(&a, &b);
}*/
