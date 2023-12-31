/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:34:33 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/22 20:37:08 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_data(t_node **tmp, int *i, int *j)
{
	(*tmp)->to_top = ++(*i);
	(*tmp)->pos = (*j)++;
	(*tmp) = (*tmp)->next;
}

void	calc_position(t_node **stack)
{
	t_node	*tmp;
	int		i;
	int		j;
	int		len;

	if (!(stack))
		return ;
	i = -1;
	j = 0;
	tmp = *stack;
	len = stack_len(tmp);
	while (i < (len) / 2)
		write_data(&tmp, &i, &j);
	if (len % 2 != 0)
		i++;
	i *= -1;
	while (tmp)
		write_data(&tmp, &i, &j);
}
