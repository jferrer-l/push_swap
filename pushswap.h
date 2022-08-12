/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:06:22 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/16 23:18:53 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

typedef struct s_data
{
	int	*a;
	int	*ia;
	int	*b;
	int	*ib;
	int	sia;
	int	sib;
	int	rbiq;
}	t_data;

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

int		freedata(t_data *data);
void	error(t_data *data);
int		ft_isdigit(char *str);
int		check_duplicates(t_data *data);
int		ft_atoi(const char *str, t_data *data);

int		init_data(int argc, char **argv, t_data *data);

int		sort_size_5(t_data *d);
int		sort_size_3(t_data *d);

void	bsa(t_data *data);
void	bsb(t_data *data);
void	bss(t_data *data);
void	bpa(t_data *data);
void	bpb(t_data *data);
void	bra(t_data *data);
void	brb(t_data *data);
void	brr(t_data *data);
void	brra(t_data *data);
void	brrb(t_data *data);
void	brrr(t_data *data);

void	norminette1(t_data *d, int i, int *bool, int temp);
void	norminette2(t_data *d, int i, int *bool, int temp);
int		norminette3(t_data *d, int *bool);
int		norminette4(t_data *d, int count, int size, int part);

#endif
