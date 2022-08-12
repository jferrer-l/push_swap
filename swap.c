/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:05:10 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/16 23:17:38 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	sa(t_data *data)
{
	int	temp;
	int	temp2;

	temp = data->a[0];
	temp2 = data->ia[0];
	data->a[0] = data->a[1];
	data->ia[0] = data->ia[1];
	data->a[1] = temp;
	data->ia[1] = temp2;
	write(1, "sa\n", 3);
}

void	sb(t_data *data)
{
	int	temp;
	int	temp2;

	temp = data->b[0];
	temp2 = data->ib[0];
	data->b[0] = data->b[1];
	data->ib[0] = data->ib[1];
	data->b[1] = temp;
	data->ib[1] = temp2;
	write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	bsa(data);
	bsb(data);
	write(1, "ss\n", 3);
}

int	sort_size_3(t_data *d)
{
	if (d->sia == 3)
	{
		if (d->a[1] > d->a[2] && d->a[1] > d->a[0])
		{
			rra(d);
			if (d->a[0] < d->a[2] && d->a[1] < d->a[0])
				sa(d);
		}
		else if (d->a[0] > d->a[1] && d->a[0] > d->a[2])
			ra(d);
		if (d->a[0] > d->a[1] && (d->a[2] > d->a[0] || d->a[1] > d->a[2]))
			sa(d);
	}
	return (d->sia);
}

int	sort_size_5(t_data *d)
{
	int	i;
	int	done;

	i = 0;
	done = 0;
	while (d->sib < 2)
	{
		if (d->ia[0] == 0)
			pb(d);
		else if (d->ia[0] == 1)
			pb(d);
		else
			ra(d);
	}
	sort_size_3(d);
	if (d->ib[0] < d->ib[1])
		sb(d);
	pa(d);
	pa(d);
	return (d->sia);
}
