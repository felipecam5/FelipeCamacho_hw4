#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){

static const int MAX_FILE_ROWS = 129;

float* AmplitudCuerda = malloc(129*sizeof(float));
float* PosicionCuerda = malloc(129*sizeof(float));
float* NuevasAmplitudes = malloc(129*sizeof(float));
float* PasadasCondiciones= malloc(129*sizeof(float));
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
for(i=0;i<=128;i++)
{

NuevasAmplitudes[i]=0;
PasadasCondiciones[i]=0;
//printf("%f \n",NuevasAmplitudes[i]);
}
FILE* Archivo1 = fopen("datos1D.txt","w");
FILE* Archivo2 = fopen("datos1Dabierto.txt","w");
FILE* Archivo3 = fopen("Sonido.txt","w");

float C=250.0;	
float DeltaT=0.000010;
float DeltaX=PosicionCuerda[1]-PosicionCuerda[0];
int Tiempo=1;
float Valor=0;
float r=0.5;
int j;
float L=0.64;

for(j=0;j<=100000;j++)

{
	for(i=1;i<=129;i++)
	{
	AmplitudCuerda[0]=0.0;
	AmplitudCuerda[129]=0.0;
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


for(i=0;i<=128;i++)
{

NuevasAmplitudes[i]=0;
PasadasCondiciones[i]=0;
//printf("%f \n",NuevasAmplitudes[i]);
}



for(j=0;j<=100000;j++)

{
	for(i=1;i<=129;i++)
	{
	
	Valor = 2*(1-pow(r,2))*AmplitudCuerda[i]-PasadasCondiciones[i]+pow(r,2)*(AmplitudCuerda[i+1]+AmplitudCuerda[i-1]);
	
	NuevasAmplitudes[i]=Valor;
	

	}


	for(i=1;i<=129;i++)
	{
	PasadasCondiciones[i]=AmplitudCuerda[i];
	AmplitudCuerda[i]=NuevasAmplitudes[i];
	AmplitudCuerda[0]=0.0;
	AmplitudCuerda[129]=sin((2*pi*C/L)*j*DeltaT);
	if(j%25000==0)
	{
	printf("%f \n",AmplitudCuerda[i]);
	fprintf(Archivo2,"%f ",AmplitudCuerda[i]);
	
	}
	
	}
fprintf(Archivo2,"\n"); 

}


/*sin((2*pow(pi,2)*C/L)/180)*j*(DeltaT)*/;

//REFERENCIA PARA LEER LOS DATOS https://stackoverflow.com/questions/10467278/reading-from-txt-file-into-arrays-in-c

//printf("%f \n",AmplitudCuerda[5]);


return 0;





}
