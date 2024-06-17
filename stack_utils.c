/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:56:47 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/17 23:47:11 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

//recorremos la pila nodo por nodo comparando cada nodo con el siguiente 
int  stack_sort(t_stack_node *stack)
{
	if (!stack)
		return(TRUE);// devuelve 1 ya que una pila vacia se considera ordenada 
	while(stack->next) // comienza a recorrer la pila nodo por nodo mientras no sea NULL 
	{
		if(stack->value > stack->next->value) // comparamos el valor del nodo actual es mayor que el  siguiente nodo 
			return(FALSE); //si es mayor develve false (0) pila no ordenada 
		stack = stack->next; //avanzar al siguiente nodo 
	}
	return (TRUE);// la pila esta ordenada (1)
}

int stack_len(t_stack_node *stack) // recibe un puntero stack que paunta al primer nodo de la pila 
								   // y deveuelve un entero ue representa el  numero de nodos en la pila 
{
	int count;// para contar los nodos de la pila 

	count = 0;
	if(!stack) //verificamos que la pila es NULL lo que siginifca que la pila esta vacia 
		return(0);
	while(stack)
	{
		stack = stack->next; // avanza al siguiente nodo 
		count++; // se incrementa el contador 
	}
	return(count);// retorna la longiud el numero de nodos en la pila 
}

t_stack_node *find_last_node(t_stack_node *stack)
	// recibe un punero stack que apunta al primer nodo de la pila y devuelve
	// un puntero al ultimo nodo de la pila 
{
	if(!stack)
		return(NULL);
	while(stack->next) // el bucle continua mentras el nodo actual (stack) tnga un siguineete nodo
		stack = stack->next; // avanza al siguiente nodo 
	return (stack);//cuando stack->next es nulo el bucle termina y se devuelve el puntero al ultimo nodo 
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;// para almacenar el valor minimo encontrado 
	t_stack_node	*min_node;// para almacenar el puntero al nodo con el valor minimo 

	if(!stack)
		return(NULL);
	min = LONG_MAX;// se inicializa con LONGMAX 
	while (stack)
	{
		if(stack->value < min) //comparamos 
		{
			min = stack->value; //si stack->value < min se actualiza con stack->value
			min_node = stack; //y se actualiza para apuntar al nodo que contiene el valor incicial
							  //stack es el puntero al nodo actual en el
							  //recorrido 
		}
		stack = stack->next;
	}
	return (min_node);// al final el min apunta alnodo que contiene el valor minimo y min_node apunta un puntero 
					  // que contiene el valor minimo de la pila 
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
