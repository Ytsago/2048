# -----------RULES-----------#


CFLAGS = -Wall  -Wextra -Werror -MMD -MP -g3

CC = cc
AR = ar
ARFLAG = -rcs

# -----------PATHS-----------#

SRCDIR = src/

UTIDIR = $(SRCDIR)utils/

GAMEDIR = $(SRCDIR)game/

# UTILS SUBDIRECTORIES #



INCDIR = inc/
LIBDIR = libft/
OBJDIR = .Obj/

# -----------FILES-----------#

MAIN =		main.c

UTILS =		slide.c utils.c

GAME =		number.c		movement.c		fuse.c

INC =		libft.h			ft_printf.h		slide.h


# -----------SRCS-----------#


SRCS =	$(addprefix $(SRCDIR), $(MAIN)) \
		$(addprefix $(UTIDIR), $(UTILS)) \
		$(addprefix $(GAMEDIR), $(GAME)) \


# -----------OTHER-----------#

OBJS =	$(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

DEPS =	$(OBJS:.o=.d)

HEADER = $(addprefix $(INCDIR), $(INC))

LIBS =	libft.a

NAME =	2048

# -----------RULES-----------#

all: $(NAME) Makefile

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(CFLAG) -lncursesw $(OBJS) -o $(NAME) $(LIBDIR)$(LIBS)

$(OBJDIR)%.o: $(SRCDIR)%.c Makefile | $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCDIR) $(if $(LIBS),-I $(LIBDIR)$(INCDIR)) -c $< -o $@ 

$(OBJDIR):
	mkdir -p $(OBJDIR) $(dir $(OBJS))

$(LIBS): FORCE
	@$(MAKE) -C $(LIBDIR) --no-print-directory

bonus: $(NAME)_bonus

# -----------UTILS-----------#

clean:
	rm -rf $(OBJDIR)
ifneq ($(LIBS),)
	@$(MAKE) $@ -C $(LIBDIR) 
endif

fclean: clean
	rm -f $(NAME)
ifneq ($(LIBS),)
	@$(MAKE) $@ -C $(LIBDIR) 
endif

re: fclean all

FORCE:

-include $(DEPS)

.PHONY: clean fclean re all bonus