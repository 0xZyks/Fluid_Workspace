/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memctx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:44:31 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/20 09:54:30 by tsignori         ###   ########.fr       */
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
}	f_ctx;

void	*alloc(int size, f_ctx *ctx);

#endif // !MEMCTX_H
