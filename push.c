/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:09:05 by jferrer-          #+#    #+#             */
/*   Updated: 2022/10/10 02:12:37 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_data_2(int size, t_data *d);

void	pa(t_data *data)
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
	data->sib--;
	count = data->sia;
	data->sia++;
	while (--count >= 0)
	{
		data->a[count + 1] = data->a[count];
		data->ia[count + 1] = data->ia[count];
	}
	data->a[0] = temp;
	data->ia[0] = temp2;
	write(1, "pa\n", 3);
}

void	pb(t_data *data)
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
	data->sia--;
	count = data->sib;
	data->sib++;
	while (--count >= 0)
	{
		data->b[count + 1] = data->b[count];
		data->ib[count + 1] = data->ib[count];
	}
	data->b[0] = temp;
	data->ib[0] = temp2;
	write(1, "pb\n", 3);
}

int	init_data(int argc, char **argv, t_data *d)
{
	int	i;

	d->a = (int *)malloc(sizeof(int) * (argc - 1));
	d->b = (int *)malloc(sizeof(int) * (argc - 1));
	d->ia = (int *)malloc(sizeof(int) * (argc - 1));
	d->ib = (int *)malloc(sizeof(int) * (argc - 1));
	if ((!d->a || !d->b || !d->ia || !d->ib) && !freedata(d))
		exit(-1);
	d->sib = 0;
	d->sia = 0;
	d->rbiq = 0;
	i = -1;
	while (++i < (argc - 1))
	{
		if (ft_isdigit(argv[i + 1]) == -1 || *argv[i + 1] == '\0')
			error(d);
		d->a[i] = ft_atoi(argv[i + 1], d);
		d->sia++;
	}
	init_data_2(argc - 1, d);
	return (1);
}

void	init_data_2(int size, t_data *d)
{
	int	low;
	int	cont;
	int	cont2;
	int	lowpos;

	cont = -1;
	while (++cont < size)
		d->ia[cont] = -1;
	cont = -1;
	while (++cont < size)
	{
		low = 2147483647;
		cont2 = -1;
		while (++cont2 < size)
		{
			if (d->a[cont2] < low && d->ia[cont2] == -1)
			{
				low = d->a[cont2];
				lowpos = cont2;
			}
		}
		d->ia[lowpos] = cont;
	}
}

void	fix_lap1(t_data *d)
{
	if (!is_sorted(d))
		return ;
	if (d->sia == 2 && d->ia[0] > d->ia[1])
		sa(d);
	else if (d->sia == 3)
		sort_size_3(d);
	else if (d->sia == 4)
		sort_size_5(d, 1);
	else if (d->sia == 5)
		sort_size_5(d, 2);
	else
		while (d->sia > 0)
			pb(d);
}
