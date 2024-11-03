
#include "libft.h"
#include "tests.h"


int	*ft_isascii_test(void)
{
	int	i;
	int	ft_result;
	int	isascii_result;
	int failed = 0;

	i = 0;
int tests[] = {
	'\0', // NULL
    32,   // Space
    64,   // '@'
    65,   // 'A'
    90,   // 'Z'
    126,  // '~'
    127,  // DEL
    128,  // Non-ASCII
    129,  // Non-ASCII
    130,  // Non-ASCII

	};

	int length = sizeof(tests) / sizeof(tests[0]);
	int	*arraytests = (int *)malloc(sizeof(int) * (length + 1));
	printf(GREEN "Testing "BLUE"ft_isascii"RESET" in comparison with original function\n" RESET);
	while(i < length)
	{
		ft_result = ft_isascii(tests[i]);
		isascii_result = isascii(tests[i]);
		printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_isascii(%d) char '%c'" RESET " | expected: %d, got %d: ",i + 1, tests[i], tests[i], isascii_result, ft_result);

		if (ft_result == isascii_result)
		{
			printf(GREEN "[PASSED]\n" RESET);
			arraytests[i] = 1;
		}

		else if (ft_result && isascii_result)
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
