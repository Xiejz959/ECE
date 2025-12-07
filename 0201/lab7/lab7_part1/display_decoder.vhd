LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY display_decoder IS
PORT
(
	x: IN STD_LOGIC_VECTOR(3 DOWNTO 0);
	y: OUT STD_LOGIC_VECTOR(7 DOWNTO 0)
);
END display_decoder;

ARCHITECTURE comb OF display_decoder IS
BEGIN
	--HEX00
	y(0) <= (x(3) AND x(2)) OR (x(3) AND x(1)) OR ((NOT x(3)) AND (NOT x(2)) AND (NOT x(1)) AND x(0)) OR (x(2) AND (NOT x(1)) AND (NOT x(0)));
	--HEX01
	y(1) <= (x(3) AND x(2)) OR (x(3) AND x(1)) OR (x(2) AND (x(1) XOR x(0)));
	--HEX02
	y(2) <= (x(3) AND x(2)) OR (x(3) AND x(1)) OR ((NOT x(2)) AND x(1) AND (NOT x(0)));
	--HEX03
	y(3) <= (x(3) AND x(2)) OR (x(3) AND x(1)) OR ((NOT x(3)) AND (NOT x(2)) AND (NOT x(1)) AND x(0)) OR (x(2) AND (NOT (X(1) XOR x(0))));
	--HEX04
	y(4) <= x(0)  OR  (x(2) AND (NOT x(1)) AND (NOT x(0))) OR (X(3) AND x(1) AND (NOT x(0)));
	--HEX05
	y(5) <= (x(3) AND x(2)) OR (x(3) AND x(1)) OR (x(1) AND x(0)) OR ((NOT x(3)) AND (NOT x(2)) AND (x(1) OR x(0)));
	--HEX06
	y(6) <= (x(3) AND x(2)) OR (x(3) AND x(1)) OR (x(2) AND x(1) AND x(0)) OR ((NOT x(3)) AND (NOT x(2)) AND (NOT x(1)));
	--HEX07
	y(7) <= '1';
END comb;
