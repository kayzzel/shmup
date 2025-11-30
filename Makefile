#-------------------------------- VARIABLES ----------------------------------#

NAME			=	ft_shmup
CC				=	cc
CFLAGS			=	-Wall -Wextra -O3 -g
LDFLAGS			=	-lncurses
MAKEFLAGS		+=	-j $$(nproc)
DEPS			=	-MMD -MP

#-------------------------------- DIRECTORIES --------------------------------#

LIBFT_DIR		=	lib/libft

INCLUDE_DIR		=	inc/

SRC_DIR			=	src/
OBJ_DIR			=	.build/

#-------------------------------- INCLUDES & FLAGS ---------------------------#

INCLUDES		= -I $(INCLUDE_DIR)

#-------------------------------- SOURCE FILES -------------------------------#

INIT_SRCS		:=	init/init.c

FPS_SRCS		:=	fps/fps.c

LINKED_LIST_SRC	:=	linked_list/linked_list.c

OBJECTS_SRC		:= objects/objects.c

PROJECTILE_SRC	:= projectile/projectile.c

OPONENTS_SRC	:= oponents/oponents.c

PLAYER_SRCS		:=	player/game_loop.c \
					player/player.c

MAIN_SRCS		:=	main.c

SRCS			:=	$(addprefix $(SRC_DIR), \
					$(MAIN_SRCS) \
					$(INIT_SRCS) \
					$(FPS_SRCS) \
					$(PLAYER_SRCS) \
					$(OBJECTS_SRC) \
					$(PROJECTILE_SRC) \
					$(LINKED_LIST_SRC) \
					$(OPONENTS_SRC))

#-------------------------------- OBJECTS ------------------------------------#

OBJS			=	$(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))
DEPENDENCIES	=	$(OBJS:.o=.d)

#-------------------------------- RULES --------------------------------------#


all: $(NAME)

$(NAME): $(OBJS)
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
