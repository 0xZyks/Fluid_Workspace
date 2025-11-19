# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 16:33:39 by tsignori          #+#    #+#              #
#    Updated: 2025/11/19 16:36:58 by tsignori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### CONFIG
################################################################################

NAME        := gnl.a

SRC_DIR     := src
OBJ_DIR     := obj
INC_DIR     := includes

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -I$(INC_DIR)

################################################################################
### SOURCES / OBJECTS (AUTO)
################################################################################

# → récupère tous les .c, y compris dans les sous-dossiers
SRC_FILES   := $(shell find $(SRC_DIR) -type f -name "*.c")

# → remplace src/xxx.c par obj/xxx.o automatiquement
OBJ_FILES   := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

################################################################################
### COLORS
################################################################################

RESET		:=	\033[0m
BOLD		:=	\033[1m
ITALIC		:=	\033[3m

RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
YELLOW		:=	\033[1;33m
BLUE		:=	\033[1;34m
CYAN		:=	\033[1;36m

################################################################################
### RULES
################################################################################

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(GREEN)[AR]$(RESET) - $@"
	@ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(BLUE)[CC]$(RESET) - $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)[RM]$(RESET) - $(OBJ_DIR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[RM]$(RESET) - $(NAME)"

re: fclean all

.PHONY: all clean fclean re
