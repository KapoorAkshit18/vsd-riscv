# 4 Week Internship by VLSI System Design by Kunal Ghosh
## Focus: Hardware synthesis on the FPGA (VSDSquadron) 

<details>
<summary>About VSDSquadron and platform used throuout the internship.Few abbreviations <asm> means assembly.  
</summary>


Feel free to explore the Tasks folders where you will find the necessary codes along with its png file.










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
./a.out
```
here the *gcc* command (GNU C Compiler) is used to compile the c code in linux
commands used to run the c program in the riscv  

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
Piped with less command is more convenient and by typing `/main` we can scroll easily and find the required main program. Use CTRL+Z to come out of the object code.
</details>


**Task 2 continues**  
To run the same command used earlier with a small modification. 

`riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum_1_to_n_ofast.o sum_1_to_n.c`  
now, after that we will run the objdump command used earlier piped with less in the new tab

`riscv64-unknown-elf-objdump -d sum_1_to_n.o | less ` (one which was compiled with fast optimization) It is recommended to change the object file name for each optimization, initially for understanding purposes
Following that we will run the below command:  
`spike pk sum_1_to_n.o`

<details> </details>
After that we will use the below command when we need to do the debugging.  

`spike -d pk sum_1_to_n.o`   

**Task 3**  
To study about the RISCV asm instructions with a focus on our program's asm.

15 uniques instructions were:

<!-- addi sp,sp,-16    
adds content of sp wit negative 16 and stores the result in sp.  
32 bit instruction code:  

sd ra,8(sp)    

li a5,150    

addiw a5,a5,-1  

bnez a5,10190    

lui a2,0x3    

addi a2,a2,-963  

li a1,150  

lui a0,0x21  

addi a0,a0,400  

jal ra,10418  

li a0,0  

ld ra,8(sp)  

 addi sp,sp,16    
 
 ret  -->
### RISC-V 32-bit Instruction Encodings

1. `addi sp, sp, -16`  
   → `0xff010113`

2. `sd ra, 8(sp)`  
   → `0x00813023`

3. `li a5, 150` (pseudo → `addi a5, x0, 150`)  
   → `0x09600793`

4. `addiw a5, a5, -1`  
   → `0xfff7879b`

5. `bnez a5, 10190` (pseudo → `bne a5, x0, target`)  
   → **PC-relative, needs current PC to compute**

6. `lui a2, 0x3`  
   → `0x00003137`

7. `addi a2, a2, -963`  
   → `0xc6d60613`

8. `li a1, 150` (pseudo → `addi a1, x0, 150`)  
   → `0x09600593`

9. `lui a0, 0x21`  
   → `0x00021537`

10. `addi a0, a0, 400`  
    → `0x19050513`

11. `jal ra, 10418`  
    → **PC-relative, needs current PC to compute**

12. `li a0, 0` (pseudo → `addi a0, x0, 0`)  
    → `0x00000513`

13. `ld ra, 8(sp)`  
    → `0x00813083`

14. `addi sp, sp, 16`  
    → `0x01010113`

15. `ret` (pseudo → `jalr x0, 0(ra)`)  
    → `0x00008067`

   
