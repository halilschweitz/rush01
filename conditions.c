/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacikar <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:54:22 by hsacikar          #+#    #+#             */
/*   Updated: 2021/12/04 20:58:36 by hsacikar         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	check_colup(int table[4][4], int position, const int set[16])
{
	int	i;
	int	max;
	int	visible_towers;

	i = -1;
	max = 0;
	visible_towers = 0;
	if (position / 4 == 3)
	{
		while (++i < 4)
		{
			if (table[i][position % 4] > max)
			{
				max = table[i][position % 4];
				visible_towers++;
			}
		}
		if (set[position % 4] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_coldown(int table[4][4], int position, const int set[16])
{
	int	i;
	int	max;
	int	visible_towers;

	i = 4;
	max = 0;
	visible_towers = 0;
	if (position / 4 == 3)
	{
		while (--i >= 0)
		{
			if (table[i][position % 4] > max)
			{
				max = table[i][position % 4];
				visible_towers++;
			}
		}
		if (set[4 + position % 4] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_rowleft(int table[4][4], int position, const int set[16])
{
	int	i;
	int	max;
	int	visible_towers;

	i = -1;
	max = 0;
	visible_towers = 0;
	if (position % 4 == 3)
	{
		while (++i < 4)
		{
			if (table[position / 4][i] > max)
			{
				max = table[position / 4][i];
				visible_towers++;
			}
		}
		if (set[8 + position / 4] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_rowright(int table[4][4], int position, const int set[16])
{
	int	i;
	int	max_size;
	int	visible_towers;

	i = 4;
	max_size = 0;
	visible_towers = 0;
	if (position % 4 == 3)
	{
		while (--i >= 0)
		{
			if (table[position / 4][i] > max_size)
			{
				max_size = table[position / 4][i];
				visible_towers++;
			}
		}
		if (set[12 + position / 4] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_case(int table[4][4], int position, const int set[16])
{
	if (check_rowleft(table, position, set) == 1)
		return (1);
	if (check_rowright(table, position, set) == 1)
		return (1);
	if (check_coldown(table, position, set) == 1)
		return (1);
	if (check_colup(table, position, set) == 1)
		return (1);
	return (0);
}
