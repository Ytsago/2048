# -----------RULES-----------#


CFLAGS = -Wall  -Wextra -Werror -MMD -MP -g3

CC = cc
AR = ar
ARFLAG = -rcs

# -----------PATHS-----------#

SRCDIR = src/
SRCDIR_BONUS = src_bonus/

UTIDIR = $(SRCDIR)utils/

GAMEDIR = $(SRCDIR)game/

# UTILS SUBDIRECTORIES #



INCDIR = inc/
LIBDIR = libft/
OBJDIR = .Obj/

# -----------FILES-----------#

MAIN =		main.c

BONUS =		main.c highscore.c

UTILS =		slide.c utils.c

GAME =		number.c		movement.c		fuse.c

INC =		libft.h			ft_printf.h		slide.h


# -----------SRCS-----------#


SRCS =	$(addprefix $(SRCDIR), $(MAIN)) \
		$(addprefix $(UTIDIR), $(UTILS)) \
		$(addprefix $(GAMEDIR), $(GAME)) \

SRCS_B =	$(addprefix $(SRCDIR_BONUS), $(BONUS)) \
			$(addprefix $(UTIDIR), $(UTILS)) \
			$(addprefix $(GAMEDIR), $(GAME)) \

# -----------OTHER-----------#


OBJS = $(SRCS:%.c=$(OBJDIR)%.o)
OBJS_B = $(SRCS_B:%.c=$(OBJDIR)%.o)

HEADER = $(addprefix $(INCDIR), $(INC))

LIBS =	libft.a

NAME =	2048

REMAKE = libft/Makefile libft/inc/bt_malloc.h libft/inc/color.h libft/inc/ft_printf.h libft/inc/get_next_line.h libft/inc/libft.h \
		Makefile inc/move.h inc/wong_car_wai.h

# -----------RULES-----------#

all: $(NAME)

$(NAME): $(LIBDIR)$(LIBS) $(OBJS)
	$(CC) $(CFLAG) -lncursesw $(OBJS) -o $(NAME) $(LIBDIR)$(LIBS)

$(OBJDIR)%.o: %.c $(REMAKE) | $(OBJDIR)
	$(CC) $(CFLAGS) -I $(INCDIR) $(if $(LIBS),-I $(LIBDIR)$(INCDIR)) -c $< -o $@ 

$(OBJDIR):
	mkdir -p $(OBJDIR) $(dir $(OBJS)) $(dir $(OBJS_B))

$(LIBDIR)$(LIBS): FORCE
	@$(MAKE) -C $(LIBDIR) --no-print-directory

bonus: $(NAME)_bonus

$(NAME)_bonus: $(LIBDIR)$(LIBS) $(OBJS_B)
	$(CC) $(CFLAG) -lncursesw $(OBJS_B) -o $(NAME)_bonus $(LIBDIR)$(LIBS)

# -----------UTILS-----------#

clean:
	rm -rf $(OBJDIR)
ifneq ($(LIBS),)
	@$(MAKE) $@ -C $(LIBDIR) 
endif

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME)_bonus
ifneq ($(LIBS),)
	@$(MAKE) $@ -C $(LIBDIR) 
endif

re: fclean all

FORCE:

.PHONY: clean fclean re all bonus  FORCE