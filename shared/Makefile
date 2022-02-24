

DIR = $(CURDIR)
LIB_DIR = $(DIR)/lib

SIGS = signals.c
PID_OBJ = pid.o
PID_LIB = libpid.so
PID_NAME = signals
CHILD = child

LD_LIBRARY_PATH = $LD_LIBRARY_PATH

NAMER = shared
NAMER2 = send

EXEC1 = $(NAMER).o
EXEC2 = $(NAMER2).x

OBJ = $(NAMER).o 
LIB_OBJ = $(SIGS).o

PID = pid.c

LIB_DIR = ./lib

CFLAGS = -Wall -fPIC
LFLAGS = -Wall

CO = gcc


$(PID_LIB): $(SIGS)
	
	$(CO) -c $(CFLAGS) ../lib/$(PID)
	$(CO) -shared -o ../lib/$(PID_LIB) ./$(PID_OBJ) 
	mv $(PID_OBJ) ../lib

$(EXEC1): 
	$(CO) $(LFLAGS) -o $@ $(NAMER).c -lpid
	export LD_LIBRARY_PATH=${DIR}/../lib:$$LD_LIBRARY_PATH




run: clean $(EXEC1)
	export LD_LIBRARY_PATH=../lib:; \
	./pipes3.o

shared: clean 
	$(CO) $(LFLAGS) -o $@.o $(NAMER).c -lrt -pthread
	export LD_LIBRARY_PATH=${DIR}/../lib:$$LD_LIBRARY_PATH
	./shared.o


pid: clean $(PID_LIB) 
	
clean:
	rm -f .o *~ *.a *.so *.x core core *.out; rm -rf
	rm -f shared.o
#	ls
