##
## EPITECH PROJECT, 2025
## 42sh
## File description:
## Makefile
##

## STYLE ##
ECHO	:=	/bin/echo
DEF_	:=	\e[0m
BOLD_	:=	\e[1m
RED_	:=	\e[31m
GREEN_	:=	\e[32m
CYAN_	:=	\e[36m

## KEYWORDS ##
CC	=	gcc
AR	=	ar rcs
RM	=	rm -f

## NAMES ##
NAME	=	unit_tests

## PATH ##
LIB_HF_PATH	=	../lib/hf

## FILES ##
SRCS	=	$(wildcard *.c)	\
			$(wildcard $(LIB_HF_PATH)/*.c)	\
			$(wildcard ../src/*.c)	\
			$(wildcard ../src/*/*.c)

## FLAGS ##
CFLAGS	=	-I../include/
CFLAGS	+=	-Wall
CFLAGS	+=	-Wextra
CFLAGS	+=	-Wpedantic
CFLAGS	+=	-L$(LIB_HF_PATH) -lhf
ifeq ($(ENV), dev)
	CFLAGS	+=	-g3 -DENV_DEV
else
	CFLAGS	+=	-O2
endif
FLAGS	=	-I../include/ -lcriterion --coverage

###############################################################################
###	MESSAGES
###############################################################################

define PRINT
    $(ECHO) -e "[$(GREEN_)✔$(DEF_)] $(1): $(GREEN_)$(2)$(DEF_)"
endef
define ERROR
    $(ECHO) -e "[$(RED_)✘$(DEF_)]$(RED_) $(1) ($(2))$(DEF_)"
endef
define REMOVE
    $(ECHO) -e "[$(CYAN_)✔$(DEF_)] $(1): $(CYAN_)$(2)$(DEF_)"
endef

###############################################################################
###	CALLS
###############################################################################

all:	$(NAME)

$(NAME):
	@$(CC) $(SRCS) -o $(NAME) $(FLAGS)	\
	&& $(call PRINT,BUILD,$(BOLD_)$(NAME))	\
	|| $(call ERROR,BUILD FAILED,$@)

fclean:
	@rm -f *.gcda	\
	&& $(call REMOVE,REMOVE,.gcda files)
	@rm -f *.gcno	\
	&& $(call REMOVE,REMOVE,.gcno files)
	@rm -f $(NAME)	\
	&& $(call REMOVE,REMOVE,$(NAME))

re:	fclean all

.PHONY:	all fclean re
