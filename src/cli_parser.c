/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 03:35:24 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/18 22:14:49 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

char	*set_action(char *act)
{
	if (fl_strcmp(act, "create"))
		return ("create\0");
	if (fl_strcmp(act, "open"))
		return ("open\0");
	if (fl_strcmp(act, "edit"));
		return "edit\0";
	return ((void *)0);
}

t_command	*set_command(char **cmd)
{
	char		*act;
	char		*lang;
	char		*proj;
	t_command	*command;

	act = set_action(*(++cmd));
	proj = *(++cmd);
	if (fl_strcmp(*(++av), "-l"))
	{
		++av;
		if (fl_strcmp(*av, "c"))
			lang = *av;
		if (fl_strcmp(*av, "csharp"))
			lang = *av;
		if (fl_strcmp(*av, "asm"))
			lang = *av;
	}
	command = malloc(sizeof(t_command));
	command->action = act;
	command->lang = lang;
	command->proj = proj;
	return (command);
}
