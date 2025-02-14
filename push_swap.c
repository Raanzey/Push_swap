/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:13:01 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/14 15:19:07 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap_step(char *str, t_stack *stk)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "ss") == 0)
		stk->a = step_ss(stk->a);
	else if (ft_strcmp(str, "sb") == 0 || ft_strcmp(str, "ss") == 0)
		stk->b = step_ss(stk->b);
	else if (ft_strcmp(str, "pa") == 0)
		stk->a = push_a(stk);
	else if (ft_strcmp(str, "pb") == 0)
		stk->b = push_b(stk);
	else if (ft_strcmp(str, "ra") == 0)
		stk->a = rotate_ab(stk->a);
	else if (ft_strcmp(str, "rb") == 0)
		stk->b = rotate_ab(stk->b);
	else if (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrr") == 0)
		stk->a = rev_rotate_ab(stk->a);
	else if (ft_strcmp(str, "rrb") == 0 || ft_strcmp(str, "rrr") == 0)
		stk->b = rev_rotate_ab(stk->b);
}

t_node	*addValue(t_node *node, int data)
{
	t_node	*temp;

	if (node == NULL)
	{
		node = malloc(sizeof(t_node));
		if (node == NULL)
			return (NULL);
		node->data = data;
		node->next = NULL;
		return (node);
	}
	temp = node;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = malloc(sizeof(t_node));
	if (temp->next == NULL)
		return (node);
	temp->next->data = data;
	temp->next->next = NULL;
	return (node);
}
void	list_print(t_node *node)
{
	t_node	*temp;

	temp = node;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}
int	main(int argc, char **argv)
{
	t_stack	*stk;
	char	**av;

	av = split_check(argc, argv);
	check(av);
	stk = malloc(sizeof(t_stack));
	stk->a = NULL;
	stk->b = NULL;
	list_op_add(stk, av, argc);
	turk_sorter(stk);
    //list_print(stk->a);
    // list_print(stk->b);
	free_list(stk->b);
	free_list(stk->a);
	free_argv(av);
	free(stk);
}
