include ../Makefile.inc

GEN_EXE = copy \
		  seek_io \
		  bad_exclusive_open \
		  t_readv \
		  t_truncate \
		  large_file \
		  multi_descriptors

LINUX_EXE = copy

EXE = ${GEN_EXE} ${LINUX_EXE}

all : ${EXE}

allgen : ${GEN_EXE}

clean : 
	${RM} ${EXE} *.o

showall :
	@ echo ${EXE}
	@ echo ${TLPI_LIB}

${EXE} : ${TLPI_LIB}		# True as a rough approximation
