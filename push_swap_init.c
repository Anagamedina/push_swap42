/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:14:17 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/21 14:33:52 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>


/*asigna a cada nodo en la pila (b) un "nodo objetivo" en la pila (a), este
 * nodo objetivo es el elugar en (a) donde el nodo de (b) debeeria ser
 * insertado para mantener (a) ordenada */


static void set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;// el nodo de "a" donde el nodo de "b" deberia ser insertado
	long			best_index;// guarda temporal el valor del nodo de "a" que es el mejor candidato
							   // como "nodo objetivo" para el nodo de "b"

	while (b) // empieza iterando sobre cada nodo en la pila "b"
	{
		best_index = LONG_MAX;// para asegurar que cualquier valor valido en (a) sera menor
		current_a = a;
		while (current_a) //iteramos sobre cada nodo en a 
		{
			if (current_a->value > b->value
				&& current_a->value < best_index)
			{
				best_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_index)
			b->target_node = find_value_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int len_a;
	int len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while(b)
	{
		b->push_price = b->current_position;
		if(!(b->above_median))
			b->push_price = len_b - (b->current_position);
		if (b->target_node->above_median)
				b->push_price += b->target_node->current_position;
		else
		b->push_price += len_a - (b->target_node->current_position);
		b = b->next;		
	}
}

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (stack == NULL)
		return;
	centerline = stack_len(stack)/ 2;
	while (stack)
	{
		stack->current_position = i;
		if (i<= centerline)
			stack->above_median = TRUE;
		else
			stack->above_median = FALSE;
		stack = stack->next;
		++i;
	}
}
