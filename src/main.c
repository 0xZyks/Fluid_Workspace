/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 03:23:43 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/18 22:14:51 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include <stdio.h>

int	display_errors(int flag)
{
	if (flag == 0)
		printf("Try fluid -h|--help !");
	if (flag == 1)
	{

	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (display_errors(0));
	if (ac == 2)
		return (display_errors(1));
	char	**cmd = ++av;
	printf("%s\n", cmd);
}
