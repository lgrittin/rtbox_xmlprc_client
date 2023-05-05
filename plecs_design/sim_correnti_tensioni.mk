CROSS            ?= "C:/Users/LGrittin/Documents/Plexim/PLECS 4.6 (64 bit)/PLECS_RT_Box/bin/win/arm-none-eabi/bin/arm-none-eabi-"
CFLAGS           := -Wall -O2 -c -fmessage-length=0 -DEXTERNAL_MODE=1 \
   -fgcse-after-reload \
   -finline-functions \
   -fipa-cp-clone \
   -floop-interchange \
   -floop-unroll-and-jam \
   -fpeel-loops \
   -fpredictive-commoning \
   -fsplit-paths \
   -ftree-loop-distribute-patterns \
   -ftree-loop-distribution \
   -ftree-loop-vectorize \
   -ftree-partial-pre \
   -ftree-slp-vectorize \
   -funswitch-loops \
   -fvect-cost-model \
   -fno-fast-math \
   -mtune=cortex-a9 -mcpu=cortex-a9 \
   -Wno-unused-variable \
   -funsafe-math-optimizations -fopt-info-vec --param max-completely-peeled-insns=1000 --param max-completely-peel-times=100
CC               = $(CROSS)gcc
STRIP            = $(CROSS)strip
INCLUDE          := -I"C:/Users/LGrittin/Documents/Plexim/PLECS 4.6 (64 bit)/PLECS_RT_Box/include/rtbox"
LIBS             := -L"C:/Users/LGrittin/Documents/Plexim/PLECS 4.6 (64 bit)/PLECS_RT_Box/lib/rtbox" -L"C:/Users/LGrittin/Documents/Plexim/PLECS 4.6 (64 bit)/PLECS_RT_Box/lib/rtbox/OpenAmp" \
                    -L"C:/Users/LGrittin/Documents/Plexim/PLECS 4.6 (64 bit)/PLECS_RT_Box/lib/rtbox/Xilinx" -lplexim_hil -lopen_amp -lbaremetal_remote \
                    -lm -Wl,--start-group,-lxil,-lgcc,-lc,--end-group
LFLAGS           := -Wl,-T -Wl,"C:/Users/LGrittin/Documents/Plexim/PLECS 4.6 (64 bit)/PLECS_RT_Box/build/rtbox.ld"

undefine GCC_EXEC_PREFIX

ifeq ($(OS),Windows_NT)
 SHELL            := cmd.exe
 RM               := DEL /F
 CP               := COPY /Y
else
 RM               := rm -f
 CP               := cp
endif

APP = sim_correnti_tensioni.elf

HEADERS += sim_correnti_tensioni.h
C_SRCFILES += sim_correnti_tensioni_main.c sim_correnti_tensioni.c sim_correnti_tensioni_0.c

OBJFILES := $(patsubst %.c, %.o, $(C_SRCFILES))
DEPFILES := $(patsubst %.c, %.d, $(C_SRCFILES))

all: $(APP)

$(APP): $(OBJFILES)
	@echo Linking $@
	@$(CC) -o $@ $(LFLAGS) $(OBJFILES) $(LIBS)
	@$(STRIP) $@

%.o:%.c $(HEADERS)
	@echo Compiling $(<:.c=.o)
	@$(CC) $(CFLAGS) $(ARCH_CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	-$(RM) $(LIB) $(OBJFILES)

FORCE:

PHONY: all clean
