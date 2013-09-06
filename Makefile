# CFLAGS =

all: James

James: James.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	-rm -f James *.o
