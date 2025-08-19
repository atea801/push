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
				parsing/parsing_utils.c \
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
