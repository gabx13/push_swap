/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:34:51 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/19 00:29:42 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "inc/push_swap.h"

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
			// printf("len argv:%lu\n", strlen(argv[i + 1]));
			list[i] = ft_strdup_ps(argv[i + 1], ft_strlen(argv[i + 1]));
			i++;
		}
		list[i] = NULL;
	}
	return (list);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**list;

	if (argc < 2 || !argv[1][0])
		return(ft_printf("Error\n"), 0);
	else
	{
		if (!(list = parser(argc, argv)))
			return (1);
	}

	if (!(stack_a = stack_init(check_list(list))))
		return(printf("Error\n"), 0);
	stack_b = NULL;
	assign_index(&stack_a, stack_len(stack_a));
	push_up_three(&stack_a, &stack_b, stack_len(stack_a), 0);

	sort3(&stack_a);
	printer(NULL, NULL, 0);
	// printer(stack_a, stack_b, "start");
	while (stack_b)
	{
		calc_position(&stack_b);
		calc_position(&stack_a);
		get_target_position(&stack_a, &stack_b);
		get_price(&stack_a, &stack_b);
		printer(stack_a, stack_b, "before move");
		// make_move(&stack_a, &stack_b);
		check_make_move(&stack_a, &stack_b);
		printer(stack_a, stack_b, "after move");
	}

	// int sa = 0;
	// int sb = 0;
	// printf("index to use first:a%d, b%d\n", find_index_w_lowest_price(stack_a, &sa), find_index_w_lowest_price(stack_b, &sb));
	// printf("sa:%d, sb:%d\n", sa, sb);
	// printf("position of next move:%d\n", get_next_move(stack_a, stack_b));

	// free_list(list);
	// if (stack_a != NULL)
	// 	free_stack(stack_a);
	// if (stack_b != NULL)
	// 	free_stack(stack_b);
	return (0);
}
