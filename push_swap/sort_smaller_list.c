/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smaller_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aergul <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 03:16:59 by aergul          #+#    #+#             */
/*   Updated: 2022/09/08 03:17:04 by aergul         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	triple_list(t_data *a)
{
	if (!(a->array[0] > a->array[1] && a->array[0] > a->array[2]))
	{
		if (a->array[1] > a->array[2])
			rev_rotate_rra_or_rrb(a, 0);
		else if (a->array[2] > a->array[1])
			rotate_ra_or_rb(a, 0);
	}
	if (a->array[2] > a->array[1])
		swap_sa_or_sb(a, 0);
}

void	quartet_list(t_data *a, t_data *b)
{
	if (a->array[3] != 0)
	{
		if (a->array[2] == 0)
			rotate_ra_or_rb(a, 0);
		else if (a->array[1] == 0)
		{
			rev_rotate_rra_or_rrb(a, 0);
			rev_rotate_rra_or_rrb(a, 0);
		}
		else if (a->array[0] == 0)
			rev_rotate_rra_or_rrb(a, 0);
	}
	push_pa_or_pb(a, b, 0);
	triple_list(a);
	push_pa_or_pb(b, a, 0);
}

void	quintuple_list(t_data *a, t_data *b)
{
	int	i;

	i = 4;
	while (i > 2)
	{
		if (a->array[i] == 0 || a->array[i] == 1)
		{
			push_pa_or_pb(a, b, 0);
			i--;
		}
		else
			rotate_ra_or_rb(a, 0);
	}
	if (b->array[0] > b->array[1])
		swap_sa_or_sb(b, 0);
	triple_list(a);
	push_pa_or_pb(b, a, 0);
	push_pa_or_pb(b, a, 0);
}

void	sort_smaller_list(t_data *a, t_data *b)
{
	if (a->size == 2)
		swap_sa_or_sb(a, 0);
	else if (a->size == 3)
		triple_list(a);
	else if (a->size == 4)
		quartet_list(a, b);
	else if (a->size == 5)
		quintuple_list(a, b);
}
