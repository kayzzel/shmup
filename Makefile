#-------------------------------- VARIABLES ----------------------------------#

NAME			=	shmup
CC				=	cc
CFLAGS			=	-Wall -Wextra -O3
LDFLAGS			=	-lncurses
MAKEFLAGS		+=	-j $$(nproc)
DEPS			=	-MMD -MP

#-------------------------------- DIRECTORIES --------------------------------#

LIBFT_DIR		=	lib/libft

INCLUDE_DIR		=	inc/

SRC_DIR			=	src/
OBJ_DIR			=	.build/

#-------------------------------- INCLUDES & FLAGS ---------------------------#

INCLUDES		= -I $(INCLUDE_DIR) -I ./lib/libft/includes -I $(LIBMLX_DIR) 

#-------------------------------- SOURCE FILES -------------------------------#

INIT_SRCS		:=	init/init.c

MAIN_SRCS		:=	main.c

SRCS			:=	$(addprefix $(SRC_DIR), \
					$(MAIN_SRCS) \
					$(INIT_SRCS))

#-------------------------------- OBJECTS ------------------------------------#

OBJS			=	$(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))
DEPENDENCIES	=	$(OBJS:.o=.d)

#-------------------------------- RULES --------------------------------------#


all: $(NAME)

$(NAME):  $(MLX) $(OBJS)
	$(CC) $(OBJS) -o $(NAME)  $(LDFLAGS)

$(OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) $(DEPS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)


re: fclean
	$(MAKE) all

print-%:
	@echo $($(patsubst print-%,%,$@))

-include $(DEPENDENCIES)

.PHONY: all clean fclean re print-%