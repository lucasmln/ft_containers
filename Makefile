# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 15:54:28 by lucas             #+#    #+#              #
#    Updated: 2021/02/25 19:47:50 by lucas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS =			-Wall -Werror -Wextra -std=c++98# -pedantic

STD =			-D MODE=std
STD_PAIR =			-D PAIR=std::pair

FT =			-D MODE=ft
FT_PAIR =			-D PAIR=Pair

CC =			clang++

vector:
				$(CC) $(FLAGS) $(STD) srcs/Vector/test/main_vector.cpp -o vector
				./vector > result_std
				rm ./vector
				$(CC) $(FLAGS) $(FT) srcs/Vector/test/main_vector.cpp -o vector
				./vector > result_ft
				rm ./vector
				diff -s result_ft result_std > result_diff

list:
				$(CC) $(FLAGS) $(STD) srcs/List/test/main_list.cpp -o list
				./list	> result_std
				rm  list
				$(CC) $(FLAGS) $(FT) srcs/List/test/main_list.cpp -o list
				./list	> result_ft
				rm  list
				diff -s result_ft result_std > result_diff

map:
				$(CC) $(FLAGS) $(STD_PAIR) $(STD) srcs/Map/test/main_map.cpp -o map
				./map	> result_std
				rm  map
				$(CC) $(FLAGS) $(FT_PAIR) $(FT) srcs/Map/test/main_map.cpp -o map
				./map	> result_ft
				rm  map
				diff -s result_ft result_std > result_diff

multimap:
				$(CC) $(FLAGS) $(STD_PAIR) $(STD) srcs/Multimap/test/main_multimap.cpp -o multimap
				./multimap	> result_std
				rm  multimap
				$(CC) $(FLAGS) $(FT_PAIR) $(FT) srcs/Multimap/test/main_multimap.cpp -o multimap
				./multimap	> result_ft
				rm  multimap
				diff -s result_ft result_std > result_diff
stack:
				$(CC) $(FLAGS) $(STD) srcs/Stack/test/main_stack.cpp -o stack
				./stack > result_std
				rm  stack
				$(CC) $(FLAGS) $(FT) srcs/Stack/test/main_stack.cpp -o stack
				./stack > result_ft
				rm  stack
				diff -s result_ft result_std > result_diff

queue:
				$(CC) $(FLAGS) $(STD) srcs/Queue/test/main_queue.cpp -o queue
				./queue > result_std
				rm  queue
				$(CC) $(FLAGS) $(FT) srcs/Queue/test/main_queue.cpp -o queue
				./queue > result_ft
				rm  queue
				diff -s result_ft result_std > result_diff

deque:
				$(CC) $(FLAGS) $(STD) srcs/Deque/test/main_deque.cpp -o deque
				./deque > result_std
				rm  deque
				$(CC) $(FLAGS) $(FT) srcs/Deque/test/main_deque.cpp -o deque
				./deque > result_ft
				rm  deque
				diff -s result_ft result_std > result_diff
clean:
				rm result*
