CC = gcc
CFLAGS = -W -Wall -g
OBJETS = cp_sys.o cp_std.o cp_rev.o read_int.o write_int.o

all: cp_sys cp_std cp_rev read_int write_int

cp_sys cp_std cp_rev read_int write_int: % : %.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f cp_sys cp_std cp_rev read_int write_int $(OBJETS)
	@echo "Clean done."
