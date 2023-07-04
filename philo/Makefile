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

CFLAGS		= -Wall -Werror -Wextra  -g -g3 -pthread 
#-fsanitize=thread

NAME		= philo

################ COLORS ################

C_GREEN=\033[0;32m
C_RED=\033[0;31m
C_BLUE=\033[0;34m
C_YELLOW=\033[0;33m
C_PINK=\033[0;35m
C_TEAL=\033[0;36m

B_GREEN=\033[32;1m
B_RED=\033[31;1m
B_BLUE=\033[34;1m
B_YELLOW=\033[33;1m
B_PINK=\033[35;1m
B_TEAL=\033[36;1m

C_END=\033[0m

################ RULES ################

all: $(NAME)

$(NAME): $(OBJPATH) $(OBJ) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "🍝$(B_GREEN) Spaghetti a la bolognese ready for the feast $(C_END)🍝"

-include $(DEP)

$(OBJPATH)%.o:%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(C_PINK).o file generated$(C_END)"

$(OBJPATH):
	@mkdir -p $(OBJPATH)
	@echo "$(C_BLUE).obj/ folder created$(C_END)"
	
clean: 
	@rm $(NAME)
	@echo "$(C_YELLOW)Exec file deleted$(END)"

fclean: clean
	@rm -rf $(OBJPATH)
	@echo "$(C_YELLOW)Object files & folder deleted$(END)"

re: fclean all

.PHONY: all clean fclean re

checks: $(OBJPATH) $(OBJ) $(INCLUDES)
	$(CC) $(CFLAGS) -fsanitize=thread $(OBJ) -o $(NAME)

gmk:
		@if [ -d make ];then echo "$(C_GREEN)Source file list updated$(C_END)" ;else mkdir make;fi
		@find -name '*.c' | sed 's/^/SRC += /' > make/src.mk
		@find -name '*.h' | sed 's/^/INC += /' > make/inc.mk