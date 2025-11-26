vsim work.rps

# ??????
add wave *

# ???
force A 00
force B 00
run 10ns

force A 00
force B 01
run 10ns

force A 00
force B 10
run 10ns

force A 00
force B 11
run 10ns

force A 01
force B 00
run 10ns

force A 01
force B 01
run 10ns

force A 01
force B 10
run 10ns

force A 01
force B 11
run 10ns

force A 10
force B 00
run 10ns

force A 10
force B 01
run 10ns

force A 10
force B 10
run 10ns

force A 10
force B 11
run 10ns

force A 11
force B 00
run 10ns

force A 11
force B 01
run 10ns

force A 11
force B 10
run 10ns

force A 11
force B 11
run 10ns

run 10ns
