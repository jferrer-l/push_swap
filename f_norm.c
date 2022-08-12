/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_norm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:11:55 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/16 23:16:12 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	norminette1(t_data *d, int i, int *bool, int temp)
{
	while (d->ib[0] != i)
	{
		if (d->ib[0] == i - 1 && temp == 0)
		{
			bool[0] = 1;
			pa(d);
		}
		if (d->ib[0] == (i - 2))
		{
			bool[1] = 1;
			pa(d);
			ra(d);
		}
		if (d->ib[0] != i)
			rb(d);
	}
}

void	norminette2(t_data *d, int i, int *bool, int temp)
{
	while (d->ib[0] != i)
	{
		if (d->ib[0] == i - 1 && temp == 0)
		{
			bool[0] = 1;
			pa(d);
		}
		if (d->ib[0] == (i - 2))
		{
			bool[1] = 1;
			pa(d);
			ra(d);
		}
		if (d->ib[0] != i)
			rrb(d);
	}
}

int	norminette3(t_data *d, int *bool)
{
	if (bool[0] == 1 && bool[1] == 1)
	{
		sa(d);
		rra(d);
		return (3);
	}
	else if (bool[0] == 1 && bool[1] == 0)
	{
		sa(d);
		return (1);
	}
	else if (bool[1] == 1 && bool[0] == 0)
	{
		if (d->sia > 2 && d->ia[0] > d->ia[1])
			sa(d);
		rra(d);
		return (2);
	}
	return (0);
}

int	norminette4(t_data *d, int count, int size, int part)
{
	if (d->ia[0] < count * (size / part))
	{
		if (d->ia[0] >= (count * (size / part)) - (size / (2 * part)))
		{
			while (d->rbiq > 0)
			{
				d->rbiq--;
				rb(d);
			}
		}
		pb(d);
		if (d->ib[0] < (count * (size / part)) - (size / (2 * part)))
			d->rbiq++;
		return (1);
	}
	else
	{
		if (d->rbiq > 0 && d->rbiq-- > 0)
			rr(d);
		else
			ra(d);
	}
	return (0);
}
