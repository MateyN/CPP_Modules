NAME = phonebook

CXX		=	c++

SRCS = Phonebook.cpp Contact.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

CXFLAGS = -Wall -Wextra -Werror -std=c++98

%.o : %.cpp
	$(CXX) $(CXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXFLAGS) $^ -o $@

clean:
	rm -f *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

