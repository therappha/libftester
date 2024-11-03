
#include "libft.h"
#include "tests.h"

typedef struct s_struct
{
	char src[50];
	char buffer[50];
	char buffer_ft[50];
	size_t	n;
}	t_memcpy;

static int additional_tests(int i, int *arraytests)
{
	int ft_result;
	int memcpy_result;
	int failed;
	int src[] = {255, 511, 2147483647};

	failed = 0;
	for(int j = 0; j <= 2; j++)
	{

		printf( BLUE "Test [%d] "RESET, i);
		ft_memcpy(&ft_result, &src[j], 4);
		memcpy(&memcpy_result, &src[j], 4);

		printf( "testing" YELLOW " ft_memcpy(dest, %d %d)" RESET " | expected: \"%d\", got \"%d\": ", src[j] , 4, memcpy_result, ft_result);


		if (ft_result == memcpy_result)
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
	return (failed);
}

int	*ft_memcpy_test(void)
{
	int	i;
	char	*ft_result;
	char *memcpy_result;
	int failed = 0;

	i = 0;

t_memcpy tests[] =
{
	{"abcde", "xxxxx", "xxxxx", 3},
	{"Hello, World!", "Goodbye, World!", "Goodbye, World!", 5},
	{"1234567890", "0987654321", "0987654321", 10},
	{"This is a test.", "This is a test.", "This is a test.", 10},
	{"", "", "", 0},
	{"Short", "Short", "Short", 0},
	{"A", "B", "B", 1},  // Copy 1 char
	{"Overlap Test", "Overlap Test", "Overlap Test", 5},
	{"Overlap Test", "Overlap Test", "Overlap Test", 10},
	{"Hello, World!", "Hello, World!", "Hello, World!", 13},
	{"a", "b", "b", 1},
	{"abc", "xyz", "xyz", 2},
	{"1234567890", "54321", "54321", 5},
	{"abc\0def", "xxxxxxx", "xxxxxxx", 4},
	{"abc\0def", "xxxxxxx", "xxxxxxx", 7},
	{"The quick brown fox jumps over the lazy dog", "The quick brown fox", "The quick brown fox", 40}
};


	int length = sizeof(tests) / sizeof(tests[0]);
	int	*arraytests = (int *)malloc(sizeof(int) * (length + 4));
	printf(GREEN "Testing "BLUE"ft_memcpy"RESET " in comparison with original function\n" RESET);
	while(i < length)
	{
		printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_memcpy(\"%s\", %s, %zu)" RESET, i + 1, tests[i].buffer, tests[i].src, tests[i].n );
		ft_result = (char *)ft_memcpy(tests[i].buffer_ft, tests[i].src, tests[i].n);
		memcpy_result = (char *)memcpy(tests[i].buffer, tests[i].src, tests[i].n);
		printf(" | expected: \"%s\", got \"%s\": ", memcpy_result, ft_result);

		if (memcmp(ft_result, memcpy_result, 50) == 0)
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
	failed = additional_tests(i, arraytests) || failed ? 1 : 0;
	failed ? printf(RED "SOME TEST FAILED!\n\n" RESET) : printf(GREEN "ALL TESTS PASSED!\n\n" RESET);
	arraytests[i] = -1;
	return (arraytests);
}
