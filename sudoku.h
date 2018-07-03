/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 16:42:12 by ovirchen          #+#    #+#             */
/*   Updated: 2017/09/30 16:42:14 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <unistd.h>
# include <stdlib.h>

int		**mas_to_int(char **av);
void	print_sudoku(int **sud);
int		go_through_sud(int **sud);
int		is_valid_num(int **sud, int num, int row, int col);

#endif
