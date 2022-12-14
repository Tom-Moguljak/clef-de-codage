### VARIABLES ###
CC = gcc
CFLAGS = -Wall -ansi
OFILES = afaire.o
EXE = vernam

## BUT PAR DEFAUT ###
 
but : ${EXE}
 
### REGLES ESSENTIELLES ###
 
${EXE} : ${OFILES}
	$(CC) $(CFLAGS) -o ${EXE} ${OFILES}

### REGLES OPTIONNELLES ###
 
clean :
	-rm -f ${OFILES}

mrproper : clean but
 
### BUTS FACTICES ###
 
.PHONY : but clean mrproper
 
### FIN ###