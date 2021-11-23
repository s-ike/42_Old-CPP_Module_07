NAME		:= a.out
ifdef TEST
SRCS		:= main2.cpp
else
SRCS		:= main.cpp
endif
OBJDIR		:= ./objs/
OBJS		:= $(addprefix $(OBJDIR), $(SRCS:.cpp=.o))
DEPENDS		:= $(addprefix $(OBJDIR), $(SRCS:.cpp=.d))

INCLUDES	:= -I.
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -MP $(INCLUDES)

RM			:= rm -f
C_GREEN		:= "\033[32m"
C_DEFAULT	:= "\033[39m"
C_RESET		:= "\033[m"

$(OBJDIR)%.o:	%.cpp
			@if [ ! -d $(OBJDIR) ]; then \
				echo "mkdir $(OBJDIR)"; mkdir $(OBJDIR); \
			fi
			$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:		all clean fclean re
all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $@
			@echo $(C_GREEN)"=== Make Done ==="$(C_DEFAULT)$(C_REST)

clean:
			$(RM) $(OBJS)
			$(RM) $(DEPENDS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

-include	$(DEPENDS)

.PHONY:		test
test:
			$(MAKE) TEST=TRUE
