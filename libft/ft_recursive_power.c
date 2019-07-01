/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_recursive_power.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 15:30:26 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/07/01 15:33:53 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, unsigned int power)
{
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
