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
NAME	=	libhf.a

## FILES ##
SRCS	=	$(wildcard *.c)

## TRANSFORMATIONS ##
OBJS	=	$(SRCS:%.c=%.o)

## FLAGS ##
CFLAGS	=	-I../../include/
CFLAGS	+=	-Wall
CFLAGS	+=	-Wextra
CFLAGS	+=	-Wpedantic
CFLAGS	+=	-Wunused
CFLAGS	+=	-Wunused-parameter
ifeq ($(ENV), dev)
	CFLAGS	+=	-g3 -DENV_DEV
else
	CFLAGS 	+=	-O2
endif

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

$(NAME):	$(OBJS)
	@$(AR) $(NAME) $(OBJS)	\
	&& $(call PRINT,ARCHIVED,$(BOLD_)$@)	\
	|| $(call ERROR,ARCHIVED FAILED,$@)

%.o:	%.c
	@$(CC) -o $@ -c $< $(CFLAGS)	\
	&& $(call PRINT,COMPILED,$@)	\
	|| $(call ERROR,BUILD FAILED,$@)

clean:
	@$(RM) $(OBJS)	\
	&& $(call REMOVE,REMOVE,.o files)

fclean:	clean
	@$(RM) $(NAME)	\
	&& $(call REMOVE,REMOVE,$(NAME))

re:	fclean all

.PHONY:	all clean fclean re
