/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:21:13 by faguilar          #+#    #+#             */
/*   Updated: 2018/09/30 18:35:06 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		number;

	number = 0;
	while (*str++)
		number++;
	return (number);
}

int		ft_isdigit(char c)
{
	if (c - '0' > 0 && c - '0' <= 9)
		return (1);
	else
		return (0);
}
