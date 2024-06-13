/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 09:07:04 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/13 10:18:49 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	error(t_stack_node **a, char **argv)
{
	exit(2);
}

int error_repeat(t_slack_node *a, int n)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next; 
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
