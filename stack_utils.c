/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:00:40 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/13 19:01:29 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>


bool stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return(1);
	while(stack->next)
	{
		if(stack-> value > stack->next->value)
			return(false);
		stack = stack->next;
	}
	return (true);
}

int stack_len(t_slack_node *stack)
{
	int count;

	count = 0;
	if(!stack)
		return(0);
	while(stack)
	{
		stack = stack->next;
		count++;
	}
	return(count);
}

t_stack_node *find_last(t_stack_node *stack)
{
	if(!stack)
		return(NULL);
	while(stack->next)
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_node;

	if(!stack)
		return(NULL);
	min = LONG_MAX;
	while (stack)
	{
		if(stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node  *find_max(t_stack_node *stack)
{
	long				max;
	t_stack_node		*max_node;

	if(!stack)
		return(NULL);
	max = LONG_MAX;
	while (stack)
	{
		if(stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return(max_node);
}

