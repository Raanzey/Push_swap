/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:06:38 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/19 22:08:59 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_sorter(t_stack *stk, int num_a, int num_b)
{
	// int i;
	// i = 0;
	// printf("A listesi---->\n");
	// list_print(stk->a);
	swap_step("pb", stk);
	if (list_len(stk->a) > 3)
	{
		swap_step("pb", stk);
		while (list_len(stk->a) > 3)
		{	
			num_a = calculate_num(stk);
			//printf("A SAYISI----> %d\n", num_a);
			num_b = number_find_b(stk, num_a);
			//printf("B SAYISI----> %d\n", num_b);
			sorter_push_b(stk, num_a, num_b);
		}
		sorter_3(stk);
		max_number_find_b(stk, stk->b->data);
	}
	while (list_len(stk->b) > 1)
	{
		num_a = number_find_a(stk, stk->b->data);
		// printf("YENİ B SAYISI----> %d\n", stk->b->data);
		// printf("YENİ A SAYISI----> %d\n", num_a);
		sorter_push_a(stk, num_a, stk->b->data);
		//i++;
	}
	if (list_len(stk->b) == 1)
		swap_step("pa", stk);
	if (is_sorted(stk) == 0)
		first_min_number_a(stk, min_number_a(stk));
	//printf("A listesi---->\n");
	//list_print(stk->a);
	//printf("B listesi---->\n");
	//list_print(stk->b);
}
int	calculate_num(t_stack *stk)
{
	int		a;
	t_node	*temp;

	temp = stk->a;
	while (temp)
	{
		if (number_b(stk, 2147483647, 0) == calculate_index(stk->a, temp->data))
			a = temp->data;
		temp = temp->next;
		//printf("NUM_A---->%d\n",a);
	}
	return (a);
}
void	sorter_push_b(t_stack *stk, int num_a, int num_b)
{
	int	index_a;
	int	index_b;

	index_a = calculate_index(stk->a, num_a);
	//printf("İNDEX_A----->%d\n",index_a);
	index_b = calculate_index(stk->b, num_b);
	//printf("İNDEX_B----->%d\n",index_b);
	if (list_len(stk->a) / 2 > index_a && list_len(stk->b) / 2 > index_b) //+ +
		plus_plus(stk, num_a, num_b, 0);
	else if (list_len(stk->a) / 2 <= index_a && list_len(stk->b) / 2 >= index_b)//- +
		minus_plus(stk, num_a, num_b, 0);
	else if (list_len(stk->a) / 2 >= index_a && list_len(stk->b) / 2 <= index_b)//+ -
		plus_minus(stk, num_a, num_b, 0);
	else if (list_len(stk->a) / 2 <= index_a && list_len(stk->b) / 2 <= index_b)//- -
		minus_minus(stk, num_a, num_b, 0);
}
int	number_find_b(t_stack *stk, int data_a)
{
	int min;
	int max;
	int count;
	t_node *temp_b;

	count = 0;
	min = -2147483648;
	max = -2147483648;
	temp_b = stk->b;
	while (temp_b)
	{
		if (temp_b->data < data_a && temp_b->data > min)
		{
			min = temp_b->data;
			count++;
		}
		else if (temp_b->data > data_a && temp_b->data > max)
			max = temp_b->data;
		temp_b = temp_b->next;
	}
	if (count > 0)
		return (min);
	//printf("MAX---->%d\n",max);
	//printf("MİN---->%d\n",min);		
	return (max);
}