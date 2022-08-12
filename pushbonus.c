/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:09:05 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/09 20:47:10 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	bpa(t_data *data)
{
	int	temp;
	int	count;

	temp = data->b[0];
	count = -1;
	while (++count < (data->sib - 1))
		data->b[count] = data->b[count + 1];
	data->sib--;
	count = data->sia;
	data->sia++;
	while (--count >= 0)
		data->a[count + 1] = data->a[count];
	data->a[0] = temp;
}

void	bpb(t_data *data)
{
	int	temp;
	int	count;

	temp = data->a[0];
	count = -1;
	while (++count < (data->sia - 1))
		data->a[count] = data->a[count + 1];
	data->sia--;
	count = data->sib;
	data->sib++;
	while (--count >= 0)
		data->b[count + 1] = data->b[count];
	data->b[0] = temp;
}
