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


