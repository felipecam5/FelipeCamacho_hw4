#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){

static const int MAX_FILE_ROWS = 129;

float AmplitudCuerda[129];
float PosicionCuerda[129];
float NuevasAmplitudes[129];
float PasadasCondiciones[129];
float pi=3.1416;



double lines[MAX_FILE_ROWS][2];
FILE *file = fopen("cond_ini_cuerda.dat", "r");

for (int i = 0; i < MAX_FILE_ROWS; i++)
{
    if (feof(file))
        break;

    fscanf(file, "%lf %lf ", &(lines[i][0]), &(lines[i][1]));
   //printf("%f %f \n",(lines[i][0]), (lines[i][1]));
	AmplitudCuerda[i]=(lines[i][1]);
	PosicionCuerda[i]=(lines[i][0]);
	//printf("%f \n",AmplitudCuerda[i]);
	
}

fclose(file);

int i;
for(i=0;i<=129;i++)
{

NuevasAmplitudes[i]=0;
PasadasCondiciones[i]=0;
//printf("%f \n",NuevasAmplitudes[i]);
}
FILE* Archivo1 = fopen("datos1D.txt","w");
int C=250;	
int DeltaT=0.000010;
float DeltaX=PosicionCuerda[1]-PosicionCuerda[0];
int Tiempo=1;
float Valor=0;
float r=0.5;
int j;
float L=0.64;

for(j=0;j<=100000;j++)

{
	for(i=1;i<129;i++)
	{
	AmplitudCuerda[0]=0;
	AmplitudCuerda[130]=0;
	Valor = 2*(1-pow(r,2))*AmplitudCuerda[i]-PasadasCondiciones[i]+pow(r,2)*(AmplitudCuerda[i+1]+AmplitudCuerda[i-1]);
	
	NuevasAmplitudes[i]=Valor;
	

	}


	for(i=1;i<=129;i++)
	{
	PasadasCondiciones[i]=AmplitudCuerda[i];
	AmplitudCuerda[i]=NuevasAmplitudes[i];
	if(j%25000==0)
	{
	//printf("%f \n",AmplitudCuerda[i]);
	fprintf(Archivo1,"%f ",AmplitudCuerda[i]);
	}
	
	}
fprintf(Archivo1,"\n"); 

}

/*for(j=0;j<=100000;j++)

{
	for(i=1;i<129;i++)
	{
	AmplitudCuerda[0]=0;
	AmplitudCuerda[130]=sin((2*pi*C/L))*j*(1/DeltaT)
;
	Valor = 2*(1-pow(r,2))*AmplitudCuerda[i]-PasadasCondiciones[i]+pow(r,2)*(AmplitudCuerda[i+1]+AmplitudCuerda[i-1]);
	
	NuevasAmplitudes[i]=Valor;
	

	}


	for(i=1;i<=129;i++)
	{
	PasadasCondiciones[i]=AmplitudCuerda[i];
	AmplitudCuerda[i]=NuevasAmplitudes[i];
	if(j%25000==0)
	{
	//printf("%f \n",AmplitudCuerda[i]);
	fprintf(Archivo1,"%f ",AmplitudCuerda[i]);
	}
	
	}
fprintf(Archivo1,"\n"); 

}
*/



//REFERENCIA PARA LEER LOS DATOS https://stackoverflow.com/questions/10467278/reading-from-txt-file-into-arrays-in-c

//printf("%f \n",AmplitudCuerda[5]);


return 0;





}
