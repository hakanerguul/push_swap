/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assing_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aergul <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 03:12:39 by aergul          #+#    #+#             */
/*   Updated: 2022/09/08 03:12:57 by aergul         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	number_size(char const *av)
{
	size_t	i;

	i = 0;
	while (*av == ' ' && *av)
		av++;
	while (*av)
	{
		if (*av != ' ' && (*(av + 1) == ' ' || *(av +1) == '\0'))
			i++;
		av++;
	}
	return (i);
}

char	*substrr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return ((char *)ft_calloc(1, 1));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[i + start];
		i++;
	}
	dst[i] = '\0';
	str = dst;
	free(dst);
	return (str);
}

int	atoii(const char *av, t_data *a_stack, t_data *b_stack)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	while (*av == ' ' || (*av >= '\t' && *av <= '\r'))
		av++;
	if (*av == '+' || *av == '-')
	{
		if (*av == '-')
			sign = -1;
		av++;
	}
	while (*av != '\0')
	{
		if (!(*av >= '0' && *av <= '9'))
			error_mes(a_stack, b_stack);
		result = (result * 10) + *av++ - '0';
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			error_mes(a_stack, b_stack);
	}
	return (result * sign);
}

size_t	splitt(char *av, t_data *a, t_data *b, size_t a_i)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (av[i] != '\0')
	{
		while (av[i] == ' ')
			i++;
		j = i;
		while (av[i] && av[i] != ' ')
			i++;
		if (i > j)
		{
			a->array[a->size - a_i - 1] = atoii(substrr(av, j, i - j), a, b);
			a_i++;
		}
	}
	return (a_i);
}

void	assign_to_stack(int ac, char **av, t_data *a_stack, t_data *b_stack)
{
	int		i;
	int		size;
	size_t	array_i;

	i = 0;
	size = 0;
	array_i = 0;
	while (++i < ac)
		size += number_size(av[i]);
	a_stack->array = (int *)malloc(sizeof(int) * size);
	b_stack->array = (int *)malloc(sizeof(int) * size);
	a_stack->size = size;
	b_stack->size = 0;
	if (size == 1)
		atoii(av[1], a_stack, b_stack);
	i = 0;
	while (++i < ac)
		array_i = splitt(av[i], a_stack, b_stack, array_i);
	i = 0;
}
