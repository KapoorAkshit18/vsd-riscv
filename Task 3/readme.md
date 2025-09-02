**Task 3**  
<details> To run the same command used earlier with a small modification. 

`riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o sum_1_to_n_ofast.o sum_1_to_n.c`  
now, after that we will run the objdump command used earlier piped with less in the new tab

`riscv64-unknown-elf-objdump -d sum_1_to_n.o | less ` (one which was compiled with fast optimization) It is recommended to change the object file name for each optimization, initially for understanding purposes
</details>
Following that we will run the below command:  

`spike -d pk sum_1_to_n_ofast.o`

  
then, we will specify the program counter value so, to run our program's instruction one by one.    
`until pc 0 10184`

Write below command for checking contents of the register:  
`reg <x0> <alias>`
eg: reg 0 a1 

  
Few RISCV Instructions focused in this task was:
lui and aui.  

Both are of 32 bits and internally works by shifting the bits to the left and storing it to the destination register.  

eg:
` lui a1,0x8000`
this will make a1 lower 12 bit to be zero or garbage value and upper 20 bits to be 0x80000 in hexadecimal. Simillarly, addi but with addition to the existing value.
eg:  
`addi sp, sp, -16`

<img src="https://github.com/KapoorAkshit18/vsd-riscv/blob/main/Task%202%2Fo1.png" alt="Alt text" width="1000">

<img src="(https://github.com/KapoorAkshit18/vsd-riscv/blob/main/Task%203/spike.png)" alt="Alt text" width="1000">
  
To study about the RISCV asm instructions with a focus on our program's asm.
```
I-type: opcode[6:0] | rd[11:7] | funct3[14:12] | rs1[19:15] | imm[31:20]

S-type: opcode[6:0] | imm[11:7] | funct3[14:12] | rs1[19:15] | rs2[24:20] | imm[31:25]

B-type: branch offset split across fields

U-type: opcode[6:0] | rd[11:7] | imm[31:12]

J-type: jump target split across fields
```

Registers: x2 = sp, x1 = ra, x10 = a0, x11 = a1, x12 = a2, x15 = a5
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

   

