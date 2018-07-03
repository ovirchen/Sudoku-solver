/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 13:24:45 by mvolkov           #+#    #+#             */
/*   Updated: 2017/09/30 13:24:46 by mvolkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		check_17(int **sud)
{
	int i;
	int j;
	int count;

	j = 1;
	count = 0;
	while (j <= 9)
	{
		i = 1;
		while (i <= 9)
		{
			if (sud[j][i] > 0 && sud[j][i] <= 9)
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

int		main(int argc, char **argv)
{
	int **sud;
	int i;

	if (argc == 10)
	{
		i = 1;
		while (i < 10)
		{
			if (ft_strlen(argv[i]) != 9)
				return (error());
			i++;
		}
		if (mas_to_int(argv) != 0)
			sud = mas_to_int(argv);
		else
			return (error());
		if (check_17(sud) < 17)
			return (error());
		if (go_through_sud(sud) == 1)
			print_sudoku(sud);
		else
			return (error());
	}
	else
		return (error());
}
