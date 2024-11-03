
#include "libft.h"
#include "tests.h"

typedef struct s_struct
{
	char *str1;
	char *str2;
	size_t	n;
}	t_strncmp;

int	*ft_strncmp_test(void)
{
	int	i;
	int	ft_result;
	int strncmp_result;
	int failed = 0;

	i = 0;
   t_strncmp tests[] = {
    {"aabcde", "aabcxde", 4},
    {"Hello, World!", "Hello, friend!", 5},
    {"This is a test.", "This is the test.", 14},
    {"Search for A", "Search for Z", 12},
    {"All good things", "All good things", 15},
    {"", "", 0},
	{"123213", "", 0},
    {"testing for over", "testing", 10},
    {"May the force be with you", "May the weakness be with you!", 30},
    {"abc", "abcd", 4},
	{"abc", "abcd", 3},
    {"abc", "a", 3}
   };

	int length = sizeof(tests) / sizeof(tests[0]);
	int	*arraytests = (int *)malloc(sizeof(int) * (length + 1));
	printf(GREEN "Testing "BLUE"ft_strncmp"RESET " in comparison with original function\n" RESET);
	while(i < length)
	{
		ft_result = ft_strncmp(tests[i].str1, tests[i].str2, tests[i].n);
		strncmp_result = strncmp(tests[i].str1, tests[i].str2, tests[i].n);
		printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_strncmp(\"%s\", \"%s\" '%zu')" RESET " | expected: \"%d\", got \"%d\": ",i + 1, tests[i].str1, tests[i].str2, tests[i].n, strncmp_result, ft_result);

		if (ft_result == strncmp_result)
		{
			printf(GREEN "[PASSED]\n" RESET);
			arraytests[i] = 1;
		}

		else if ((ft_result > 0 && strncmp_result > 0) || (ft_result < 0 && strncmp_result < 0))
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
