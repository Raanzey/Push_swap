/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:44:17 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/16 12:52:55 by yozlu            ###   ########.fr       */
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

	index_a = calculate_index(stk->a, num_a);
	index_b = calculate_index(stk->b, num_b);
	if (list_len(stk->a) / 2 > index_a && list_len(stk->b) / 2 > index_b) //+ +
		plus_plus(stk, num_a, num_b, 1);
	else if (list_len(stk->a) / 2 <= index_a && list_len(stk->b) / 2 >= index_b)//- +
		minus_plus(stk, num_a, num_b, 1);
	else if (list_len(stk->a) / 2 >= index_a && list_len(stk->b) / 2 <= index_b)//+ -
		plus_minus(stk, num_a, num_b, 1);
	else if (list_len(stk->a) / 2 <= index_a && list_len(stk->b) / 2 <= index_b)//- -
		minus_minus(stk, num_a, num_b, 1);
}
int	min_number_a(t_stack *stk)
{
	int		min;
	t_node	*temp;
	
	temp = stk->a;
	min = 2147483647;
	//printf("MinSayi-----> %d\n",temp->data);
	while (temp)
	{
		//printf("MinSayi-----> %d\n",min);
		if (temp->data < min)	
			min = temp->data;
		temp = temp->next;
	}
	//printf("MinSayi-----> %d\n",min);
	return (min);
}
void first_min_number_a(t_stack *stk, int data_a)
{
	int index_a;
	index_a = calculate_index(stk->a,data_a);
	if (list_len(stk->a) / 2 >= index_a)
	{
		printf("BURADAA---->\n");
		while (index_a > 0)
		{
			swap_step("ra", stk);
			index_a--;
		}
	}
	index_a = calculate_index(stk->a,data_a);
	if (list_len(stk->a) / 2 < index_a)
	{
		printf("BURADAA---->\n");
		while (index_a < list_len(stk->a))
		{
			swap_step("rra", stk);
			index_a++;
		}
	}
}
