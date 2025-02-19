/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:13:01 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/18 14:43:13 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_step(char *str, t_stack *stk)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "ss") == 0)
		stk->a = step_ss(stk->a);
	if (ft_strcmp(str, "sb") == 0 || ft_strcmp(str, "ss") == 0)
		stk->b = step_ss(stk->b);
	if (ft_strcmp(str, "pa") == 0)
		stk->a = push_a(stk);
	if (ft_strcmp(str, "pb") == 0)
		stk->b = push_b(stk);
	if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rr") == 0)
		stk->a = rotate_ab(stk->a);
	if (ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0)
		stk->b = rotate_ab(stk->b);
	if (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrr") == 0)
		stk->a = rev_rotate_ab(stk->a);
	if (ft_strcmp(str, "rrb") == 0 || ft_strcmp(str, "rrr") == 0)
		stk->b = rev_rotate_ab(stk->b);
	ft_putstr(str);
	write(1, "\n", 1);	
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
		ft_putnbr(temp->data);
		write(1, "\n", 1);
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
	if (list_op_add(stk, av, argc, 0) == 0)
		turk_sorter(stk, 0, 0);
    //list_print(stk->a);
    // list_print(stk->b);
	free_list(stk->b);
	free_list(stk->a);
	free_argv(av);
	free(stk);
}
