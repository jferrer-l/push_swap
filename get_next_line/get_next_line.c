/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:08:05 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/17 18:40:51 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*readline(int fd, char *temp);
static char	*savetemp(char *temp);
static char	*update(char *temp);

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = readline(fd, temp);
	if (!temp || !temp[0])
	{
		free(temp);
		return (NULL);
	}
	ret = savetemp(temp);
	temp = update(temp);
	return (ret);
}

static char	*readline(int fd, char *temp)
{
	char	*buffer;
	int		i;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr(temp, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (ft_strchr(buffer, EOF))
			break ;
		if (i < 1)
		{
			free(buffer);
			return (temp);
		}
		buffer[i] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

static char	*savetemp(char *temp)
{
	char	*ret;
	int		i;

	i = 0;
	if (!temp[0])
		return (NULL);
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	i++;
	ret = ft_substr(temp, 0, i);
	return (ret);
}

static char	*update(char *temp)
{
	char	*str;
	int		i;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	i++;
	str = ft_substr(temp, i, ft_strlen(temp) - i);
	free(temp);
	return (str);
}
