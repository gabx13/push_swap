/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:56:43 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/22 20:13:01 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack, FILE *o, char s)
{
	t_node	*tmp;

	tmp = stack;
	if (tmp)
	{
		while (tmp->next != NULL )
		{
			fprintf(o, "	stack %c:%i,	index:%d,	to top:%d, price:%d, pos:%d, target_pos:%d\n",s, tmp->data, tmp->index, tmp->to_top, tmp->price, tmp->pos, tmp->target_pos);
			tmp = tmp->next;
		}
		fprintf(o, "	stack %c:%i,	index:%d,	to top:%d,	price:%d, pos:%d, target_pos:%d\n",s, tmp->data, tmp->index, tmp->to_top, tmp->price, tmp->pos, tmp->target_pos);
	}
}

void printer(t_node *stack_a, t_node *stack_b, char* ba)
{
	if (stack_a == NULL)
	{
		FILE *log = fopen("log.txt", "w");
		fprintf(log, "");
		fclose(log);
		return ;
	}
	FILE *log = fopen("log.txt", "a");

	fprintf(log, "\t%s\nA:\n", ba);
	print_stack(stack_a, log, 'A');
	fprintf(log, "\nB:\n");
	print_stack(stack_b, log, 'B');
	fprintf(log, "\n\n");
	fclose(log);
}
