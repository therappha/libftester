
#include "libft.h"
#include "tests.h"

typedef struct s_struct
{
	char *str;
	int	c;
}	t_strchr;

int	*ft_strchr_test(void)
{
	int	i;
	char	*ft_result;
	char *strchr_result;
	int failed = 0;

	i = 0;
   t_strchr tests[] = {
        {"aabcde", 'b'},
        {"Hello, World!", 'W'},
        {"This is a test.", 't'},
        {"Search for Z", 'Z'},
        {"All good things", 'g'},
        {"", 'a'},
        {"testing null char", '\0'},
		 {"", '\0'},
		{"May the force be with you", 'x'}
    };

	int length = sizeof(tests) / sizeof(tests[0]);
	int	*arraytests = (int *)malloc(sizeof(int) * (length + 1));
	printf(GREEN "Testing "BLUE"ft_strchr"RESET " in comparison with original function\n" RESET);
	while(i < length)
	{
		ft_result = ft_strchr(tests[i].str, tests[i].c);
		strchr_result = strchr(tests[i].str, tests[i].c);
		printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_strchr(\"%s\", '%c')" RESET " | expected: \"%s\", got \"%s\": ",i + 1, tests[i].str, tests[i].c, strchr_result, ft_result);

		if (ft_result == strchr_result)
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
