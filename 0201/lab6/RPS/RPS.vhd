LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY RPS IS
	PORT
	(
		A  : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
		B  : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
		WA : OUT STD_LOGIC;
		WB : OUT STD_LOGIC;
		E  : OUT STD_LOGIC
	);
END RPS;

ARCHITECTURE comb OF RPS IS
BEGIN

	--error,input is 11
	E <= (A(1) AND A(0)) OR (B(1) AND B(0));
	
	--A win
	WA <= ((A(1) AND A(0)) OR (B(1) AND B(0))) AND
			( 
				( (NOT A(1) AND NOT A(0)) AND (B(1) AND NOT B(0) ) ) OR
			   ( (NOT A(1) AND A(0))     AND (NOT B(1) AND NOT B(0) ) ) OR
			   ( (A(1) AND NOT A(0))     AND (NOT B(1) AND B(0) ) ) OR
			  
			   ((A(1) XNOR B(1)) AND (A(0) XNOR B(0))) 
			);
	
	--B win
	WB <= ((A(1) AND A(0)) OR (B(1) AND B(0))) AND
			( 
				( (NOT B(1) AND NOT B(0)) AND (A(1) AND NOT A(0) ) ) OR
			   ( (NOT B(1) AND B(0))     AND (NOT A(1) AND NOT A(0) ) ) OR
			   ( (B(1) AND NOT B(0))     AND (NOT A(1) AND A(0) ) ) OR
			  
			   ((A(1) XNOR B(1)) AND (A(0) XNOR B(0)))
			);
			
END comb;