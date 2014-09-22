#include <stdio.h>

int radcon(char* str, int n, int radix);

int main(void)
{
	char str[20];
	radcon (str, 123, 16);
	printf("%s\n", str);
}

int radcon(char* str, int n, int radix)
{
	/* return 0 on success */
	int quot = n;
	int tmp[32];
	int i = 0;
	
	while (quot > 0)
	{
		tmp[i++] = quot % radix;
		quot /= radix;
	}

	int j = 0;
	for (; i >= 0; i--, j++)
	{
		if (tmp[i] < 10)
			str[j] = tmp[i] + 48;
		else
		{
			str[j] = tmp[i] + 55;
		}
	}

	str[j] = '\0';
	
	return 0;
}
