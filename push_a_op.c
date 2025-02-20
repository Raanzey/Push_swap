/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:44:17 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/20 20:06:55 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_find_a(t_stack *stk, int data_b)
{
	int		max;
	int		min;
	t_node	*temp_a;

	temp_a = stk->a;
	max = 2147483647;
	min = 2147483647;
	while (temp_a)
	{
		if (temp_a->data > data_b && temp_a->data < max)
			max = temp_a->data;
		if (temp_a->data < min)
			min = temp_a->data;
		temp_a = temp_a->next;
	}
	if (max != 2147483647)
		return (max);
	return (min);
}
void	sorter_push_a(t_stack *stk, int num_a, int num_b)
{
	int	index_a;
	int	index_b;
	int len_a;
	int len_b;

	len_a = list_len(stk->a);
	len_b = list_len(stk->b);
	if (list_len(stk->a) % 2 == 1)
		len_a = list_len(stk->a) + 1;
	if (list_len(stk->b) % 2 == 1)
		len_b = list_len(stk->b) + 1;		
	index_a = calculate_index(stk->a, num_a);
	index_b = calculate_index(stk->b, num_b);
	if (len_a / 2 > index_a && len_b / 2 > index_b) //+ +
	{
		//printf("+ +\n");
		plus_plus(stk, num_a, num_b, 1);
	}
	else if (len_a / 2 <= index_a && len_b / 2 > index_b)//- +
	{	
		//printf("- +\n");
		minus_plus(stk, num_a, num_b, 1);
	}
	else if (len_a / 2 > index_a && len_b / 2 <= index_b)//+ -
	{	
		//printf("+ -\n");
		plus_minus(stk, num_a, num_b, 1);
	}
	else if (len_a / 2 <= index_a && len_b / 2 <= index_b)//- -
	{
		//printf("- -\n");
		minus_minus(stk, num_a, num_b, 1);
	}
}
int	min_number_a(t_stack *stk)
{
	int		min;
	t_node	*temp;
	
	temp = stk->a;
	min = 2147483647;
	while (temp)
	{
		if (temp->data < min)	
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}
void first_min_number_a(t_stack *stk, int data_a)
{
	int index_a;
	index_a = calculate_index(stk->a,data_a);
	if (list_len(stk->a) / 2 >= index_a)
	{
		while (index_a > 0)
		{
			swap_step("ra", stk);
			index_a--;
		}
	}
	index_a = calculate_index(stk->a,data_a);
	if (list_len(stk->a) / 2 < index_a)
	{
		while (index_a < list_len(stk->a))
		{
			swap_step("rra", stk);
			index_a++;
		}
	}
}
