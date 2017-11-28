from scipy.io.wavfile import write
import numpy as np
import matplotlib.pyplot as plt

VEL =np.zeros(300)

DATOS=np.genfromtxt('RadialVelocities.dat')
#RESULTADOS= np.genfromtxt('Resultados.txt')

#Mb=RESULTADOS[]
#Md=RESULTADOS[]
#Mh=RESULTADOS[]



RADIO=DATOS[:,0]
VELOCIDAD=DATOS[:,1]
plt.figure()

#def ajuste(MB,MD,MH,R):
	#Bb=0.2497
	#Bd=5.16
	#Ad=0.3105
	#Ah=64.3
	#V= ((MB**0.5)*(R)/(R**2+Bb**2)**0.75) + ((MD**0.5)*(R)/ (R**2+(Bd+Ad)**2)**0.75) + ((MH**0.5)*(R)/(R**2+Ah**2)**0.25)
	#return V

#for i in range (300):
#	VEL[i]=ajuste(Mb,Md,Mh,RADIO[i])



plt.scatter(RADIO,VELOCIDAD)
#plt.plot(RADIO,VEL)
plt.title("DATOS Y AJUSTE")
plt.xlabel("RADIO")
plt.ylabel("VELOCIDAD")
plt.legend(('DATOS'), loc = 'upper right')

plt.savefig("AJUSTEMODELO.pdf")


