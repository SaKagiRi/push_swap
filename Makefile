NAME	= push_swap
FILE	= push_swap.c parser.c swap_node.c utils.c push_node.c rotate.c reverse_rotate.c index.c sort.c utils2.c sort2.c
BFILE	= checker.c parser.c swap_node.c utils.c push_node.c rotate.c reverse_rotate.c index.c sort.c utils2.c sort2.c
FLAGS	= -Wall -Wextra -Werror -g3 #-o0 -fsanitize=address,undefined
CC		= cc
OBJD	= obj
SRCD	= src
INC		= include
KML		= KML

SRC		= $(addprefix $(SRCD)/, $(FILE))
OBJ		= $(addprefix $(OBJD)/, $(FILE:%.c=%.o))

BSRC	= $(addprefix $(SRCD)/, $(BFILE))

OUT		= ./

all		:$(NAME)

$(OBJD)/%.o :$(SRCD)/%.c | $(OBJD)
			@$(CC) $(FLAGS) -I$(INC) -c $< -o $@

bonus		:$(OBJD) $(BOBJ)
			@make -C $(KML) && $(CC) $(FLAGS) $(BSRC) $(KML)/kml.a -I$(INC) -o $(OUT)/checker -D SHOW_OPERATION=0 -D BUFFER_SIZE=1

$(NAME)		:$(OBJ) 
			@make -C $(KML) && $(CC) $(FLAGS) $(SRC) $(KML)/kml.a -I$(INC) -o $(OUT)/$(NAME)

$(OBJD)		:
			@mkdir -p $(OBJD)

clean		:
			@rm -rf $(OBJD) && make clean -C $(KML)

fclean		:clean
			@rm -rf $(OUT)/$(NAME) && make fclean -C $(KML)
			@rm -rf $(OUT)/checker

re			:fclean all

.PHONY		:all clean fclean re bonus
