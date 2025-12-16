library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL; 

entity binary_adder is
    Port (
        A       : in  STD_LOGIC_VECTOR (7 downto 0);
        B       : in  STD_LOGIC_VECTOR (7 downto 0);
        C_in    : in  STD_LOGIC;
        S       : out STD_LOGIC_VECTOR (7 downto 0);
        C_out   : out STD_LOGIC
    );
end binary_adder;

architecture behavioral of binary_adder is

    -- 8bit + 1 bit may exist
    signal Result_9bit : UNSIGNED(8 downto 0); 

begin
    
    Result_9bit <= (  ('0' & UNSIGNED(A))            
                    + ('0' & UNSIGNED(B))            
                    + ('0' & '0' & '0' & '0' & '0' & '0' & '0' & '0' & C_in) 
                   );

    
    S     <= STD_LOGIC_VECTOR(Result_9bit(7 downto 0));   -- last 8 bits
    C_out <= Result_9bit(8);                               -- the highest bit

end behavioral;