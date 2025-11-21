;/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memctx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:44:31 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/21 12:52:04 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMCTX_H
# define #MEMCTX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_ptr {
	int				size;
	void			*ptr;
	struct s_ptr	*next;
} f_ptr;

typedef struct s_memctx {
	int		init;
	char	*name;
	f_ptr	*head;
	void	(*free_all)(struct s_memctx *ctx);
}	f_ctx;

void	*alloc(int size, f_ctx *ctx);
void	set_ctx(char *name);
void	*alloc(int size);
f_ctx	*get_gtx(void);


#endif // !MEMCTX_H
