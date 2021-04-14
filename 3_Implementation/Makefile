PROJECT_NAME=game
#TEST_NAME=testf
SRC=3_Implementation/project_main.c\
3_Implementation/src/handcricket.c\
3_Implementation/src/hangman.c\

SRC2=3_Implementation/src/handcricket.c\
3_Implementation/src/hangman.c\

TEST_SRC= 3_Implementation/test/test.c \
3_Implementation/unity/unity.c

INC_H =3_Implementation/inc
INC_T =3_Implementation/unity


all.exe:
	gcc $(SRC) -I $(INC_H) -I $(INC_T)  -o $(PROJECT_NAME).exe
test:
	gcc $(SRC2) $(TEST_SRC) -I $(INC_H) -I $(INC_T) -o testf.exe


 
run:$(PROJECT_NAME).exe
	$(PROJECT_NAME).exe

cppcheck:
	cppcheck --enable=all $(SRC)


