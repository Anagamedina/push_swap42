/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:27:18 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/15 20:52:15 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H   // directivas de preprocesadores 
                      // para evitar la inclusion multiple del archivo de
                      // cabecera 
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_stack_node
{
  int					value;
  int					current_position;
  int					final_index;
  int					push_price;
  struct s_stack_node	*target_node;
  struct s_stack_node	*prev;
  struct s_stack_node	*next;
}				t_stack_node;

#endif

// Funciones para operaciones básicas de pila
void append_node_last(t_stack_node **stack, int n);
t_stack_node *find_last(t_stack_node *stack);
t_stack_node *find_min(t_stack_node *stack);
t_stack_node *find_max(t_stack_node *stack);
void free_stack(t_stack_node **stack);
int stack_sorted(t_stack_node *stack);
int stack_len(t_stack_node *stack);

// Funciones específicas para el algoritmo Push Swap

//  Funciones de manejo de errores

// Funciones auxiliares
long ft_atol(const char *str);
void stack_init(t_stack_node **a, char **argv);

#endif
