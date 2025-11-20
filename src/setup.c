/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:31:15 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/20 09:44:07 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_workspace.h" 
#include "utils.h"

f_ctx	*get_ctx(void)
{
	static f_ctx	ctx;
	static int		init;
	
	if (!init)
	{
		init = 1;
	}
	return (&ctx);
}

int	create_config(char *path)
{

}

int	init(char *path)
{
	char	response;
	f_ctx	*ctx;

	ctx = get_ctx();
	response = 0;
	if(system(fl_strjoin_sep("test -d", path, " ")))
	{
		system(fl_strjoin_sep("mkdir -p", fl_strjoin(path, "/bin/src", ctx), " ", ctx));
		system(fl_strjoin_sep("mkdir -p", fl_strjoin(path, "/bin/includes", ctx), " ", ctx));
		system(fl_strjoin_sep("mkdir -p", fl_strjoin(path, "/bin/templates", ctx), " ", ctx));
		system(fl_strjoin_sep("mkdir -p", fl_strjoin(path, "/bin/libs", ctx), " ", ctx));
		system(fl_strjoin_sep("mkdir -p", fl_strjoin(path, "/config", ctx), " ", ctx));
		system(fl_strjoin_sep("mkdir -p", fl_strjoin(path, "/projects", ctx), " ", ctx));
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
			scanf(" %c", response);
			if (*response == 10 || *response == 'Y' || *response == 'y')
			{
				system("rm -rf ~/.fluid/workspace"));
				return (init(path, mode));
			}
		}
		else
			return (0);
	}
	return (0);
}
