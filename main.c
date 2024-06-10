/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:40:14 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/10 13:03:54 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int main(int argc, char **argv)
{
  t_stack_node  *a;
  t_stack_node  *b;

  a = NULL;
  b = NULL;
  if (1 == argc || (2 == argc && !argv[1][0])) // pero el primer caracter de la entrada es cero: cadena vacia 
    return (1);
  else if (2 == argc)
    argv = ft_split(argv[1], ' ');
  //stack_init(&a, argv )


}
