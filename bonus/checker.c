/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:39:03 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/25 01:05:48 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	safe_stack_free(t_node **stack)
{
	if (*stack)
		free_stack(*stack);
}

char	*check_command(char *line)
{
	if (ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "sb\n") == 0
		|| ft_strcmp(line, "ss\n") == 0 || ft_strcmp(line, "pa\n") == 0
		|| ft_strcmp(line, "pb\n") == 0 || ft_strcmp(line, "ra\n") == 0
		|| ft_strcmp(line, "rb\n") == 0 || ft_strcmp(line, "rr\n") == 0
		|| ft_strcmp(line, "rra\n") == 0 || ft_strcmp(line, "rrb\n") == 0
		|| ft_strcmp(line, "rrr\n") == 0)
	{
		line[ft_strlen(line) - 1] = '\0';
		return (line);
	}
	else
		return (free(line), NULL);
}

void	next_line(t_node **stack_a, t_node **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		line = check_command(line);
		if (!line)
		{
			ft_printf("Error\n");
			safe_stack_free(stack_a);
			safe_stack_free(stack_b);
			exit(EXIT_FAILURE);
		}
		c_action(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
}

void	checker(char **list)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = stack_init(check_list(list));
	if (!stack_a)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	next_line(&stack_a, &stack_b);
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	safe_stack_free(&stack_a);
	safe_stack_free(&stack_b);
}

int	main(int argc, char **argv)
{
	char	**list;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	list = parser(argc, argv);
	if (!list)
		exit(EXIT_FAILURE);
	checker(list);
	free_list(list);
	return (0);
}
