/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:13:01 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/05 16:14:33 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// void	free_list(t_node *node)
// {
//     t_node *temp = node;
//     while (temp != NULL )
//         temp = temp->next;

// 		free(node);
// }
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
void list_print(t_node *node)
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
    //t_stack *stk;
    //int i;
    char **av;
    av = split_check(argc, argv);
    //i = 0;
    check(av);
    // stk = malloc(sizeof(t_stack));
    // stk->a = NULL;
    // stk->b = NULL;
    // while (av[i])
    // { 
    //         stk->a = addValue(stk->a, ft_atoi(av[i]));
    //         i++;
    // }
    //swap_step("rra", stk.a);   
    //list_print(stk->a);
    //free_list(stk->a);    
    //display(stk->b);     
}
