#include <stdio.h>

double
tvlmo(double n1){
    double min, max;
    min=363104.0/n1;
    max=405696/n1;
    printf("It would take a minimum of %lf hours and a maximum of %lf hours to get from Earth to the Moon\n\n", min, max );
    return(n1);
}
double 
tvlma(double n2){
    double min1,max1;
    min1=54600000/n2;
    max1=401000000/n2;
    printf("It would take a minimum of %lf hours and a maximum of %lf hours to get from Earth to the Moon\n\n", min1, max1 );
    return(n2);
}
double
tvlve(double n3){
  double min2,max2;
  min2=38000000/n3;
  max2=261000000/n3;
  printf("It would take a minimum of %lf hours and a maximum of %lf hours to get from Earth to the Moon\n\n", min2, max2 );
  return(n3);  
}
int main()
{
    int num;
    double speed;
    do {
      printf("Enter 1 to calculate the travel time from Earth to the Moon enter 2 to calculate the travel time from Earth to Mars enter 3 to calculate the travel time from Earth to Venus enter 4 to exit: ");
      scanf("%d", &num);
      if(num != 4){
          printf("enter traveling speed in km/h: ");
          scanf("%lf", &speed);
      }
      if (num==1){
        tvlmo(speed);  
      }
      else if (num==2){
        tvlma(speed);  
      }
      else if (num==3){
        tvlve(speed);  
      }
    }
    while(num != 4);   
    return(0);
}
