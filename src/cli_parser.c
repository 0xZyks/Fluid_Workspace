/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 03:35:24 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/19 07:52:08 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "command.h"

int	fl_strcmp(char *s1, char *s2);

char	*set_action(char *act)
{
	if (fl_strcmp(act, "create"))
		return ("create\0");
	if (fl_strcmp(act, "open"))
		return ("open\0");
	if (fl_strcmp(act, "edit"))
		return "edit\0";
	return ((void *)0);
}

t_command	*set_command(char **cmd)
{
	char		*act;
	char		*lang;
	char		*proj;
	t_command	*command;

	act = set_action(*cmd);
	proj = *(++cmd);
	lang = (void *)0;
	if (fl_strcmp(*(++cmd), "-l"))
	{
		++cmd;
		if (fl_strcmp(*cmd, "c"))
			lang = *cmd;
		if (fl_strcmp(*cmd, "csharp"))
			lang = *cmd;
		if (fl_strcmp(*cmd, "asm"))
			lang = *cmd;
	}
	command = malloc(sizeof(t_command));
	command->action = act;
	command->lang = lang;
	command->proj = proj;
	return (command);
}
