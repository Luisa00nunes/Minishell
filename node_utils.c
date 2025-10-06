/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 15:50:10 by ldos_sa2          #+#    #+#             */
/*   Updated: 2025/10/04 15:51:35 by ldos_sa2         ###   ########.fr       */
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
		temp = temp->next;
	return(temp);
}
void	nodeadd_back(t_node **lst, t_node *new)
{
	if(!lst || !new)
		return ;
	if (*lst)
		node_last(*lst)->next = new;
	else
		*lst = new;
}
