/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:16:15 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/17 17:46:58 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack_node **head)
{
	if(*head == NULL || head == NULL)
		return;
	*head = (*head)->next;  //1->2->3->4
	(*head)->prev->prev = *head; //2->1->3->4
	(*head)->prev->next = (*head)->next; //2->1(next=3)->3(prev=1)->4
	if((*head)->next)
			(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}
