# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akheired <akheired@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 17:28:51 by akheired          #+#    #+#              #
#    Updated: 2024/03/29 15:49:30 by akheired         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

server	=	server
client	=	client

server_bonus	=	server_bonus
client_bonus	=	client_bonus

OBJs	=	server.c
OBJc	=	client.c

BOBJs	=	server_bonus.c
BOBJc	=	client_bonus.c

all: ${server} ${client}

${server}: ${OBJs}
			${CC} ${CFLAGS} ${OBJs} -o ${server}
${client}: ${OBJc}
			${CC} ${CFLAGS} ${OBJc} -o ${client}


bonus:	${server_bonus} ${client_bonus}

${server_bonus}: ${OBJs}
			${CC} ${CFLAGS} ${BOBJs} -o ${server_bonus}
${client_bonus}: ${OBJc}
			${CC} ${CFLAGS} ${BOBJc} -o ${client_bonus}

clean:
	${RM} ${server} ${client} ${server_bonus} ${client_bonus}

fclean:	clean

re:	fclean all
