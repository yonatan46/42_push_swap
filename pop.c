#include <stdio.h>
#include <stdlib.h>
int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;
	int					i;
	int					d;

	result = 0;
	i = 0;
	d = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		++i;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
		d++;
	}
	if ((result >= 9223372036854775808ULL && sign == 1) || d > 19)
		return (-(sign == 1));
	return (result * sign);
}
int main(int ac, char **av)
{
	printf("Our Atoi says:	%d\n", ft_atoi(av[1]));
	printf("PC  Atoi says:	%d\n",	 atoi(av[1]));
}