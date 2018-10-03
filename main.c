/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:59:02 by faguilar          #+#    #+#             */
/*   Updated: 2018/09/30 16:54:41 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		*find(int **board)
{
	int *dest;
	int	row;
	int	col;

	row = -1;
	dest = malloc(sizeof(int) * 2);
	while (++row < 9)
	{
		col = -1;
		while (++col < 9)
		{
			if (board[row][col] == 0)
			{
				dest[0] = row;
				dest[1] = col;
				return (dest);
			}
		}
	}
	dest[0] = row;
	dest[1] = col;
	return (dest);
}

int		solve(int **board)
{
	int	row;
	int	col;
	int	nbr;
	int	*res;

	res = find(board);
	row = res[0];
	col = res[1];
	if (row == 9 && col == 9)
		return (1);
	nbr = 0;
	while (++nbr < 10)
	{
		if (is_safe(board, row, col, nbr))
		{
			board[row][col] = nbr;
			if (solve(board))
				return (1);
			board[row][col] = 0;
		}
	}
	return (0);
}

int		**init_board(char **argv)
{
	int	row;
	int	col;
	int	**board;

	row = -1;
	board = (int**)malloc(sizeof(int*) * 9);
	while (++row < 9)
	{
		board[row] = (int*)malloc(sizeof(int) * 9);
		col = -1;
		while (++col < 9)
		{
			if (argv[row + 1][col] == '\0')
				return (0);
			if (ft_isdigit(argv[row + 1][col]))
				board[row][col] = (argv[row + 1][col] - '0');
			else
				board[row][col] = 0;
		}
	}
	return (board);
}

void	show_board(int **board)
{
	int	row;
	int	col;

	row = -1;
	col = -1;
	while (++row < 9)
	{
		col = -1;
		while (++col < 9)
		{
			ft_putchar(board[row][col] + '0');
			if (col < 8)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int		main(int argc, char **argv)
{
	int	length;
	int i;
	int	**board;

	if (argc != 10)
		RETURN_ERROR;
	length = ft_strlen(argv[1]);
	if (!is_valid_sudoku(argv))
		RETURN_ERROR;
	i = 1;
	while (++i < argc)
		if (length != ft_strlen(argv[i]))
			RETURN_ERROR;
	board = init_board(argv);
	solve(board);
	if (board && solve(board))
	{
		show_board(board);
		free(board);
	}
	else
		RETURN_ERROR;
	return (0);
}
