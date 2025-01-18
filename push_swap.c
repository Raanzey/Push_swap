/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:13:01 by yozlu             #+#    #+#             */
/*   Updated: 2025/01/18 17:42:51 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	count;

	i = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		count = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = 0;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	result *= count;
	return (result);
}

t_stack swap_step(char *str)
{
    if ()
    {
        /* code */
    }
    
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
    if (node == NULL)
        return NULL;
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
int main(int argc, char const **argv)
{
    t_stack *stk;
    int i;
    
    stk = malloc(sizeof(t_stack));
    stk->a = NULL;
    stk->b = NULL;
    i = 1;
    if (argc < 2)
        printf("\n");
    if (argc > i) {
        while (argv[i])
        { 
            stk->a = addValue(stk->a, ft_atoi(argv[i])); 
            i++;
        }
    }
    display(stk->a);     
}
