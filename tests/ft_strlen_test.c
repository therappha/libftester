
#include "libft.h"
#include "tests.h"


int	*ft_strlen_test(void)
{
	int	i;
	size_t	ft_result;
	size_t	strlen_result;
	int failed = 0;

	i = 0;
	char *tests[] = {"", "Hello, World!", "42", "101010", "May the force be with you", "Even the smallest person can change the course of the future."};
	int length = sizeof(tests) / sizeof(tests[0]);
	int	*arraytests = (int *)malloc(sizeof(int) * (length + 1));
	printf(GREEN "Testing "BLUE"ft_strlen"RESET" in comparison with original function\n" RESET);
	while(i < length )
	{
		ft_result = ft_strlen(tests[i]);
		strlen_result = strlen(tests[i]);
		printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_strlen(\"%s\")" RESET " | expected: %zu, got %zu: ",i + 1, tests[i], strlen_result, ft_result);

		if (ft_result == strlen_result)
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
