# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ton_nom <ton_email@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 20:00:00 by ton_nom           #+#    #+#              #
#    Updated: 2025/07/28 20:00:00 by ton_nom           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -I. -Iprintf -Ilibft


# ————————————— SOURCES OPÉRATIONNELLES —————————————
OP_SRCS :=	operation/operation_pop_node.c \
			operation/operation_push_node.c \
			operation/operation_reverse_rotate.c \
			operation/operation_rotate.c \
			operation/operation_swap.c \
			operation/operation_utils.c \
			operation/wrappers/wrappers_pa.c \
			operation/wrappers/wrappers_pb.c \
			operation/wrappers/wrappers_ra.c \
			operation/wrappers/wrappers_rb.c \
			operation/wrappers/wrappers_rr.c \
			operation/wrappers/wrappers_rra.c \
			operation/wrappers/wrappers_rrb.c \
			operation/wrappers/wrappers_rrr.c \
			operation/wrappers/wrappers_sa.c \
			operation/wrappers/wrappers_sb.c \
			operation/wrappers/wrappers_ss.c

PARS_SRCS :=	parsing/parsing_build_stack_a.c \
				parsing/parsing_check_duplicates.c \
				parsing/parsing_clean_free_split.c \
				parsing/parsing_clean_free_stack.c \
				parsing/parsing_has_int_overflow.c \
				parsing/parsing_is_valid_number.c \
				parsing/parsing_main.c \
				parsing/parsing_split_args.c \
				parsing/parsing_validate_numbers.c

SORT_SRCS := 	sorting/sorting_init.c \
				sorting/big_sort/big_sort_k_sort.c \
				sorting/big_sort/chunks/chunks_push_utils.c \
				sorting/big_sort/chunks/chunks_push.c \
				sorting/big_sort/chunks/chunks_return_from_b.c \
				sorting/big_sort/index/index_compress_indices.c \
				sorting/big_sort/index/index_sort_int_array.c \
				sorting/initialisation/initialisation_is_sorted.c \
				sorting/initialisation/initialisation_stack_size.c \
				sorting/initialisation/initialisation_utils.c \
				sorting/small_sort/ss_find_min_position.c \
				sorting/small_sort/ss_push_min_until_three.c \
				sorting/small_sort/ss_reverse_min_to_top.c \
				sorting/small_sort/ss_small_sort.c \
				sorting/small_sort/ss_sort_2.c \
				sorting/small_sort/ss_sort_3.c

# ————————————— SOURCES FT_PRINTF —————————————
PRINTF_SRCS := \
	printf/ft_printf.c \
	printf/ft_convert.c \
	printf/ft_convert_base.c

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a



# Assemblage de toutes les sources → objets
SRCS	:= push_swap.c $(OP_SRCS) $(PRINTF_SRCS) $(PARS_SRCS) $(SORT_SRCS)
OBJS	:= $(SRCS:.c=.o)

# ————————————— CIBLE PRINCIPALE —————————————
all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o $@

#==============================================
#==============================================

# ————————————— TEST OPERATIONS —————————————
test_sa: CFLAGS += -DTEST_SA
test_sa: $(OBJS)
	$(CC) $(CFLAGS) $^ -o test_sa

test_sb: CFLAGS += -DTEST_SB
test_sb: $(OBJS)
	$(CC) $(CFLAGS) $^ -o test_sb

test_ss: CFLAGS += -DTEST_SS
test_ss: $(OBJS)
	$(CC) $(CFLAGS) $^ -o test_ss

test_ra: CFLAGS += -DTEST_RA
test_ra:$(OBJS)
	$(CC) $(CFLAGS) $^ -o test_ra

test_rb: CFLAGS += -DTEST_RB
test_rb:$(OBJS)
	$(CC) $(CFLAGS) $^ -o test_rb

test_rr: CFLAGS += -DTEST_RR
test_rr:$(OBJS)
	$(CC) $(CFLAGS) $^ -o test_rr

test_rra: CFLAGS += -DTEST_RRA
test_rra:$(OBJS)
	$(CC) $(CFLAGS) $^ -o test_rra

test_rrb: CFLAGS += -DTEST_RRB
test_rrb:$(OBJS)
	$(CC) $(CFLAGS) $^ -o test_rrb

test_rrr: CFLAGS += -DTEST_RRR
test_rrr:$(OBJS)
	$(CC) $(CFLAGS) $^ -o test_rrr

test_pa: CFLAGS += -DTEST_PA
test_pa: $(OBJS)
	$(CC) $(CFLAGS) $^ -o test_pa

test_pb: CFLAGS += -DTEST_PB
test_pb: $(OBJS)
	$(CC) $(CFLAGS) $^ -o test_pb

# ————————————— TEST PARSING —————————————

test_is_valid_nbr: CFLAGS += -DTEST_IS_VALID_NBR
test_is_valid_nbr: $(OBJS)
	$(CC) $(CFLAGS) $^ -o test_is_valid_nbr

test_overflow: CFLAGS += -DTEST_OVERFLOW
test_overflow: $(OBJS)
	$(CC) $(CFLAGS) $^ -o test_overflow

test_split_args: CFLAGS += -DTEST_SPLIT_ARGS
test_split_args: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o test_split_args

test_validate_nbr: CFLAGS += -DTEST_VALIDATE_NBR
test_validate_nbr: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o test_validate_nbr

test_check_duplicate: CFLAGS += -DTEST_CHECK_DUPLICATE
test_check_duplicate: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o test_check_duplicate

test_build_stack: CFLAGS += -DTEST_BUILD_STACK
test_build_stack: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o test_build_stack

test_parsing: CFLAGS += -DTEST_PARSING
test_parsing: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o test_parsing


# ————————————— SORTING > INITIALISATION —————————————

test_is_sorted: CFLAGS += -DTEST_IS_SORTED
test_is_sorted: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o test_is_sorted

test_stack_size: CFLAGS += -DTEST_STACK_SIZE
test_stack_size: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o test_stack_size

test_init_sort: CFLAGS += -DTEST_INIT_SORT
test_init_sort: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o test_init_sort
# ————————————— SORTING > SMALL_SORT —————————————
test_small_sort: CFLAGS += -DTEST_SMALL_SORT
test_small_sort: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o test_small_sort
# ————————————— SORTING > BIG_SORT —————————————
test_big_sort_index: CFLAGS += -DTEST_BIG_SORT_INDEX
test_big_sort_index: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o test_big_sort_index

test_big_sort_chunks: CFLAGS += -DTEST_CHUNKS_PUSH
test_big_sort_chunks: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o test_big_sort_chunks

test_k_sort: CFLAGS += -DTEST_K_SORT
test_k_sort: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o test_k_sort


#==============================================
#==============================================

# ————————————— RÈGLE GÉNÉRIQUE .c → .o —————————————
# Chaque .c dépend de push_swap.h et ft_printf.h
%.o: %.c push_swap.h printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

# ————————————— NETTOYAGE —————————————
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) test_sa

re: fclean all

.PHONY: all clean fclean re test_sa
