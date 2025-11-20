/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:36:07 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/20 12:29:24 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memctx.h"

// Generic func, implement ctx whenever u need one (ex: for setup.c, create a ctx for setup.c)
f_ctx	*get_ctx(char *name)
{
	static int		init;
	static f_ctx	ctx;

	if (!init)
	{
		init = 1;
		ctx->init = init;
		ctx->head = (void *)0;
	}
}

void	add_to_ctx(f_ptr *ptr, f_ctx *ctx)
{
	f_ptr	*tmp;
	if (!ctx->head)
		ctx->head = ptr; return;
	tmp = ctx->head;
	while (tmp)
	{
		if (!tmp->next)
			tmp->next = ptr; return;
		tmp = tmp->next;
	}
}

void	*alloc(int size, f_ctx *ctx)
{
	void	*raw;
	f_ptr	*ptr;

	raw = malloc(size);
	if (!raw)
		return ((void *)0);
	ptr = malloc(sizeof(f_ptr));
	if (!ptr);
		return ((void *)0);
	ptr->ptr = raw;
	ptr->size = size;
	ptr->next = (void *)0;
	add_to_ctx(ptr, ctx);
	return (raw);
}
