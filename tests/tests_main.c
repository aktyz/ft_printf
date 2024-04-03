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

#include <stdio.h>

int	main(void)
{
	int		o_result;
	int		my_result;
	char	var[30];

	o_result = printf("My first test case\n");
	my_result = ft_printf("My first test case\n");
	if(o_result != my_result)
	{
		printf("First test case failed!!!\n\n")
	}
	/*strcpy(var, "My second test case\n");
	o_result = printf("%s", var);
	my_result = ft_printf("%s", var);
	if(o_result != my_result)
	{
		printf("Second test case failed!!!\n\n")
	}*/
	return (0);
}
