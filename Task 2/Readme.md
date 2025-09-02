**Task 2**
First create a folder of the c file with .o extension

`riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum_1_to_n_o1.o sum_1_to_n.c`

<!--lp = longpointer -->  
<details>Following this command 4 steps internally occurs i.e preprocess--->compile--->assemble--->link Elf here is Executable Linkable Form, mabi is Machine Applicable Binary Interface, march is Machine Architecture.</details>

After that the converted C code to the assembly language is readed by the following command:  

`riscv64-unknown-elf-objdump -d sum_1_to_n.o`    <!-- d is disassemble -->  

`riscv64-unknown-elf-objdump -d sum_1_to_n.o | less `  
<details>In the assemble code search for main
Certain calculations reveals Byte addressing and for int type it is 4 bytes so, it is increamented accordingly.
Piped with less command is more convenient and by typing `/main` we can scroll easily and find the required main program. Use CTRL+Z to come out of the object code.Calculation of calc1 and calc2 shows action of o1 and ofast.

To run the same command used earlier with a small modification.  

`riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum_1_to_n_ofast.o sum_1_to_n.c`  

now, after that we will run the objdump command used earlier piped with less in the new tab

`riscv64-unknown-elf-objdump -d sum_1_to_n.o | less`  
  
(one which was compiled with fast optimization) It is recommended to change the object file name for each optimization, initially for understanding purposes Following that we will run the below command:  

`spike -d pk sum_1_to_n_ofast.o`  

then, we will specify the program counter value so, to run our program's instruction one by one. Write below command for checking contents of the register:  

`reg <x0> <alias>` eg: reg 0 a1

  
Few RISCV Instructions focused in this task was: lui and aui. Both are of 32 bits and internally works by shifting the bits to the left and storing it to the destination register. eg:  lui a1,0x8000 this will make a1 lower 12 bit to be zero or garbage value and upper 20 bits to be 0x80000 in hexadecimal. Simillarly, addi but with addition to the existing value.
eg:
addi sp, sp, -16
</details>
