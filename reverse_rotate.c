/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:21:53 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/12 19:02:05 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	rra(t_data *data)
{
	int	temp;
	int	temp2;
	int	count;

	temp = data->a[data->sia - 1];
	temp2 = data->ia[data->sia - 1];
	count = data->sia - 1;
	while (--count >= 0)
	{
		data->a[count + 1] = data->a[count];
		data->ia[count + 1] = data->ia[count];
	}
	data->a[0] = temp;
	data->ia[0] = temp2;
	write(1, "rra\n", 4);
}

void	rrb(t_data *data)
{
	int	temp;
	int	temp2;
	int	count;

	temp = data->b[data->sib - 1];
	temp2 = data->ib[data->sib - 1];
	count = data->sib - 1;
	while (--count >= 0)
	{
		data->b[count + 1] = data->b[count];
		data->ib[count + 1] = data->ib[count];
	}
	data->b[0] = temp;
	data->ib[0] = temp2;
	write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	brra(data);
	brrb(data);
	write(1, "rrr\n", 4);
}
