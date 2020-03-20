NAME		= libasm.a

SRCS		= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_strdup.s ft_read.s

OBJS		= $(SRCS:.s=.o)

RM			= rm -rf

all:		$(NAME)

.s.o:
			nasm -f elf64 -o $(<:.s=.o)  $<

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) 

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

