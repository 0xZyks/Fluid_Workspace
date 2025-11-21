/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:04:25 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/21 15:53:19 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*get_env(void)
{
	char	*home = getenv("HOME");
	if (!home)
		return ((void *)0);
	home = fl_strjoin(home, "/");
	return (home);
}
