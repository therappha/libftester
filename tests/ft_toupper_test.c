/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:10:43 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/02 19:10:43 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "tests.h"


int	*ft_toupper_test(void)
{
	int	i;
	int	ft_result;
	int	toupper_result;
	int failed = 0;

	i = 0;
	char tests[] = {'\0','a', 'A', 'r', ',', '4', 'z', '2', 'X', 'Z'};
	int length = sizeof(tests) / sizeof(tests[0]);
	int	*arraytests = (int *)malloc(sizeof(int) * (length + 1));
	printf(GREEN "Testing "BLUE"ft_toupper"RESET " in comparison with original function\n" RESET);
	while(i < length)
	{
		ft_result = ft_toupper(tests[i]);
		toupper_result = toupper(tests[i]);
		printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_toupper('%c')" RESET " | expected: '%c', got '%c': ",i + 1, tests[i], toupper_result, ft_result);

		if (ft_result == toupper_result)
		{
			printf(GREEN "[PASSED]\n" RESET);
			arraytests[i] = 1;
		}
		else
		{
			printf(RED "[FAILED]\n" RESET);
			failed = 1;
			arraytests[i] = 0;
		}
		i++;
		usleep(0.1 * 1000000);
	}
	failed ? printf(RED "SOME TEST FAILED!\n\n" RESET) : printf(GREEN "ALL TESTS PASSED!\n\n" RESET);
	arraytests[i] = -1;
	return (arraytests);
}
