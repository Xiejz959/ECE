import numpy as np
import matplotlib.pyplot as plt

# 参数设置
Vpp = 10
Vm = Vpp / 2          # 峰值 5V
f = 10000            # 10 kHz
Vd = 0.7             # 二极管压降

# 时间轴（取2个周期）
t = np.linspace(0, 2/f, 1000)
t_ms = t * 1e3  # 转换为毫秒用于绘图

# 输入信号
vin = Vm * np.sin(2 * np.pi * f * t)

# 固定压降法输出（半波整流）
vout = np.where(vin > Vd, vin - Vd, 0)

# 画图
plt.figure()
plt.plot(t_ms, vin, label='Vin (Input)', linestyle='--')
plt.plot(t_ms, vout, label='Vout (Fixed Drop)', linewidth=2)

plt.title('Fixed Drop Method Time-Domain Waveform')
plt.xlabel('Time (ms)')
plt.ylabel('Voltage (V)')
plt.legend()
plt.grid()

plt.show()