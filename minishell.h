/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:19:09 by ldos_sa2          #+#    #+#             */
/*   Updated: 2025/10/06 21:40:47 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
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

char	**ms_split(char const *s);
int	count_words(char const *s);
t_node	*newnode(char *v, e_token type);
t_node	*node_last(t_node *node);
void	nodeadd_back(t_node **lst, t_node *new);
void	skip_words(const char *s, int *i);
void	handle_redd(const char *s, int *i);
int	handle_q(const char *s, int *i);
void	free_nodelist(t_node *list);
void	split_process(char *prompt);

#endif
