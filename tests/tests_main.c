/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:43:27 by zslowian          #+#    #+#             */
/*   Updated: 2024/04/03 21:43:27 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdio.h>

void	test_char(void);
void	test_percent(void);
void	test_string(void);

int	main(void)
{
	test_string();
	return (0);
}

void	test_char(void)
{
	int		o_result;
	int		my_result;

	o_result = printf("My first test case\n");
	my_result = ft_printf("My first test case\n");
	if (o_result != my_result)
	{
		printf("First char test case failed!!!\n\n");
	}
	printf("Character testing completed\n\n");
}

void	test_percent(void)
{
	int		o_result;
	int		my_result;

	o_result = printf("Percent sign %%\n");
	my_result = ft_printf("Percent sign %%\n");
	if (o_result != my_result)
	{
		printf("Percent sign test case failed!!!\n\n");
	}
	printf("Percent sign testing completed\n\n");
}

void	test_string(void)
{
	int		o_result;
	int		my_result;
	char	var[100];

	strcpy(var, "My second test case\n");
	o_result = printf("%s", var);
	strcpy(var, "My second test case\n");
	my_result = ft_printf("%s", var);
	if (o_result != my_result)
	{
		printf("First string test case failed!!! Numbers printed:\n");
		printf("Official function printed %d chars\n", o_result);
		printf("My function printed %d chars\n\n", my_result);
	}
	/**var = '\0';
	o_result = printf("%s", var);
	my_result = ft_printf("%s", var);
	if (o_result != my_result)
	{
		printf("Second string test case failed -> print out null!!!");
		printf(" Numbers printed:\n");
		printf("Official function printed %d chars\n", o_result);
		printf("My function printed %d chars\n\n", my_result);
	}*/
	printf("String testing completed\n\n");
}
