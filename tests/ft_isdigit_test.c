
#include "libft.h"
#include "tests.h"


int	*ft_isdigit_test(void)
{
	int	i;
	int	ft_result;
	int	isdigit_result;
	int failed = 0;

	i = 0;
	char tests[] = {'1', '#', '0', ',', '4', '\t', '9'};
	int length = sizeof(tests) / sizeof(tests[0]);
	int	*arraytests = (int *)malloc(sizeof(int) * (length + 1));
	printf(GREEN "Testing "BLUE"ft_isdigit"RESET" in comparison with original function\n" RESET);
	while(i < length )
	{
		ft_result = ft_isdigit(tests[i]);
		isdigit_result = isdigit(tests[i]);
		printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_isdigit(\"%c\")" RESET " | expected: %d, got %d: ",i + 1, tests[i], isdigit_result, ft_result);

		if (ft_result == isdigit_result)
		{
			printf(GREEN "[PASSED]\n" RESET);
			arraytests[i] = 1;
		}

		else if (ft_result && isdigit_result)
		{
			printf(YELLOW "[OK]\n" RESET);
			arraytests[i] = 2;
		}

		else
			{
				arraytests[i] = 0;
				printf(RED "[FAILED]\n" RESET);
				failed = 1;
			}
		i++;
		usleep(0.1 * 1000000);
	}
	failed ? printf(RED "SOME TEST FAILED!\n\n" RESET) : printf(GREEN "ALL TESTS PASSED!\n\n" RESET);
	arraytests[i] = -1;
	return (arraytests);
}
