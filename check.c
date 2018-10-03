/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:56:00 by faguilar          #+#    #+#             */
/*   Updated: 2018/09/30 18:10:45 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		is_valid_sudoku(char **argv)
{
	int row;
	int col;
	int numbers;

	numbers = 0;
	row = -1;
	while (++row < 9)
	{
		col = -1;
		while (++col < 9)
		{
			if (argv[row + 1][col] == '\0')
				;
			else if (ft_isdigit(argv[row + 1][col]))
				numbers++;
			else if (argv[row + 1][col] == '.')
				;
			else
				return (0);
		}
	}
	if (numbers >= 17)
		return (1);
	else
		return (0);
}

int		find_row(int **board, int row, int nbr)
{
	int	col;

	col = -1;
	while (++col < 9)
		if (board[row][col] == nbr)
			return (1);
	return (0);
}

int		find_col(int **board, int col, int nbr)
{
	int	row;

	row = -1;
	while (++row < 9)
		if (board[row][col] == nbr)
			return (1);
	return (0);
}

int		find_box(int **board, int start_row, int start_col, int nbr)
{
	int	row;
	int	col;

	row = -1;
	while (++row < 3)
	{
		col = -1;
		while (++col < 3)
			if (board[row + start_row][col + start_col] == nbr)
				return (1);
	}
	return (0);
}

int		is_safe(int **board, int row, int col, int nbr)
{
	return (!find_row(board, row, nbr) && !find_col(board, col, nbr)
			&& !find_box(board, row - row % 3, col - col % 3, nbr));
}
