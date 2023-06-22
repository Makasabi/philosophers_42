include make/inc.mk
include make/src.mk

################ PATHS ################

OBJPATH		= .obj/
SRCPATH		= src/
INCPATH		= inc/
DEPPATH		= .dep/

################ MACROS ################

OBJ			= $(SRC:.c=.o)
OBJ			:= $(addprefix $(OBJPATH), $(OBJ))

DEP			= $(SRC:.c=.d)

cc			= gcc

CFLAGS		= -Wall -Werror -Wextra -g -g3 -pthread

NAME		= philo

################ RULES ################

all: $(NAME)

$(NAME): $(OBJPATH) $(OBJ) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

-include $(DEP)

$(OBJPATH)%.o:%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJPATH):
	@mkdir -p $(OBJPATH)

clean: 
	rm $(NAME)

fclean: clean
	rm -rf $(OBJPATH)

re: fclean all

.PHONY: all clean fclean re

checks: $(OBJPATH) $(OBJ) $(INCLUDES)
	$(CC) $(CFLAGS) -fsanitize=thread $(OBJ) -o $(NAME)

gmk:
		@if [ -d make ];then echo ok;else mkdir make;fi
		@find -name '*.c' | sed 's/^/SRC += /' > make/src.mk
		@find -name '*.h' | sed 's/^/INC += /' > make/inc.mk