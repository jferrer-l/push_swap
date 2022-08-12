/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:37:07 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/17 18:51:56 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	select_operation(char *str, t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		sorted(t_data *data);

int	freee(char *str)
{
	free(str);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	*str;

	str = malloc(sizeof(char) * 500);
	if (argc == 1 || !str)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data && freee(str))
		return (0);
	if (init_data(argc, argv, data) == -1 || !check_duplicates(data))
		error(data);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		select_operation(str, data);
	}
	if (sorted(data) == 1)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	freedata(data);
	free(str);
	return (0);
}

int	sorted(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->sia - 1)
	{
		if (data->a[i] > data->a[i + 1])
			return (-1);
	}
	if (data->sib > 0)
		return (-1);
	return (1);
}

void	select_operation(char *str, t_data *data)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		bsa(data);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		bsb(data);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		bss(data);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		bpa(data);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		bpb(data);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		bra(data);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		brb(data);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		brr(data);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		brra(data);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		brrb(data);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		brrr(data);
	else
		error(data);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	contador;

	contador = 0;
	if (n == 0)
		return (0);
	while (s2[contador] && s1[contador]
		&& s1[contador] == s2[contador] && contador + 1 < n)
		contador++;
	return (((unsigned char *)s1)[contador] - ((unsigned char *)s2)[contador]);
}
