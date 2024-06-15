/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:02:13 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/15 21:02:24 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>


static long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

void stack_init(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while(argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv);
		n = ft_atol(argv[i]);
		if(n > INT_MAX || n < INT_MIN)
			error_free(a, argv);
		if(error_duplicate(*a, (int)n))
			error_free(a, argv);
		append_node(a(int)n);
		++i;
	}
}
