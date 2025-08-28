**Task 3**  
To run the same command used earlier with a small modification. 

`riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum_1_to_n_ofast.o sum_1_to_n.c`  
now, after that we will run the objdump command used earlier piped with less in the new tab

`riscv64-unknown-elf-objdump -d sum_1_to_n.o | less ` (one which was compiled with fast optimization) It is recommended to change the object file name for each optimization, initially for understanding purposes
Following that we will run the below command:  
`spike -d pk sum_1_to_n_ofast.o`
then, we will specify the program counter value so, to run our program's instruction one by one.
Write below command for checking contents of the register:  
`reg <x0> <alias>`
eg: reg 0 a1 

Few RISCV Instructions focused in this task was:
lui and aui.
Both are of 32 bits and internally works by shifting the bits to the left and storing it to the destination register.
eg:
` lui a1,0x8000`
this will make a1 lower 12 bit to be zero or garbage value and upper 20 bits to be 0x80000 in hexadecimal. Simillarly, aui but 
