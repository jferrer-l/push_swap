/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:51:56 by jferrer-          #+#    #+#             */
/*   Updated: 2022/01/26 11:59:07 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	p = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (p == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		p[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (p);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != (char)c)
	{
		if (s[i] == '\0' && (char)c != '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	temp;

	if (!s)
		return (NULL);
	temp = 0;
	if (start >= ft_strlen(s))
		p = malloc(sizeof(char));
	else if (ft_strlen(s) - start < len)
		p = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	while (start + temp < ft_strlen(s) && temp < len)
	{
		p[temp] = s[start + temp];
		temp++;
	}
	p[temp] = '\0';
	return (p);
}
