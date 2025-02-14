/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:06:38 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/14 17:57:24 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_sorter(t_stack *stk)
{
	int num_a;
	int num_b;
	swap_step("pb", stk);
	if (list_len(stk->a) > 3)
		swap_step("pb", stk);	
	if (list_len(stk->a) > 3)
	{	
		num_a = calculate_num(stk);
		num_b = number_find_b(stk, num_a);
		
		printf("A---->%d\n",num_a);			
		printf("B---->%d\n",num_b);		
	}
}
int calculate_num(t_stack *stk)
{
	int a;
	t_node *temp;

	temp = stk->a;
	while (temp)
	{
		if (number_b(stk,2147483647,0) == calculate_index(stk->a, temp->data))
			a = temp->data;
		temp = temp->next;
	}
	return a;	
}
void plus_plus(t_stack *stk, int index_a, int index_b)
{
	
}
void plus_minus()
{
	
}