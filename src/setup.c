/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:31:15 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/19 09:39:30 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <direct.h>
#include <stdio.h>

int	init(char *path, int mode)
{
	char	response;

	response = '\0';
	if(mkdir(path, mode))
	{
		mkdir(fl_strjoin(path, "/bin/src"), mode);
		mkdir(fl_strjoin(path, "/bin/includes"), mode);
		mkdir(fl_strjoin(path, "/bin/libs"), mode);
		mkdir(fl_strjoin(path, "/bin/template"), mode);
		mkdir(fl_strjoin(path, "/bin"), mode);
		mkdir(fl_strjoin(path, "/projects"), mode);
		return (0);
	}
	else
	{
		printf("Fluid Workspace is already setup\nDo you want to reinstall ? [Y/n]");
		scanf("%d", response);
		if (response == 10 && response == 'Y' && response == 'y')
		{

			// rm -rf le path folder;
		}
		else
			return (1);
	}
	return (0);
}
