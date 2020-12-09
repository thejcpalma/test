/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpalma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:29:07 by jpalma            #+#    #+#             */
/*   Updated: 2020/12/02 09:29:09 by jpalma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space_or_sign(char c)
{
	int is_space_or_sign;

	is_space_or_sign = 0;
	if ((c == ' ' || c == '\n' || c == '\t'
			|| c == '\v' || c == '\f' || c == '\r'))
		is_space_or_sign = 1;
	if (c == '+' || c == '-')
		is_space_or_sign = 2;
	return (is_space_or_sign);
}

int	is_from_base(const char *num, const char *base)
{
	int		is_num;
	char	*str;
	char	*num_str;

	str = (char *)base;
	num_str = (char *)num;
	is_num = 0;
	while (*(num++) != 0)
	{
		while (*(str++) != 0)
		{
			if (*str == *num)
				is_num = 1;
		}
	}
	return (is_num);
}

int	check_base(char *base, int base_len)
{
	char	*bs;
	int		i;
	int		j;
	int		ret;

	if (base_len < 2)
		return (1);
	bs = (char *)base;
	i = 0;
	ret = 0;
	while (bs[i] != '\0')
	{
		j = i + 1;
		if (bs[i] == '-' || bs[i] == '+')
			ret = 1;
		while (bs[j] != '\0')
		{
			if (bs[i] == bs[j])
				ret = 1;
			j++;
		}
		i++;
	}
	return (ret);
}

int	base_to_dec(char *str, char *base, int base_len)
{
	int		pow;
	char	*str_nbr;
	int		i;
	int		ret;

	pow = 1;
	ret = 0;
	str_nbr = str;
	while (*(str_nbr) != '\0')
	{
		i = 0;
		while (base[i] != *str_nbr)
			i++;
		ret = ret + pow * i;
		pow *= base_len;
		str_nbr++;
	}
	return (ret);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	char	*base_str;
	int		base_len;

	sign = 1;
	base_len = 0;
	base_str = base;
	while (*(base_str++))
		base_len++;
	if (check_base(base, base_len))
		return (0);
	if (is_from_base(str, base))
		return (0);
	while (is_space_or_sign(*str) == 1)
		str++;
	while (is_space_or_sign(*str) == 2)
	{
		if (*(str) == '-')
			sign *= -1;
		str++;
	}
	return (base_to_dec(str, base, base_len) * sign);
}
