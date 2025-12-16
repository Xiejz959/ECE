library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
 
entity Full_Adder is
	Port (	 x         : in STD_LOGIC;
				 y         : in STD_LOGIC;
				 carry_in  : in STD_LOGIC;
				 sum	     : out STD_LOGIC;
				 carry_out : out STD_LOGIC
		  );
	end Full_Adder;
 
architecture struct of Full_Adder is
 

 signal w0,w1,w2,w3,w4,w5,w6: STD_LOGIC; 
 
begin
	
	
	-- 2ns 
	w0 <= x AND y after 2 ns;
	w1 <= x AND carry_in after 2 ns;
	w2 <= y AND carry_in after 2 ns;
	
	-- 4ns 
	w3 <= x XOR y after 4 ns;
	w4 <= w3 XOR carry_in after 4 ns; -- w3 
	
	-- 2ns 
	w5 <= w0 OR w1 after 2 ns;       -- w0  w1 
	w6 <= w1 OR w2 after 2 ns;       -- w1  w2 
	
	sum <= w4;
	carry_out <= w5 OR w6;
		
		
end struct;