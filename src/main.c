/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:34:51 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/18 00:12:06 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "inc/push_swap.h"

void	free_list(char **list)
{
	int	i;

	if (list == NULL)
		return ;
	i = 0;
	while (list[i] != NULL)
	{
		// if (list[i] == NULL)
		// 	break ;
		// printf("--------free list NR:%i\n", i);
		free(list[i]);
		list[i] = NULL;
		i++;
	}
	free(list);
	list = NULL;
}

int	check_duplicate(int *list, int num, int n)
{
	if (!list)
	{
		// ft_printf("!list or !num");
		return (0);
	}
	if (n == 1)
	{
		// ft_printf("only one or first arg\n");
		return(1);
	}
	while (1 < n)
	{
		if (list[--n] == num)
			return (0);
	}
	return (1);
}

// int	additional_check_numb(char *number)
// {
// 	int	i;

// 	i = 0;
// 	if (number[0] == ' ' && number[1] == '\0')
// 		return (0);
// 	return (1);
// }

// int	ft_strcmp(char *s1, char *s2)
// {
// 	while (*s1 && *s2)
// 	{
// 		if (*s1 != *s2)
// 			return (*s1 - *s2);
// 		s1++;
// 		s2++;
// 	}
// 	return (*s1 - *s2);
// }

int	correct_numb(char *number)
{
	size_t	i;

	if (!number)
		return (0);
	i = 0;
	if ((number[i] == '-' || number[i] == '+') && number[i + 1] != 0)
		i++;
	while (number[i] && ft_isdigit(number[i]) && ((!number[i]) == '\0'))
		i++;
	// printf("NUMBER:%s\n", number);
	if ((ft_strlen(number) == i) && ft_strlen(number) != 0)// && additional_check_numb(number))
	{
		// printf("correct number\n");
		return (1);
	}
	else
	{
		// printf("wrong number\n");
		return (0);
	}
}



int *check_list(char **list)
{
	int		*int_list;
	int		lsize;
	int		i;
	long	ch_nmb;

	if (!list || list[0] == NULL)
		return ((int *)0);
	lsize = 0;
	while (list[lsize])
	{
		lsize++;
	}
	// printf("list size to be created: %i\n", lsize);
	int_list = malloc((lsize + 1) * sizeof(int));
	if (!int_list)
		return (0);
	int_list[0] = lsize; //write list size to first entry
	i = 0;
	while (list[i] != NULL && correct_numb(list[i]))
	{
		ch_nmb = ft_atol(list[i]);
		if (ch_nmb > INT_MAX || ch_nmb < INT_MIN)
		{
			// ft_printf("MIN/MAX number exceeded\n");
			return ((int *)0);
			// error(*list);
		}
		int_list[i + 1] = (int)ch_nmb;
		// int_list[i + 1] = ft_atoi(list[i]);
		if (!check_duplicate(int_list, int_list[i + 1], i + 1))
		{
			// ft_printf("Duplicate found\n");
			return (free(int_list), free_list(list), (int *)0);
		}
		i++;
		// ft_printf("added to list %i on %i position\n", int_list[i], i);
	}
	if (lsize != i)
	{
		// ft_printf("Error in list\n");
		return(free(int_list), free_list(list), (int *)0);
	}
	// printf("check list: %i\n", i);

	return(int_list);
}

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

void printer(t_node *stack_a, t_node *stack_b, char* ba)
{
	if (stack_a == NULL || stack_b == NULL)
	{
		FILE *log = fopen("log.txt", "w");		//write in log
		fprintf(log, "");						//write in log
		fclose(log);							//write in log
		return ;
	}
	FILE *log = fopen("log.txt", "a");		//write in log
	// print_stack(stack_a, log);				//write in log
	// sort3(&stack_a);
	fprintf(log, "\t%s\nA:\n", ba);					//write in log
	print_stack(stack_a, log, 'A');				//write in log
	fprintf(log, "\nB:\n");					//write in log
	print_stack(stack_b, log, 'B');				//write in log
	fprintf(log, "\n\n");					//write in log
	fclose(log);							//write in log
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
	// int ss = 4;
	printer(NULL, NULL, 0);
	printer(stack_a, stack_b, "start");
	while (stack_b->next->next)
	{
		calc_position(&stack_b);
		calc_position(&stack_a);
		printer(stack_a, stack_b, "before move");
		get_price(&stack_a, &stack_b);
		make_move(&stack_a, &stack_b);
		printer(stack_a, stack_b, "after move");
	}

	// int sa = 0;
	// int sb = 0;
	// printf("index to use first:a%d, b%d\n", find_index_w_lowest_price(stack_a, &sa), find_index_w_lowest_price(stack_b, &sb));
	// printf("sa:%d, sb:%d\n", sa, sb);
	// printf("position of next move:%d\n", get_next_move(stack_a, stack_b));



	// printf("\nLAST NODE IDX:%d\n", last_node_idx(stack_b));
	free_list(list);
	if (stack_a != NULL)
		free_stack(stack_a);
	if (stack_b != NULL)
		free_stack(stack_b);
	return (0);
}
