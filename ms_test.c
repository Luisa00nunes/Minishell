/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:18:07 by ldos_sa2          #+#    #+#             */
/*   Updated: 2025/10/02 17:32:30 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*newnode(char *v, e_token type)
{
	t_node	*new_node;
	char	*value;

	value = ft_strdup(v);
	new_node = (t_node *)malloc(sizeof(t_node));
	if(!new_node)
		return (NULL);
	new_node->value = value;
	new_node->type = type;
	new_node->next = NULL;
	return (new_node);
}

t_node	*node_last(t_node *node)
{
	t_node	*temp;

	if(!node)
		return (NULL);
	temp = node;
	while (temp->next != NULL)
		temp = temp->next; //o ponteiro temp vai "virar" o ponteiro next
	return(temp);
}
void	nodeadd_back(t_node **lst, t_node *new)
{
	if(!lst || !new) //se head n existir
		return ;
	if (*lst) //se head está apont. para alguma coisa
		node_last(*lst)->next = new;
	else //se head tiver apontando para o null
		*lst = new;
}
t_node	*split_tokens(char *process)
{
	t_node	*ls = NULL;
	t_node	*node;

	if(!ft_strncmp(process, "|", 1))
	{
		node = newnode(process, PIPE);
		nodeadd_back(&ls, node);
	}
	else
	{
		node = newnode(process, WORD);
		nodeadd_back(&ls, node);
	}
	/*while(ls)
	{
		printf("Type: %i   Value: %s\n", ls->type, ls->value);
		printf("aaaa\n");
		ls = ls ->next;
	}*/
	return(ls);
}

void	split_process(char *prompt)
{
	char	**token_list;

	int	i;
	int	tokens;

	i = 0;
	//tratar error de começo - prompt vazio etc
	tokens = count_words(prompt);
	token_list = ms_split(prompt);
	while(i < tokens)
	{
		split_tokens(token_list[i]);
		free(token_list[i]);
		i++;
	}
	free(token_list);
	token_list = NULL;
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
