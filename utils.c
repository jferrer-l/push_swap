/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:05:33 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/12 18:34:30 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	freedata(t_data *data)
{
	if (data)
	{
		if (data->a)
			free(data->a);
		if (data->b)
			free(data->b);
		if (data->ia)
			free(data->ia);
		if (data->ib)
			free(data->ib);
		free(data);
	}
	return (0);
}

void	error(t_data *data)
{
	freedata(data);
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_isdigit(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		str++;
	}
	return (1);
}

int	check_duplicates(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->sia - 1)
	{
		j = i + 1;
		while (j < data->sia)
		{
			if (data->a[i] == data->a[j])
				error(data);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str, t_data *data)
{
	int			i;
	int			j;
	long		sum;

	i = 0;
	j = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' && str[i++] == '-')
		j = -1;
	else if (str[i] == '+')
		i++;
	sum = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		sum = (sum * 10) + (str[i] - 48);
		i++;
		if (sum > 2147483647 && j == 1)
			error(data);
		else if (sum > 2147483648 && j == -1)
			error(data);
	}
	return (sum * j);
}
