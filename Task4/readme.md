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
