# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 15:54:28 by lucas             #+#    #+#              #
#    Updated: 2021/02/18 16:53:47 by lucas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS =			-Wall -Werror -Wextra -std=c++98# -pedantic

STD =			-D MODE=std
STD_PAIR =			-D PAIR=std::pair

FT =			-D MODE=ft
FT_PAIR =			-D PAIR=Pair

CC =			clang++

vector:
				$(CC) $(FLAGS) $(FT) srcs/Vector/test/main_vector.cpp -o vector
				./vector > result_ft
				rm ./vector
				$(CC) $(FLAGS) $(STD) srcs/Vector/test/main_vector.cpp -o vector
				./vector > result_std
				rm ./vector
				rm result_diff
				diff result_ft result_std > result_diff

list:
				$(CC) $(FLAGS) $(FT) srcs/List/test/main_list.cpp -o list
				./list	> result_ft
				rm  list
				$(CC) $(FLAGS) $(STD) srcs/List/test/main_list.cpp -o list
				./list	> result_std
				rm  list
				diff -s result_ft result_std > result_diff

map:
				$(CC) $(FLAGS) $(FT_PAIR) $(FT) srcs/Map/test/main_map.cpp -o map
				./map	> result_ft
				rm  map
				$(CC) $(FLAGS) $(STD_PAIR) $(STD) srcs/Map/test/main_map.cpp -o map
				./map	> result_std
				rm  map
				diff -s result_ft result_std > result_diff

stack:
				$(CC) $(FLAGS) $(FT) srcs/Stack/test/main_stack.cpp -o stack
				./stack > result_ft
				rm  stack
				$(CC) $(FLAGS) $(STD) srcs/Stack/test/main_stack.cpp -o stack
				./stack > result_std
				rm  stack
				diff -s result_ft result_std > result_diff

queue:
				$(CC) $(FLAGS) $(FT) srcs/Queue/test/main_queue.cpp -o queue
				./queue > result_ft
				rm  queue
				$(CC) $(FLAGS) $(STD) srcs/Queue/test/main_queue.cpp -o queue
				./queue > result_std
				rm  queue
				diff -s result_ft result_std > result_diff

clean:
				rm result*
