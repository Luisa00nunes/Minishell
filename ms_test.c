/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:18:07 by ldos_sa2          #+#    #+#             */
/*   Updated: 2025/10/04 15:57:54 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*split_tokens(char **token_list)
{
	t_node	*ls = NULL;
	t_node	*node;
	int	i;

	i = 0;
	while(token_list[i])
	{
		if(!ft_strncmp(token_list[i], "|", 1))
		{
			node = newnode(token_list[i], PIPE);
			nodeadd_back(&ls, node);
			i++;
		}
		node = newnode(token_list[i], WORD);
		nodeadd_back(&ls, node);
		free(token_list[i]);
		i++;
	}
	/*while(ls)
	{
		printf("Type: %i   Value: %s\n", ls->type, ls->value);
		printf("aaaa\n");
		ls = ls ->next;
	}*/
	return(ls);
}
void	free_nodelist(); //fazer!

void	split_process(char *prompt)
{
	char	**token_list;
	t_node	*tokens;
	t_node	*temp;
	int	i;
	int	num_tokens;

	i = 0;
	//tratar error de começo - prompt vazio etc
	num_tokens = count_words(prompt);
	token_list = ms_split(prompt);
	tokens = split_tokens(token_list);
	free(token_list);
	token_list = NULL;
	while(tokens)
	{
		printf("Type: %i   Value: %s\n", tokens->type, tokens->value);
		tokens = tokens ->next;
	}
}


int	main()
{
	char *prompt;

	while(1)
	{
		prompt = readline("minishell > ");
		add_history(prompt);
		split_process(prompt);
		printf("%s\n", prompt);
		free(prompt);
	}
	return (0);
}
