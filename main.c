/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 17:06:39 by mskeleto          #+#    #+#             */
/*   Updated: 2020/12/09 17:06:44 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	sastantua(int size);

int	ft_putchar(char si)
{
	write(1, &si, 1);
	return (0);
}

int	ft_isdigit(int c)
{
	if ((c > 47) && (c < 58))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long int	resul;
	int			positive;

	positive = 1;
	resul = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		positive = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		resul = resul * 10 + (*str - 48);
		if ((resul > 2147483648) && (positive == -1))
			return (0);
		if ((resul > 2147483647) && (positive == 1))
			return (-1);
		str++;
	}
	return (resul * positive);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	sastantua(ft_atoi(argv[1]));
	return (0);
}
