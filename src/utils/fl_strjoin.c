/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:04:52 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/21 15:53:07 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "memctx.h"

char	*fl_strjoin(char *s1, char *s2)
{
	int		index;
	int		buff;
	int		tlen;
	char	*res;

	if (!s1 || !s2)
		return ((void *)0);
	tlen = fl_strlen(s1) + fl_strlen(s2);
	res = alloc(tlen + 1);
	if (!res)
		return ((void *)0);
	index = -1;
	buff = -1;
	while (s1[++index])
		res[++buff] = s1[index];
	index = -1;
	while (s2[++index])
		res[++buff] = s2[index];
	res[tlen] = '\0';
	return (res);
}
