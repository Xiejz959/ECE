quit -sim

cd D:/FPGA/Lab8/lab8_part4

vlib work
vmap work work

vcom Full_Adder.vhd
vcom ripple_full_adder.vhd

vsim work.ripple_full_adder

view wave
radix binary

add wave Cin
add wave C
add wave Cout

force A 11111111
force B 00000000
force Cin 0
run 200 ns

force Cin 1
run 200 ns

