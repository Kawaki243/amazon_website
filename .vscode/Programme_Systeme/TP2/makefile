CC = gcc
CFLAGS = -W -Wall -g
OBJETS = my_stat.o ls1.o ls2.o ls_rec.o chercher_chaine.o

all: my_stat ls1 ls2 ls_rec chercher_chaine

my_stat ls1 ls2 ls_rec chercher_chaine: % : %.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f my_stat ls1 ls2 ls_rec chercher_chaine $(OBJETS)
	@echo "Clean done."
