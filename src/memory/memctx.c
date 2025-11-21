/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memctx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:36:07 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/21 15:11:29 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memctx.h"

void	set_ctx(char *name)
{
	f_ctx	*ctx;
	ctx = get_ctx();
	if (!ctx->init)
	{
		ctx->name = name;
		ctx->init = 1;
		ctx->free_all = free_ctx;
	}
}

f_ctx	*get_ctx(void)
{
	static f_ctx	ctx;
	return (&ctx);
}

void	free_ctx(f_ctx *ctx)
{
	f_ptr	*tmp;
	void	*tmp_ptr;

	while (ctx->head)
	{
		tmp = ctx->head->next;
		tmp_ptr = ctx->head->ptr;
		printf("Free %p - Value: %s in %s Context\n", tmp_ptr, (char *)tmp_ptr, ctx->name);
		free(ctx->head->ptr);
		free(ctx->head);
		ctx->head = tmp;
	}
}

void	add_to_ctx(f_ptr *ptr, f_ctx *ctx)
{
	f_ptr	*tmp;
	if (!ctx->head)
	{
		ctx->head = ptr;
		return;
	}
	tmp = ctx->head;
	while (tmp)
	{
		if (!tmp->next)
		{
			tmp->next = ptr;
			return;
		}
		tmp = tmp->next;
	}
}

void	*alloc(int size)
{
	void	*raw;
	f_ptr	*ptr;
	f_ctx	*ctx;

	raw = malloc(size);
	if (!raw)
		return ((void *)0);
	ptr = malloc(sizeof(f_ptr));
	if (!ptr)
		return ((void *)0);
	ptr->ptr = raw;
	ptr->size = size;
	ptr->next = (void *)0;
	ctx = get_ctx();
	if (!ctx)
	{
		free(ptr);
		free(raw);
		return ((void *)0);
	}
	add_to_ctx(ptr, ctx);
	return (raw);
}
