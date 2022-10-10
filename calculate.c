/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:14:12 by jferrer-          #+#    #+#             */
/*   Updated: 2022/10/10 02:13:08 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		sort_size_3(t_data *d);
void	sort1(t_data *d, int part);
int		rotate(t_data *d, int i, int temp);
int		sort_size_5(t_data *d, int var);

int	is_sorted(t_data *d)
{
	int	i;

	i = 0;
	while (++i < d->sia)
		if (d->ia[i - 1] > d->ia[i])
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (init_data(argc, argv, data) == -1)
		error(data);
	check_duplicates(data);
	if (argc <= 4)
		sort_size_3(data);
	else if (argc == 5 && is_sorted(data))
		sort_size_5(data, 1);
	else if (argc == 6 && is_sorted(data))
		sort_size_5(data, 2);
	else if (argc < 150 && is_sorted(data))
		sort1(data, 5);
	else if (is_sorted(data))
		sort1(data, 7);
	freedata(data);
	return (0);
}

void	sort2(t_data *d)
{
	int	temp;
	int	xd;
	int	va;

	xd = d->sib - 1;
	temp = 0;
	va = 0;
	while (d->sib > 0)
	{
		va = rotate(d, xd, temp);
		temp = 0;
		if (va == 1)
			xd--;
		if (va == 2)
			temp = 1;
		if (va == 3)
			xd -= 2;
		xd--;
	}
}

void	sort1(t_data *d, int part)
{
	int	count;
	int	temp;
	int	size;

	size = d->sia;
	count = 1;
	temp = 0;
	while (count <= part)
	{
		temp += norminette4(d, count, size, part);
		if (temp == count * (size / part))
		{
			while (d->rbiq > 0 && --d->rbiq > -1)
				rb(d);
			count++;
		}
	}
	fix_lap1(d);
	sort2(d);
}

int	rotate(t_data *d, int i, int temp)
{
	int	j;
	int	k;
	int	bool[2];

	j = 0;
	bool[0] = temp;
	bool[1] = 0;
	while (d->ib[j] != i)
		j++;
	k = d->sib - 1;
	while (d->ib[k] != i)
		k--;
	k = i - k;
	if (j < k)
		norminette1(d, i, bool, temp);
	else
		norminette2(d, i, bool, temp);
	pa(d);
	return (norminette3(d, bool));
}
