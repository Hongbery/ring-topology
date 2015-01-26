#
#
CC=gcc
CFLAGS=-g

# comment line below for Linux machines
#LIB= -lsocket -lnsl

all: master listen speak

master:	master.o socket_message_parser.o
	$(CC) $(CFLAGS) -o $@ master.o socket_message_parser.o linked_list.o $(LIB)

#socket_utils: socket_utils.o
#	$(CC) $(CFLAGS) -c socket_utils.c

#linked_list: linked_list.o
#	$(CC) $(CFLAGS) -c linked_list.c

master.o:	socket_message_parser.h socket_message.h linked_list.h
	$(CC) $(CFLAGS) -c master.c  socket_message_parser.c linked_list.c

socket_message_parser.o: socket_message_parser.h 

linked_list.o: linked_list.h

listen:	listen.o
	$(CC) $(CFLAGS) -o $@ listen.o $(LIB)
listen.o:	listen.c

speak:	speak.o
	$(CC) $(CFLAGS) -o $@ speak.o $(LIB)
speak.o:	speak.c 

clean:
	\rm -f master listen speak

squeaky:
	make clean
	\rm -f master.o socket_message_parser.o linked_list.o listen.o speak.o

