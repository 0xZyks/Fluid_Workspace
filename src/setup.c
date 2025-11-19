/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:31:15 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/19 16:40:47 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_workspace.h" 
#include "utils.h"

int	init(char *path, int mode)
{
	char	*response;

	response = "\0";
	if(mkdir(path, mode))
	{
		mkdir(fl_strjoin(path, "/bin/src"), mode);
		mkdir(fl_strjoin(path, "/bin/includes"), mode);
		mkdir(fl_strjoin(path, "/bin/libs"), mode);
		mkdir(fl_strjoin(path, "/bin/template"), mode);
		mkdir(fl_strjoin(path, "/bin"), mode);
		mkdir(fl_strjoin(path, "/config"), mode);
		mkdir(fl_strjoin(path, "/projects"), mode);
		return (1);
	}
	else
	{
		printf("Fluid Workspace is already setup\nDo you want to reinstall ? [Y/n]\n");
		scanf("%c", response);
		if (*response == 10 || *response == 'Y' || *response == 'y')
		{
			printf("Are you sure ? All ur project gonna be deleted from local [Y/n]\n");
			scanf("%c", response);
			if (*response == 10 || *response == 'Y' || *response == 'y')
			{
				system(fl_strjoin_sep("rm -rf", path, " "));
				return (init(path, mode));
			}
		}
		else
			return (1);
	}
	return (0);
}
