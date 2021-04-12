PROJECT_NAME=game

SRC=project_main.c\
src/handcricket.c\
src/hangman.c

TEST_SRC=src/handcricket.c\
src/hangman.c

INC = -Iinc


$(PROJECT_NAME).exe: $(SRC) 
	gcc $(INC) $(SRC)  -o $(PROJECT_NAME).exe
 
run:$(PROJECT_NAME).exe
	$(PROJECT_NAME).exe

