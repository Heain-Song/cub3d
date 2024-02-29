/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:14:16 by ede-siga          #+#    #+#             */
/*   Updated: 2024/02/29 21:12:43 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int nb)
{
	if (nb >= '0' && nb <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	nb;
	int				sign;

	sign = 1;
	while (*str && ((*str >= '\t' && *str <= '\r') || (*str == ' ')))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	nb = 0;
	while (*str && *str != ',')
	{
		if (!ft_isdigit(*str) && *str != ',')
			return (-1);
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (nb * sign);
}
