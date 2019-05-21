/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_recursive_power.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 17:32:44 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/05/21 17:43:28 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power > 0)
		nb = nb * ft_recursive_power(nb, power - 1);
	return (nb);
}
