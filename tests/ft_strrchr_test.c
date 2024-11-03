
#include "libft.h"
#include "tests.h"

typedef struct s_struct
{
	char *str;
	int	c;
}	t_strrchr;

int	*ft_strrchr_test(void)
{
	int	i;
	char	*ft_result;
	char *strrchr_result;
	int failed = 0;

	i = 0;
   t_strrchr tests[] = {
        {"aeabecdeeefg", 'e'},
        {"Hello, World!", 'l'},
        {"this is a test.", 't'},
        {"ZSearchZ for Z in Zetta!", 'Z'},
        {"All good things are great!", 'g'},
        {"", 'a'},
        {"testing null char", '\0'},
		{"", '\0'},
		{"May the force be with you", 'y'},
		{"there is no lower 'A' here", 'a'}
    };

	int length = sizeof(tests) / sizeof(tests[0]);
	int	*arraytests = (int *)malloc(sizeof(int) * (length + 1));
	printf(GREEN "Testing "BLUE"ft_strrchr"RESET " in comparison with original function\n" RESET);
	while(i < length)
	{
		ft_result = ft_strrchr(tests[i].str, tests[i].c);
		strrchr_result = strrchr(tests[i].str, tests[i].c);
		printf( BLUE "Test [%d] " RESET  "testing" YELLOW " ft_strrchr(\"%s\", '%c')" RESET " | expected: \"%s\", got \"%s\": ",i + 1, tests[i].str, tests[i].c, strrchr_result, ft_result);

		if (ft_result == strrchr_result)
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
