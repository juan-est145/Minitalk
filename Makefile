LIBFT_PATH = libft

NAME = server
NAME_CLIENT = client

SCRS_SERVER = main_s.c
OBJS_SERVER = $(SCRS_SERVER:.c=.o)

SCRS_CLIENT = main_c.c
OBJS_CLIENT = $(SCRS_CLIENT:.c=.o)

HEADER = minitalk.h

COMPILER = CC
FLAGS= -Wall -Werror -Wextra
LIBRARY_FLAG = -Llibft -lft -o

RM = rm -rf

all: make-library $(NAME) $(NAME_CLIENT)

make-library:
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJS_SERVER) $(HEADER)
	$(COMPILER) $(FLAGS) $(LIBRARY_FLAG) $(NAME) $(OBJS_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(HEADER)
	$(COMPILER) $(FLAGS) $(LIBRARY_FLAG) $(NAME_CLIENT) $(OBJS_CLIENT)

clean:
	$(MAKE) clean -C $(LIBFT_PATH)
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(NAME) $(NAME_CLIENT)

re: fclean
	$(MAKE) all