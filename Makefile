ASM = asm_func

#---------Program consists of 6 files:-------------------------------------------
#---------"asm_functions" - math functions written on nasm-----------------------
#---------"root" - calculating point of intersection of two functions------------
#---------"integral" - calculating Riemann integral------------------------------
#---------"main" - calculates sqr of curved triangle and gives UI----------------
#---------"testr" - allows testing "root" function-------------------------------
#---------"testi" - allows testing "integral" function---------------------------

SRC = asm_func.o testr.o testi.o integral.o root.o main.o

#---------Flag for c-functions -m32 to build them in x86-32----------------------

CFLAGS = -m32 -c -o

#---------Format for assembly elf32(UNIX x86-32)---------------------------------

ASMFLAGS = -f elf32 -o

#---------Variable "R" determine the method  for "root" function:----------------
#---------Type "make R=0" to use tangent method----------------------------------
#---------Type "make R=1" to use the chord method(default)-----------------------

R = 1

.PHONY: all clean
all: program
clean:
#---------Type "make clean" to remove all object files---------------------------
	rm -rf *.o
program: $(SRC)
	gcc -m32 -o $@ $(SRC) -lm
integral.o: integral.c
	gcc $(CFLAGS) integral.o integral.c
main.o: main.c trsqr.h
	gcc $(CFLAGS) main.o main.c
testr.o: testr.c trsqr.h	
	gcc $(CFLAGS) testr.o testr.c
testi.o: testi.c trsqr.h
	gcc $(CFLAGS) testi.o testi.c
root.o: root.c
	gcc $(CFLAGS) root.o root.c -D 'RT=$(R)'
asm_func.o: asm_func.asm trsqr.h
	nasm $(ASMFLAGS) $(ASM).o $(ASM).asm
