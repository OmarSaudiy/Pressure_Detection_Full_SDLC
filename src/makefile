CC=arm-none-eabi-
CFLAGS=-mthumb -mcpu=cortex-m3 
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
Asm=$(wildcard *.s)
AsmOBJ=$(Asm:.s=.o)
Project_name=Pressure_Detection


all: $(Project_name).bin
	@echo "=====.bin GENERATED====="

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@


$(Project_name).elf: $(OBJ) $(AsmOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsmOBJ) -Map=mapfile.map -o $@

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy -O binary $< $@

clean_all:
	rm *.o *.elf *.bin
	@echo "=====All Deleted====="

clean:
	rm *.elf *.bin
	@echo "=====.elf & .bin are Deleted====="