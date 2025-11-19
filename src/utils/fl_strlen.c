/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:04:44 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/19 12:04:45 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	fl_strlen(char *s)
{
	int	index;

	index = 0;
	while (*(s + (++index))) ;
	return (index);
}
