NAME = push_swap

SRCDIR = src
OBJDIR = obj
INCDIR = includes

SRC =	main.c error.c arg_parsing.c brut_force.c dispatcher.c utils.c push_rotate_moves.c \
		reverse_rotate_moves.c swap_moves.c frees_utils.c struct_init.c struct_utils.c \
		direct_ins.c struct_utils2.c struct_utils3.c radix.c exe_instructions.c sort_stack.c optimisations.c
SRC := $(addprefix $(SRCDIR)/, $(SRC))
OBJ := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

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

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
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

