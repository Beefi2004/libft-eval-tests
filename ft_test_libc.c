/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_libc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehale <ehale@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 13:29:23 by ehale             #+#    #+#             */
/*   Updated: 2026/10/09 14:22:35 by ehale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Explicit test file that holds unit tests for the Libc functions.
// Run: Compile the library using the Makefile,
// then compile it with this file into an executable.
// COMPILE IT WITH GCC to include bsd for comparing
// with the actual functions (e.g. strlcat).

#include "libft.h"
#include <stdio.h>

void	print_test_name(char *name)
{
	printf("Unittest: %s\n", name);
}

int	test_ft_isalpha(void)
{
	print_test_name("ft_isalpha");
	if (!ft_isalpha('t'))
		return (1);
	if (!ft_isalpha('M'))
		return (1);
	if (ft_isalpha('0'))
		return (1);
	return (0);
}

int	test_ft_isdigit(void)
{
	print_test_name("ft_isdigit");
	if (!ft_isdigit('0'))
		return (1);
	if (!ft_isdigit('7'))
		return (1);
	if (ft_isdigit('a'))
		return (1);
	return (0);
}

int	test_ft_isalnum(void)
{
	print_test_name("ft_isalnum");
	if (!ft_isalnum('2'))
		return (1);
	if (!ft_isalnum('Y'))
		return (1);
	if (!ft_isalnum('l'))
		return (1);
	if (ft_isalnum('$'))
		return (1);
	return (0);
}

int	test_ft_isascii(void)
{
	print_test_name("ft_isascii");
	if (!ft_isascii('2'))
		return (1);
	if (!ft_isascii('Y'))
		return (1);
	if (!ft_isascii('%'))
		return (1);
	if (ft_isascii(740))
		return (1);
	return (0);
}

int	test_ft_isprint(void)
{
	print_test_name("ft_isprint");
	if (!ft_isprint('2'))
		return (1);
	if (!ft_isprint('Y'))
		return (1);
	if (ft_isprint(8))
		return (1);
	if (ft_isprint(0))
		return (1);
	if (ft_isprint(127))
		return (1);
	return (0);
}

int test_ft_strlen(void)
{
	print_test_name("ft_strlen");
	if (ft_strlen("15 char's long.") != 15)
		return (1);
	if (ft_strlen("") != 0)
		return (1);
	return (0);
}

int test_ft_memset(void)
{
	print_test_name("ft_memset");
	char mem[] = "Hello";
	printf("%s\n", (char *) ft_memset(mem, 'a', 5));
	printf("%s\n", (char *) ft_memset(mem, 'b', 2));
	return (0);
}

int test_ft_bzero(void)
{
	print_test_name("ft_bzero");
	char mem[] = "Hello";
	ft_bzero(mem, 5);
	for (unsigned int i = 0; i < 5; i++)
	{
		if (mem[i] != '\0')
			return (1);
	}
	return (0);
}

int test_ft_memcpy(void)
{
	print_test_name("ft_memcpy");
	char mem1[] = "Hello";
	char mem2[] = "World";
	printf("%s\n", (char *) ft_memcpy(mem2, mem1, 5));
	printf("%s\n", mem2);
	return (0);
}

int test_ft_memmove(void)
{
	print_test_name("ft_memmove");
	char mem1[] = "Hello";
	char mem2[] = "World";
	printf("%s\n", (char *) ft_memcpy(mem2, mem1, 5));
	printf("%s\n", mem2);
	printf("%s\n", (char *) ft_memmove(mem1 + 1, mem1, 3));
	printf("%s\n", mem1);
	return (0);
}

int test_ft_strlcpy(void)
{
	print_test_name("ft_strlcpy");
	char s1[] = "Hello";
	char s2[] = "World";
	// size is the size of the buffer (including the null terminator), so it only copies up to size - 1 to leave space for the \0.
	if (ft_strlcpy(s2, s1, 6) != 5)
		return (1);
	printf("%s\n", s2);
	if (ft_strlcpy(s2, s1, 3) != 5)
		return (1);
	printf("%s\n", s2);
	return (0);
}

int test_ft_strlcat(void)
{
	print_test_name("ft_strlcat");
	char s1[] = "World";
	char s2[11] = "Hello";
	// Same here, it copies up to size - len(dest) - 1 to use the empty space after dest and leave one char for \0.
	if (ft_strlcat(s2, s1, 11) != 10)
		return (1);
	printf("%s\n", s2);
	return (0);
}

int test_ft_toupper(void)
{
	print_test_name("ft_toupper");
	if (ft_toupper('f') != 'F')
		return (1);
	if (ft_toupper('H') != 'H')
		return (1);
	if (ft_toupper('8') != '8')
		return (1);
	if (ft_toupper('%') != '%')
		return (1);
	return (0);
}

int test_ft_tolower(void)
{
	print_test_name("ft_tolower");
	if (ft_tolower('f') != 'f')
		return (1);
	if (ft_tolower('H') != 'h')
		return (1);
	if (ft_tolower('8') != '8')
		return (1);
	if (ft_tolower('%') != '%')
		return (1);
	return (0);
}

int test_ft_strchr(void)
{
	print_test_name("ft_strchr");
	char *test = "test";
	if (ft_strchr(test, 'y') != NULL)
		return (1);
	printf("%s\n", ft_strchr(test, 'e' + 256));
	printf("%s\n", ft_strchr(test, 't'));
	return (0);
}

int test_ft_strrchr(void)
{
	print_test_name("ft_strrchr");
	char *test = "test";
	if (ft_strrchr(test, 'y') != NULL)
		return (1);
	if (ft_strchr("", 'i') != NULL)
		return (1);
	printf("%s\n", ft_strrchr(test, 'e' + 256));
	printf("%s\n", ft_strrchr(test, 't'));
	return (0);
}

int test_ft_strncmp(void)
{
	print_test_name("ft_strncmp");
	if (ft_strncmp("Test", "Temp", 2) != 0)
		return (1);
	if (ft_strncmp("Test", "Temp", 8) != 6)
		return (1);
	if (ft_strncmp("", "Temp", 8) != -84)
		return (1);
	return (0);
}

int test_ft_memchr(void)
{
	print_test_name("ft_memchr");
	char *test = "test";
	if (ft_memchr(test, 's', 2) != NULL)
		return (1);
	printf("%s\n", (char *) ft_memchr(test, 'e' + 256, 3));
	printf("%s\n", (char *) ft_memchr(test, 't', 4));
	return (0);
}

int test_ft_memcmp(void)
{
	print_test_name("ft_memcmp");
	if (ft_memcmp("Test", "Temp", 2) != 0)
		return (1);
	if (ft_memcmp("Test", "Temp", 8) != 6)
		return (1);
	if (ft_memcmp("", "Temp", 8) != -84)
		return (1);
	return (0);
}

int test_ft_strnstr(void)
{
	print_test_name("ft_strnstr");
	char *test = "aaabccd";
	if (ft_strnstr(test, "abc", 4) != NULL)
		return (1);
	if (ft_strnstr(test, "bla", 4) != NULL)
		return (1);
	printf("%s\n", ft_strnstr(test, "abc", 5));
	printf("%s\n", ft_strnstr("abc", "c", 5));
	return (0);
}

int test_ft_atoi(void)
{
	print_test_name("ft_atoi");
	if (ft_atoi("    -123as5235fa") != -123)
		return (1);
	if (ft_atoi(" - 123") != 0)
		return (1);
	if (ft_atoi("--123") != 0)
		return (1);
	if (ft_atoi("--a123") != 0)
		return (1);
	if (ft_atoi("2147483647") != 2147483647)
		return (1);
	if (ft_atoi("-2147483648") != -2147483648)
		return (1);
	if (ft_atoi("-0") != 0)
		return (1);
	if (ft_atoi("+0001230") != 1230)
		return (1);
	return (0);
}

int test_ft_calloc(void)
{
	print_test_name("ft_calloc");
	if (ft_calloc(SIZE_MAX, 2) != NULL)
		return (1);
	void *mem = ft_calloc(0, 5);
	free(mem);
	mem = ft_calloc(2, 3);
	for (unsigned int y = 0; y < 2; y++)
	{
		for (unsigned int x = 0; x < 3; x++)
		{
			if (((char *) mem)[y * 3 + x] != '\0')
			{
				free(mem);
				return (1);
			}
		}
	}
	free(mem);
	return (0);
}

int	test_ft_strdup(void)
{
	print_test_name("ft_strdup");
	char *dup = ft_strdup("Hello");
	printf("%s\n", dup);
	free(dup);
	return (0);
}

// Return 0 for no errors, return 1 for errors.
// Each unit test can also print values.
// Seperate the output of each unittest by "---" or something.
// Each unittest should print their name.
// For some tests you could also just print stuff 
// and return 0 at the end if assertions are too hard
// (or use libc funcs for asserting).
// Compile and run: make,
// then: gcc ft_test_libc.c -L. -l:libft.a -lbsd -o test
// Run with valgrind: valgrind ./test
int	main(void)
{
	int	i;
	int num_tests = 23;
	int	(*tests[num_tests])(void);

	tests[0] = test_ft_isalpha;
	tests[1] = test_ft_isdigit;
	tests[2] = test_ft_isalnum;
	tests[3] = test_ft_isascii;
	tests[4] = test_ft_isprint;
	tests[5] = test_ft_strlen;
	tests[6] = test_ft_memset;
	tests[7] = test_ft_bzero;
	tests[8] = test_ft_memcpy;
	tests[9] = test_ft_memmove;
	tests[10] = test_ft_strlcpy;
	tests[11] = test_ft_strlcat;
	tests[12] = test_ft_toupper;
	tests[13] = test_ft_tolower;
	tests[14] = test_ft_strchr;
	tests[15] = test_ft_strrchr;
	tests[16] = test_ft_strncmp;
	tests[17] = test_ft_memchr;
	tests[18] = test_ft_memcmp;
	tests[19] = test_ft_strnstr;
	tests[20] = test_ft_atoi;
	tests[21] = test_ft_calloc;
	tests[22] = test_ft_strdup;
	i = 0;
	while (i < num_tests)
	{
		if (tests[i]())
		{
			printf("Test FAILED\n");
			return (1);
		}
		printf("Test PASSED\n");
		printf("---\n");
		i++;
	}
	printf("All Tests PASSED\n");
	return (0);
}
