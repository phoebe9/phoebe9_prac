#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define N 64 //FFTのデータ点数

void dft(double x[N], double Xr[N], double Xi[N]);

int main(void)
{
  //DFT計算に必要な変数
  double x[N], Xr[N], Xi[N];
  int i;

  for(i=0; i<N; i++) x[i] = 0.0;
  for(i=N/4; i<3*N/4; i++) x[i]=1.0;

  dft(x, Xr, Xi);

  for(i=0; i<N; i++){
    printf("%f,%f,%f,%f\n",Xr[i], Xi[i],sqrt(Xr[i]*Xr[i]+Xi[i]*Xi[i]),x[i]);

  }
  return 0;
}

void dft(double x[N], double Xr[N], double Xi[N])
{
  int k,p;

  for(k=0; k<N; k++){
    Xr[k]=0.0;
    Xi[k]=0.0;

    for(p=0; p<N; p++){
      Xr[k]+=x[p]*cos(2.0*PI*p*k/(double)N);
      Xi[k]-=x[p]*sin(2.0*PI*p*k/(double)N);
    }
    Xr[k]=Xr[k]/sqrt((double)N);
    Xi[k]=Xi[k]/sqrt((double)N);

  }
}
