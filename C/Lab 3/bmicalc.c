#include <stdio.h>
#include <math.h>
/* Body mass index function */
double
BMI (double n1, double n2)
{
    double a;
	a = n1/(pow(n2,2.0));
	
	return (a);
}

int
main (void)
{
	double height, weight, result ;
	
	/* User entered height */
	printf ("Enter a height in meters: ");
	scanf ("%lf", &height);
	/* User entered weight */
	printf ("Enter a weight in kilograms: ");
	scanf ("%lf", &weight);
	/* BMI calculation */
	result = BMI (weight, height);
	/* determining BMI classification */
	if (result<18.5){
	    printf ("Your BMI value is %.2lf, which classifies you as underweight \n", result);
	}
	else if (result<=24.9){
	    printf ("Your BMI value is %.2lf, which classifies you as normal \n", result);
	}
	else if (result<=29.9){
	    printf ("Your BMI value is %.2lf, which classifies you as overweight \n", result);
	}
	else if (result>=30){
	    printf ("Your BMI value is %.2lf, which classifies you as obese \n", result);
	}


	return (0);
}
