/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:48:08 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/26 13:05:36 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_index(t_node *node, int data)
{
	int		i;
	t_node	*temp;

	temp = node;
	i = 0;
	while (temp && temp->data != data)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	list_len(t_node *node)
{
	int	count;

	count = 0;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return (count);
}

int	list_op_add(t_stack *stk, char **av)
{
	int	i;

	i = -1;
	while (av[++i])
		stk->a = add_value(stk->a, ft_atoi(av[i]));
	if (i == 1)
		return (1);
	else if (i == 2)
	{
		swap_step("sa", stk);
		return (1);
	}
	else if (i == 3)
	{
		sorter_3(stk);
		return (1);
	}
	return (0);
}

void	sorter_3(t_stack *stk)
{
	int	a;
	int	b;
	int	c;

	a = stk->a->data;
	b = stk->a->next->data;
	c = stk->a->next->next->data;
	if (a > b && b > c)
	{
		swap_step("sa", stk);
		swap_step("rra", stk);
	}
	else if (a > c && c > b)
		swap_step("ra", stk);
	else if (a > b && a < c)
		swap_step("sa", stk);
	else if (b > c && c > a)
	{
		swap_step("sa", stk);
		swap_step("ra", stk);
	}
	else if (a < b && a > c)
		swap_step("rra", stk);
}

int	is_sorted(t_stack *stk)
{
	t_node	*temp;

	temp = stk->a;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}
