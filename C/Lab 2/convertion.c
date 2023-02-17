#include <stdio.h>
#include <math.h>

double
spsound (double n1)
{
	double a,b,c;
	/* conversion from Celsius to fahrenheit*/
	a =  ((n1*(5.0/9.0))+32.0);
	/* formula*/
	b = 1086*(sqrt((5*a+297.0)/247.0));
	/* conversion from feet/sec to km/h*/
	c = (b*3600.0)/3280.8;
	
	return (a,b,c);
}


int
main (void)
{
	double t, result;

	printf ("Enter the temperature in degrees Celsius: ");
	scanf ("%lf", &t);

	result = spsound (t);

	printf ("The speed is %lf km/h.\n", result);
	
	return (0);
}
