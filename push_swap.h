/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:27:18 by anamedin          #+#    #+#             */
/*   Updated: 2024/06/10 10:39:37 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

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

#endif
