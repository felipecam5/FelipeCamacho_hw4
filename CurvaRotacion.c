#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){

static const int MAX_FILE_ROWS = 300;

float* RADIO = malloc(MAX_FILE_ROWS*sizeof(float));
float* VELOCIDAD = malloc(MAX_FILE_ROWS*sizeof(float));
float* MODELO = malloc(MAX_FILE_ROWS*sizeof(float));
float* RESTA = malloc(MAX_FILE_ROWS*sizeof(float));
float* SUMATORIA = malloc(MAX_FILE_ROWS*sizeof(float));
float pi=3.1416;

float chicuadrado;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

double lines[MAX_FILE_ROWS][2];
FILE *file = fopen("RadialVelocities.dat", "r");

for (int i = 0; i < MAX_FILE_ROWS; i++)
{
    if (feof(file))
        break;

    fscanf(file, "%lf %lf ", &(lines[i][0]), &(lines[i][1]));
   //printf("%f %f \n",(lines[i][0]), (lines[i][1]));
	VELOCIDAD[i]=(lines[i][1]);
	RADIO[i]=(lines[i][0]);
	printf("%f \n",VELOCIDAD[i]);
	
}

fclose(file);

float AL1;
float AL2;
float AL3;
int contador=0;
float Bb=0.2497;
float Bd=5.16;
float Ad=0.3105;
float Ah=64.3;
float V;
float alfa;
float beta;
float Mb;
float Md;
float R;
float Mh;
float XVIEJO;
float XNUEVO;
float fvieja;
float fnueva;
float betha;
float SUMA;
float ALMODELO;
float Vel(float Mb,float Md,float Mh,float R)
{
	V= V = ((pow(Mb,0.5))*(R)/pow((pow(R,2)+pow(Bb,2)),0.75)) + ((pow(Md,0.5))*(R)/ pow((pow(R,2)+pow(Bd+Ad,2)),0.75)) + ((pow(Mh,0.5))*(R)/pow((pow(R,2)+pow(Ah,2)),0.25));
	return V;
	
}





int i;
int j;
while(chicuadrado>=0.1)
{
AL1 = drand48();
AL2 = drand48();
AL3 = drand48();

for(j=0;j<300;j++)
{
ALMODELO = 40*drand48();
MODELO[j]= ALMODELO;
}

for(j=0;j<300;j++)
{
ALMODELO = VELOCIDAD[j]-MODELO[j];
RESTA[j] = ALMODELO;

}

for(j=0;j<300;j++)
{
SUMA = SUMA + RESTA[j];

}
chicuadrado=(1.0/2.0)*pow(SUMA,2);
XVIEJO=40*drand48();
XNUEVO=40*drand48();

fvieja = Vel(Mb,Md,Mh,XVIEJO);
fnueva = Vel(Mb,Md,Mh,XNUEVO);

alfa=fnueva/fvieja;

if(alfa>1){}
if(alfa<1)
{
	
	beta= drand48();
	if(betha<alfa)
	{

	
	}

}

}


 






return 0;

}

