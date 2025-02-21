/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:44:08 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/21 16:11:05 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	plus_plus(t_stack *stk, int num_a, int num_b, int tmp)
{
	int	index_a = calculate_index(stk->a, num_a);
	int	index_b = calculate_index(stk->b, num_b);

	while (index_a > 0 && index_b > 0)
	{
		swap_step("rr", stk);
		index_a--;
		index_b--;
	}
	while (index_b > 0)
	{
		swap_step("rb", stk);
		index_b--;
	}
	while (index_a > 0)
	{
		swap_step("ra", stk);
		index_a--;
	}
	if (tmp == 0)
		swap_step("pb", stk);
	else
		swap_step("pa", stk);
}

void	minus_plus(t_stack *stk, int num_a, int num_b, int tmp)
{
	int	index_a = calculate_index(stk->a, num_a);
	int	index_b = calculate_index(stk->b, num_b);

	while (index_a < list_len(stk->a))
	{
		swap_step("rra", stk);
		index_a++;
	}
	while (index_b > 0)
	{
		swap_step("rb", stk);
		index_b--;
	}
	if (tmp == 0)
		swap_step("pb", stk);
	else
		swap_step("pa", stk);
}

void	plus_minus(t_stack *stk, int num_a, int num_b, int tmp)
{
	int	index_a = calculate_index(stk->a, num_a);
	int	index_b = calculate_index(stk->b, num_b);

	while (index_b < list_len(stk->b))
	{
		swap_step("rrb", stk);
		index_b++;
	}
	while (index_a > 0)
	{
		swap_step("ra", stk);
		index_a--;
	}
	if (tmp == 0)
		swap_step("pb", stk);
	else
		swap_step("pa", stk);
}

void	minus_minus(t_stack *stk, int num_a, int num_b, int tmp)
{
	int	index_a = calculate_index(stk->a, num_a);
	int	index_b = calculate_index(stk->b, num_b);

	while (index_a < list_len(stk->a) && index_b < list_len(stk->b))
	{
		swap_step("rrr", stk);
		index_a++;
		index_b++;
	}
	while (index_a < list_len(stk->a))
	{
		swap_step("rra", stk);
		index_a++;
	}
	while (index_b < list_len(stk->b))
	{
		swap_step("rrb", stk);
		index_b++;
	}
	if (tmp == 0)
		swap_step("pb", stk);
	else
		swap_step("pa", stk);
}
