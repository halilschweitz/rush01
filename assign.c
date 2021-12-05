/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacikar <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:52:13 by hsacikar          #+#    #+#             */
/*   Updated: 2021/12/04 20:53:00 by hsacikar         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "functions.h"

int	check(int ac, char **av)
{
	int	i;

	i = -1;
	if (ac != 2)
		return (1);
	if (ft_strlen(av[1]) != 31)
		return (1);
	while (av[1][++i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (av[1][i] < '1' || av[1][i] > '4')
				return (1);
		}
		else
		{
			if (av[1][i] != ' ')
				return (1);
		}
	}
	return (0);
}

void	get_values(int *set, char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i] != '\0')
		if (str[i] >= '1' && str[i] <= '4')
			set[j++] = str[i] - '0';
}
