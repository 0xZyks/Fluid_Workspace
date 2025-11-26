/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 03:35:24 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/24 17:11:55 by tsignori         ###   ########.fr       */
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
		return ("edit\0");
	if (fl_strcmp(act, "-h") || fl_strcmp(act, "--help"))
		return ("help\0");
	return ((void *)0);
}

char	*set_lang(char *cmd)
{	
	if (fl_strcmp(cmd, "c"))
		return ("c\0");
	if (fl_strcmp(cmd, "csharp"))
		return ("csharp\0");
	if (fl_strcmp(cmd, "asm"))
		return ("asm\0");
	if (fl_strcmp(cmd, "python"))
		return ("python\0");
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
		if (++cmd)
			lang = set_lang(*cmd);
	}
	command = malloc(sizeof(t_command));
	command->action = act;
	command->lang = lang;
	command->proj = proj;
	return (command);
}

#include <stdio.h>
int main(int ac, char **av)
{
	if (ac <= 1)
		return (0);
	t_command	*cmd = set_command(++av);
	printf("Action: %s\n", cmd->action);
	printf("lang: %s\n", cmd->lang);
	printf("Proj Name: %s\n", cmd->proj);
	return (0);
}
