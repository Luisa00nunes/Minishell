/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:18:07 by ldos_sa2          #+#    #+#             */
/*   Updated: 2025/10/06 20:54:29 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redd(char *token)
{
	if(!ft_strncmp(token, ">", 1) || !ft_strncmp(token, "<", 1))
		return (1);
	else if(!ft_strncmp(token, ">>", 2) || !ft_strncmp(token, "<<", 2))
		return (1);
	else
		return (0);
}

void	not_words(char *token, t_node *ls)
{
	t_node	*node;

	if(!ft_strncmp(token, "<<", 2))
	{
		node = newnode(token, HEREDOC);
		nodeadd_back(&ls, node);
	}
	else if(!ft_strncmp(token, ">>", 2))
	{
		node = newnode(token, APP_OUT);
		nodeadd_back(&ls, node);
	}
		else if(!ft_strncmp(token, "<", 1))
	{
		node = newnode(token, RED_IN);
		nodeadd_back(&ls, node);
	}
	else if(!ft_strncmp(token, ">", 1))
	{
		node = newnode(token, RED_OUT);
		nodeadd_back(&ls, node);
	}
	else
		return ;
}

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
		}
		else if (is_redd(token_list[i]))
			not_words(token_list[i], ls);
		else
		{
			node = newnode(token_list[i], WORD);
			nodeadd_back(&ls, node);
		}
		free(token_list[i]);
		i++;
	}
	return(ls);
}
void	free_nodelist(t_node *list)
{
	t_node	*tmp;

	while(list)
	{
		tmp = list->next;
		free(list->value);
		free(list);
		list = tmp;
	}
}

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

	t_node *tmp = tokens;
	while(tmp)
	{
		printf("Type: %i   Value: %s\n", tmp->type, tmp->value);
		tmp = tmp ->next;
	}
	free_nodelist(tokens);
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
