/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:44:46 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/22 15:11:04 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "memctx.h"

static int	add_wrd(char *dest, char *src, int buffer)
{
	int	index;

	index = -1;
	while (src[++index])
		dest[++buffer] = src[index];
	return (buffer);
}

char  *fl_strjoin_sep(char *s1, char* s2, char *set)
{
	int		buff;
	int		tlen;
	char	*res;

	if (!s1 || !s2 || !set)
		return ((void *)0);
	tlen = fl_strlen(s1) + fl_strlen(s2) + fl_strlen(set);
	res = alloc(tlen + 1);
	if (!res)
		return ((void *)0);
	buff = -1;
	buff = add_wrd(res, s1, buff);
	buff = add_wrd(res, set, buff);
	buff = add_wrd(res, s2, buff);
	res[tlen] = '\0';
	return (res);
}
