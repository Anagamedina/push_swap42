/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:14:17 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/19 21:52:16 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static void set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_index;

	while (b)
	{
		best_index = LONG_MAX;
		current_a = a;
		while (current_a)
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
