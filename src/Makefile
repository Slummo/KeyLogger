CC = gcc
LIBS = -lws2_32
DEPS = funcs.h
ODIR = ../obj
BDIR = ../bin
C_OBJ = $(ODIR)/client.o $(ODIR)/funcs.o
S_OBJ = $(ODIR)/server.o $(ODIR)/funcs.o

all: client server funcs build

client: client.c $(DEPS)
	$(CC) -c client.c -o $(ODIR)/client.o

server: server.c $(DEPS)
	$(CC) -c server.c -o $(ODIR)/server.o

funcs: funcs.c $(DEPS)
	$(CC) -c funcs.c -o $(ODIR)/funcs.o

build: $(C_OBJ) $(S_OBJ)
	$(CC) $(C_OBJ) $(LIBS) -o $(BDIR)/client.exe
	$(CC) $(S_OBJ) $(LIBS) -o $(BDIR)/server.exe

clear:
	rm $(ODIR)/*.o $(BDIR)/*.exe