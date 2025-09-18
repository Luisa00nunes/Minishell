/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:18:07 by ldos_sa2          #+#    #+#             */
/*   Updated: 2025/09/18 13:02:32 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}
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
	while (temp->next != NULL) //enquanto o pont next n estiver apont. para o null
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
void	split_tokens(char *prompt)
{
	int i = 0;
	char	**list;
	t_node	*ls = NULL;
	t_node	*node;

	list = ft_split(prompt, ' ');
	while (i < count_words(prompt, ' '))
	{
		if(!ft_strncmp(list[i], "|", 2))
		{
			node = newnode(list[i], PIPE);
			nodeadd_back(&ls,node);
		}
		else
		{
			node = newnode(list[i], WORD);
			nodeadd_back(&ls, node);
		}
		free(list[i]);
		i++;
	}
	free(list);
	i = 0;
	while(ls)
	{
		printf("Type: %i   Value: %s\n", ls->type, ls->value);
		ls = ls ->next;
	}

}

int	main()
{
	char *prompt;

	while(1)
	{
		prompt = readline("minishell > ");
		split_tokens(prompt);
		printf("%s\n", prompt);
	}
	return (0);
}
