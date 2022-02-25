DIR = $(CURDIR)
E = euler
MYMC = mymc
LIB = libmymc

CO = gcc
LFLAGS = -Wall
CFLAGS = -Wall -fPIC




EXEC1 = $(E).o

$(MYMC):
	$(CO) -c $(CFLAGS) ../lib/$(MYMC).c
	$(CO) -shared -o ../lib/$(LIB).so ./$(MYMC).o
	mv $(MYMC).o ../lib


$(EXEC1): $(MYMC)
	export LD_LIBRARY_PATH=${DIR}/../lib:$$LD_LIBRARY_PATH
	$(CO) -L/$(DIR)/../lib $(LFLAGS) -o test $(E).c -lrt -lpthread -lmymc


run: clean $(EXEC1)
	export LD_LIBRARY_PATH=../lib:; \
	./test


clean:
	rm -f .o *~ *.a *.so *.x core core *.out; rm -rf
	rm -f euler.o