TARGET_MODULE := My_Kernel

obj-m := $(TARGET_MODULE).o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
CC := gcc

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	@rm -f *.o *.ko *.mod.* *.symvers *.order *.mod.cmd *.mod

Prog:
	@$(CC) -o 2.out 2_2.c
	@sudo ./2.out
	@rm -f 2.txt 2.out

load:
	@sudo insmod $(TARGET_MODULE).ko

unload:
	@sudo rmmod $(TARGET_MODULE).ko
