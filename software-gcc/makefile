#
# Copyright (c) 2018 Arm Limited. All rights reserved.
#

TARGET_APP=hello.axf
TARGET_DIS=hello.dis

CC=arm-none-eabi-gcc
FE=arm-none-eabi-objdump
LD=arm-none-eabi-ld

CFLAGS   = -mcpu=cortex-m7 -mthumb -O2 -g -mfpu=fpv5-d16 -mfloat-abi=hard

LDFLAGS  = -mcpu=cortex-m7 -mthumb -specs=rdimon.specs -mfpu=fpv5-d16 -mfloat-abi=hard
DEFINES  = 
LINKFILE = gcc.ld

# Select build rules based on Windows or Unix
ifdef windir
RM=if exist $(1) del /q $(1)
SHELL=$(windir)\system32\cmd.exe
else
RM=rm -f $(1)
endif


all: $(TARGET_APP) $(TARGET_DIS)

clean:
	$(call RM,*.o)
	$(call RM,$(TARGET_DIS))
	$(call RM,$(TARGET_APP))

main.o: main.c
	$(CC) -c $(CFLAGS) $(DEFINES) $< 

startup.o: startup.c
	$(CC) -c $(CFLAGS) $(DEFINES) $<

OBJ_FILES =  main.o startup.o

$(TARGET_APP): $(OBJ_FILES) $(LINKFILE)
	$(CC) -T $(LINKFILE) $(OBJ_FILES) $(LDFLAGS) -o $@
    
$(TARGET_DIS): $(TARGET_APP)
	$(FE) -D $(TARGET_APP) > $(TARGET_DIS)
    
