library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity mux4to1 is
    Port (
        
        S    : in  STD_LOGIC_VECTOR (1 downto 0);
        
        
        D0   : in  STD_LOGIC_VECTOR (3 downto 0);
        D1   : in  STD_LOGIC_VECTOR (3 downto 0);
        D2   : in  STD_LOGIC_VECTOR (3 downto 0);
        D3   : in  STD_LOGIC_VECTOR (3 downto 0);
        
        
        Y    : out STD_LOGIC_VECTOR (3 downto 0)
    );
end mux4to1;

architecture behavioral of mux4to1 is
begin

    MUX_PROCESS : process (S, D0, D1, D2, D3)
    begin
        
        
        case S is
            when "00" =>
                -- D0
                Y <= D0;
                
            when "01" =>
                -- D1
                Y <= D1;
                
            when "10" =>
                -- D2
                Y <= D2;
                
            when "11" =>
                -- D3
                Y <= D3;
                
            
            when others =>
                
                Y <= (others => 'X'); 
                
        end case;
        
    end process MUX_PROCESS;

end behavioral;