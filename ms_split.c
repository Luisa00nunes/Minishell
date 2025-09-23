/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:36:27 by ldos_sa2          #+#    #+#             */
/*   Updated: 2025/09/23 00:20:31 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// primeiro separar em pipe
// com aspas
// red in red out append e heredoc
static int	count_process(char const *s)
{
	int	i;
	int	process;
	int pipes;

	i = 0;
	process = 0;
	pipes = 0;
	while (s[i])
	{
		if (s[i] != '|')
		{
			process++;
			while (s[i] != '|' && s[i])
				i++;
		}
		else
			pipes++;
			i++;
	}
	return (process + pipes);
}

void	split_process(char *prompt)
{
	int i = 0;
	char	**process_list;
	char	**process;
	t_node	*ls = NULL;
	t_node	*node;

	process_list = ft_split(prompt, '|');
	while(i < count_process(prompt))
	{
		process = ft_split(process_list[i], ' ');
		//crio os tokens
		//limpo a lista process
		i++;
	}
	/*i = 0;
	while(ls)
	{
		printf("Type: %i   Value: %s\n", ls->type, ls->value);
		ls = ls ->next;
	}*/
}
int	main()
{
	char *prompt;

	while(1)
	{
		prompt = readline("minishell > ");
		split_process(prompt);
		printf("%s\n", prompt);
	}
	return (0);
}
