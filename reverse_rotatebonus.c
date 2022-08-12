/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:21:53 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/09 20:54:28 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	brra(t_data *data)
{
	int	temp;
	int	count;

	temp = data->a[data->sia - 1];
	count = data->sia - 1;
	while (--count >= 0)
		data->a[count + 1] = data->a[count];
	data->a[0] = temp;
}

void	brrb(t_data *data)
{
	int	temp;
	int	count;

	temp = data->b[data->sib - 1];
	count = data->sib - 1;
	while (--count >= 0)
		data->b[count + 1] = data->b[count];
	data->b[0] = temp;
}

void	brrr(t_data *data)
{
	brra(data);
	brrb(data);
}
