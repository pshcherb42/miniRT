/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:32:48 by pshcherb          #+#    #+#             */
/*   Updated: 2025/05/09 16:26:28 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	return (
		c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
	);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

double	custom_atof(const char *str)
{
	double 	result;
	double 	fraction;
	int		sign;

	result = 0.0;
	fraction = 1.0;
	sign = 1;
	while (ft_isspace(*str))
        str++;
	if (*str == '-')
	    sign = -1;
	while (ft_isdigit(*str++))
        result = (result * 10.0) + (*str - '0');
	if (*str == '.')
    {
        while (ft_isdigit(*str++))
        {
            fraction /= 10.0;
            result += (*str - '0') * fraction;
        }
    }
	return (result * sign);
}

#include <stdio.h>

int main()
{
    printf("Value: %f\n", custom_atof("42.5"));     // Output: Value: 42.500000
    printf("Value: %f\n", custom_atof("-3.14"));    // Output: Value: -3.140000
    printf("Value: %f\n", custom_atof("0.001"));    // Output: Value: 0.001000
    printf("Value: %f\n", custom_atof("bad_input")); // Output: Error: Invalid double value: bad_input
    printf("Value: %f\n", custom_atof("2.2.2"));    // Output: Error: Invalid double value: 2.2.2
    printf("Value: %f\n", custom_atof("123abc"));   // Output: Error: Invalid double value: 123abc
}