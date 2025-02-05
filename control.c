/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:41:06 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/05 16:37:13 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	error(char **data)
{
	free_argv(data);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
	
}
void	check(char **data)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (data[i])
	{
		j = 0;
		if (data[i][j] == '+' || data[i][j] == '-')
			j++;
		while (data[i][j])
		{
			if (ft_isdigit(data[i][j]) == 0)
				error(data);
			j++;
		}
		if (ft_atol(data[i]) > 2147483647 || ft_atol(data[i]) < -2147483648)
			error(data);
		temp = ft_atol(data[i]);
		if (ft_strcmp(ft_itoa(temp), data[i]) != 0 && (data[i][0] != '+'&& data[i][0] != '-'))
			error(data);
		i++;
	}
	check_last(data);
}

void	check_last(char **data)
{
	int	i;
	int j;

	i = -1;
	while (data[++i])
	{
		j = i + 1;
		while (data[j])
		{
			if (ft_strcmp(data[i], data[j++]) == 0)
				error(data);	
		}	
	}
	i = 0;
	while (data[i + 1])
	{		
			if ((ft_atol(data[i]) > ft_atol(data[i + 1])))
				return ;
		i++;
	}
	if (i > 0)
		exit(0);
}
