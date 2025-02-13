/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:48:08 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/13 19:17:25 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calculate_index(t_node *node, int data)
{
	int i;
	t_node *temp;
	temp = node;
	i = 0;
	while (temp && temp->data != data)
	{
		i++;
		temp = temp->next;
	}
	return i;	
}
int list_len(t_node *node)
{
	int count;
	count = 0;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return count;
}
void	list_op_add(t_stack *stk, char **av, int ac)
{
	int i;
	i = -1;
	while (av[++i])
		stk->a = addValue(stk->a, ft_atoi(av[i]));
	if (ac == 4)
		sorter_3(stk);
	else if (ac == 3)
		swap_step("sa", stk); 
}
void	sorter_3(t_stack *stk)
{
	int	a;
	int	b;
	int	c;

	a = stk->a->data;
	b = stk->a->next->data;
	c = stk->a->next->next->data;
	if (a > b && b < c && a < c) // 2 1 3
		swap_step("sa", stk);
	else if (a > b && b > c) // 3 2 1
	{
		swap_step("sa", stk);
		swap_step("rra", stk);
	}
	else if (a > b && b < c && a > c) // 3 1 2
		swap_step("ra", stk);
	else if (a < b && b > c && a < c) // 1 3 2
	{
		swap_step("sa", stk);
		swap_step("ra", stk);
	}
	else if (a < b && b > c && a > c) // 2 3 1
		swap_step("rra", stk);
}
