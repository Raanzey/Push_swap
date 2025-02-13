/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:25:19 by yozlu             #+#    #+#             */
/*   Updated: 2025/02/13 15:11:07 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node *node)
{
	t_node	*temp;

	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
}
void	free_argv(char **argv)
{
	int	i;

	i = -1;
	if (argv)
	{
		while (argv[++i])
			free(argv[i]);
		free(argv);
	}
}
char	**split_check(int argc, char **argv)
{
	char	**av;
	int		i;
	int		j;

	av = NULL;
	i = 1;
	if (argc == 2)
		av = ft_split(argv[1], ' ');
	else
	{
		av = malloc(argc * sizeof(char*));
		if (!av)
			return (NULL);
		j = 0;
		while (argv[i])
		{
			av[j] = ft_strdup(argv[i]);
			if (!av[j])  
                return(free_argv(av),NULL);  
			i++;
			j++;
		}
		av[j] = NULL;
	}
	return (av);
}
long	ft_atol(const char *str)
{
	int		i;
	long	result;
	int		count;

	i = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!str[i + 1])
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		if (str[i] == '-')
			count = -1;
		i++;
	}
	result = 0;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
		result = result * 10 + str[i++] - '0';
	return (result * count);
}
int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str2 == '0')
		str2++;
	while (*str1 == '0')
		str1++;
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}