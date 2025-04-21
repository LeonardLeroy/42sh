##
## EPITECH PROJECT, 2025
## B-PSU-200-LYN-2-1-minishell1-valentin.guinet
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
NAME	=	42sh

## PATH ##
LIB_HF_PATH	=	lib/hf
TESTS_PATH	=	tests

## FILES ##
SRCS	=	$(wildcard src/*.c)	\
			$(wildcard src/*/*.c)	\
			$(wildcard src/*/*/*.c)	\
			$(wildcard bonus/*.c)	\
			main.c

## TRANSFORMATIONS ##
OBJS	=	$(SRCS:%.c=%.o)

## FLAGS ##
CFLAGS	=	-I./include/
CFLAGS	+=	-Wall
CFLAGS	+=	-Wextra
CFLAGS	+=	-Wpedantic
CFLAGS	+=	-Wunused
CFLAGS	+=	-Wunused-parameter
CFLAGS	+=	-L$(LIB_HF_PATH) -lhf
CFLAGS	+=	-lncurses
ifeq ($(ENV), dev)
	CFLAGS	+=	-g3 -DENV_DEV
else
	CFLAGS	+=	-O2 -fno-builtin
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

### make
make_libs:
	@make --no-print-directory -C $(LIB_HF_PATH)

$(NAME): make_libs $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS)	\
	&& $(call PRINT,COMPILED,$(BOLD_)$(NAME))	\
	|| $(call ERROR,BUILD FAILED,$@)
	@cp $(NAME) $(TESTS_PATH)/tester/

%.o:	%.c
	@$(CC) -o $@ -c $< $(CFLAGS)	\
	&& $(call PRINT,COMPILED,$@)	\
	|| $(call ERROR,BUILD FAILED,$@)

### clean
make_clean_libs:
	@make --no-print-directory clean -C $(LIB_HF_PATH)

clean:
	@$(RM) $(OBJS)	\
	&& $(call REMOVE,REMOVE,.o files)

### fclean
make_fclean_libs:
	@make --no-print-directory fclean -C $(LIB_HF_PATH)

make_fclean_tests:
	@make --no-print-directory fclean -C $(TESTS_PATH)

fclean: clean make_fclean_libs make_fclean_tests
	@$(RM) $(NAME)	\
	&& $(call REMOVE,REMOVE,$(NAME))
	@$(RM) $(TESTS_PATH)/tester/$(NAME)	\
	&& $(call REMOVE,REMOVE,$(NAME))
	@$(RM) *.txt	\
	&& $(call REMOVE,REMOVE,.txt files)

### re
re:	fclean all

## -- CRITERION TESTS -- ##
unit_tests:
	@make --no-print-directory re -C $(TESTS_PATH)

tests_run:	unit_tests
	@./$(TESTS_PATH)/unit_tests

lines:	tests_run
	gcovr --exclude $(TESTS_PATH)

branches:	tests_run
	gcovr --exclude $(TESTS_PATH) --txt-metric branch

coding-style:	fclean
	./format.sh include/header.h
	./format.sh include/help_fc.h
	clear
	mango

github:
	git remote get-url origin |	\
	sed 's/git@github.com:/https:\/\/github.com\//' |	\
	xargs xdg-open

.PHONY: all clean fclean re	\
		make_libs make_clean_libs make_fclean_libs	\
		make_tests make_fclean_tests	\
		unit_tests tests_run lines branches	\
		coding-style	\
		github
