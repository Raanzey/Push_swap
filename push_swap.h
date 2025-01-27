/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:15:29 by yozlu             #+#    #+#             */
/*   Updated: 2025/01/27 14:35:51 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../Push_swap/libft/libft.h"
# include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
}t_node;

typedef struct stack
{
    t_node *a;
    t_node *b;
}t_stack;


t_node *push_b(t_stack *stk);
t_node *push_a(t_stack *stk);
t_node *rotate_ab(t_node *node);
t_node *rev_rotate_ab(t_node *node);

t_node *addValue(t_node *node, int data);
t_node *step_ss(t_node *node);
void display(t_node *node);
void check(char **data);
#endif