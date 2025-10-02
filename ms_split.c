/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldos_sa2 <ldos-sa2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:36:27 by ldos_sa2          #+#    #+#             */
/*   Updated: 2025/10/02 17:20:26 by ldos_sa2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// primeiro separar em pipe
// com aspas
// red in red out append e heredoc


static void	skip_words(const char *s, int *i)
{
	while(s[*i] && s[*i] != ' ' && s[*i] != '|')
		(*i)++;
}

static int	handle_pq(const char *s, int *i)
{
	char q;

	if (s[*i] == '|')
	{
		(*i)++;
		return (1);
	}
	else
	{
		q = s[*i];
		(*i)++;
		while(s[*i] && s[*i] != q)
			(*i)++;
		if(!s[*i])
			return (-1);
		(*i)++;
	}
	return(1);
}

int	count_words(char const *s)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while(s[i] == ' ')
			i++;
		if (s[i] == '"' || s[i] == '\'' || s[i] == '|')
		{
			if(handle_pq(s, &i) == -1)
				return (-1);
			words++;
		}
		else
		{
			skip_words(s, &i);
			words++;
		}
	}
	return (words);
}

static char	*copy_tokens(const char *s, int *i)
{
	char	*token;
	char	q;
	int		start;

	if (s[*i] == '"' || s[*i] == '\'')
	{
		q = s[*i];
		(*i)++;
		start = *i;
		while(s[*i] && s[*i] != q)
			(*i)++;
		token = ft_substr(s, start, *i - start);
		if(s[*i] == q)
			(*i)++;
	}
	else
	{
		start = *i;
		while (s[*i] && s[*i] != ' ' && s[*i] != '|')
			(*i)++;
		token = ft_substr(s, start, *i - start);
	}
	return(token);
}

char	**ms_split(char const *s)
{
	int		i;
	int		j;
	int		num_tokens;
	char	**tokens;

	i = 0;
	j = 0;
	num_tokens = count_words(s);
	if(num_tokens == -1)
		return (NULL); //tratar esse erro depois
	tokens = (char **)malloc((num_tokens + 1) * sizeof(char *));
	while(s[i])
	{
		while(s[i] == ' ')
			i++;
		if (s[i] == '|')
		{
			tokens[j++] = ft_strdup("|");
			i++;
		}
		else if(s[i])
			tokens[j++] = copy_tokens(s, &i);
	}
	tokens[j] = NULL;
	return (tokens);
}
