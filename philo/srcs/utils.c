
#include "philo.h"

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(const char *str)
{
	long	nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	if (*str == '+' && sign == 1)
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (nb > LONG_MAX / 10 || (nb == LONG_MAX / 10 && *str - '0' > 7))
			return ((((sign + 1) / 2) * -1));
		nb = (*str - '0') + (nb * 10);
		str++;
	}
	return (nb * sign);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *) s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}
