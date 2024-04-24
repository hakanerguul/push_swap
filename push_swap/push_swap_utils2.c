/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aergul <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 03:15:21 by aergul          #+#    #+#             */
/*   Updated: 2022/09/08 03:15:24 by aergul         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_together(t_data *stack1, t_data *stack2, int control)
{
	if (control == 0)
	{
		swap_sa_or_sb(stack1, 1);
		swap_sa_or_sb(stack2, 1);
		write(1, "ss\n", 3);
	}
}

void	rotate_together(t_data *stack1, t_data *stack2, int control)
{
	if (control == 0)
	{
		rotate_ra_or_rb(stack1, 1);
		rotate_ra_or_rb(stack2, 1);
		write(1, "rr\n", 3);
	}
}

void	rev_rotate_together(t_data *stack1, t_data *stack2, int control)
{
	if (control == 0)
	{
		rev_rotate_rra_or_rrb(stack1, 1);
		rev_rotate_rra_or_rrb(stack2, 1);
		write(1, "rrr\n", 4);
	}
}
