module rv32i_tb;

reg clk;
reg rn;
wire [31:0]WB_OUT;
wire [31:0]npc;

rv32i dut (
	.clk(clk),
	.rn(rn),
	.npc(npc),
	.WB_OUT(WB_OUT)

	);


always #3  clk=!clk;

initial begin 

rn  = 1'b1;
clk = 1'b1;

$dumpfile ("rv32i_tb.vcd"); //by default vcd
$dumpvars (0, dut);
  
  #5 rn = 1'b0;
  
  #300 $finish;

end
endmodule
