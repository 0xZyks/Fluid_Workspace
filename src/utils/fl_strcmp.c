/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 03:31:57 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/24 17:12:58 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "utils.h"

int	fl_strcmp(char *s1, char *s2)
{
	int	index;

	if (!s1 || !s2)
		return (-1);
	index = -1;
	while (s1[++index] || s2[index])
		if (s1[index] != s2[index])
			return (0);
	return (1);
}
