import numpy as np
import matplotlib.pyplot as plt


Datos1D=np.genfromtxt('datos1D.txt')
Iniciales=np.genfromtxt('cond_ini_cuerda.dat')

X=Iniciales[:,0]
Y=Iniciales[:,1]

FILA1=Datos1D[0,:]
FILA2=Datos1D[1,:]
FILA3=Datos1D[2,:]
FILA4=Datos1D[3,:]
FILA5=Datos1D[4,:]

plt.plot(X,FILA1)
plt.plot(X,FILA2)
plt.plot(X,FILA3)
plt.plot(X,FILA4)
plt.plot(X,FILA5)
plt.savefig("Extremos Fijos 1D")



