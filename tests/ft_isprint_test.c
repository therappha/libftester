
#include "libft.h"
#include "tests.h"


int	*ft_isprint_test(void)
{
	int	i;
	int	ft_result;
	int	isprint_result;
	int failed = 0;

	i = 0;
	int tests[] = {'1', '#', '0', ',', '4', '\t', '9', 7, 8, 12};
	int length = sizeof(tests) / sizeof(tests[0]);
		int	*arraytests = (int *)malloc(sizeof(int) * (length + 1));
	printf(GREEN "Testing "BLUE"ft_isprint"RESET" in comparison with original function\n" RESET);
	while(i < length )
	{
		ft_result = ft_isprint(tests[i]);
		isprint_result = isprint(tests[i]);
		isprint_result ?
			 printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_isprint(\'%c\')" RESET " | expected: %d, got %d: ",i + 1, tests[i], isprint_result, ft_result) :
			 printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_isprint('<non printable>') with int value: %d" RESET " | expected: %d, got %d: ",i + 1, tests[i], isprint_result, ft_result);
		if (ft_result == isprint_result)
		{
			printf(GREEN "[PASSED]\n" RESET);
			arraytests[i] = 1;
		}

		else if (ft_result && isprint_result)
		{
			printf(YELLOW "[OK]\n" RESET);
			arraytests[i] = 2;
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
