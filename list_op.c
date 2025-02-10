/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:48:08 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/10 17:11:14 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_op_add(t_stack *stk, char **av, int ac)
{
	int i;
	i = -1;
	while (av[++i])
		stk->a = addValue(stk->a, ft_atoi(av[i]));
	if (ac == 4)
		sorter_3(stk);
	else if (ac == 3)
		sorter_2(stk); 
    swap_step("pb", stk);
    swap_step("pb", stk); 
}
