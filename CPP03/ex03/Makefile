NAME	= diamondTrap
CFLAGS	= -Wall -Wextra -Werror -Wshadow -std=c++98
RM		= rm -rf
CC		= c++
SRC_DIR = src/
OBJ_DIR = obj/

SRC		= main \
		  ClapTrap \
		  ScavTrap \
		  FragTrap \
 		  DiamondTrap

SRCS	= $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC)))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
