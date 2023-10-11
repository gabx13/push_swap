/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:34:51 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/11 17:53:38 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

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
		printf("--------free list NR:%i\n", i);
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
		return (printf("!list or !num"), 0);
	if (n == 1)
		return(printf("only one or first arg\n"), 1);
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
	printf("NUMBER:%s\n", number);
	if ((ft_strlen(number) == i) && ft_strlen(number) != 0)// && additional_check_numb(number))
		return (printf("correct number\n"), 1);
	else
		return (printf("wrong number\n"), 0);
}

int *check_list(char **list)
{
	int	*int_list;
	int	lsize;
	int	i;

	if (!list || list[0] == NULL)
		return ((int *)0);
	lsize = 0;
	while (list[lsize])
	{
		lsize++;
	}
	printf("list size to be created: %i\n", lsize);
	int_list = malloc((lsize + 1) * sizeof(int));
	if (!int_list)
		return (0);
	int_list[0] = lsize; //write list size to first entry
	i = 0;
	while (list[i] != NULL && correct_numb(list[i]))
	{
		int_list[i + 1] = ft_atoi(list[i]);
		if (!check_duplicate(int_list, int_list[i + 1], i + 1))
			return (ft_printf("Duplicate found\n"), free(int_list), free_list(list), (int *)0);
		i++;
		ft_printf("added to list %i on %i position\n", int_list[i], i);
	}
	if (lsize != i)
		return(ft_printf("Error in list\n"), free(int_list), free_list(list), (int *)0);
	printf("check list: %i\n", i);

	return(int_list);
}

int	main(int argc, char *argv[])
{
	t_node	*stack;
	char	**list;
	int		i;

	if (argc < 2 || !argv[1][0])
		return(ft_printf("Error\n"), 0);

	else if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
	}
	else
	{
		list = (char **)malloc((argc + 1) * sizeof(char *));
		if (list == NULL)
			return (11);
		i = 0;
		while (i < argc - 1)
		{
			printf("len argv:%lu\n", strlen(argv[i + 1]));
			list[i] = ft_strdup_ps(argv[i + 1], ft_strlen(argv[i + 1]));
			i++;
		}
		list[i] = NULL;
	}

	if (!(stack = stack_init(check_list(list))))
		return(printf("Exit error\n"), 13);
	free_list(list);
	free_stack(stack);
	return (0);
}
