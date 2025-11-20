/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:07:41 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/20 08:39:40 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*get_cmd(char *cmd)
{
	int		index;
	int		buff;
	char	*base;

	if (!cmd || !cmd[0])
		return ((void *)0);
	base = "fluid";
	index = -1;
	buff = -1;
	while (cmd[++index])
		if (cmd[index] == base[0] && index == 0)
			while (base[++buff] == cmd[index++])
				if (!base[buff])
					return (&cmd[index + buff]);
	return ((void *)0);
}

int	display_error(int flag)
{
	if (flag == 0)
	{
		printf("Bad use, try fluid -h|--help !\n");
		return (0);
	}
	if (flag == 1)
	{
		printf("Welcome in Fluid Helper\n");
		printf("Commands List:\n");
		printf("	-fluid create -l <c/csharp/asm/...> To create a project\n");
		printf("	-fluid open <proj name> To access to a projecti\n");
		printf("	-fluid info <proj_name> To get project information\n");
		printf("	-fluid --config-edit <proj_name> To edit project configuration\n");
		return (0);
	}
	return (0);
}
