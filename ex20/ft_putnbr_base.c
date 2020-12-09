/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:28:50 by jpalma            #+#    #+#             */
/*   Updated: 2020/12/02 09:28:53 by jpalma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	dec_to_base(int nbr, char *base, int base_len)
{
	if (nbr < 1 - base_len)
		dec_to_base(nbr / base_len, base, base_len);
	write(1, &base[-nbr % base_len], 1);
}

int		has_dup(const char *base)
{
	char	*bs;
	int		i;
	int		j;
	int		ret;

	bs = (char *)base;
	i = 0;
	ret = 0;
	while (bs[i] != '\0')
	{
		j = i + 1;
		while (bs[j] != '\0')
		{
			if (bs[i] == bs[j])
			{
				ret = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

int		has_sign(const char *base)
{
	char	*bs;
	int		i;
	int		ret;

	bs = (char *)base;
	i = 1;
	ret = 0;
	while (*bs != '\0')
	{
		if (*(bs) == '-' || *(bs) == '+')
		{
			ret = 1;
			break ;
		}
		bs++;
	}
	return (ret);
}

int		base_valid(char *base, int base_len)
{
	int	is_valid;

	is_valid = 0;
	if (base_len < 2)
		is_valid = 1;
	if (has_dup(base))
		is_valid = 1;
	if (has_sign(base))
		is_valid = 1;
	return (is_valid);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	char	*base_str;

	base_len = 0;
	base_str = base;
	while (*(base_str++))
		base_len++;
	if (base_valid(base, base_len))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		dec_to_base(nbr, base, base_len);
	}
	else
		dec_to_base(-nbr, base, base_len);
}
