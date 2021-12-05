/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacikar <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:54:40 by hsacikar          #+#    #+#             */
/*   Updated: 2021/12/04 23:15:11 by hsacikar         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "functions.h"
#define SIZE 4
#define SIZE2 16

int	is_double(int table[4][4], int position, int size)
{
	int	i;

	i = -1;
	while (++i < position / 4)
		if (table[i][position % 4] == size)
			return (1);
	i = -1;
	while (++i < position % 4)
		if (table[position / 4][i] == size)
			return (1);
	return (0);
}

int	solve(int table[SIZE][SIZE], const int set[SIZE2], int position)
{
	int	size;

	if (position == 16)
		return (1);
	size = 0;
	while (++size <= 4)
	{
		if (is_double(table, position, size) == 0)
		{
			table[position / 4][position % 4] = size;
			if (check_case(table, position, set) == 0)
			{
				if (solve(table, set, position + 1) == 1)
					return (1);
			}
			else
				table[position / 4][position % 4] = 0;
		}
	}
	return (0);
}

void	display_solution(int table[SIZE][SIZE])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putchar(table[i][j] + '0');
			if (j != 3)
			{
				ft_putchar(' ');
			}
		}
		ft_putchar('\n');
	}
}

int	main(int ac, char **av)
{
	int	table[SIZE][SIZE];
	int	*set;

	if (check(ac, av) == 1)
	{
		ft_putstr("Invalid entry\n");
		return (0);
	}
	set = malloc (sizeof(int) * 16);
	get_values(set, av[1]);
	if (solve(table, set, 0) == 1)
		display_solution(table);
	else
		ft_putstr("Did not find any solutions\n");
	free(set);
	return (0);
}
