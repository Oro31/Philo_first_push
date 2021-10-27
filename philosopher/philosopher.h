/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:55:32 by rvalton           #+#    #+#             */
/*   Updated: 2021/10/27 17:49:34 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define psleep(sec) sleep ((sec))
# define INITIAL_STOCK	20
# define NB_CLIENTS		5

typedef struct	s_cient {
	pthread_t		th_client;
	pthread_mutex_t	mutex;
	int				id;
	int				ordering;
}				t_client;

typedef struct	s_store {
	int			stock;
	pthread_mutex_t	mutex;
	pthread_t	th_store;
	t_client	clients [NB_CLIENTS];
}				t_store;

static t_store	store = 
{
	.stock = INITIAL_STOCK,
};

#endif
