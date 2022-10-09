CC = gcc
LIBS = -lws2_32
DEPS = debug.h
ODIR = ../obj
BDIR = ../bin
C_OBJ = $(ODIR)/client.o $(ODIR)/debug.o
S_OBJ = $(ODIR)/server.o $(ODIR)/debug.o

all: client server debug build

client: client.c $(DEPS)
	$(CC) -c client.c -o $(ODIR)/client.o

server: server.c $(DEPS)
	$(CC) -c server.c -o $(ODIR)/server.o

debug: debug.c $(DEPS)
	$(CC) -c debug.c -o $(ODIR)/debug.o

build: $(C_OBJ) $(S_OBJ)
	$(CC) $(C_OBJ) $(LIBS) -o $(BDIR)/client.exe && $(CC) $(S_OBJ) $(LIBS) -o $(BDIR)/server.exe

clear:
	rm $(ODIR)/*.o $(BDIR)/*.exe