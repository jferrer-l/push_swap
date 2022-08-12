/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:05:10 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/09 21:01:38 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	bsa(t_data *data)
{
	int	temp;

	temp = data->a[0];
	data->a[0] = data->a[1];
	data->a[1] = temp;
}

void	bsb(t_data *data)
{
	int	temp;

	temp = data->b[0];
	data->b[0] = data->b[1];
	data->b[1] = temp;
}

void	bss(t_data *data)
{
	bsa(data);
	bsb(data);
}
