
#include "libft.h"
#include "tests.h"

typedef struct s_struct
{
	char buffer[50];
	char buffer_ft[50];
	int		c;
	size_t	n;
}	t_memset;

int	*ft_memset_test(void)
{
	int	i;
	char	*ft_result;
	char *memset_result;
	int failed = 0;

	i = 0;
t_memset tests[] = {
    {"aabcde", "aabcde", 'x', 4},
    {"Hello, World!", "Hello, World!", '#', 5},
    {"This is a test.", "This is a test.", 'z', 10},
    {"Search for Z", "Search for Z", '@', 7},
    {"All good things", "All good things", '-', 0},
    {"", "", 'a', 0},
    {"123213", "123213", '0', 3},
    {"testing for over", "testing for over", '*', 8},
    {"May the force be with you", "May the force be with you", '!', 15},
    {"abc", "abc", '+', 2},
	{"", "", 0, 50}

};

	int length = sizeof(tests) / sizeof(tests[0]);
		int	*arraytests = (int *)malloc(sizeof(int) * (length + 1));
	printf(GREEN "Testing "BLUE"ft_memset"RESET " in comparison with original function\n" RESET);
	while(i < length)
	{
		printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_memset(\"%s\", %d, %zu)" RESET, i + 1, tests[i].buffer, tests[i].c, tests[i].n );
		ft_result = ft_memset(tests[i].buffer_ft, tests[i].c, tests[i].n);
		memset_result = memset(tests[i].buffer, tests[i].c, tests[i].n);
		printf(" | expected: \"%s\", got \"%s\": ", memset_result, ft_result);

		if (memcmp(ft_result, memset_result, 50) == 0)
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
