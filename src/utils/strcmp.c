/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 03:31:57 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/18 03:36:51 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	fl_strcmp(char *s1, const char *s2)
{
	int	index;

	if (!s1 || !s2)
		return ((void *)0);
	while (s1[++index] || s2[index])
		if (s1[index] != s2[index])
			return (0);
	return (1);
}
