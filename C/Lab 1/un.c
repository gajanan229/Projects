#include <stdio.h>
#include <math.h>

int main()
{
	/*user inputs the values of the short sides*/
   printf("enter the length of side that is not the hypotenuse: \n");
   double sidea; 
   scanf("%lf",&sidea);
   printf("enter the length of the other side that is not the hypotenuse: \n");
   double sideb; 
   scanf("%lf",&sideb);
   /*perimeter calculations*/
   double perimeter = sidea + sideb + sqrt(sidea*sidea + sideb*sideb) ; 
   /*perimeter calculations displayed*/
   printf("the length of the perimeter is: %1.2lf \n",perimeter);
   
   /*surface area calculations*/
   double area= (sidea*sideb)/2;
   /*area calculations displayed*/
   printf("the area of the triangle is: %1.2lf \n",area);
    return 0;
}
