IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=../bin/obj
LDIR =../lib

LIBS=-lm

_DEPS = Pilha.hpp PilhaEncadeada.hpp PilhaVetor.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = TestaPilha.o PilhaEncadeada.o PilhaVetor.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

TestaPilha: $(OBJ)
	$(CC) -o ../bin/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
