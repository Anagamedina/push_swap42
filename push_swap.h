/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:27:18 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/17 23:59:36 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H   // directivas de preprocesadores 
                      // para evitar la inclusion multiple del archivo de
                      // cabecera 
#define PUSH_SWAP_H
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


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

//*** Handle input ./push_swap "1 -42 1337" ***
char			**ft_split(char *str, char separator);

//*** Handle errors-free ***
void			free_matrix(char **argv);
void			error_free(t_stack_node **a, char **argv);
int             error_repeat(t_stack_node *stack, int n);
void			free_stack(t_stack_node **stack);
int				error_syntax(char *str_nbr);

//*** Stack creation ***
void			stack_init(t_stack_node **a, char **argv);

//*** linked list utils ***
void			append_node(t_stack_node **stack, int n);
t_stack_node	*find_last_node(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
int			stack_sort(t_stack_node *stack);
int				stack_len(t_stack_node *stack);

//*** Algorithms ***
//void			tiny_sort(t_stack_node **a);
//void			push_swap(t_stack_node **a, t_stack_node **b);

//*** Commands ***
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
#endif
