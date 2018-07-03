/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_through_sud.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 21:27:01 by mvolkov           #+#    #+#             */
/*   Updated: 2017/09/30 21:27:02 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		find_zero(int **sud, int *row, int *col)
{
	while (*row <= 9)
	{
		*col = 1;
		while (*col <= 9)
		{
			if (sud[*row][*col] == 0)
				return (1);
			*col += 1;
		}
		*row += 1;
	}
	return (0);
}

int		go_through_sud(int **sud)
{
	int i;
	int j;
	int num;

	j = 1;
	i = 1;
	if (find_zero(sud, &j, &i) == 0)
		return (1);
	num = 1;
	while (num <= 9)
	{
		if (is_valid_num(sud, num, j, i) == 1)
		{
			sud[j][i] = num;
			if (go_through_sud(sud) == 1)
				return (1);
			sud[j][i] = 0;
		}
		num++;
	}
	return (0);
}
