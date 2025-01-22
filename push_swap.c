/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:13:01 by yozlu             #+#    #+#             */
/*   Updated: 2025/01/22 18:22:26 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void swap_step(char *str, t_stack *stk)
{
    if (ft_strncmp(str, "sa", 2) == 0|| ft_strncmp(str, "ss", 2) == 0)
        stk->a = step_ss(stk->a);
    else if (ft_strncmp(str, "sb", 2) == 0|| ft_strncmp(str, "ss", 2) == 0)
        stk->b = step_ss(stk->b);
    else if (ft_strncmp(str, "pa", 2) == 0)
        stk->a = push_a(stk); 
    else if (ft_strncmp(str, "pb", 2) == 0)
        stk->b = push_b(stk);
    else if (ft_strncmp(str, "ra", 2) == 0)
        stk->a = rotate_ab(stk->a);
    else if (ft_strncmp(str, "rb", 2) == 0)
        stk->b = rotate_ab(stk->b);
    else if (ft_strncmp(str, "rra", 3) == 0|| ft_strncmp(str, "rrr", 2) == 3)
        stk->a = rev_rotate_ab(stk->a);
    else if (ft_strncmp(str, "rrb", 3) == 0|| ft_strncmp(str, "rrr", 2) == 3)
        stk->b = rev_rotate_ab(stk->b);
}

t_node *addValue(t_node *node, int data)
{
    if (node == NULL)
    {
        node = malloc(sizeof(t_stack));  
        if (node == NULL)
            return NULL;
        node->data = data;
        node->next = NULL;
        return node;    
    }   
    t_node *temp = node;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = malloc(sizeof(t_stack));
    temp->next->data = data;
    temp->next->next = NULL;
    return node;     
}
void display(t_node *node)
{
    t_node *temp = node;
    while (temp != NULL )
    {
        printf("%d\n", temp->data);
        temp = temp->next;     
    }
}
int main(int argc, char **argv)
{
    t_stack *stk;
    int i;
    
    stk = malloc(sizeof(t_stack));
    stk->a = NULL;
    stk->b = NULL;
    i = 1;
    if (argc == 2) {
        argv = ft_split(argv[1], ' ');   
        i = 0;  
    }
    while (argv[i])
    { 
            stk->a = addValue(stk->a, ft_atoi(argv[i]));
            i++;
    }
    swap_step("rra", stk);      
    display(stk->a);    
    //display(stk->b);     
}
