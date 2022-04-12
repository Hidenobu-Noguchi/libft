#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	return (ft_strncmp(s1, s2, n) ? 0 : 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (i < (n - 1))
	{
		if (*(s1 + i) == '\0' || *(s2 + i) == '\0')
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		if ((*(s1 + i) - *(s2 + i)) != 0)
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i += 1;
	}
	return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}

int	ft_strnequ(char const *s1, char const *s2, size_t n);

#include <string.h>
#include <stdio.h>

int	main(void)
{
	int	diff = 0;
	char	str0[10] = "123456789";
	char	str1[10] = "1234567890";
	char	str2[10] = "1234567890";
	char	str3[1] = "\0";
	char	str4[1];
	char	*str5;

	printf("\nstr0[10] = ");
	for (int i = 0; i < 10; i++)
		if (str0[i] == '\0')
			printf("\\0");
		else
			printf("%c", str0[i]);

	printf("\n\n");
	diff = strncmp(str0, "123456789", 20);
	printf("strncmp(str0, \"123456789\", 20);       = %d\n", diff);
	diff = ft_strnequ(str0, "123456789", 20);
	printf("ft_strnequ(str0, \"123456789\", 20);    = %d\n", diff);

	printf("\n");
	diff = strncmp(str0, "12345a789", 10);
	printf("strncmp(str0, \"12345a789\", 10);       = %d\n", diff);
	diff = ft_strnequ(str0, "12345a789", 10);
	printf("ft_strnequ(str0, \"12345a789\", 10);    = %d\n", diff);
	printf("\n");
	diff = strncmp(str0, "12345", 10);
	printf("strncmp(str0, \"12345\", 10);           = %d\n", diff);
	diff = ft_strnequ(str0, "12345", 10);
	printf("ft_strnequ(str0, \"12345\", 10);        = %d\n", diff);

	printf("\n");
	diff = strncmp(str0, "123456789012", 10);
	printf("strncmp(str0, \"123456789012\", 10);    = %d\n", diff);
	diff = ft_strnequ(str0, "123456789012", 10);
	printf("ft_strnequ(str0, \"123456789012\", 10); = %d\n", diff);

	printf("\n------------------------------\n");
	printf("\nstr1[10] = ");
	for (int i = 0; i < 10; i++)
		if (str1[i] == '\0')
			printf("\\0");
		else
			printf("%c", str1[i]);

	printf("\nstr2[10] = ");
	for (int i = 0; i < 10; i++)
		if (str2[i] == '\0')
			printf("\\0");
		else
			printf("%c", str2[i]);

	printf("\n\n");
	diff = strncmp(str1, str2, 20);
	printf("strncmp(str1, str2, 20);              = %d\n", diff);
	diff = ft_strnequ(str1, str2, 20);
	printf("ft_strnequ(str1, str2, 20);           = %d\n", diff);

	printf("\n");
	diff = strncmp("", "abcde", 10);
	printf("strncmp(\"\", \"abcde\", 10);             = %d\n", diff);
	diff = ft_strnequ("", "abcde", 10);
	printf("ft_strnequ(\"\", \"abcde\", 10);          = %d\n", diff);

	printf("\n");
	diff = strncmp("abcde", "", 10);
	printf("strncmp(\"abcde\", \"\", 10);             = %d\n", diff);
	diff = ft_strnequ("abcde", "", 10);
	printf("ft_strnequ(\"abcde\", \"\", 10);          = %d\n", diff);

	printf("\n");
	diff = strncmp("\0", "1", 10);
	printf("strncmp(\"\\0\", \"1\", 10);               = %d\n", diff);
	diff = ft_strnequ("\0", "1", 10);
	printf("ft_strnequ(\"\\0\", \"1\", 10);            = %d\n", diff);

	printf("\n");
	diff = strncmp("1", "\0", 10);
	printf("strncmp(\"1\", \"\\0\", 10);               = %d\n", diff);
	diff = ft_strnequ("1", "\0", 10);
	printf("ft_strnequ(\"1\", \"\\0\", 10);            = %d\n", diff);

	printf("\n");
	diff = strncmp("", "", 10);
	printf("strncmp(\"\", \"\", 10);                  = %d\n", diff);
	diff = ft_strnequ("", "", 10);
	printf("ft_strnequ(\"\", \"\", 10);               = %d\n", diff);

	printf("\n------------------------------\n");
	printf("\nstr3[1] = \\0");
	printf("\n\n");
	diff = strncmp(str3, "1", 10);
	printf("strncmp(str3, \"1\", 10);               = %d\n", diff);
	diff = ft_strnequ(str3, "1", 10);
	printf("ft_strnequ(str3, \"1\", 10);            = %d\n", diff);

	printf("\n------------------------------\n");
	printf("\nstr4[1];");
	printf("\n\n");
	diff = strncmp(str4, "1", 10);
	printf("strncmp(str4, \"1\", 10);               = %d\n", diff);
	diff = ft_strnequ(str4, "1", 10);
	printf("ft_strnequ(str4, \"1\", 10);            = %d\n", diff);

	printf("\n------------------------------\n");
	printf("\n*str5;");
	printf("\n\n");
	diff = strncmp("1", str5, 10);
	printf("strncmp(\"1\", str5, 10);               = %d\n", diff);
	diff = ft_strnequ("1", str5, 10);
	printf("ft_strnequ(\"1\", str5, 10);            = %d\n", diff);

	return (0);
}
