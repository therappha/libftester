
#include "libft.h"
#include "tests.h"

typedef struct s_struct
{
	char *str1;
	char *str2;
	size_t	n;
}	t_memcmp;


static int additional_tests(int i, int *arraytests)
{
	int ft_result;
	int memcmp_result;
	int failed;
	int a = 255;
	int b = 511;
	failed = 0;
	for(int j = 1; j <= 2; j++)
	{
		ft_result = ft_memcmp(&a, &b, j);
		memcmp_result = memcmp(&a, &b, j);
		printf( BLUE "Test [%d] "RESET, i + 1);
		printf("Comparing %d bytes of int 255: 11111111 00000000 00000000 00000000\n                          with int 511: 11111111 00000001 00000000 00000000\n", j);
		printf( "testing" YELLOW " ft_memcmp(\"%d\", \"%d\" '%d')" RESET " | expected: \"%d\", got \"%d\": ", a, b, j, memcmp_result, ft_result);


		if (ft_result == memcmp_result)
		{
			arraytests[i] = 1;
 			printf(GREEN "[PASSED]\n" RESET);
		}

		else if ((ft_result > 0 && memcmp_result > 0) || (ft_result < 0 && memcmp_result < 0))
		{
			arraytests[i] = 2;
			printf(YELLOW "[OK]\n" RESET);
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
	return (failed);
}

int	*ft_memcmp_test(void)
{
	int	i;
	int	ft_result;
	int memcmp_result;
	int failed = 0;

	i = 0;
   t_memcmp tests[] = {
    {"aabcde", "aabcxde", 4},
    {"Hello, World!", "Hello, friend!", 5},
    {"This is a test.", "This is the test.", 14},
    {"Search for A", "Search for Z", 12},
    {"", "", 0},
	{"123213", "", 0},
    {"May the force be with you", "May the weakness be with you!", 30},
    {"abc", "abcd", 4},
	{"abc", "abcd", 3},
    {"abc", "a", 3}

   };

	int length = sizeof(tests) / sizeof(tests[0]);
		int	*arraytests = (int *)malloc(sizeof(int) * (length + 3));
	printf(GREEN "Testing "BLUE"ft_memcmp"RESET " in comparison with original function\n" RESET);
	while(i < length)
	{
		ft_result = ft_memcmp(tests[i].str1, tests[i].str2, tests[i].n);
		memcmp_result = memcmp(tests[i].str1, tests[i].str2, tests[i].n);
		printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_memcmp(\"%s\", \"%s\" '%zu')" RESET " | expected: \"%d\", got \"%d\": ",i + 1, tests[i].str1, tests[i].str2, tests[i].n, memcmp_result, ft_result);

		if (ft_result == memcmp_result)
		{
			arraytests[i] = 1;
 			printf(GREEN "[PASSED]\n" RESET);
		}

		else if ((ft_result > 0 && memcmp_result > 0) || (ft_result < 0 && memcmp_result < 0))
		{
			arraytests[i] = 2;
			printf(YELLOW "[OK]\n" RESET);
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
	failed = additional_tests(i, arraytests) || failed ? 1 : 0;
	failed ? printf(RED "SOME TEST FAILED!\n\n" RESET) : printf(GREEN "ALL TESTS PASSED!\n\n" RESET);
	arraytests[i] = -1;
	return (arraytests);
}
