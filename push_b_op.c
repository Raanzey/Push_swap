/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:44:08 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/15 17:17:42 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void plus_plus(t_stack *stk, int num_a, int num_b, int tmp)//+ +
{
	int index_a;
	int index_b;
	index_a = calculate_index(stk->a, num_a) + 1;
	index_b = calculate_index(stk->b, num_b) + 1;
	if (index_a < index_b)
	{
		while (--index_a > 0)
			swap_step("rr",stk);
		while (--index_b > 0)
			swap_step("rb", stk);
	}
	else if (index_a > index_b)
	{
		while (--index_b > 0)
			swap_step("rr",stk);
		while (--index_a > 0)
			swap_step("ra", stk);
	}
	else
		while (--index_a > 0 && --index_b > 0)
			swap_step("rr",stk);
	if (tmp == 0)
		swap_step("pb", stk);
	else	
		swap_step("pa", stk);			
}
void minus_plus(t_stack *stk, int num_a, int num_b, int tmp)//- +
{
	int index_a;
	int index_b;
	index_a = calculate_index(stk->a, num_a) - 1;
	index_b = calculate_index(stk->b, num_b) + 1;
	while (++index_a != list_len(stk->a))
		swap_step("rra", stk);
	if (++index_a == list_len(stk->a))
		swap_step("rra", stk);
	while (--index_b > 0)
		swap_step("rb", stk);
	if (tmp == 0)
		swap_step("pb", stk);
	else	
		swap_step("pa", stk);		
}
void plus_minus(t_stack *stk, int num_a, int num_b, int tmp)//+ -
{
	int index_a;
	int index_b;
	index_a = calculate_index(stk->a, num_a) + 1;
	index_b = calculate_index(stk->b, num_b) - 1;
	while (++index_b != list_len(stk->b))
		swap_step("rrb", stk);
	if (++index_b == list_len(stk->b))
		swap_step("rrb", stk);		
	while (--index_a > 0)
		swap_step("ra", stk);
	if (tmp == 0)
		swap_step("pb", stk);
	else	
		swap_step("pa", stk);	
}
void minus_minus(t_stack *stk, int num_a, int num_b, int tmp)//- -
{
	int index_a;
	int index_b;
	index_a = calculate_index(stk->a, num_a) - 1;
	index_b = calculate_index(stk->b, num_b) - 1;
	if (index_b < index_a)
	{
		while (++index_b < list_len(stk->b))
			swap_step("rrr",stk);
		while (++index_a < list_len(stk->a))
			swap_step("rra", stk);
	}
	else if (index_b > index_a)
	{
		while (++index_a < list_len(stk->a))
			swap_step("rrr",stk);
		while (++index_b < list_len(stk->b))
			swap_step("rrb", stk);
	}
	else
		while (--index_a > list_len(stk->a) && --index_b > list_len(stk->b))
			swap_step("rr",stk);
	if (tmp == 0)
		swap_step("pb", stk);
	else	
		swap_step("pa", stk);		
}