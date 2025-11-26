LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY halfadder is
	port
	(
		a : IN STD_LOGIC;
		b : IN STD_LOGIC;
		c : OUT STD_LOGIC;
		s : OUT STD_LOGIC
	);
END ENTITY;

ARCHITECTURE rtl OF halfadder IS
BEGIN
	s <= a XOR b;
	c <= a AND b;
END rtl;
