/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mas_from_1to9.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 17:54:58 by ovirchen          #+#    #+#             */
/*   Updated: 2017/09/30 17:55:00 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		is_valid_mas(int **sud)
{
	int i;
	int j;
	int num;

	j = 1;
	while (j <= 9)
	{
		i = 1;
		while (i <= 9)
		{
			if (sud[j][i] != 0)
			{
				num = sud[j][i];
				sud[j][i] = 0;
				if (is_valid_num(sud, num, j, i) == 0)
					return (0);
				sud[j][i] = num;
			}
			i++;
		}
		j++;
	}
	return (1);
}

int		**mas_to_int(char **av)
{
	int **sud;
	int *row;
	int i;
	int j;

	sud = (int**)malloc(sizeof(int*) * 10);
	j = 0;
	while (++j <= 9)
	{
		i = -1;
		row = (int*)malloc(sizeof(int) * 10);
		while (++i <= 8)
		{
			if ((av[j][i] < '0' || av[j][i] > '9') && av[j][i] != '.')
				return (0);
			if (av[j][i] == '.')
				row[i + 1] = 0;
			else
				row[i + 1] = av[j][i] - 48;
		}
		sud[j] = row;
	}
	if (is_valid_mas(sud) == 0)
		return (0);
	return (sud);
}
