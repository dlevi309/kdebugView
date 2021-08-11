CC = gcc-iphone
LIBS   := -framework Foundation
SIGN   := ldid -Sent.xml

all:
	$(CC) $(FLAGS) kdebugView.c -o kdv $(LIBS)
	$(SIGN) kdv