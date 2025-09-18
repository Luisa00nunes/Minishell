/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:19:09 by ldos_sa2          #+#    #+#             */
/*   Updated: 2025/09/18 11:56:23 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "../printf/ft_printf.h"
# include "../libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

typedef enum t_token
{
	WORD,
	PIPE,
	RED_IN,
	RED_OUT,
	APP_OUT,
	HEREDOC,
}			e_token;

typedef struct s_node
{
	char			*value;
	e_token			type;
	struct s_node	*next;
}				t_node;

#endif
