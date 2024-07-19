savedcmd_/home/iloveos/os_hw/3/My_Kernel.mod := printf '%s\n'   My_Kernel.o | awk '!x[$$0]++ { print("/home/iloveos/os_hw/3/"$$0) }' > /home/iloveos/os_hw/3/My_Kernel.mod
