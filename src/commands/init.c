/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:04:34 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/24 16:30:33 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_workspace.h" 
#include "utils.h"
#include "memctx.h"
/*
int	create_config(char *path)
{

}
*/
int	init(char *path)
{
	char	*response;

	response = 0;
	if(system(fl_strjoin_sep("test -d", path, " ")))
	{
		system(fl_strjoin_sep("mkdir -p", fl_strjoin(path, "/bin/src"), " "));
		system(fl_strjoin_sep("mkdir -p", fl_strjoin(path, "/bin/includes"), " "));
		system(fl_strjoin_sep("mkdir -p", fl_strjoin(path, "/bin/templates"), " "));
		system(fl_strjoin_sep("mkdir -p", fl_strjoin(path, "/bin/libs"), " "));
		system(fl_strjoin_sep("mkdir -p", fl_strjoin(path, "/config"), " "));
		system(fl_strjoin_sep("mkdir -p", fl_strjoin(path, "/projects"), " "));
		// Add ctx alloc manager for free all (make a lib ? or only src.c files compiled inside binaries ?)
		return (1);
	}
	else
	{
		printf("Fluid Workspace is already setup\nDo you want to reinstall ? [Y/n]\n");
		scanf(" %c", response);
		if (*response == 10 || *response == 'Y' || *response == 'y')
		{
			printf("Are you sure ? All ur project gonna be deleted from local [Y/n]\n");
			response = 0;
			scanf(" %c", response);
			if (*response == 10 || *response == 'Y' || *response == 'y')
			{
				system("rm -rf ~/.fluid/workspace");
				return (init(path));
			}
		}
		else
			return (0);
	}
	return (0);
}
