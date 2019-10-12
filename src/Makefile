
NAME		= ft_gkrellm

SRCS     := *.cpp
OBJS     := $(SRCS:.cpp=.o)

CPP      := clang++
CPPFLAGS := -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(OBJS) -o $@
	@printf '\033[32m%s\n\033[0m' "Created ft_gkrellm! Yoohooo!"

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@printf '\033[31m%s\n\033[0m' "Cleaned objects of ft_gkrellm"

fclean: clean
	@rm -f $(NAME)
	@printf '\033[31m%s\n\033[0m' "All cleaned"

re:		fclean all
