/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:43:46 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/08 19:25:25 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	show_int_test(int *int_test, int width, int length);

int		main(void)
{
	int		int_test[5];
	char	chr_test[5];
	char	*str_test[5];

	int_test[0] = 0;
	int_test[1] = 100;
	int_test[2] = 12345678;
	int_test[3] = -100;
	int_test[4] = -12345678;

	chr_test[0] = 'A';
	chr_test[1] = '\n';
	chr_test[2] = 'b';
	chr_test[3] = '7';
	chr_test[4] = 0;

	str_test[0] = "Hola";
	str_test[1] = "Mundo";
	str_test[2] = "foo";
	str_test[3] = "bar";
	str_test[4] = "";

	show_int_test(int_test, 0, 1);
	show_int_test(int_test, 20, 5);
	show_int_test(int_test, -10, 5);
	show_int_test(int_test, 40, 30);

	printf("%-0-30.30d\n", 12345);
	printf("%.3d\n", 12345);
	return (0);
}

void	show_int_test(int *int_test, int width, int length)
{
	int	i;

	i = 0;

	printf("\n\n____________________________________________\n>TEST(%d.%dd)\n", width, length);
	printf("\t\t\t0****.****1****.****2****.****3****.****4");
	while (i < 5)
	{
		printf("\n\tint_test[%d]:\t|%*.*i|", i, width, length, int_test[i]);
//		printf("\n\t\t\t|    .    |    .    |    .    |    .    |");
		i++;
	}
}
