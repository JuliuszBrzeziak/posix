

DIR = $(CURDIR)
LIB_DIR = $(DIR)/lib

PID = pid.c
PID_OBJ = pid.o
PID_LIB = libpid.so
PID_NAME = pid
CHILD = child

LD_LIBRARY_PATH = $LD_LIBRARY_PATH

NAMER = run

EXEC1 = $(NAMER).x

OBJ = $(NAMER).o 
LIB_OBJ = $(PID).o


LIB_DIR = ./lib

CFLAGS = -Wall -fPIC
LFLAGS = -Wall

CO = gcc

$(CHILD):
	$(CO) $(LFLAGS) -o $(CHILD).x $(CHILD).c

$(PID_LIB): $(PID)
	$(CO) -c $(CFLAGS) $(PID)
	$(CO) -shared -o $(PID_LIB) $(PID_OBJ) 
	mkdir -p $(LIB_DIR)
	mv $(PID_LIB) ./lib


$(EXEC1): $(PID_LIB) $(PID) 
	
	$(CO) $(LFLAGS) -o $@ $(NAMER).c -l$(PID_NAME)
#	export LD_LIBRARY_PATH=${DIR}/lib:$$LD_LIBRARY_PATH


run: $(EXEC1) $(CHILD)
	export LD_LIBRARY_PATH=./lib:; \
	./$(EXEC1)

	






clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}

