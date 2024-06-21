/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:59:15 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/21 19:34:55 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//esta funcion es para clasificar 3 nodos cual sera el mas grande


void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = find_value_max(*a);
	if (*a == highest_node)
		ra(a);
	else if((*a)->next == highest_node)
		rra(a);
	if((*a)->value > (*a)->next->value)
		sa(a);
}

void	handle_five(t_stack_node **a, t_stack_node **b)
{
	while(stack_len(*a) < 3)
	{
		init_node();
		//poner funcion que sirva para mover nodos al stack b 
	}

}
