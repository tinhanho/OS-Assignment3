TARGET_MODULE := My_Kernel

obj-m := $(TARGET_MODULE).o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
CC := gcc

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	@rm -f *.o *.ko *.mod.* *.symvers *.order *.mod.cmd *.mod

Prog_1thread:
	@rm -f 2.txt
	@echo "#define THREAD_NUMBER 1" > 3_2_Config.h
	@$(CC) -o 2.out 2_2.c
	@sudo ./2.out

Prog_2thread:
	@rm -f 2.txt
	@echo "#define THREAD_NUMBER 2" > 3_2_Config.h
	@$(CC) -o 2.out 2_2.c
	@sudo ./2.out

load:
	@sudo insmod $(TARGET_MODULE).ko

unload:
	@sudo rmmod $(TARGET_MODULE).ko
