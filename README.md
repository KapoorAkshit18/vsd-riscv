# 4 Week Internship by VLSI System Design by Kunal Ghosh
## Focus: Hardware synthesis on the Dev Board (VSDSquadron-mini) 

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
type until pc 0 10184   

not necessary 10184 it depends upon where does your main instruction starts.

**Task 3**  
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

**Task 4**
    
## Functional SImulation of RISC-V Core using iverilog and gtkwave.

<details> The ubuntu .ini file have iverilog and gtkwave preinstalled, so, only few commands and waveform analysis part remains, which is completed in this task and can be verified from the task 4 repository. It is an implementation of the Task 3, which was to know about the RISC-V instructions and understand its instruction encoding. The verilog code provided have implemented basic blocks of the cpu like fetch, decode, execute (exe), etc. The testbench file have only have 1 test case which is of initializing the rn and clock signal and making rn zero again. Furthermore, the credit for this verilog code goes to https://github.com/vinayrayapati/rv32i. The commands of it can also be found out in the task4 readme file.
</details>
Commands for running the verilog compiler and simulator:

`iverilog -o your executable file name your verilog file/files name.v `
eg: iverilog -o rv32i_tb_exe2 rv32i.v  rv32i_tb.v  
<details> Multiple files are seperated by space here. Most likely error message will pop up or nothing will happen. We expect second case here. After this we need to open the executable file that icarus have made. </details> 
`vvp your executable file name`
eg: vvp rv32i_tb_exe2  
below output if came we can move to the next command.
  
`VCD info: dumpfile rv32i_tb.vcd opened for output.`  
Command for running gtk wave for running the vcd file, made through tb file by the icarus is:  

` gtkwave rv32i_tb.vcd` 


<details> The waveform (attached the png file in the repository) verifies functionality of the riscv core, as npc denotes program counter increament per clock cycle and, from the add instruction encoding and simulation the result is 3 can be seen. </details>   

# Task 5: A brief about what previous task  

<details> from the task 4, if see the Verilog code used in it, it is having hardcoded instructions, which is not equivalent to the standard ISA encoding for RISCV. For example: for the add instruction `add r1, r2, r3 ` riscv encoding is 0x3100b3 where as in our simulation waveform we have got 0x 02208300 that make our design check failed for the System on Chip Design flow (not inside our course scope). To make the circuit diagram ckt designer is utilized. </details>.    

# Mini Project Smart Motion Detector with Servo Motor using Squadron Board Mini

This project demonstrates how to connect a PIR motion sensor and a servo motor to the **Squadron Board Mini** to create a motion-based automated mechanism.

## Components Used
- Squadron Board Mini
- PIR Motion Sensor
- Servo Motor
- Breadboard and Jumper Wires
- External Power Supply (optional for servo motor)

## Circuit Connections

| Component        | Pin/Connection on Squadron Mini | Connected To | Notes |
|-----------------|---------------------------------|--------------|------|
| PIR Sensor VCC   | 3.3V or 5V                      | VCC          | Power supply to PIR sensor |
| PIR Sensor GND   | GND                             | GND          | Ground connection |
| PIR Sensor OUT   | GPIO Pin (e.g., D3)             | Signal Input | Detects motion, digital output |
| Servo Motor VCC  | 5V                              | Power supply | Squadron board mini's  |
| Servo Motor GND  | GND                             | Ground      | Common ground with board and sensor |
| Servo Motor PWM  | GPIO Pin (e.g., D2)             | Control Signal | PWM control for servo position |

## Notes
- Ensure that all grounds (GND) are connected together to avoid signal reference issues.
- If the servo motor requires more current than the board can supply, use an external power source and ensure common grounding.
- Verify the logic level compatibility of the PIR sensor output and the Squadron Mini’s GPIO input.
- Adjust GPIO pins (`D2`, `D3`) as per availability and application needs.

## How it Works
1. The PIR sensor detects motion and sends a HIGH signal through its output pin.
2. The Squadron Mini reads the signal and triggers the servo motor using PWM to perform a desired action, like opening a door or turning towards the motion.

## Future Improvements
- Add debounce logic to avoid false triggers.
- Implement wireless notifications or logging.
- Integrate with IoT platforms for remote monitoring.



   
