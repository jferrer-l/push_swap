/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:09:54 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/12 19:00:48 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ra(t_data *data)
{
	int	temp;
	int	temp2;
	int	count;

	temp = data->a[0];
	temp2 = data->ia[0];
	count = -1;
	while (++count < (data->sia - 1))
	{
		data->a[count] = data->a[count + 1];
		data->ia[count] = data->ia[count + 1];
	}
	data->a[data->sia - 1] = temp;
	data->ia[data->sia - 1] = temp2;
	write(1, "ra\n", 3);
}

void	rb(t_data *data)
{
	int	temp;
	int	temp2;
	int	count;

	temp = data->b[0];
	temp2 = data->ib[0];
	count = -1;
	while (++count < (data->sib - 1))
	{
		data->b[count] = data->b[count + 1];
		data->ib[count] = data->ib[count + 1];
	}
	data->b[data->sib - 1] = temp;
	data->ib[data->sib - 1] = temp2;
	write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	bra(data);
	brb(data);
	write(1, "rr\n", 3);
}
