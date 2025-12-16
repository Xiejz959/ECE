library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

--8-bit ripple carry adder
entity lab8_part1 is
	port (	A    : IN  STD_LOGIC_VECTOR ( 7 DOWNTO 0);
				B    : IN  STD_LOGIC_VECTOR ( 7 DOWNTO 0);
				Cin  : IN  STD_LOGIC;
				S    : OUT STD_LOGIC_VECTOR ( 7 DOWNTO 0);
				Cout : OUT  STD_LOGIC
			);
end lab8_part1;

ARCHITECTURE calculation of lab8_part1 is

	-- declaration of full adder
	component Full_Adder
		port (      x 				: in STD_LOGIC;
						y 				: in STD_LOGIC;
						carry_in    : in STD_LOGIC;
						sum	 		: out STD_LOGIC;
						carry_out 	: out STD_LOGIC
				);
	end component;
	
	--carry end for every full adder
	signal C : STD_LOGIC_VECTOR ( 8 DOWNTO 0);

	begin
	
		C(0) <= Cin;
		
		G_RCA_BITS: for i in 0 to 7 generate
		
		FA_i : Full_Adder
		port map (
						x => A(i),
						y => B(i),
						carry_in => C(i),
						sum => S(i),
						carry_out => C(i+1)
					);
		
	end generate G_RCA_BITS;
	
	Cout <= C(8);
		
end calculation;
