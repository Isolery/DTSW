include ../Makefile.inc

GEN_EXE = necho \
		  display_env \
		  modify_env 

LINUX_EXE = necho

EXE = ${GEN_EXE} ${LINUX_EXE}

all : ${EXE}

allgen : ${GEN_EXE}

clean : 
	${RM} ${EXE} *.o

showall :
	@ echo ${EXE}
	@ echo ${TLPI_LIB}

${EXE} : ${TLPI_LIB}		# True as a rough approximation
