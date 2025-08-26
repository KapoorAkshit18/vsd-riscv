# 4 Week Internship by VLSI System Design by Kunal Ghosh
## Focus: Hardware synthesis on the FPGA (VSDSquadron) 

<details>
<summary>About VSDSquadron</summary>













Oracle Virtual Machine platform is used for running the ubuntu linux vmi as provided. It is an user friendly desktop app used for virualization.
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
here the *gcc* command (GNU C Compiler) is used to compile the c code in linux
commands used to run the c program in the riscv  

**Task 2**
First create a folder of the c file with .o extension

`riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum_1_to_n.o sum_1_to_n.c`

<!--lp = longpointer -->

After that the converted C code to the assembly language is readed by the following command:  

`riscv64-unknown-elf-objdump -d sum_1_to_n.o`    <!-- d is disassemble -->  

`riscv64-unknown-elf-objdump -d sum_1_to_n.o | less `  
<details>In the assemble code search for main
Certain calculations reveals Byte addressing and for int type it is 4 bytes so, it is increamented accordingly. Moreover, The total instructions were 11 and next instruction is correct is verified for the c program.
Piped with less command is more convenient and by typing `/main` we can scroll easily and find the required main program. Use CTRL+Z to come out of the object code.
</details>


**Task 3**  
To run the same command used earlier with a small modification.  

`riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum_1_to_n.o sum_1_to_n.c`  

<details>Following this command 4 steps internally occurs i.e preprocess--->compile--->assemble--->link Elf here is Executable Linkable Form, mabi is Machine Applicable Binary Interface, march is Machine Architecture.</details>



