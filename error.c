/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:05:27 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/19 16:53:43 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack_node **a, char **argv)
{
	free_stack(a);
	free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int error_repeat(t_stack_node *stack, int n)
{
	if (NULL == stack)
		return (0);
	while (stack)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next; 
	}
	return (0);
}

int error_syntax(char *str_n)
{
	//comprobar si NO es "+" o '-'
	if(!(*str_n == '+'
				|| *str_n == '-'
				|| (*str_n >= '0' && *str_n <= '9')))
		return (1); //si no ningun de esos retorna 1 inicando error de sintaxis
	if((*str_n == '+' 
				|| *str_n == '-')
			&& !(str_n[1] >= '0' && str_n[1] <= '9'))
			return (1);
	while(*++str_n) //pre-incremento, Incrementa el puntero (str_n) antes de usar su valor.
	{
		if ((str_n[1]>= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);

}
