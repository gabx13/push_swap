/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:22:12 by vgabovs           #+#    #+#             */
/*   Updated: 2023/10/11 23:59:26 by vgabovs          ###   ########.fr       */
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

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
