/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <gabach@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:53:19 by gabach            #+#    #+#             */
/*   Updated: 2025/11/29 18:42:13 by gabach           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*actual;

	if (!lst)
		return (0);
	count = 1;
	actual = lst;
	while (actual->next != NULL)
	{
		count++;
		actual = actual->next;
	}
	return (count);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	if (current == NULL)
		return ;
	while (current->next != NULL)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	ft_lstdelone(current, del);
	*lst = NULL;
	return ;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && lst->content)
		(*del)(lst->content);
	if (lst)
		free(lst);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
	return ;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*new;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}


t_list	*lstdel_relink(t_list **lst, t_list *current, t_list *last)
{
	if (last)
	{
		last->next = current->next;
		ft_lstdelone(current, free);
		current = last->next;
	}
	else
	{
		*lst = current->next;
		ft_lstdelone(current, free);
		current = *lst;
	}
	return (current);
}
