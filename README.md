# 4 Week Internship by VLSI System Design by Kunal Ghosh
## Focus: Hardware synthesis on the FPGA (VSDSquadron) 

<details>
</summary>About VSDSquadron</summary>
  
</details>

**Task 1**                                              <!-- add these commands only not explanation in the task folders -->
Download leafpad for writing up the c code.
```
sudo apt update
sudo snap install leafpad 
```


commands to run for running the c program:

```
gcc <name of you c file.c>
.a/out
```
commands used to run the c program in the riscv

First create a folder of the c file with .o extension

`riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum_1_to_n.o sum_1_to_n.c`

<!--lp = longpointer -->

After that the converted C code to the assembly language is readed by the following command:
`riscv64-unknown-elf-objdump -d sum_1_to_n.o`    <!-- d is disassemble
In the assemble code search for main
Certain calculations reveals Byte addressing and for int type it is 4 bytes so, it is increamented accordingly. Moreover, The total instructions were 11 and next instruction is correct is verified for the c program.
Below instruction is more convenient and by typing `/main` we can scroll easily and find the required main program.
`riscv64-unknown-elf-objdump -d sum_1_to_n.o | less `



