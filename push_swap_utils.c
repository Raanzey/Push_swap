/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:57:21 by yozlu             #+#    #+#             */
/*   Updated: 2025/01/22 19:02:41 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_node *step_ss(t_node *node)
{
    t_node *temp;
    temp = node->next;
    node->next = temp->next;
    temp->next = node;        
    return temp;    
}
t_node *push_b(t_stack *stk)
{
    if (!stk->b)
    {
        stk->b = malloc(sizeof(t_node));
        if (!stk->b)
            return NULL;
        stk->b->next = NULL;
    }
    else
    {
        t_node *first;
        first = malloc(sizeof(t_node));
        if (stk->b)
            return NULL;
        first->next = stk->b;
        stk->b = first;   
    }
    stk->b->data = stk->a->data;
    t_node *temp;
    temp = stk->a;
    stk->a = stk->a->next;
    free(temp);
    return stk->b;
}
t_node *push_a(t_stack *stk)
{
    if (!stk->a)
    {
        stk->a = malloc(sizeof(t_node));
        if (!stk->a)
            return NULL;
        stk->a->next = NULL;
    }
    else
    {
        t_node *first;
        first = malloc(sizeof(t_node));
        if (!first)
            return NULL;
        first->next = stk->a;
        stk->a = first;   
    }
    stk->a->data = stk->b->data;
    t_node *temp;
    temp = stk->b;
    stk->b = stk->b->next;
    free(temp);
    return stk->a;
}
t_node *rotate_ab(t_node *node)
{
    t_node *temp = node->next;
    t_node *last = node;
    while (last->next != NULL )
        last = last->next;        
    last->next = node;     
    node->next = NULL; 
    return temp;   
    
}
t_node *rev_rotate_ab(t_node *node)
{    
    t_node *last = node;
    
    while (last->next != NULL )
    {
        last = last->next;
    }
    
    last->next = node;
  
    node->next = NULL;
    return node;
    // printf("dfsdfdsfdsf\n");
    // t_node *last = node;
    // t_node *temp = malloc(sizeof(t_node));
    // while (last->next != NULL )
    //     last = last->next;
    // temp->data = last->data;
    // temp->next = node;
    // last = NULL;
    // free(last);
    // return temp;
} 
