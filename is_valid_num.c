/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 19:29:45 by ovirchen          #+#    #+#             */
/*   Updated: 2017/09/30 19:29:47 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_cube3x3(int **sud, int num, int row, int col)
{
	int i;
	int j;
	int ni;
	int nj;

	i = ((col - 1) / 3 * 3) + 1;
	j = ((row - 1) / 3 * 3) + 1;
	nj = 0;
	while (nj < 3)
	{
		ni = 0;
		while (ni < 3)
		{
			if (sud[j + nj][i + ni] == num)
				return (0);
			ni++;
		}
		nj++;
	}
	return (1);
}

int		is_valid_num(int **sud, int num, int row, int col)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (j <= 9)
	{
		while (i <= 9)
		{
			if (sud[row][i] == num || sud[i][col] == num)
				return (0);
			i++;
		}
		j++;
	}
	if (check_cube3x3(sud, num, row, col) == 1)
		return (1);
	else
		return (0);
}
