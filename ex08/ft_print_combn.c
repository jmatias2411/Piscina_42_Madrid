/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalomin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:20:10 by mpalomin          #+#    #+#             */
/*   Updated: 2025/03/01 18:08:36 by mpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int *tab, int n)
{
	int	i;
	bool	low;

	i = 1;
	low = 1;
	while (i < n)
	{
		if (tab[i - 1] >= tab[i])
		{
			low = 0;
		}
		i++;
	}
	if (low)
	{
		i = 0;
		while (i < n)
			ft_putchar(tab[i++] + 48);
		if (tab[0] < (10 - n))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	tab[n];

	i = 0;
	while (i < n)
	{
		tab[i++] = 0;
	}
	while (tab[0] <= (10 - n) && n >= 1 && n < 10)
	{
		print(tab, n);
		tab[n - 1]++;
		i = n - 1;
		while (i && n > 1)
		{
			if (tab[i] > 9)
			{
				tab[i - 1]++;
				tab[i] = 0;
			}
			i--;
		} 
	}
}

int	main(void)
{
	ft_print_combn(0);
} 
