/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:58:36 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/18 13:00:28 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
