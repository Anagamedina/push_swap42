/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:02:31 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/17 16:14:45 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void rotate_command(t_stack_node**stack)
{
	t_stack_node	last_node;

	if (stack == NULL || (*stack) == NULL || (*stack) == NULL)
		return;
	last_node = find_last(*stack);
	last_node->next = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;

}


