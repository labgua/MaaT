
CC=g++

IDIR=src
INCLUDE=include
ODIR=obj

#------------------------

#1) Cerca tutti i file source
SRC_FILES=$(wildcard $(IDIR)/*.c*)

#2) Normalizza in CPP
CPP_FILES=$(SRC_FILES:.c=.cpp)

#3) Definisci tutti i file oggetto
_OBJ_FILES=$(CPP_FILES:.cpp=.o)

#4) Definisci i file oggetto con opportune path relative 
OBJ_FILES=$(subst $(IDIR)/,$(ODIR)/,$(_OBJ_FILES))

#-------------------------

# Define the library used in the program (static link) [only for main test]
IMPORTED_LIBRARY=
NEEDED_OBJS := $(foreach obj,$(IMPORTED_LIBRARY),$(ODIR)/$(obj).o)

#---------------------------------------------------------------------------

all: $(OBJ_FILES)
	@echo "All .obj files are compiled with success!"

$(ODIR)/%.o: $(IDIR)/%.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE)




test_newmodule: main.cpp module.o module.h
	$(CC) -o main main.cpp module.o $(NEEDED_OBJS) -I$(INCLUDE)

module.o: module.cpp
	$(CC) -c module.cpp -o module.o -I$(INCLUDE)


### TEST SECTION

test1:
	@echo "Print all src files to compile:"
	@echo $(CPP_FILES)

test2:
	@echo "Print all targets object:"
	@echo $(OBJ_FILES)

test3:
	@echo "Needed OBJ for newmodule:"
	@echo $(NEEDED_OBJS)