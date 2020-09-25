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


int main()
{
	char dest[50];
	char dest2[50];
	char dest3[50];
	int fd = open("./main.c", O_RDONLY, 0); 

	printf("****ft_strlen****\n\n");
	printf("ft_strlen : %ld\n", ft_strlen("salut"));
	printf("strlen : %ld\n", strlen("salut"));
	printf("ft_strlen : %ld\n", ft_strlen("fghjfjgg fgugfyu &&\n"));
	printf("strlen : %ld\n", strlen("fghjfjgg fgugfyu &&\n"));
	printf("ft_strlen : %ld\n", ft_strlen(""));
	printf("strlen : %ld\n", strlen(""));

	write(1, "\n", 1);

	printf("****ft_strcpy****\n\n");
	printf("adress before call ft_strcpy: %p\n", dest);
	printf("adress after call ft_strcpy : %p\n", ft_strcpy(dest, "bienvenue"));
	printf("ft_strcpy : %s\n", dest);
	printf("strcpy : %s\n", ft_strcpy(dest3, "bienvenue"));

	write(1, "\n", 1);

	printf("****ft_strcmp****\n\n");
	printf("ft_strcmp : %d\n", ft_strcmp("salutations", "salutations"));
	printf("strcmp : %d\n", strcmp("salutations", "salutations"));
	printf("ft_strcmp : %d\n", ft_strcmp("salutations", "salutacions"));
	printf("strcmp : %d\n", strcmp("salutations", "salutacions"));
	printf("ft_strcmp : %d\n", ft_strcmp("salutations", "salztations"));
	printf("strcmp : %d\n", strcmp("salutations", "salztations"));

	write(1, "\n", 1);

	printf("****ft_write****\n\n");
	printf("ret : %ld\n", ft_write(1, "salut\n", 6));
	printf("ret : %ld\n", ft_write(1, 0, 2));
	printf("errno : %d\n", errno);
	printf("ret : %ld\n", write(1, 0, 2));
	printf("errno : %d\n", errno);

	write(1, "\n", 1);

	printf("****ft_read****\n\n");
	printf("ret : %ld\n", ft_read(fd, &dest2, 30));
	printf("%s\n", dest2);
	printf("ret : %ld\n", ft_read(fd, &dest2, 100));
	printf("%s\n", dest2);
	printf("ret : %ld\n", ft_read(fd, 0, 30));

	write(1, "\n", 1);

	printf("****ft_strdup****\n\n");
	printf("ft_strdup : %s\n", ft_strdup("strdup c'est pas du r/p"));
	printf("strdup : %s\n", strdup("strdup c'est pas du r/p"));
	printf("ft_strdup : %s\n", ft_strdup(""));
	printf("strdup : %s\n", strdup(""));
	printf("ft_strdup : %s\n", ft_strdup("hsdwui 6768&&&&\n"));
	printf("strdup : %s\n", strdup("hsdwui 678&&&&\n"));

	close(fd);
	return (0);
}
