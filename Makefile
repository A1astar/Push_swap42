NAME = push_swap

SRCDIR = src
OBJDIR = obj
INCDIR = includes

SRC_MAIN = src/main.c
SRC_ERR = src/error.c
SRC_MOVES = src/moves/push_rotate_moves.c src/moves/reverse_rotate_moves.c src/moves/swap_moves.c
SRC_PARS = src/parsing/arg_parsing.c src/parsing/parsing_utils.c
SRC_SORT = src/sorting/brut_force.c src/sorting/dispatcher.c src/sorting/execute_moves.c src/sorting/put_moves.c src/sorting/sort_stack.c src/sorting/sort_stack2.c
SRC_STRUC = src/structs/struct_free.c src/structs/struct_init.c src/structs/struct_min_max.c src/structs/struct_modif.c src/structs/struct_search_node.c src/structs/struct_browse_count.c
SRC_OPTI = src/optimisation/check_combo.c src/optimisation/new_inst_set.c

SRC = $(SRC_MAIN) $(SRC_ERR) $(SRC_MOVES) $(SRC_PARS) $(SRC_SORT) $(SRC_STRUC) $(SRC_OPTI)
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE := $(LIBFT_DIR)/includes
LDFLAGS = -L$(LIBFT_DIR)
LIBS = $(LIBFT)

AR = ar
ARFLAGS = rcs

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -g3 -I$(LIBFT_INCLUDE)

all: $(OBJDIR) $(LIBFT) $(NAME)

$(OBJDIR):
	$(V)mkdir -p $(OBJDIR) || true

DEP = $(OBJ:.o=.d)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(V)$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP)

$(NAME): $(OBJ) $(LIBFT)
	$(V)$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(LIBFT):
	$(V)$(MAKE) --silent -C $(LIBFT_DIR)

clean:
	$(V)rm -rf $(OBJDIR)

fclean: clean
	$(V)rm -f $(NAME)
	$(V)$(MAKE) --silent -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus regen
.DEFAULT_GOAL := all



