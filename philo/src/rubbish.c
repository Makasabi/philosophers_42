/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rubbish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:08:41 by mrony             #+#    #+#             */
/*   Updated: 2023/06/23 17:57:52 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_bin **ft_rubbish()
{
	static t_bin *bin;
	
	return(&bin);
}

t_bin	*ft_binnew(void *content)
{
	t_bin	element;
	t_bin	*ptr;

	memset(&element, 0, sizeof(t_bin));
	ptr = &element;
	element.rubbish = content;
	element.next = NULL;
	return (ptr);
}

void	ft_binadd_front(t_bin **bin, t_bin *new)
{
	if (bin && new)
	{
		new->next = *bin;
		*bin = new;
	}
}

void	ft_bindelone(t_bin *bin, void (*del)(void*))
{
	if (!bin || !del)
		return ;
	else
	{
		del(bin->rubbish);
		free(bin);
	}
}

void	ft_binclear(t_bin **bin, void (*del)(void*))
{
	t_bin	*tmp;

	if (bin && del)
	{
		while (*bin)
		{
			tmp = (*bin)->next;
			ft_bindelone(*bin, del);
			(*bin) = tmp;
		}
	}
}

void	*ft_malloc(int size)
{
	void			*content;
	static t_bin	*bin;
	t_bin			*element;

	content = malloc(size);
	if (!content)
	{
		ft_putstr_fd(MALERR, 2);
		ft_binclear(&bin, free);
		exit(EXIT_FAILURE);
	}
	else
	{
		memset(content, 0, size);
		element = ft_binnew(content);
		ft_binadd_front(&bin, element);
	}
	return(content);
}