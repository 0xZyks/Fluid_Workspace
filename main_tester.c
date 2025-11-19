/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 03:23:43 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/19 07:53:43 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/command.h"
#include <stdio.h>

t_command	*set_command(char **cmd);

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
	char		**cmd = ++av;
	t_command	*command = set_command(cmd);
	printf("Action: %s\n", command->action);
	printf("Proj Name: %s\n", command->proj);
	printf("Action: %s\n", command->lang);
}
