/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:34:33 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/17 23:36:53 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "../inc/push_swap.h"

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
	{
		tmp->to_top = ++i;
		tmp->pos = j++;
		tmp = tmp->next;
	}
	if (len % 2 != 0)
		i++;
	i *= -1;
	while (tmp)
	{
		tmp->to_top = ++i;
		tmp->pos = j++;
		tmp = tmp->next;
	}
}

