/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 23:30:09 by mskeleto          #+#    #+#             */
/*   Updated: 2020/03/08 23:33:15 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char si);

int		co(int a, int p1)
{
	if (p1 == 1)
	{
		if (a == 0)
			return (0);
		else
			return ((a + 2 + co((a - 1), 1)));
	}
	if (p1 == 2)
	{
		if (a == 1)
			return (0);
		else
			return ((a - 2) / 2 + 2 + co((a - 1), 2));
	}
	if (p1 == 3)
		return (co((a), 2) + co((a - 1), 1));
	else
		return (0);
}

void	pr(int l, int pp, int p2)
{
	while (l <= pp)
	{
		if (p2 == 1)
			ft_putchar(' ');
		if (p2 == 2)
			ft_putchar('*');
		if (p2 == 3)
			ft_putchar('|');
		if (p2 == 4)
		{
			if (l == pp - 1)
				ft_putchar('$');
			else
				ft_putchar('|');
		}
		l++;
	}
}

void	pu(int u, int size)
{
	int j;
	int l;
	int pp;
	int pz;

	j = 1;
	pz = co((u), 3) * 2 + 1;
	while (j <= (u + 2))
	{
		pp = co((size), 3) + size + 2 - co((u), 3) - j;
		l = 1;
		pr(l, pp, 1);
		ft_putchar('/');
		pr(l, pz, 2);
		ft_putchar('\\');
		j++;
		ft_putchar('\n');
		pz += 2;
	}
}

void	ddd(int u, int j, int pz, int sr)
{
	int pp;
	int l;

	pz = ((pz - 1) / 2 - (u - 1) / 2 + j - 1);
	while (j <= (u + 2))
	{
		pp = u + 2 - j;
		l = 1;
		pr(l, pp, 1);
		ft_putchar('/');
		pr(l, pz, 2);
		if ((u > 4) && (j == sr))
			pr(l, (u - ((u + 1) % 2)), 4);
		else if (j > ((u + 1) % 2 + 2))
			pr(l, (((u - 1) / 2) * 2 + 1), 3);
		else if (j <= ((u + 1) % 2 + 2))
			pr(l, (u - (u + 1) % 2), 2);
		pr(l, pz, 2);
		ft_putchar('\\');
		j++;
		ft_putchar('\n');
		pz += 1;
	}
}

int		sastantua(int size)
{
	int u;
	int sr;

	if (size > 0)
	{
		u = 1;
		while (u < size)
		{
			pu(u, size);
			u++;
		}
		if (u == size)
		{
			sr = 3 + (u + 1) % 2 + ((u - 1) / 2);
			ddd(u, 1, (co((u), 3) * 2 + 1), sr);
		}
	}
	return (0);
}
