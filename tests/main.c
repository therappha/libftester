/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:45:19 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/02 15:45:19 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "tests.h"
#include "libft.h"

int	main(void)
{
	system("clear");
	int wait_time = 1;
	printf(GREEN "\n Welcome to " RED "therappha's"RESET " libft tester\n" RESET);
	sleep(wait_time);
	int failed = 0;

	char *testarray[16];
	int *results[16];
	int resultsprint[16];
	testarray[0] = "ft_atoi";		results[0] = ft_atoi_test();	sleep(wait_time);
	testarray[1] = "ft_bzero";		results[1] = ft_bzero_test();	sleep(wait_time);
	testarray[2] = "ft_isalpha";	results[2] = ft_isalpha_test();	sleep(wait_time);
	testarray[3] = "ft_isdigit";	results[3] = ft_isdigit_test();	sleep(wait_time);
	testarray[4] = "ft_isalnum";	results[4] = ft_isalnum_test();	sleep(wait_time);
	testarray[5] = "ft_isascii";	results[5] = ft_isascii_test();	sleep(wait_time);
	testarray[6] = "ft_isprint";	results[6] = ft_isprint_test();	sleep(wait_time);
	testarray[7] = "ft_strlen";		results[7] = ft_strlen_test();	sleep(wait_time);
	testarray[8] = "ft_toupper";	results[8] = ft_toupper_test();	sleep(wait_time);
	testarray[9] = "ft_tolower";	results[9] = ft_tolower_test();	sleep(wait_time);
	testarray[10] = "ft_strchr";	results[10] = ft_strchr_test();	sleep(wait_time);
	testarray[11] = "ft_strrchr";	results[11] = ft_strrchr_test();sleep(wait_time);
	testarray[12] = "ft_strncmp";	results[12] = ft_strncmp_test();sleep(wait_time);
	testarray[13] = "ft_memset";	results[13] = ft_memset_test();	sleep(wait_time);
	testarray[14] = "ft_memcmp";	results[14] = ft_memcmp_test();	sleep(wait_time);
	testarray[15] = "ft_memcpy";	results[15] = ft_memcpy_test();	sleep(wait_time);

	printf("\n");
	printf(GREEN" 		 -------- RESULTS  --------\n"RESET);
	int length = sizeof(results) / sizeof(results[0]);
	for (int i = 0; i < length; i++)
	{
		printf("%s:", testarray[i]);
		resultsprint[i] = 1;
		for (int j = 0; results[i][j] != -1; j++)
		{
			if (results[i][j] == 1)
				printf(GREEN ", [OK]"RESET);
			else if (results[i][j] == 2)
				printf(YELLOW " [OK]"RESET);
			else
			{
				printf(RED " [%d: FAIL]"RESET, j + 1);
				resultsprint[i] = 0;
				failed = 1;
			}
			usleep(0.2 * 100000);
		}
		printf("\n");
	}
	if (failed)
	{
		printf(RED"\nfailed tests: "RESET);
		for (int i = 0; i < length; i++)
		{
			if (!resultsprint[i])
				printf(" %s",  testarray[i]);
		}
		printf("\n");
	}
	printf(GREEN"\nsucceeded tests:"RESET);
	for (int i = 0; i < length; i++)
	{
		if (resultsprint[i])
			printf(" %s",  testarray[i]);
	}
	sleep(wait_time);
	if (!failed)
		printf( "\n\n -------- CONGRATULATIONS, YOU PASSED ALL TESTS!!! -------- ");
}

