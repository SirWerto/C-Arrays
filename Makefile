CC=gcc

all: bin/Proof


.PHONY: create_dir move_f
create_dir:
	mkdir -p bin
	mkdir -p obj
	mkdir -p src

move_f:
	mv -v *.c src
	mv -v *.h src
	mv -v *.o obj

obj/%.o: src/%.c src/%.h
	@echo Generando objeto $<...
	$(CC) $(CFLAGS) -c -o $@ $<

bin/Proof: create_dir obj/Array.o obj/Proof.o 
	$(CC) -o bin/Proof obj/Proof.o obj/Array.o
