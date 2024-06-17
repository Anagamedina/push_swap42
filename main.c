/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:01:10 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/17 22:53:54 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1);
	if (!stack_sort(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
	}
	free_stack(&a);
}







/*int main(int argc, char **argv)
  //se usa para determinar la cantidad de elemnentos en la pila lo que influye
  //en la eleccion del algoritmo de ordenamineto.
{
  t_stack_node  *a;
  t_stack_node  *b;

  a = NULL;
  b = NULL;
  if (1 == argc || (2 == argc && !argv[1][0])) // pero el primer caracter de la entrada es cero: cadena vacia 
                                               // comprueba si no se han pasado argumentos
                                               //  o si se pasó un único argumento vacío
    return (1);
  else if (2 == argc)
    argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1);
    if (!stack_sort(a)) // significa que la condición se cumple si la pila a NO está ordenada.
                        // true pila ordenada 
                        // false pila desordenada 
    {
      if (stack_len(a) == 2)
        sa(&a);//si no esta ordenada se procede con el algoritmo de ordenamiento
              //depende de la longitud de la pila a se elige un metodo de
              //ordenamiento especifico si tiene 2 argumentos usamos sa swap

      else if (stack_len(a) == 3)
        tiny_sort(&a); // si la pila tiene 3 argumentos, usamos el algorithm para ordenar 3 elementos 

      else
        push_swap(&a, &b);// si la pila tiene mas de 3, usamos el algorith mas complejo para ordenar de MAYOR A MENOR 
    }
    free_stack(&a); //Liberar memoria u otras operaciones al finalizar el programa
}*/
