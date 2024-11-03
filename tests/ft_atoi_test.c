
#include "libft.h"
#include "tests.h"


int	*ft_atoi_test(void)
{
	int	i;
	int	ft_result;
	int	atoi_result;
	int failed = 0;

	i = 0;
	char *tests[] = { "", "-42", "42", "2147483647", "-2147483648", "10", "-58", "2147483647123", "--42", "+42"};
	int length = sizeof(tests) / sizeof(tests[0]);
	int	*arraytests = (int *)malloc(sizeof(int) * (length + 1));
	printf(GREEN "Testing "BLUE"ft_atoi"RESET" in comparison with original function\n" RESET);
	while(i < length)
	{
		ft_result = ft_atoi(tests[i]);
		atoi_result = atoi(tests[i]);
		printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_atoi(\"%s\")" RESET " | expected: %d, got %d: ",i + 1, tests[i], atoi_result, ft_result);
		if (ft_result == atoi_result)
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
