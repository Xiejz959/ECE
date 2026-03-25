import numpy as np
import matplotlib.pyplot as plt

# 输入范围（横轴 Vin）
Vin = np.linspace(-8, 8, 1000)

# 限幅电压
V_clamp = 3.7

# 输出关系
Vout = np.minimum(Vin, V_clamp)

# 画图
plt.figure()
plt.plot(Vin, Vout, label='Transfer Characteristic')

# 辅助线（可选但推荐）
plt.axhline(V_clamp, linestyle='--', color='red', label='Clipping Level')
plt.axvline(V_clamp, linestyle='--', color='red', alpha=0.7)
plt.scatter([V_clamp], [V_clamp], color='black', zorder=5, label='Knee Point')
plt.annotate('(3.7, 3.7)', xy=(V_clamp, V_clamp), xytext=(10, -14),
		 textcoords='offset points', ha='left', va='top')

plt.xlabel('Vin (V)')
plt.ylabel('Vout (V)')
plt.title('Transfer Characteristic of Diode Clipper')
plt.legend(loc='lower right')
plt.grid()

plt.show()