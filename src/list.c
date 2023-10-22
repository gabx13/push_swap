/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:58:36 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/22 19:55:24 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int *list, int num, int n)
{
	if (!list)
		return (0);
	if (n == 1)
		return (1);
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
	if ((ft_strlen(number) == i) && ft_strlen(number) != 0)
		return (1);
	else
		return (0);
}

int	*check_int_list(char **list, int lsize)
{
	int		*int_list;
	int		i;
	long	ch_nmb;

	int_list = malloc((lsize + 1) * sizeof(int));
	if (!int_list)
		return (0);
	int_list[0] = lsize;
	i = 0;
	while (list[i] != NULL && correct_numb(list[i]))
	{
		ch_nmb = ft_atol(list[i]);
		if (ch_nmb > INT_MAX || ch_nmb < INT_MIN)
			return (free_list(list), free(int_list), (int *)0);
		int_list[i + 1] = (int)ch_nmb;
		if (!check_duplicate(int_list, int_list[i + 1], i + 1))
			return (free(int_list), free_list(list), (int *)0);
		i++;
	}
	if (lsize != i)
		return (free(int_list), free_list(list), (int *)0);
	return (int_list);
}

int	*check_list(char **list)
{
	int		lsize;

	if (!list || list[0] == NULL)
		return ((int *)0);
	lsize = 0;
	while (list[lsize])
		lsize++;
	return (check_int_list(list, lsize));
}
