NAME = pipex

INC = pipex.h

SRC1 = 	src/verif_funct.c \
		src/help_verif_funct.c \
		src/error.c

OBJ = ${SRC1:.c=.o}

all: $(NAME) 

CFLAGS = -Wall -Wextra -Werror 


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 
#ifeq [$(shell ls | grep "o_files" | wc -l) == 1]; then\
#	echo "done !!!";\
#fi

C_O = \
	if [ ! -e  "oubject" ]; then \
	mkdir oubject; \
	fi


$(NAME): $(OBJ) $(INC)
	@$(CC) $(OBJ) -g -o $(NAME)
	@$(C_O)
	@mv $(OBJ) oubject/
	@echo "funct ready !!"

clean: deleting
	@rm -rf oubject
	@echo "done !!"

fclean:	deleting_lib deleting clean 
	@rm -rf $(NAME)

libx:
	make -C mlx/


re: fclean  all
	
annoncement :
		@echo "creating program..."

deleting :
	@echo "deleting OBJECT_FILES files..."

deleting_lib :
	@echo "deleting program...."

save: fclean 
	@git add *.c *.h Makefile
	@git commit -m autosave
	@git push