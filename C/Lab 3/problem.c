#include <stdio.h>
#include <math.h>
/* Male Max Heart rate function */
double
mmhr (double n1)
{
    double a;
	a = 203.7/(1.0+exp(0.0453*(n1-104.3)));
	
	return (a);
}
/* Female Max Heart rate function */
double
fmhr (double n2)
{
    double b;
	b = 190.2/(1.0+exp(0.0453*(n2-107.5)));
	
	return (b);
}
/* Training Heart rate function */
double
THR (double n3, double n4, double n5, double n6)
{
    double c;
	c = (n3-n4)*n5+n6;
	
	return (c);
}
int
main (void)
{
	double age, MHR, RHR, INTEN, result;
	char gender, FT;
	/* User entered gender */
	printf ("Enter a gender 'M' for male and 'F' for female: ");
	scanf ("%c", &gender);
	/* User entered age */
	printf ("Enter a age: ");
	scanf ("%lf", &age);
	/* User entered resting heartrate */
	printf ("Enter a resting heartrate: ");
	scanf ("%lf", &RHR);
	/* User entered fitness level*/ 
	printf ("Enter a fitness level, 'L' for low, 'M' for medium and 'H' for high: ");
	scanf (" %c", &FT);
	/* calculating Max Heart Rate based on gender */
	if (gender=='M'){
	    MHR = mmhr (age);
	}
	else if (gender=='F'){
	    MHR = fmhr (age);
	}
	/* finding INTEN based on fitness level */
	if (FT=='L'){
	   INTEN = 0.55;
	}
	else if (FT=='M'){
	    INTEN = 0.65;
	}
	else if (FT=='H'){
	    INTEN = 0.8;
	}
	/* Calculating taget heart rate */
	result = THR (MHR,RHR,INTEN,RHR);
	/* displaying target heart rate  */
	printf ("The training heart rate is %lf.\n", result);
	return (0);
}
