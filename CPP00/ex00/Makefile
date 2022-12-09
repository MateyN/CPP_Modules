NAME	=	megaphone

CPP		=	c++

CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 

SRCS	=	megaphone.cpp

OBJS	=	$(SRCS:.cpp=.o)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
