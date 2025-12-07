vlib work
vmap work work

vcom D:/FPGA/Lab7/lab7_part2/hex_display_decoder.vhd
vcom D:/FPGA/Lab7/lab7_part2/two_digit_display.vhd

vsim -voptargs=+acc work.two_digit_display
add wave *


proc to_bin4 {val} {
    set b0 [expr { ($val & 1) ? 1 : 0 }]
    set b1 [expr { ($val & 2) ? 1 : 0 }]
    set b2 [expr { ($val & 4) ? 1 : 0 }]
    set b3 [expr { ($val & 8) ? 1 : 0 }]
    return "$b3$b2$b1$b0"
}


for {set a 0} {$a < 16} {incr a} {

    for {set b 0} {$b < 16} {incr b} {

        set abin [to_bin4 $a]
        set bbin [to_bin4 $b]


        force Ain $abin
        force Bin $bbin

        run 100ns
    }
}

