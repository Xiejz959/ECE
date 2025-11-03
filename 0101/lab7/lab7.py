import math
R=1000 # ohm
C=0.00000001 # farad
f=[10000,12500,16670,25000,50000] # hertz
T=[1/(f[i]) for i in range(len(f))] # seconds
V_H=5 # volts
V_L=-5 # volts
e=math.exp(1)
def Vc_1(T):
    return (V_L*(1-e**(-T/(2*R*C))))/(1-e**(-T/(R*C))) + V_H*(e**(-T/(2*R*C)) - e**(-T/(R*C)))/(1-e**(-T/(R*C)))
def Vc_2(T):
    return V_H*(1-e**(-T/(2*R*C)))/(1-e**(-T/(R*C))) + V_L*(e**(-T/(2*R*C)) - e**(-T/(R*C)))/(1-e**(-T/(R*C)))
ans_1=[Vc_1(T[i]) for i in range(len(T))]
ans_2=[Vc_2(T[i]) for i in range(len(T))]

print("===================================================")
print("   f(Hz)  |   T(s)     |    Vc_1(V)  |    Vc_2(V)")
for i in range(len(f)):
    print(f"{f[i]:8d}  | {T[i]:10.8f} | {ans_1[i]:10.8f} | {ans_2[i]:10.8f}")
print("===================================================")