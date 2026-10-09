/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehale <ehale@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 13:02:41 by ehale             #+#    #+#             */
/*   Updated: 2026/10/09 14:43:51 by ehale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	print_test_name(char *name)
{
	printf("Unittest: %s\n", name);
}

int	test_ft_lstnew(void)
{
	print_test_name("ft_lstnew");
	char	*test_data = ft_strdup("test");
	t_list	*test_node = ft_lstnew(test_data);
	if (test_node->next)
		return (1);
	printf("%s\n", (char *) test_node->content);
	ft_lstdelone(test_node, free);
	return (0);
}

int	test_ft_lstadd_front(void)
{
	print_test_name("ft_lstadd_front");
	t_list	*test_node = NULL;
	char	*test_data1 = ft_strdup("test1");
	char	*test_data2 = ft_strdup("test2");
	ft_lstadd_front(&test_node, ft_lstnew(test_data1));
	if (test_node->next)
		return (1);
	printf("%s\n", (char *) test_node->content);
	ft_lstadd_front(&test_node, ft_lstnew(test_data2));
	if (test_node->next->next)
		return (1);
	printf("%s\n", (char *) test_node->content);
	printf("%s\n", (char *) test_node->next->content);
	ft_lstclear(&test_node, free);
	return (0);
}

int	test_ft_lstsize(void)
{
	print_test_name("ft_lstsize");
	char	*test_data1 = ft_strdup("test1");
	char	*test_data2 = ft_strdup("test2");
	char	*test_data3 = ft_strdup("test3");
	t_list	*test_node = ft_lstnew(test_data1);
	ft_lstadd_back(&test_node, ft_lstnew(test_data2));
	ft_lstadd_back(&test_node, ft_lstnew(test_data3));
	if (ft_lstsize(test_node) != 3)
		return (1);
	ft_lstclear(&test_node, free);
	return (0);
}

int	test_ft_lstlast(void)
{
	print_test_name("ft_lstlast");
	char	*test_data1 = ft_strdup("test1");
	char	*test_data2 = ft_strdup("test2");
	char	*test_data3 = ft_strdup("test3");
	t_list	*test_node = ft_lstnew(test_data1);
	ft_lstadd_back(&test_node, ft_lstnew(test_data2));
	ft_lstadd_back(&test_node, ft_lstnew(test_data3));
	t_list	*last = ft_lstlast(test_node);
	if (last->next)
		return (1);
	printf("%s\n", (char *) last->content);
	ft_lstclear(&test_node, free);
	return (0);
}

int	test_ft_lstadd_back(void)
{
	print_test_name("ft_lstadd_back");
	t_list	*test_node = NULL;
	char	*test_data1 = ft_strdup("test1");
	char	*test_data2 = ft_strdup("test2");
	ft_lstadd_back(&test_node, ft_lstnew(test_data1));
	if (test_node->next)
		return (1);
	printf("%s\n", (char *) test_node->content);
	ft_lstadd_back(&test_node, ft_lstnew(test_data2));
	if (test_node->next->next)
		return (1);
	printf("%s\n", (char *) test_node->content);
	printf("%s\n", (char *) test_node->next->content);
	ft_lstclear(&test_node, free);
	return (0);
}

static void	lstiterprintwrapper(void *str)
{
	printf("%s\n", (char *) str);
}

int test_ft_lstiter(void)
{
	print_test_name("ft_lstiter");
	char	*test_data1 = ft_strdup("test1");
	char	*test_data2 = ft_strdup("test2");
	char	*test_data3 = ft_strdup("test3");
	t_list	*test_node = ft_lstnew(test_data1);
	ft_lstadd_back(&test_node, ft_lstnew(test_data2));
	ft_lstadd_back(&test_node, ft_lstnew(test_data3));
	ft_lstiter(test_node, lstiterprintwrapper);
	ft_lstclear(&test_node, free);
	return (0);
}

static void	*lstmapupper(void *str)
{
	char	*cpy;
	char	*new;

	cpy = str;
	new = (char *) malloc(sizeof(char) * (ft_strlen(cpy) + 1));
	unsigned int i;
	for (i = 0; cpy[i]; i++)
		new[i] = ft_toupper(cpy[i]);
	new[i] = '\0';
	return (new);
}

int test_ft_lstmap(void)
{
	print_test_name("ft_lstmap");
	char	*test_data1 = ft_strdup("test1");
	char	*test_data2 = ft_strdup("test2");
	char	*test_data3 = ft_strdup("test3");
	t_list	*test_node = ft_lstnew(test_data1);
	ft_lstadd_back(&test_node, ft_lstnew(test_data2));
	ft_lstadd_back(&test_node, ft_lstnew(test_data3));
	t_list	*new_list = ft_lstmap(test_node, lstmapupper, free);
	ft_lstiter(new_list, lstiterprintwrapper);
	ft_lstclear(&test_node, free);
	ft_lstclear(&new_list, free);
	return (0);
}

// Clear and delete are implicitly tested in almost each test case. 
// Valgrind handles the rest.
// Compile and run: make,
// then: gcc ft_test_ll.c -L. -l:libft.a -lbsd -o test
// Run with valgrind: valgrind ./test
int	main(void)
{
	int	i;
	int num_tests = 7;
	int	(*tests[num_tests])(void);

	tests[0] = test_ft_lstnew;
	tests[1] = test_ft_lstadd_front;
	tests[2] = test_ft_lstsize;
	tests[3] = test_ft_lstlast;
	tests[4] = test_ft_lstadd_back;
	tests[5] = test_ft_lstiter;
	tests[6] = test_ft_lstmap;
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