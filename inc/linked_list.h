/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <gabach@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:57:22 by gabach            #+#    #+#             */
/*   Updated: 2025/11/29 18:43:31 by gabach           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILES_H
# define UTILES_H

// INCLUDES

#include <stdlib.h>

// STRUCTS

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

// FUNCS

t_list	*ft_lstnew(void	*content);
void	ft_lstadd_front(t_list **lst, t_list *new_l);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new_l);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*lstdel_relink(t_list **lst, t_list *current, t_list *last);

#endif
