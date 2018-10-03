/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:47:30 by faguilar          #+#    #+#             */
/*   Updated: 2018/09/30 16:46:38 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <unistd.h>
# include <stdlib.h>

# define RETURN_ERROR return ( (int)write(1, "Error\n", 6) )

int				ft_strlen(char *str);
void			ft_putchar(char c);
int				ft_isdigit(char c);
int				is_valid_sudoku(char **argv);
int				find_row(int **board, int row, int nbr);
int				find_col(int **board, int col, int nbr);
int				find_box(int **board, int start_row, int start_col, int nbr);
int				is_safe(int **board, int row, int col, int nbr);
int				*find(int **board);

#endif
