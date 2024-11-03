
#include "libft.h"
#include "tests.h"


int	*ft_isalpha_test(void)
{
	int	i;
	int	ft_result;
	int	isalpha_result;
	int failed = 0;

	i = 0;
	char tests[] = {'\0','a', 'A', '0', ',', '4', 'z', '9', 'Z'};
	int length = sizeof(tests) / sizeof(tests[0]);
		int	*arraytests = (int *)malloc(sizeof(int) * (length + 1));;
	printf(GREEN "Testing "BLUE"ft_isalpha"RESET " in comparison with original function\n" RESET);
	while(i < length)
	{
		ft_result = ft_isalpha(tests[i]);
		isalpha_result = isalpha(tests[i]);
		printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_isalpha(\"%c\")" RESET " | expected: %d, got %d: ",i + 1, tests[i], isalpha_result, ft_result);

		if (ft_result == isalpha_result)
		{
			printf(GREEN "[PASSED]\n" RESET);
			arraytests[i] = 1;
		}

		else if (ft_result && isalpha_result)
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
