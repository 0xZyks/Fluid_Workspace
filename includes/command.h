/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 03:37:09 by tsignori          #+#    #+#             */
/*   Updated: 2025/11/18 03:39:01 by tsignori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

typedef struct s_commad {
	char	*action;
	char	*lang;
	char	*proj;
	void	(*exec)(char *);
}	t_command;

#endif // !COMMAND_H


