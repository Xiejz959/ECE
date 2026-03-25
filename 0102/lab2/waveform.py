import numpy as np
import matplotlib.pyplot as plt

# 参数设置
Vpp = 14            # 14 Vpp
A = Vpp / 2         # 振幅 ±7V
f = 1000            # 1 kHz
t = np.linspace(0, 2e-3, 1000)  # 2ms 时间轴（两周期）

# 输入信号
Vin = A * np.sin(2 * np.pi * f * t)

# 二极管限幅（3.7V）
V_clamp = 3.7
Vout = np.minimum(Vin, V_clamp)

# 画图
plt.figure()
plt.plot(t * 1000, Vin, label='Vin (input)')
plt.plot(t * 1000, Vout, label='Vout (clipped)')
plt.xlabel('Time (ms)')
plt.ylabel('Voltage (V)')
plt.title('Time-Domain Waveform (Diode Clipping at 3.7V)')
plt.legend()
plt.grid()

plt.show()