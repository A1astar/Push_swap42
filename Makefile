NAME = push_swap
BONUS_NAME = checker

SRCDIR = src
OBJDIR = obj
OBJDIR_BONUS = obj_bonus
OBJDIR_SHARED = obj_shared
INCDIR = includes

SRC_MAIN_BONUS = src/checker/checker_main.c src/checker/checker_exe_inst.c
SRC_MAIN = src/main.c
SRC_BONUS = bonus/src/checker_main.c
SRC_SORT = src/sorting/brut_force.c src/sorting/dispatcher.c src/sorting/execute_moves.c src/sorting/put_moves.c src/sorting/sort_stack.c src/sorting/sort_stack2.c
SRC_STRUC = src/structs/struct_min_max.c
SRC_OPTI = src/optimisation/check_combo.c src/optimisation/new_inst_set.c
SRC_SHARED = src/parsing/arg_parsing.c src/parsing/parsing_utils.c src/error.c src/moves/push_rotate_moves.c src/moves/reverse_rotate_moves.c \
			src/moves/swap_moves.c src/structs/struct_free.c src/structs/struct_init.c src/structs/struct_modif.c src/structs/struct_check.c \
			src/structs/struct_search_node.c src/structs/struct_browse_count.c \


SRC = $(SRC_MAIN) $(SRC_SORT) $(SRC_STRUC) $(SRC_OPTI)
SRC_BONUS = $(SRC_MAIN_BONUS)

OBJ = $(patsubst %.c, $(OBJDIR)/%.o,$, $(SRC))
OBJ_BONUS = $(patsubst %.c, $(OBJDIR_BONUS)/%.o, $(SRC_BONUS))
OBJ_SHARED = $(patsubst %.c, $(OBJDIR_SHARED)/%.o, $(SRC_SHARED))

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE := $(LIBFT_DIR)/includes
LDFLAGS = -L$(LIBFT_DIR)
LIBS = $(LIBFT)

AR = ar
ARFLAGS = rcs

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -g3 -I$(LIBFT_INCLUDE)

all: $(OBJDIR) $(OBJDIR_SHARED) $(LIBFT) $(NAME)
bonus: $(OBJDIR_BONUS) $(OBJ_SHARED) $(LIBFT) $(BONUS_NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR) || true

$(OBJDIR_SHARED):
	mkdir -p $(OBJDIR_SHARED)

$(OBJDIR_BONUS):
	mkdir -p $(OBJDIR_BONUS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJDIR_SHARED)/%.o: %.c | $(OBJDIR_SHARED)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJDIR_BONUS)/%.o: %.c | $(OBJDIR_BONUS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(OBJ:.o=.d)
-include $(OBJ_SHARED:.o=.d)
-include $(OBJ_BONUS:.o=.d)

$(NAME): $(OBJ) $(OBJ_SHARED) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(OBJ_SHARED) $(LIBS) -o $(NAME)

$(BONUS_NAME): $(OBJ_BONUS) $(OBJ_SHARED) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ_BONUS) $(OBJ_SHARED) $(LIBS) -o $(BONUS_NAME)

$(LIBFT):
	$(MAKE) --silent -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJDIR)
	rm -rf $(OBJDIR_SHARED)
	rm -rf $(OBJDIR_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	$(MAKE) --silent -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
.DEFAULT_GOAL := all



