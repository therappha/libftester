/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:10:43 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/02 19:10:43 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "tests.h"


int	*ft_tolower_test(void)
{
	int	i;
	int	ft_result;
	int	tolower_result;
	int failed = 0;

	i = 0;
	char tests[] = {'\0','a', 'A', 'r', ',', '4', 'z', '2', 'X', 'Z'};
	int length = sizeof(tests) / sizeof(tests[0]);
	int	*arraytests = (int *)malloc(sizeof(int) * (length + 1));
	printf(GREEN "Testing "BLUE"ft_tolower"RESET " in comparison with original function\n" RESET);
	while(i < length)
	{
		ft_result = ft_tolower(tests[i]);
		tolower_result = tolower(tests[i]);
		printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_tolower('%c')" RESET " | expected: '%c', got '%c': ",i + 1, tests[i], tolower_result, ft_result);

		if (ft_result == tolower_result)
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
