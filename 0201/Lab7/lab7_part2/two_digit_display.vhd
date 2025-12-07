LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY two_digit_display IS
    PORT (
        Ain     : IN  STD_LOGIC_VECTOR(3 DOWNTO 0);  -- Input 1: SW3~SW0
        Bin     : IN  STD_LOGIC_VECTOR(3 DOWNTO 0);  -- Input 2: SW7~SW4
        Aout    : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);  -- Output 1: HEX0
        Bout    : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)   -- Output 2: HEX1
    );
END two_digit_display;

ARCHITECTURE structural OF two_digit_display IS
    COMPONENT hex_display_decoder
        PORT (
            X       : IN  STD_LOGIC_VECTOR(3 DOWNTO 0);
            Y       : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)
        );
    END COMPONENT;

BEGIN
    -- Instantiate decoder 0 
    DISP0 : hex_display_decoder
        PORT MAP (
            X => Ain,
            Y => Aout
        );

    -- Instantiate decoder 1
    DISP1 : hex_display_decoder
        PORT MAP (
            X => Bin,
            Y => Bout
        );

END structural;