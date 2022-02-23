

DIR = $(CURDIR)
LIB_DIR = $(DIR)/lib

SIGS = signals.c
PID_OBJ = pid.o
PID_LIB = libpid.so
PID_NAME = signals
CHILD = child

LD_LIBRARY_PATH = $LD_LIBRARY_PATH

NAMER = signals

EXEC1 = $(NAMER).x

OBJ = $(NAMER).o 
LIB_OBJ = $(SIGS).o

PID = pid.c

LIB_DIR = ./lib

CFLAGS = -Wall -fPIC
LFLAGS = -Wall

CO = gcc


$(PID_LIB): $(SIGS)
	
	$(CO) -c $(CFLAGS) ../lib/$(PID)
	mv $(PID_OBJ) ../lib
	$(CO) -shared -o ../lib/$(PID_LIB) ../lib/$(PID_OBJ) 


$(EXEC1): 
	$(CO) $(LFLAGS) -o $@ $(NAMER).c -lpid
	export LD_LIBRARY_PATH=${DIR}/../lib:$$LD_LIBRARY_PATH



run: clean $(EXEC1)
	export LD_LIBRARY_PATH=../lib:; \
	./$(EXEC1) 3

pid: clean $(PID_LIB) 
	
clean:
	rm -f .o *~ *.a *.so *.x core core *.out; rm -rf
