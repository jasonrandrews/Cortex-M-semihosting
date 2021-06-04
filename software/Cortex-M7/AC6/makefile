#
# Copyright (c) 2018 Arm Limited. All rights reserved.
#

TARGET_APP=hello.axf
TARGET_DIS=hello.dis

AR=armar
AS=armasm
CC=armclang
FE=fromelf
LD=armlink


CFLAGS   = -march=armv6-m --target=arm-arm-none-eabi -mthumb -O2 -g
LDFLAGS  = 
DEFINES  = 
LINKFILE = scatter.scat


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
	$(LD) --scatter=$(LINKFILE) $(OBJ_FILES) $(LDFLAGS) -o $@
    
$(TARGET_DIS): $(TARGET_APP)
	$(FE) -c $(TARGET_APP) > $(TARGET_DIS)
    
