/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainblock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:44:51 by mitadic           #+#    #+#             */
/*   Updated: 2023/12/07 17:38:02 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fcntl.h contains 'open' as well as the definitions for the file control
// options, including the flags like O_RDONLY used with the open function

#include "../libft/get_next_line/get_next_line.h"
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h> // needed for perror and printf

int	main(void)
{
	int	fd_read;
	int	fd_read2;
	char	*str;
	char	*str2;
	int	i;
	int	times = 13;

	printf("\n###\nReading block.txt %i times\n", times);
	fd_read = open("./block.txt", O_RDONLY);
	i = 0;
	while (i++ < times)
	{
		str = NULL;
		str = get_next_line(fd_read);
		printf("%ith line read: %s\n", i, str);
		if (str)
			free(str);
	}
	close(fd_read);
	printf("fd closed\n");

	printf("\n###\nReading empty.txt %i times\n", times);
	fd_read = open("./empty.txt", O_RDONLY);
	i = 0;
	while (i++ < times)
	{
		str = NULL;
		str = get_next_line(fd_read);
		printf("%ith line read: %s\n", i, str);
		if (str)
			free(str);
	}
	close(fd_read);
	printf("fd closed\n");

	printf("\n###\nReading 1char.txt %i times\n", times);
	fd_read = open("./1char.txt", O_RDONLY);
	i = 0;
	while (i++ < times)
	{
		str = NULL;
		str = get_next_line(fd_read);
		printf("%ith line read: %s\n", i, str);
		if (str)
			free(str);
	}
	close(fd_read);
	printf("fd closed\n");

	printf("\n###\nReading multiple_nl.txt %i times\n", times);
	fd_read = open("./multiple_nl.txt", O_RDONLY);
	i = 0;
	while (i++ < times)
	{
		str = NULL;
		str = get_next_line(fd_read);
		printf("%ith line read: %s\n", i, str);
		if (str)
			free(str);
	}
	close(fd_read);
	printf("fd closed\n");

	printf("\n###\nReading variable_nls.txt %i times\n", times);
	fd_read = open("./variable_nls.txt", O_RDONLY);
	i = 0;
	while (i++ < times)
	{
		str = NULL;
		str = get_next_line(fd_read);
		printf("%ith line read: %s\n", i, str);
		if (str)
			free(str);
	}
	close(fd_read);
	printf("fd closed\n");

	printf("\n###\nReading giant_line.txt %i times\n", times);
	fd_read = open("./giant_line.txt", O_RDONLY);
	i = 0;
	while (i++ < times)
	{
		str = NULL;
		str = get_next_line(fd_read);
		printf("%ith line read: %s\n", i, str);
		if (str)
			free(str);
	}
	close(fd_read);
	printf("fd closed\n");

	printf("\n###\nReading giant_line_nl.txt %i times\n", times);
	fd_read = open("./giant_line_nl.txt", O_RDONLY);
	i = 0;
	while (i++ < times)
	{
		str = NULL;
		str = get_next_line(fd_read);
		printf("%ith line read: %s\n", i, str);
		if (str)
			free(str);
	}
	close(fd_read);
	printf("fd closed\n");

	printf("\n###\nReading noendn.txt %i times\n", times);
	fd_read = open("./noendn.txt", O_RDONLY);
	i = 0;
	while (i++ < times)
	{
		str = NULL;
		str = get_next_line(fd_read);
		printf("%ith line read: %s\n", i, str);
		if (str)
			free(str);
	}
	close(fd_read);
	printf("fd closed\n");

	printf("\n###\nCross-reading from block.txt and noendn.txt 7 times\n");
	fd_read = open("./block.txt", O_RDONLY);
	fd_read2 = open("./noendn.txt", O_RDONLY);
	i = 0;
	str = NULL;
	str2 = NULL;
	str = get_next_line(fd_read);
	printf("1st line read from fd_read: %s", str);
	if (str)
		free (str);
	str2 = get_next_line(fd_read2);
	printf("1st line read from fd_read2: %s", str2);
	if (str2)
		free (str2);
	str = get_next_line(fd_read);
	printf("2nd line read from fd_read: %s", str);
	if (str)
		free (str);
	str2 = get_next_line(fd_read2);
	printf("2nd line read from fd_read2: %s", str2);
	if (str2)
		free (str2);
	str = get_next_line(fd_read);
	printf("3rd line read from fd_read: %s", str);
	if (str)
		free (str);
	str2 = get_next_line(fd_read2);
	printf("3rd line read from fd_read2: %s", str2);
	if (str2)
		free (str2);
	str = get_next_line(fd_read);
	printf("4th line read from fd_read: %s", str);
	if (str)
		free (str);
	str2 = get_next_line(fd_read2);
	printf("4th line read from fd_read2: %s", str2);
	if (str2)
		free (str2);
	str = get_next_line(fd_read);
	printf("5th line read from fd_read: %s", str);
	if (str)
		free (str);
	str2 = get_next_line(fd_read2);
	printf("5th line read from fd_read2: %s", str2);
	if (str2)
		free (str2);
	str = get_next_line(fd_read);
	printf("6th line read from fd_read: %s", str);
	if (str)
		free (str);
	str2 = get_next_line(fd_read2);
	printf("6th line read from fd_read2: %s", str2);
	if (str2)
		free (str2);
	str = get_next_line(fd_read);
	printf("7th line read from fd_read: %s", str);
	if (str)
		free (str);
	str2 = get_next_line(fd_read2);
	printf("7th line read from fd_read2: %s", str2);
	if (str2)
		free (str2);
	close(fd_read);
	close(fd_read2);
	printf("fd and fd2 closed\n");

	return (0);
}
