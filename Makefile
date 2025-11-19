# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsignoroi <tsignori@student.42perpignan.fr +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/06 14:50:25 by masanna           #+#    #+#              #
#    Updated: 2025/11/19 07:42:40 by tsignori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
###
##		CONFIG
#

NAME			:=	gnl.a

INC_DIR			:=	./includes/
SRC_DIR			:=	./src
OBJ_DIR			:=	obj

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror -I$(INC_DIR)


################################################################################
###
##		SOURCES / OBJECTS
#

SRC_FILES		:= \
					cli_parser.c \
					/utils/strcmp.c \

OBJ_FILES		:=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))


################################################################################
###
##		FORMATTING
#

RESET			:=	\033[0m
BOLD			:=	\033[1m
ITALIC			:=	\033[3m

RED				:=	\033[1;31m
GREEN			:=	\033[1;32m
YELLOW			:=	\033[1;33m
BLUE			:=	\033[1;34m
CYAN			:=	\033[1;36m


################################################################################
###
##		RULES
#

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "[AR] - $@"
	@ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "[CC] - $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "[RM] - $(OBJ_DIR)"

fclean: clean
	@echo "[RM] - $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

