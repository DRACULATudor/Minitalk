# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 12:58:33 by tlupu             #+#    #+#              #
#    Updated: 2024/04/29 14:41:32 by tlupu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
CLIENT = client
SERVER = server
FT_PRINTF = /home/tlupu/projects/minitalk/ft_printf
INCLUDES = -I$(FT_PRINTF)
FT_PRINTF_LIBS = -L$(FT_PRINTF) -lftprintf

all: libftprintf ${CLIENT} ${SERVER}

libftprintf:
	make -C $(FT_PRINTF)

%:	%.c
	cc ${FLAGS} $< -o $@ $(INCLUDES) $(FT_PRINTF_LIBS)
    
clean:
	rm -rf *.o
	make -C $(FT_PRINTF) clean
    
fclean : clean
	rm -rf ${CLIENT} ${SERVER}
	make -C $(FT_PRINTF) fclean

re: fclean all