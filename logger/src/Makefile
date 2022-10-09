CC = gcc
DEPS = funcs.h
ODIR = ../obj
BDIR = ../bin
OBJ = $(ODIR)/logger.o $(ODIR)/funcs.o

all: logger funcs build

logger: logger.c $(DEPS)
	$(CC) -c logger.c -o $(ODIR)/logger.o

funcs: funcs.c $(DEPS)
	$(CC) -c funcs.c -o $(ODIR)/funcs.o

build: $(OBJ)
	$(CC) $(OBJ) -o $(BDIR)/logger.exe

clear:
	rm $(ODIR)/*.o $(BDIR)/*.exe