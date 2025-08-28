**Task 2**
First create a folder of the c file with .o extension

`riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum_1_to_n_o1.o sum_1_to_n.c`

<!--lp = longpointer -->  
<details>Following this command 4 steps internally occurs i.e preprocess--->compile--->assemble--->link Elf here is Executable Linkable Form, mabi is Machine Applicable Binary Interface, march is Machine Architecture.</details>

After that the converted C code to the assembly language is readed by the following command:  

`riscv64-unknown-elf-objdump -d sum_1_to_n.o`    <!-- d is disassemble -->  

`riscv64-unknown-elf-objdump -d sum_1_to_n.o | less `  
<details>In the assemble code search for main
Certain calculations reveals Byte addressing and for int type it is 4 bytes so, it is increamented accordingly. Moreover, The total instructions were 11 and next instruction is correct is verified for the c program.
Piped with less command is more convenient and by typing `/main` we can scroll easily and find the required main program. Use CTRL+Z to come out of the object code.
</details>
