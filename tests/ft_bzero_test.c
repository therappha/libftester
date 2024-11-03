
#include "libft.h"
#include "tests.h"

typedef struct s_struct
{
	char buffer[50];
	char buffer_ft[50];
	size_t	n;
}	t_bzero;

int	*ft_bzero_test(void)
{
	int	i;
	int failed = 0;

	i = 0;
t_bzero tests[] = {
    {"aabcde", "aabcde",  4},
    {"Hello, World!", "Hello, World!",  5},
    {"This is a test.", "This is a test.",  13},
    {"Search for Z", "Search for Z", 7},
    {"All good things", "All good things", 0},
    {"", "", 0},
    {"123213", "123213",  3},
    {"testing for over", "testing for over",  8},
    {"May the force be with you", "May the force be with you", 15},
    {"abc", "abc", 2},
	{"", "", 50}
};
	size_t bufferlen;
	int length = sizeof(tests) / sizeof(tests[0]);
	int	*arraytests = (int *)malloc(sizeof(int) * (length + 1));
	printf(GREEN "Testing "BLUE"ft_bzero"RESET " in comparison with original function\n" RESET);
	while(i < length)
	{
		bufferlen = strlen(tests[i].buffer) > tests[i].n ? strlen(tests[i].buffer) : tests[i].n;
		printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_bzero(\"%s\", %zu)  | \nexpected: " RESET, i + 1, tests[i].buffer, tests[i].n );
		ft_bzero(tests[i].buffer_ft, tests[i].n);
		bzero(tests[i].buffer,  tests[i].n);

		for (size_t j = 0; j < bufferlen; j++)
		{

			printf(" %u", (unsigned char)tests[i].buffer[j]);
				if (j > 18)
				{
					printf("...");
					break;
				}
		}
		printf(YELLOW" got:"RESET);
		for (size_t j = 0; j < bufferlen; j++)
		{
				printf(" %u", (unsigned char)tests[i].buffer_ft[j]);
				if (j > 18)
				{
					printf("...");
					break;
				}
		}

		if (memcmp(tests[i].buffer, tests[i].buffer_ft, 50) == 0)
		{
			printf(GREEN " [PASSED]\n" RESET);
			arraytests[i] = 1;
		}
		else
			{
				printf(RED " [FAILED]\n" RESET);
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
