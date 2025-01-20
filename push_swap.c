/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:13:01 by yozlu             #+#    #+#             */
/*   Updated: 2025/01/20 18:22:50 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// t_stack swap_step(char *str)
// {
//     if (str == "sa" || str == "ss")
//     {
        
//     }
//     else if (str == "sb" || str == "ss")
//     {
//         /* code */
//     }
//     else if (str == "pa")
//     {
//         /* code */
//     }
//     else if (str == "pb")
//     {
//         /* code */
//     }
//     else if (str == "ra" || str == "rr")
//     {
//         /* code */
//     }
//     else if (str == "rb" || str == "rr")
//     {
//         /* code */
//     }
//     else if (str == "rra" || str == "rrr")
//     {
//         /* code */
//     }
//     else if (str == "rrb" || str == "rrr")
//     {
//         /* code */
//     }
// }

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
    display(stk->a);     
}
