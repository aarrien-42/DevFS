# PROGRAM
NAME = DevFS

# FOLDERS
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
BIN_DIR = bin

# FILES
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# COMPILATION
CC = c++
CFLAGS = `pkg-config fuse3 --cflags`
LDFLAGS = `pkg-config fuse3 --libs`
RM = rm -rf

# COLORS
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# RULES

.SILENT:

all: $(NAME)

mount: $(NAME)
	./$(BIN_DIR)/$(NAME) $(lastword $(MAKECMDGOALS))

unmount:
	fusermount -u $(lastword $(MAKECMDGOALS))

unmount_all:
	@for dir in $$(mount | grep "$(NAME)" | awk '{print $$3}'); do \
		fusermount -u "$$dir" || true; \
	done

status:
	mount | grep $(NAME)

$(NAME): $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -I $(INC_DIR) $(LDFLAGS) -o $(BIN_DIR)/$(NAME)
	echo "$(YELLOW)Program compiled!$(DEF_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	printf "$(BLUE)Compiling: $< $(DEF_COLOR)"
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_DIR)
	echo "$(GREEN)OK$(DEF_COLOR)"

clean:
	$(RM) $(OBJ_DIR)

fclean: clean unmount_all
	$(RM) $(BIN_DIR)

re: fclean all

.PHONY: all mount unmount clean fclean re
