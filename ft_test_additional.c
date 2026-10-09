/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_additional.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehale <ehale@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 11:48:24 by ehale             #+#    #+#             */
/*   Updated: 2026/10/09 14:29:32 by ehale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

static void	print_test_name(char *name)
{
	printf("Unittest: %s\n", name);
}

static void	print_strarr(char **arr)
{
	for (unsigned int i = 0; arr[i]; i++)
		printf("[%d]: %s\n", i, arr[i]);
}

static void	free_strarr(char **arr)
{
	for (unsigned int i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}

int	test_ft_substr(void)
{
	print_test_name("ft_substr");
	char *test = "MySubstring";
	char *mem = ft_substr(test, 0, 0);
	if (ft_strlen(mem) != 0)
	{
		free(mem);
		return (1);
	}
	free(mem);
	if (ft_strlen(mem = ft_substr(test, 20, 5)) != 0)
	{
		free(mem);
		return (1);
	}
	free(mem);
	printf("%s\n", mem = ft_substr(test, 5, 10));
	free(mem);
	printf("%s\n", mem = ft_substr(test, 5, 3));
	free(mem);
	return (0);
}

int	test_ft_strjoin(void)
{
	print_test_name("ft_strjoin");
	char *mem = ft_strjoin("", "");
	if (ft_strlen(mem) != 0)
	{
		free(mem);
		return (1);
	}
	free(mem);
	printf("%s\n", mem = ft_strjoin("Hello ", "World"));
	free(mem);
	printf("%s\n", mem = ft_strjoin("Bruh", ""));
	free(mem);
	return (0);
}

int	test_ft_strtrim(void)
{
	print_test_name("ft_strtrim");
	char *mem = ft_strtrim("  x x x    xx xxxxx ", " x");
	if (ft_strlen(mem) != 0)
	{
		free(mem);
		return (1);
	}
	free(mem);
	if (ft_strlen(mem = ft_strtrim("abc", "")) != 3)
	{
		free(mem);
		return (1);
	}
	free(mem);
	printf("%s\n", mem = ft_strtrim(" xx  xxx   Hello  x xx World  xxx ", " x"));
	free(mem);
	printf("%s\n", mem = ft_strtrim("asdasd", " x"));
	free(mem);
	return (0);
}

int	test_ft_split(void)
{
	print_test_name("ft_split");
	char **mem = ft_split("    Hello   World  !   ", ' ');
	print_strarr(mem);
	free_strarr(mem);
	mem = ft_split("", 'a');
	print_strarr(mem);
	free_strarr(mem);
	mem = ft_split("jw eut w   iotw  ", 'a');
	print_strarr(mem);
	free_strarr(mem);
	return (0);
}

int	test_ft_itoa(void)
{
	print_test_name("ft_itoa");
	char *mem = ft_itoa(0);
	printf("%s\n", mem);
	free(mem);
	printf("%s\n", mem = ft_itoa(2147483647));
	free(mem);
	printf("%s\n", mem = ft_itoa(-2147483648));
	free(mem);
	printf("%s\n", mem = ft_itoa(123));
	free(mem);
	printf("%s\n", mem = ft_itoa(-123));
	free(mem);
	return (0);
}

static char	strmapiupper(unsigned int i, char c)
{
	(void) i;
	return (ft_toupper(c));
}

int	test_ft_strmapi(void)
{
	print_test_name("ft_strmapi");
	char *mem = ft_strmapi("te123st", strmapiupper);
	printf("%s\n", mem);
	free(mem);
	return (0);
}

static void	striteriupper(unsigned int i, char *c)
{
	(void) i;
	*c = ft_toupper(*c);
}

int test_ft_striteri(void)
{
	print_test_name("ft_striteri");
	char test[] = "te123st";
	ft_striteri(test, striteriupper);
	printf("%s\n", test);
	return (0);
}

int test_ft_putchar_fd(void)
{
	print_test_name("ft_putchar_fd");
	int fd = open("test_file", O_RDWR | O_CREAT);
	ft_putchar_fd('g', fd);
	lseek(fd, SEEK_SET, 0);
	char s[10] = {0};
	read(fd, s, 2);
	close(fd);
	unlink("./test_file");
	printf("%s\n", s);
	return (0);
}

int test_ft_putstr_fd(void)
{
	print_test_name("ft_putstr_fd");
	int fd = open("test_file", O_RDWR | O_CREAT);
	ft_putstr_fd("test", fd);
	lseek(fd, SEEK_SET, 0);
	char s[10] = {0};
	read(fd, s, 5);
	close(fd);
	unlink("./test_file");
	printf("%s\n", s);
	return (0);
}

int test_ft_putendl_fd(void)
{
	print_test_name("ft_putendl_fd");
	int fd = open("test_file", O_RDWR | O_CREAT);
	ft_putendl_fd("test", fd);
	lseek(fd, SEEK_SET, 0);
	char s[10] = {0};
	read(fd, s, 6);
	close(fd);
	unlink("./test_file");
	printf("%s", s);
	return (0);
}

int test_ft_putnbr_fd(void)
{
	print_test_name("ft_putnbr_fd");
	int fd = open("test_file", O_RDWR | O_CREAT);
	ft_putnbr_fd(-123, fd);
	lseek(fd, SEEK_SET, 0);
	char s[10] = {0};
	read(fd, s, 5);
	close(fd);
	unlink("./test_file");
	printf("%s\n", s);
	return (0);
}

// Apparently there is an assert library.
// Compile and run: make,
// then: gcc ft_test_additional.c -L. -l:libft.a -lbsd -o test
// Run with valgrind: valgrind ./test
int	main(void)
{
	int	i;
	int num_tests = 11;
	int	(*tests[num_tests])(void);

	tests[0] = test_ft_substr;
	tests[1] = test_ft_strjoin;
	tests[2] = test_ft_strtrim;
	tests[3] = test_ft_split;
	tests[4] = test_ft_itoa;
	tests[5] = test_ft_strmapi;
	tests[6] = test_ft_striteri;
	tests[7] = test_ft_putchar_fd;
	tests[8] = test_ft_putstr_fd;
	tests[9] = test_ft_putendl_fd;
	tests[10] = test_ft_putnbr_fd;
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