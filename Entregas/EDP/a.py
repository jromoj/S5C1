import numpy as np
import matplotlib.pyplot as plt

D = np.genfromtxt("datos.txt")

x = D[:,0]
y1 = D[:,1]
y2 = D[:,2]
y3 = D[:,3]
y4 = D[:,4]
y5 = D[:,5]
y6 = D[:,6]


plt.figure(figsize=[9, 18])
plt.subplots_adjust(hspace=0.3)

plt.subplot(6, 1, 1)
plt.plot(x, y1)
plt.title('t1', fontsize=12)

plt.subplot(6, 1, 2)
plt.plot(x, y2)
plt.title('t1', fontsize=12)

plt.subplot(6, 1, 3)
plt.plot(x, y3)
plt.title('t3', fontsize=12)

plt.subplot(6, 1, 4)
plt.plot(x, y4)
plt.title('t4', fontsize=12)

plt.subplot(6, 1, 5)
plt.plot(x, y5)
plt.title('t5', fontsize=12)

plt.subplot(6, 1, 6)
plt.plot(x, y6)
plt.title('t6', fontsize=12)

plt.savefig("graficas.png")
