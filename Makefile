# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 12:58:33 by tlupu             #+#    #+#              #
#    Updated: 2025/03/19 14:07:20 by tlupu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
CLIENT = client
SERVER = server
FT_PRINTF = ft_printf
INCLUDES = -I$(FT_PRINTF)
FT_PRINTF_LIBS = -L$(FT_PRINTF) -lftprintf

all: libftprintf ${CLIENT} ${SERVER}

libftprintf:
	make -C $(FT_PRINTF)
	touch libftprintf  # Add this line

${CLIENT}.o: ${CLIENT}.c
	cc -c ${FLAGS} $< -o $@ $(INCLUDES)

${SERVER}.o: ${SERVER}.c
	cc -c ${FLAGS} $< -o $@ $(INCLUDES)

${CLIENT}: ${CLIENT}.o libftprintf  
	cc ${FLAGS} $< -o $@ $(FT_PRINTF_LIBS)

${SERVER}: ${SERVER}.o libftprintf  
	cc ${FLAGS} $< -o $@ $(FT_PRINTF_LIBS)
	
clean:
	rm -rf *.o
	make -C $(FT_PRINTF) clean
	
fclean : clean
	rm -rf ${CLIENT} ${SERVER} libftprintf  # Add libftprintf here
	make -C $(FT_PRINTF) fclean

re: fclean all