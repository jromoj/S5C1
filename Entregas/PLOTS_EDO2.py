import numpy as np
import matplotlib.pylab as plt

D = np.genfromtxt("datos.txt")

x = D[:,0]
y = D[:,1]
eu = D[:,2]
rk = D[:,3]
lf = D[:,4]

fig=plt.figure(figsize=(10, 10))
plt.ylim([-0.15, 0.15])

ax1 = fig.add_subplot(3, 1, 1)
ax1.plot(x,y)
ax1.plot(x,eu)

ax2 = fig.add_subplot(3, 1, 2)
ax2.plot(x,y)
ax2.plot(x,rk)


ax3 = fig.add_subplot(3, 1, 3)
ax3.plot(x,y)
ax3.plot(x,lf)

plt.savefig("graficas.png")
#plt.close(fig)
