import numpy as np
import matplotlib.pyplot as plt


Datos1D=np.genfromtxt('datos1D.txt')
Iniciales=np.genfromtxt('cond_ini_cuerda.dat')
Datos1Dabierto=np.genfromtxt('datos1Dabierto.txt')

X=Iniciales[:,0]
Y=Iniciales[:,1]
plt.figure()
FILA1=Datos1D[0,:]
FILA2=Datos1D[1,:]
FILA3=Datos1D[2,:]
FILA4=Datos1D[3,:]


plt.plot(X,FILA1)
plt.plot(X,FILA2)
plt.plot(X,FILA3)
plt.plot(X,FILA4)
plt.title("Datos 1D")
plt.xlabel("Posicion")
plt.ylabel("Amplitud")
plt.legend(('t=0','t=T/8','t=T/4','t=T/8'), loc = 'upper right')

plt.savefig("Extremos Fijos 1D.pdf")

plt.figure()
plt.figure()
FILA1A=Datos1Dabierto[0,:]
FILA2A=Datos1Dabierto[1,:]
FILA3A=Datos1Dabierto[2,:]
FILA4A=Datos1Dabierto[3,:]


plt.plot(X,FILA1A)
plt.plot(X,FILA2A)
plt.plot(X,FILA3A)
plt.plot(X,FILA4A)
plt.title("Datos 1D SENO")
plt.xlabel("Posicion")
plt.ylabel("Amplitud")
plt.legend(('t=0','t=T/8','t=T/4','t=T/8'), loc = 'upper right')


plt.savefig("Extremos Fijos 1D Sin.pdf")


