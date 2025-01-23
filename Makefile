NAME			=	ircserv

INC				=	inc/
BIN				=	src/bin

SRCS			=	$(shell find src -type f -name "*.cpp")
INCS			=	$(shell find inc -type f -name "*.hpp")
OBJS			=	$(SRCS:src/%.cpp=src/bin/%.o)
HOBJS			=	$(INCS:inc/%.hpp)

CC				=	c++
RM				=	rm -rf
CPPFLAGS		=	-std=c++98 -Wall -Wextra -Werror

all:			$(NAME)

$(BIN):
	@mkdir $(BIN)

$(NAME):	$(BIN) $(OBJS) $(HOBJS)
			@echo "Compiling [$(NAME)]..."
			@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
			@echo "Compiled.."

clean:
			@echo "Deleting [$(NAME)]..."
			@$(RM) $(OBJS) $(HOBJS)
			@$(RM) $(BIN)
			@echo "Deleted.."

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

$(BIN)%.o: src/%.cpp
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CPPFLAGS) -c $< -o $@ -I$(INC)


.PHONY:			all clean fclean re bonus

