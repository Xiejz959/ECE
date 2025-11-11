import numpy as np
import matplotlib.pyplot as plt



t = np.linspace(0, 0.0002, 2000)  # 0~0.2 ms，2000个点


vC = 5 * (1 - np.exp(-32500 * t) * (np.cos(314600 * t) + 0.1033 * np.sin(314600 * t)))


plt.figure(figsize=(8, 4))
plt.plot(t * 1e6, vC, label=r'$v_C(t)$', linewidth=2)
plt.xlabel('Time (μs)')
plt.ylabel('Voltage (V)')
plt.title('RLC Step Response: $v_C(t)$')
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()
plt.tight_layout()
plt.show()
