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

force A 00000001
force B 00000000
force Cin 0
run 100 ns

force Cin 1
run 20 ns

