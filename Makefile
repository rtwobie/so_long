# config
NAME	:= so_long
CC		:= cc
SRC_DIR	:= src/
INC_DIR	:= inc/
OBJ_DIR	:= obj/

#libft
LIBFT		:= libft.a
LIBFT_DIR	:= libft/

CFLAGS	:=
CFLAGS	+= -O2
CFLAGS	+= -Wall
CFLAGS	+= -Wextra
CFLAGS	+= -Werror
CFLAGS	+= -pedantic
CFLAGS	+= -Wconversion

CPPFLAGS	:=
CPPFLAGS	+= -I$(INC_DIR)
CPPFLAGS	+= -I$(LIBFT_DIR)

LDFLAGS	:=
LDFLAGS	+= -L/usr/local/lib/
LDFLAGS	+= -L/usr/lib/
LDFLAGS	+= -L$(LIBFT_DIR)

LDLIBS	:=
LDLIBS	+= -lmlx
LDLIBS	+= -lXext
LDLIBS	+= -lX11
LDLIBS	+= -lft
# LDLIBS	+= -l$(subst lib%,%,$(basename $(LIBFT)))

ifeq ($(DEBUG), 1)
	CFLAGS	+= -ggdb3 -O0
	LDFLAGS	+= -ggdb3 -O0
endif

# sources
SRC		:=

vpath %.c src/
SRC		+= main.c
SRC		+= input.c
SRC		+= draw.c
SRC		+= get_next_line.c

OBJ		:= $(SRC:.c=.o)
OBJ		:= $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(LIBFT_DIR)/$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@

$(OBJ_DIR)/%.o:%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
