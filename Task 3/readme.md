**Task 3**  
To run the same command used earlier with a small modification. 

`riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum_1_to_n_ofast.o sum_1_to_n.c`  
now, after that we will run the objdump command used earlier piped with less in the new tab

`riscv64-unknown-elf-objdump -d sum_1_to_n.o | less ` (one which was compiled with fast optimization) It is recommended to change the object file name for each optimization, initially for understanding purposes
Following that we will run the below command:  
`spike pk sum_1_to_n.o`
