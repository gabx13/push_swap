/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:34:51 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/22 21:18:16 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parser(int argc, char **argv)
{
	char	**list;
	int		i;

	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
	}
	else
	{
		list = (char **)malloc((argc + 1) * sizeof(char *));
		if (list == NULL)
			return (NULL);
		i = 0;
		while (i < argc - 1)
		{
			list[i] = ft_strdup_ps(argv[i + 1], ft_strlen(argv[i + 1]));
			i++;
		}
		list[i] = NULL;
	}
	return (list);
}

void	solve_small(t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_a;
	if (is_sorted(tmp) || stack_len(tmp) == 1)
		return ;
	if (stack_len(tmp) == 3)
		sort3(stack_a);
	else
		action("sa", stack_a, NULL);
}

void	solve_big(t_node **stack_a)
{
	t_node	*stack_b;

	if (is_sorted(*stack_a))
		return ;
	stack_b = NULL;
	push_up_three(stack_a, &stack_b, stack_len(*stack_a), 0);
	sort3(stack_a);
	while (stack_b)
	{
		calc_position(&stack_b);
		calc_position(stack_a);
		get_target_position(stack_a, &stack_b);
		get_price(stack_a, &stack_b);
		check_make_move(stack_a, &stack_b);
	}
	final_turn(stack_a);
	if (stack_b != NULL)
		free_stack(stack_b);
}

void	push_swap(char **list)
{
	t_node	*stack_a;

	stack_a = stack_init(check_list(list));
	if (!stack_a)
	{
		printf("Error\n");
		exit (EXIT_FAILURE);
	}
	free_list(list);
	assign_index(&stack_a, stack_len(stack_a));
	if (stack_len(stack_a) <= 3)
		solve_small(&stack_a);
	else
		solve_big(&stack_a);
	if (stack_a != NULL)
		free_stack(stack_a);
}

int	main(int argc, char *argv[])
{
	char	**list;

	if (argc == 2 && !argv[1][0])
		return (0);
	else
	{
		list = parser(argc, argv);
		if (!list)
			return (1);
	}
	push_swap(list);
	return (0);
}
