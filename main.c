/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <pcariou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:39:59 by pcariou           #+#    #+#             */
/*   Updated: 2020/09/29 18:39:53 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

size_t	ft_strlen(const char *s);
char 	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
char	*ft_strdup(const char *s);
ssize_t ft_read(int fd, void *buf, size_t count);

void yellow() {
	  printf("\033[1;33m");
}

void reset() {
	  printf("\033[0m");
}

int main()
{
	char dest0[50];
	char dest[80];
	char destc[80];
	char dest2[80];
	char dest2c[80];
	char dest3[50];
	char dest4[50];
	char dest4c[50];
	char destr[50];
	char destrc[50];
	char destz[50];
	int fd;

	yellow();
	printf("****ft_strlen****\n");
	reset();
	printf("\n");
	printf("ft_strlen : %ld\n", ft_strlen("salut"));
	printf("strlen    : %ld\n", strlen("salut"));
	printf("ft_strlen : %ld\n", ft_strlen("fghjfjgg fgugfyu &&\n"));
	printf("strlen    : %ld\n", strlen("fghjfjgg fgugfyu &&\n"));
	printf("ft_strlen : %ld\n", ft_strlen(""));
	printf("strlen    : %ld\n", strlen(""));

	write(1, "\n", 1);
	
	yellow();
	printf("****ft_strcpy****\n");
	reset();
	printf("\n");
	printf("adress before call ft_strcpy: %p\n", dest);
	printf("adress after call ft_strcpy : %p\n", ft_strcpy(dest, "bienlebonjouratoi&*("));
	printf("ft_strcpy : %s\n", dest);
	printf("strcpy    : %s\n", strcpy(dest3, "bienleboujouratoi&*("));
	printf("ft_strcpy : %s\n", ft_strcpy(dest0, ""));
	printf("strcpy    : %s\n", strcpy(dest0, ""));

	write(1, "\n", 1);
	
	yellow();
	printf("****ft_strcmp****\n");
	reset();
	printf("\n");
	printf("ft_strcmp : %d\n", ft_strcmp("salutations", "salutations"));
	printf("strcmp    : %d\n", strcmp("salutations", "salutations"));
	printf("ft_strcmp : %d\n", ft_strcmp("salutations", "salutacions"));
	printf("strcmp    : %d\n", strcmp("salutations", "salutacions"));
	printf("ft_strcmp : %d\n", ft_strcmp("salutations", "salztations"));
	printf("strcmp    : %d\n", strcmp("salutations", "salztations"));
	printf("ft_strcmp : %d\n", ft_strcmp("", "salutations"));
	printf("strcmp    : %d\n", strcmp("", "salutations"));
	printf("ft_strcmp : %d\n", ft_strcmp("salutations", ""));
	printf("strcmp    : %d\n", strcmp("salutations", ""));
	printf("ft_strcmp : %d\n", ft_strcmp("", ""));
	printf("strcmp    : %d\n", strcmp("", ""));


	write(1, "\n", 1);

	yellow();
	printf("****ft_write****\n");
	reset();
	printf("\n");
	printf("ret : %ld  errno : %d\n", ft_write(1, "salut\n", 6), errno);
	printf("ret : %ld  errno : %d\n\n", write(1, "salut\n", 6), errno);
	printf("ret : %ld  errno : %d\n", ft_write(1, 0, 2), errno);
	printf("ret : %ld  errno : %d\n\n", write(1, 0, 2), errno);
	printf("ret : %ld  errno : %d\n", ft_write(-1, "youpi\n", 6), errno);
	printf("ret : %ld  errno : %d\n\n", write(-1, "youpi\n", 6), errno);
	printf("ret : %ld  errno : %d\n", ft_write(STDOUT_FILENO, "stdout is the test\n", 19), errno);
	printf("ret : %ld  errno : %d\n\n", write(STDOUT_FILENO, "stdout is the test\n", 19), errno);


	write(1, "\n", 1);

	yellow();
	printf("****ft_read****\n");
	reset();
	printf("\n");
	printf("ft_read :\n\n");
	fd = open("./Makefile", O_RDONLY, 0); 
	printf("ret : %ld  errno : %d\n", ft_read(fd, &dest, 30), errno);
	printf("%s\n", dest);
	printf("ret : %ld  errno : %d\n", ft_read(fd, &destc, 30), errno);
	printf("%s\n", destc);
	close(fd);
	printf("\n");
	printf("read :\n\n");
	fd = open("./Makefile", O_RDONLY, 0);
	printf("ret : %ld  errno : %d\n", read(fd, &dest2, 30), errno);
	printf("%s\n", dest2);
	printf("ret : %ld  errno : %d\n", read(fd, &dest2c, 30), errno);
	printf("%s\n", dest2c);
	close(fd);
	printf("\n");	
	fd = open("./main.c", O_RDONLY, 0);
	printf("ret : %ld  errno : %d\n", ft_read(fd, 0, 30), errno);
	close(fd);
	fd = open("./main.c", O_RDONLY, 0);
	printf("ret : %ld  errno : %d\n", read(fd, 0, 30), errno);
	close(fd);
	fd = open("./main.c", O_RDONLY, 0);
	printf("ret : %ld  errno : %d\n", ft_read(fd, &destz, 0), errno);
	close(fd);
	fd = open("./main.c", O_RDONLY, 0);
	printf("ret : %ld  errno : %d\n", read(fd, &destz, 0), errno);
	close(fd);
	printf("\n");
	printf("ret : %ld  errno : %d\n", ft_read(4, &dest4, 100), errno);
	printf("ret : %ld  errno : %d\n", read(4, &dest4c, 100), errno);
	printf("stdin ft_read ... \n");
	printf("ret : %ld  errno : %d\n", ft_read(STDIN_FILENO, &destr, 5), errno);
	printf("%s\n", destr);

	write(1, "\n", 1);

	yellow();
	printf("****ft_strdup****\n");
	reset();
	printf("\n");
	printf("ft_strdup : %s\n", ft_strdup("strdup c'est pas du r/p"));
	printf("strdup    : %s\n", strdup("strdup c'est pas du r/p"));
	printf("ft_strdup : %s\n", ft_strdup(""));
	printf("strdup    : %s\n", strdup(""));
	printf("ft_strdup : %s\n", ft_strdup("hsdwui 6768&&&&\n"));
	printf("strdup    : %s\n", strdup("hsdwui 6768&&&&\n"));

	return (0);
}
