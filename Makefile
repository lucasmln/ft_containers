# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 15:54:28 by lucas             #+#    #+#              #
#    Updated: 2021/02/18 16:09:57 by lucas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS =			-Wall -Werror -Wextra -std=c++98 -pedantic

STD =			-D MODE=std

FT =			-D MODE=ft

CC =			clang++

vector:
				$(CC) $(FLAGS) $(FT) srcs/Vector/test/main_vector.cpp -o vector
				./vector > result_ft
				rm  vector
				$(CC) $(FLAGS) $(STD) srcs/Vector/test/main_vector.cpp -o vector
				./vector > result_std
				diff -s result_ft result_std > result_diff
				rm  vector

list:
				$(CC) $(FLAGS) $(FT) srcs/List/test/main_list.cpp -o list
				./list	> result_ft
				rm  list
				$(CC) $(FLAGS) $(STD) srcs/List/test/main_lis.cpp -o list
				./list	> result_std
				diff -s result_ft result_std > result_diff
				rm  list

map:
				$(CC) $(FLAGS) $(FT) srcs/Map/test/main_map.cpp -o map
				./map	> result_ft 
				rm  map
				$(CC) $(FLAGS) $(STD) srcs/Map/test/main_map.cpp -o map
				./map	> result_std
				diff -s result_ft result_std > result_diff
				rm  map

stack:
				$(CC) $(FLAGS) $(FT) src/Stack/test/main_stack.cpp -o stack
				./stack > result_ft
				rm  stack
				$(CC) $(FLAGS) $(STD) srcs/Stack/test/main_stack.cpp -o stack
				./stack > result_std
				diff -s result_ft result_std > result_diff
				rm  stack

queue:
				$(CC) $(FLAGS) $(FT) srcs/Queue/test/main_queue.cpp -o queue
				./queue > result_ft
				rm  queue
				$(CC) $(FLAGS) $(STD) srcs/Queue/test/main_queue.cpp -o queue
				./queue > result_std
				diff -s result_ft result_std > result_diff
				rm  queue

clean:
				rm result*
