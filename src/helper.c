/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:22:12 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/09 22:17:11 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// t_node	*make_node(int num)
// {
// 	t_node	*new_node;

// 	new_node = (t_node *)malloc(sizeof(t_node));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->data = num;
// 	new_node->next = NULL;
// 	return (new_node);
// }

// size_t	ft_strlen_ps(const char *s)
// {
// 	size_t	n;

// 	n = 0;
// 	while (s[n] != '\0')
// 		n++;
// 	return (n);
// }

char	*ft_strdup_ps(const char *s1, int i)
{
	size_t	len;
	char	*dest;

	len = i + 1;
	dest = malloc(len);
	if (dest == NULL)
		return (NULL);
	ft_memmove(dest, s1, len);
	return (dest);
}
