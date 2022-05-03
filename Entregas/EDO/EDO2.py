import numpy as np
import matplotlib.pylab as plt

D = np.genfromtxt("datos.txt")

x = D[:,0]
y = D[:,1]
eu = D[:,2]
rk = D[:,3]
lf = D[:,4]
Ereal = D[:,5]
Eeu = D[:,6]
Erk = D[:,7]
Elf = D[:,8]
yfric = D[:,9]
eufric = D[:,10]
rkfric = D[:,11]
Ereu = (y-eu)
Errk = (y-rk)
Erlf = (y-lf)

plt.figure(figsize=[9, 33])
plt.subplots_adjust(hspace=0.3)

plt.subplot(11, 1, 1)
plt.plot(x, y)
plt.plot(x, eu)
plt.title('Euler', fontsize=12)

plt.subplot(11, 1, 2)
plt.plot(x, y)
plt.plot(x, rk)
plt.title('RK4', fontsize=12)

plt.subplot(11, 1, 3)
plt.plot(x, y)
plt.plot(x, lf)
plt.title('Leap Frog', fontsize=12)

plt.subplot(11, 1, 4)
plt.plot(x, Ereu)
plt.title('Error Euler', fontsize=12)

plt.subplot(11, 1, 5)
plt.plot(x, Errk)
plt.title('Error RK4', fontsize=12)

plt.subplot(11, 1, 6)
plt.plot(x, Erlf)
plt.title('Error Leap Frog', fontsize=12)

plt.subplot(11, 1, 7)
plt.plot(x, Ereal)
plt.plot(x, Eeu)
plt.title('Energía Euler', fontsize=12)

plt.subplot(11, 1, 8)
plt.plot(x, Ereal)
plt.plot(x, Erk)
plt.title('Energía RK4', fontsize=12)

plt.subplot(11, 1, 9)
plt.plot(x, Ereal)
plt.plot(x, Elf)
plt.title('Energía Leap Frog', fontsize=12)

plt.subplot(11, 1, 10)
plt.plot(x, yfric)
plt.plot(x, eufric)
plt.title('Euler Fricción', fontsize=12)

plt.subplot(11, 1, 11)
plt.plot(x, yfric)
plt.plot(x, rkfric)
plt.title('RK4 Fricción', fontsize=12)

plt.savefig("graficas.png")