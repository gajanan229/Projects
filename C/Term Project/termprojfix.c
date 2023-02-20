#include <stdio.h>
#include <string.h>
#include <conio.h>

/* I didn't realize Lake Erie was actually Lake Erie. Changing the variable names would be too much work at this point. */

double average(int n, double arr[]);
void coldestAndWarmest (double arr[], int *coldestIndex, int *warmestIndex);
void coldestWarmestAndTies (int days, double arr[], int *tiesColdest, int *tiesWarmest, double *coldest, double *warmest);
void coldestAndWarmestArray (int days, double arrTemps[], double coldest, double warmest, int coldestDaysArray[], int warmestDaysArray[]);
void dayToDate (int leapYear, int *dayIndex);
const char *dayToMonth (int leapYear, int day);
double summerAveraging (double array[]);
double winterAveraging (double array[]);
void sortingWithIndex (int n, double array[], int index[]);

int main()
{
	
	FILE *yearlyData2020 = fopen("yearlyData2020.txt", "r");
	
	int i, j;
	int day = 0;
	int dayIndex, numOfDays;
	int year, isLeapYear;
	
	/* The below section determines the leap year status of the data, then
	 * how many days are present in the year, and then finally rewinds the 
	 * file so it doesn't interfere with later calculations. 
	 * This was done so that the six arrays that would be filled in the 'while' 
	 * section could be initialized beforehand.*/
	
	fscanf (yearlyData2020, "%d", &year);
	if (year % 4 == 0)
	{
		numOfDays = 366;
		isLeapYear = 1;
	}
	else 
	{
		numOfDays = 365;
		isLeapYear = 0;
	}
	rewind (yearlyData2020);
	
	
	/* The below code first initializes six arrays, one for each lake. This array has the same
	 * number of days as previously determined. Next, it initializes six variables that will hold
	 * the average temperatures of each lake, and then one array to hold those variables. */
	
	double superior[numOfDays];
	double michigan[numOfDays];
	double huron[numOfDays];
	double Erie[numOfDays];
	double ontario[numOfDays];
	double clair[numOfDays];
	
	double averageSuperior;
	double averageMichigan;
	double averageHuron;	
	double averageErie;
	double averageOntario;
	double averageClair;
	double averageTotal;
	
	double arrayAverages[6];
	
	
	/* This while loop fills the priorly mentioned lake arrays with the 
	 * correct values, using a for loop and a switch-case to insert each
	 * value into the correct index in the correct array. */
	
	while (!feof(yearlyData2020))
	{
		
		fscanf (yearlyData2020, "%d", &year);
		fscanf (yearlyData2020, "%d", &day);
		
		dayIndex = day - 1;
		
		for (i = 0; i < 6; i++)
		{
			double temperature;
			fscanf (yearlyData2020, "%lf", &temperature);		
			
			switch (i)
			{
				case 0:
					superior[dayIndex] = temperature;
					break;
					
				case 1:
					michigan[dayIndex] = temperature;
					break;
				
				case 2:
					huron[dayIndex] = temperature;
					break;
					
				case 3:
					Erie[dayIndex] = temperature;
					break;
					
				case 4:
					ontario[dayIndex] = temperature;
					break;
				
				case 5:
					clair[dayIndex] = temperature;
					break;
					
			}
		}
	}
	
	
	/* This code uses the 'average' function, defined at the end, to 
	 * determine the average values of each array. Finally, it prints out 
	 * those same values. 
	 * Next, it uses a for-loop and switch-case to fill the array of averages
	 * with each average in order, and then determines and prints the average.*/
	
	averageSuperior = average (numOfDays, ontario);
	averageMichigan = average (numOfDays, Erie);
	averageHuron = average (numOfDays, huron);	
	averageErie = average (numOfDays, michigan);
	averageOntario = average (numOfDays, superior);
	averageClair = average (numOfDays, clair);
	
	printf ("The average temperature of Lake Superior is %.3lf.", averageSuperior);
	printf ("\nThe average temperature of Lake Michigan is %.3lf.", averageMichigan);
	printf ("\nThe average temperature of Lake Huron is %.3lf.", averageHuron);
	printf ("\nThe average temperature of Lake Erie is %.3lf.", averageErie);
	printf ("\nThe average temperature of Lake Ontario is %.3lf.", averageOntario);
	printf ("\nThe average temperature of Lake Saint Clair is %.3lf.", averageClair);
	
	for (i = 0; i < 6; i++)
	{
		switch (i)
		{
			case 0:
				arrayAverages[i] = averageSuperior;
				break;
					
			case 1:
				arrayAverages[i] = averageMichigan;
				break;
				
			case 2:
				arrayAverages[i] = averageHuron;
				break;
					
			case 3:
				arrayAverages[i] = averageErie;
				break;
					
			case 4:
				arrayAverages[i] = averageOntario;
				break;
				
			case 5:
				arrayAverages[i] = averageClair;
				break;
				
		}		
	}
	
	averageTotal = average (6, arrayAverages);
	printf ("\nThe average temperature of all of the lakes is %.3lf.", averageTotal);
	
	
	/* The below code uses the 'coldestAndWarmest' function to determine
	 * the coldest and warmest average temperatures from the array of 
	 * averages previously defined. It then uses a case-switch function to
	 * print out the final answer. */
	
	
	int coldestLake;
	int warmestLake;
	
	coldestAndWarmest (arrayAverages, &coldestLake, &warmestLake);
	
	printf ("\n\nThe lake with the coldest average temperature is ");
	switch (coldestLake)
	{
		case 0:
			printf ("Lake Superior.");
			break;
			
		case 1:
			printf ("Lake Michigan.");
			break;
			
		case 2:
			printf ("Lake Huron.");
			break;
			
		case 3:
			printf ("Lake Erie.");
			break;
			
		case 4:
			printf ("Lake Ontario.");
			break;
			
		case 5:
			printf ("Lake Saint Clair.");
			break;
	}
	
	printf ("\nThe lake with the warmest average temperature is ");
	switch (warmestLake)
	{
		case 0:
			printf ("Lake Superior.");
			break;
			
		case 1:
			printf ("Lake Michigan.");
			break;
			
		case 2:
			printf ("Lake Huron.");
			break;
			
		case 3:
			printf ("Lake Erie.");
			break;
			
		case 4:
			printf ("Lake Ontario.");
			break;
			
		case 5:
			printf ("Lake Saint Clair.");
			break;			
	}
	
	
	/* The below code determines which lakes have an average lower than 
	 * the total average, and then prints them out. Then it does the same
	 * for higher temperatures. */
	
	
	int count = 0;
	/* Exists just so the formatting is clean. Only places 'and' between
	 * two consequent lakes. Probably some easier way to do this, but I 
	 * couldn't figure it out. */
	
	printf ("\n\nThe lakes with an average temperature lower than the average of all the lakes are ");
	for (i = 0; i < 6; i++)
	{
		if (arrayAverages[i] < averageTotal)
		{
			count++;
			if (count > 1)
			{
				printf (" and ");
			}
			
			switch (i)
			{
				case 0:
					printf ("Lake Superior");
					break;
			
				case 1:
					printf ("Lake Michigan");
					break;
			
				case 2:
					printf ("Lake Huron");
					break;
			
				case 3:
					printf ("Lake Erie");
					break;
			
				case 4:
					printf ("Lake Ontario");
					break;
			
				case 5:
					printf ("Lake Saint Clair");
					break;
			}
		}
	}
	printf (".");
	
	
	count = 0;	
	printf ("\nThe lakes with an average temperature higher than the average of all the lakes are ");
	for (i = 0; i < 6; i++)
	{
		if (arrayAverages[i] > averageTotal)
		{
			count++;
			if (count > 1)
			{
				printf (" and ");
			}
			
			switch (i)
			{
				case 0:
					printf ("Lake Superior");
					break;
			
				case 1:
					printf ("Lake Michigan");
					break;
			
				case 2:
					printf ("Lake Huron");
					break;
			
				case 3:
					printf ("Lake Erie");
					break;
			
				case 4:
					printf ("Lake Ontario");
					break;
			
				case 5:
					printf ("Lake Saint Clair");
					break;
			}
		}
	}
	printf (".");
	
	/* This code is kind of complicated - first, it initializes variables for EACH lake
	 * that will hold that lake's coldest and warmest temperatures as well as the amount of
	 * ties there are for that temperature. Next, it uses the function 'coldestAndWarmestTies'
	 * to determine the values of those four variables. That function uses the original array
	 * and the number of days to determine these values. Next, it initializes two arrays with size
	 * of the ties we just found. This array will hold the indexes of the warmest and coldest days.
	 * It uses the function 'warmestAndColdestArray' to find all values in the original array that are
	 * equal to the coldest/warmest values and then inserts the index of that day into the new array.
	 * Finally, the for-switch-case loop uses the 'dayToDate' function and the 'dayToMonth' function to determine
	 * the actual dates for each index in each of the six arrays, and then prints them out. */
	
	
	int coldTiesSuperior;
	int warmTiesSuperior;
	double coldestSuperior;
	double warmestSuperior;
	
	int coldTiesMichigan;
	int warmTiesMichigan;
	double coldestMichigan;
	double warmestMichigan;
	
	int coldTiesHuron;
	int warmTiesHuron;
	double coldestHuron;
	double warmestHuron;
	
	int coldTiesErie;
	int warmTiesErie;
	double coldestErie;
	double warmestErie;
	
	int coldTiesOntario;
	int warmTiesOntario;
	double coldestOntario;
	double warmestOntario;
	
	int coldTiesClair;
	int warmTiesClair;
	double coldestClair;
	double warmestClair;

	coldestWarmestAndTies (numOfDays, superior, &coldTiesSuperior, &warmTiesSuperior, &coldestSuperior, &warmestSuperior);
	int coldestIndexSuperior[coldTiesSuperior];
	int warmestIndexSuperior[warmTiesSuperior];
	coldestAndWarmestArray (numOfDays, superior, coldestSuperior, warmestSuperior, coldestIndexSuperior, warmestIndexSuperior);
	
	coldestWarmestAndTies (numOfDays, michigan, &coldTiesMichigan, &warmTiesMichigan, &coldestMichigan, &warmestMichigan);
	int coldestIndexMichigan[coldTiesMichigan];
	int warmestIndexMichigan[warmTiesMichigan];
	coldestAndWarmestArray (numOfDays, michigan, coldestMichigan, warmestMichigan, coldestIndexMichigan, warmestIndexMichigan);
	
	coldestWarmestAndTies (numOfDays, huron, &coldTiesHuron, &warmTiesHuron, &coldestHuron, &warmestHuron);
	int coldestIndexHuron[coldTiesHuron];
	int warmestIndexHuron[warmTiesHuron];
	coldestAndWarmestArray (numOfDays, huron, coldestHuron, warmestHuron, coldestIndexHuron, warmestIndexHuron);
	
	coldestWarmestAndTies (numOfDays, Erie, &coldTiesErie, &warmTiesErie, &coldestErie, &warmestErie);
	int coldestIndexErie[coldTiesErie];
	int warmestIndexErie[warmTiesErie];
	coldestAndWarmestArray (numOfDays, Erie, coldestErie, warmestErie, coldestIndexErie, warmestIndexErie);
			
	coldestWarmestAndTies (numOfDays, ontario, &coldTiesOntario, &warmTiesOntario, &coldestOntario, &warmestOntario);
	int coldestIndexOntario[coldTiesOntario];
	int warmestIndexOntario[warmTiesOntario];
	coldestAndWarmestArray (numOfDays, ontario, coldestOntario, warmestOntario, coldestIndexOntario, warmestIndexOntario);
	
	coldestWarmestAndTies (numOfDays, clair, &coldTiesClair, &warmTiesClair, &coldestClair, &warmestClair);
	int coldestIndexClair[coldTiesClair];
	int warmestIndexClair[warmTiesClair];
	coldestAndWarmestArray (numOfDays, clair, coldestClair, warmestClair, coldestIndexClair, warmestIndexClair);
	
	
	int dayThen;
	
	for (i = 0; i < 6; i++)
	{
		count = 0;
		
		switch (i)
		{
			case 0:
				printf ("\n\nThe lowest temperature in Lake Superior is %.2lf degrees Celsius, and occurs on the day(s) ", coldestSuperior);
				for (j = 0; j < coldTiesSuperior; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = coldestIndexSuperior[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = coldestIndexSuperior[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
			case 1:
				printf ("\nThe lowest temperature in Lake Michigan is %.2lf degrees Celsius, and occurs on the day(s) ", coldestMichigan);
				for (j = 0; j < coldTiesMichigan; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = coldestIndexMichigan[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = coldestIndexMichigan[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
			case 2:
				printf ("\nThe lowest temperature in Lake Huron is %.2lf degrees Celsius, and occurs on the day(s) ", coldestHuron);
				for (j = 0; j < coldTiesHuron; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = coldestIndexHuron[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = coldestIndexHuron[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
			case 3:
				printf ("\nThe lowest temperature in Lake Erie is %.2lf degrees Celsius, and occurs on the day(s) ", coldestErie);
				for (j = 0; j < coldTiesErie; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = coldestIndexErie[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = coldestIndexErie[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
			case 4:
				printf ("\nThe lowest temperature in Lake Ontario is %.2lf degrees Celsius, and occurs on the day(s) ", coldestOntario);
				for (j = 0; j < coldTiesOntario; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = coldestIndexOntario[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = coldestIndexOntario[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
			case 5:
				printf ("\nThe lowest temperature in Lake Saint Clair is %.2lf degrees Celsius, and occurs on the day(s) ", coldestClair);
				for (j = 0; j < coldTiesClair; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = coldestIndexClair[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = coldestIndexClair[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
		}
	}
	
	
	for (i = 0; i < 6; i++)
	{
		count = 0;
		
		switch (i)
		{
			case 0:
				printf ("\n\nThe warmest temperature in Lake Superior is %.2lf degrees Celsius, and occurs on the day(s) ", warmestSuperior);
				for (j = 0; j < warmTiesSuperior; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = warmestIndexSuperior[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = warmestIndexSuperior[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
			case 1:
				printf ("\nThe warmest temperature in Lake Michigan is %.2lf degrees Celsius, and occurs on the day(s) ", warmestMichigan);
				for (j = 0; j < warmTiesMichigan; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = warmestIndexMichigan[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = warmestIndexMichigan[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
			case 2:
				printf ("\nThe warmest temperature in Lake Huron is %.2lf degrees Celsius, and occurs on the day(s) ", warmestHuron);
				for (j = 0; j < warmTiesHuron; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = warmestIndexHuron[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = warmestIndexHuron[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
			case 3:
				printf ("\nThe warmest temperature in Lake Erie is %.2lf degrees Celsius, and occurs on the day(s) ", warmestErie);
				for (j = 0; j < warmTiesErie; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = warmestIndexErie[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = warmestIndexErie[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
			case 4:
				printf ("\nThe warmest temperature in Lake Ontario is %.2lf degrees Celsius, and occurs on the day(s) ", warmestOntario);
				for (j = 0; j < warmTiesOntario; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = warmestIndexOntario[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = warmestIndexOntario[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
			case 5:
				printf ("\nThe warmest temperature in Lake Saint Clair is %.2lf degrees Celsius, and occurs on the day(s) ", warmestClair);
				for (j = 0; j < warmTiesClair; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = warmestIndexClair[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = warmestIndexClair[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
		}
	}

	
	
	/* First, we initialize two arrays that will hold the values of the
	 * warmest and coldest overall temperatures. Next, we use a for-switch-
	 * case loop to fill the arrays. */
	
	double warmestArray[6];
	double coldestArray[6];
	
	for (i = 0; i < 6; i++)
	{
		switch (i)
		{
			case 0:
				warmestArray[i] = warmestSuperior;
				coldestArray[i] = coldestSuperior;
				break;
					
			case 1:
				warmestArray[i] = warmestMichigan;
				coldestArray[i] = coldestMichigan;
				break;
				
			case 2:
				warmestArray[i] = warmestHuron;
				coldestArray[i] = coldestHuron;
				break;
					
			case 3:
				warmestArray[i] = warmestErie;
				coldestArray[i] = coldestErie;
				break;
					
			case 4:
				warmestArray[i] = warmestOntario;
				coldestArray[i] = coldestOntario;
				break;
				
			case 5:
				warmestArray[i] = warmestClair;
				coldestArray[i] = coldestClair;
				break;
				
		}		
	}
	
	
	/* This code determines the overall warmest and overall coldest lakes,
	 * and remembers the index of the aforementioned lake. */
	
	double warmestOverall = -9999;
	double coldestOverall = 9999;
	int warmestOverallIndex;
	int coldestOverallIndex;
	
	for (i = 0; i < 6; i++)
	{
		if (warmestArray[i] > warmestOverall)
		{
			warmestOverall = warmestArray[i];
			warmestOverallIndex = i;
		}
		if (coldestArray[i] < coldestOverall)
		{
			coldestOverall = coldestArray[i];
			coldestOverallIndex = i;
		}
	}
	
	/* Using that index, this code prints out the coldest and warmest lake 
	 * and what days that temperature occurs on. */
	
	count = 0;
	
	switch (warmestOverallIndex)
	{
			case 0:
				printf ("\n\nAt %.2lf degrees Celsius, Lake Superior is the overall warmest lake. This temperature occurs on the day(s) ", warmestOverall);
				for (j = 0; j < warmTiesSuperior; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = warmestIndexSuperior[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = warmestIndexSuperior[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
					
			case 1:
				printf ("\n\nAt %.2lf degrees Celsius, Lake Michigan is the overall warmest lake. This temperature occurs on the day(s) ", warmestOverall);
				for (j = 0; j < warmTiesMichigan; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = warmestIndexMichigan[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = warmestIndexMichigan[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
			case 2:
				printf ("\n\nAt %.2lf degrees Celsius, Lake Huron is the overall warmest lake. This temperature occurs on the day(s) ", warmestOverall);
				for (j = 0; j < warmTiesHuron; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = warmestIndexHuron[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = warmestIndexHuron[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
					
			case 3:
				printf ("\n\nAt %.2lf degrees Celsius, Lake Erie is the overall warmest lake. This temperature occurs on the day(s) ", warmestOverall);
				for (j = 0; j < warmTiesErie; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = warmestIndexErie[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = warmestIndexErie[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
					
			case 4:
				printf ("\n\nAt %.2lf degrees Celsius, Lake Ontario is the overall warmest lake. This temperature occurs on the day(s) ", warmestOverall);
				for (j = 0; j < warmTiesOntario; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = warmestIndexOntario[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = warmestIndexOntario[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
			case 5:
				printf ("\n\nAt %.2lf degrees Celsius, Lake Clair is the overall warmest lake. This temperature occurs on the day(s) ", warmestOverall);
				for (j = 0; j < warmTiesClair; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = warmestIndexClair[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = warmestIndexClair[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
	
	}
	
	count = 0;
	
	switch (coldestOverallIndex)
	{
			case 0:
				printf ("\nAt %.2lf degrees Celsius, Lake Superior is the overall coldest lake. This temperature occurs on the day(s) ", coldestOverall);
				for (j = 0; j < coldTiesSuperior; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = coldestIndexSuperior[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = coldestIndexSuperior[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
					
			case 1:
				printf ("\nAt %.2lf degrees Celsius, Lake Michigan is the overall coldest lake. This temperature occurs on the day(s) ", coldestOverall);
				for (j = 0; j < coldTiesMichigan; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = coldestIndexMichigan[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = coldestIndexMichigan[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
			case 2:
				printf ("\nAt %.2lf degrees Celsius, Lake Huron is the overall coldest lake. This temperature occurs on the day(s) ", coldestOverall);
				for (j = 0; j < coldTiesHuron; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = coldestIndexHuron[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = coldestIndexHuron[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
					
			case 3:
				printf ("\nAt %.2lf degrees Celsius, Lake Erie is the overall coldest lake. This temperature occurs on the day(s) ", coldestOverall);
				for (j = 0; j < coldTiesErie; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = coldestIndexErie[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = coldestIndexErie[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
					
			case 4:
				printf ("\nAt %.2lf degrees Celsius, Lake Ontario is the overall coldest lake. This temperature occurs on the day(s) ", coldestOverall);
				for (j = 0; j < coldTiesOntario; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = coldestIndexOntario[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = coldestIndexOntario[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
				
			case 5:
				printf ("\nAt %.2lf degrees Celsius, Lake Clair is the overall coldest lake. This temperature occurs on the day(s) ", coldestOverall);
				for (j = 0; j < coldTiesClair; j++)
				{
					count++;
					if (count > 1)
					{
						printf (", ");
					}
					
					dayThen = coldestIndexClair[j];
					printf ("%s", dayToMonth (isLeapYear, dayThen));
					
					dayThen = coldestIndexClair[j];
					dayToDate (isLeapYear, &dayThen);
					printf (" %d", dayThen);
				}
				printf (".");
				break;
	
	}
	
	
	/* This code initializes the two arrays of averages, and the index array 
	 * that will be used in the next section. */
	
	double summerAverage[6];
	int summerAverageIndex[6] = {0, 1, 2, 3, 4, 5};
	double winterAverage[6];
	int winterAverageIndex[6] = {0, 1, 2, 3, 4, 5};
	
	for (i = 0; i < 6; i++)
	{
		switch (i)
		{
			case 0:
				summerAverage[i] = summerAveraging (superior);
				winterAverage[i] = winterAveraging (superior);
				break;
				
			case 1:
				summerAverage[i] = summerAveraging (michigan);
				winterAverage[i] = winterAveraging (michigan);
				break;
				
			case 2:
				summerAverage[i] = summerAveraging (huron);
				winterAverage[i] = winterAveraging (huron);
				break;
				
			case 3:
				summerAverage[i] = summerAveraging (Erie);
				winterAverage[i] = winterAveraging (Erie);
				break;
				
			case 4:
				summerAverage[i] = summerAveraging (ontario);
				winterAverage[i] = winterAveraging (ontario);
				break;
				
			case 5:
				summerAverage[i] = summerAveraging (clair);
				winterAverage[i] = winterAveraging (clair);
				break;
				
		}
	}
	
	
	/* This code uses an index array and a sort function to sort the summer averages in
	 * descending order. */
	
	for (i = 0; i < 6; i++)
	{
		switch (i)
		{
			case 0:
				printf ("\n\nLake Superior has a summer average of %.2lf.", summerAverage[i]);
				break;
				
			case 1:
				printf ("\nLake Michigan has a summer average of %.2lf.", summerAverage[i]);
				break;
				
			case 2:
				printf ("\nLake Huron has a summer average of %.2lf.", summerAverage[i]);
				break;
				
			case 3:
				printf ("\nLake Erie has a summer average of %.2lf.", summerAverage[i]);
				break;
				
			case 4:
				printf ("\nLake Ontario has a summer average of %.2lf.", summerAverage[i]);
				break;
				
			case 5:
				printf ("\nLake Saint Clair has a summer average of %.2lf.", summerAverage[i]);
				break;
				
		}
	}
	
	printf ("\n\nFrom highest summer average to lowest, the lakes go as follows: ");
	
	sortingWithIndex (6, summerAverage, summerAverageIndex);
	
	count = 0;
	for (i = 0; i < 6; i++)
	{
		count++;
		if (count > 1)
		{
			printf (", ");
		}
		
		switch (summerAverageIndex[i])
		{
			case 0:
				printf ("Lake Superior");
				break;
				
			case 1:
				printf ("Lake Michigan");
				break;
				
			case 2:
				printf ("Lake Huron");
				break;
				
			case 3:
				printf ("Lake Erie");
				break;
				
			case 4:
				printf ("Lake Ontario");
				break;
				
			case 5:
				printf ("Lake Saint Clair");
				break;
				
		}
	}
	printf (".");
	
	
	/* This code does the same, but for the winter averages.*/
	
	for (i = 0; i < 6; i++)
	{
		switch (i)
		{
			case 0:
				printf ("\n\nLake Superior has a winter average of %.2lf.", winterAverage[i]);
				break;
				
			case 1:
				printf ("\nLake Michigan has a winter average of %.2lf.", winterAverage[i]);
				break;
				
			case 2:
				printf ("\nLake Huron has a winter average of %.2lf.", winterAverage[i]);
				break;
				
			case 3:
				printf ("\nLake Erie has a winter average of %.2lf.", winterAverage[i]);
				break;
				
			case 4:
				printf ("\nLake Ontario has a winter average of %.2lf.", winterAverage[i]);
				break;
				
			case 5:
				printf ("\nLake Saint Clair has a winter average of %.2lf.", winterAverage[i]);
				break;
				
		}
	}
	
	printf ("\n\nFrom highest winter average to lowest, the lakes go as follows: ");
	
	sortingWithIndex (6, winterAverage, winterAverageIndex);
	
	count = 0;
	for (i = 0; i < 6; i++)
	{
		count++;
		if (count > 1)
		{
			printf (", ");
		}
		
		switch (winterAverageIndex[i])
		{
			case 0:
				printf ("Lake Superior");
				break;
				
			case 1:
				printf ("Lake Michigan");
				break;
				
			case 2:
				printf ("Lake Huron");
				break;
				
			case 3:
				printf ("Lake Erie");
				break;
				
			case 4:
				printf ("Lake Ontario");
				break;
				
			case 5:
				printf ("Lake Saint Clair");
				break;
				
		}
	}
	printf (".");
	
	
	/* Calculates the amount of days in which you can swim in the lakes. */
	
	int swimmingDaysSuperior = 0;
	int swimmingDaysMichigan = 0;
	int swimmingDaysHuron = 0;
	int swimmingDaysErie = 0;
	int swimmingDaysOntario = 0;
	int swimmingDaysClair = 0;
	int index;
	
	for (index = 0; index < numOfDays; index++)
	{
		for (i = 0; i < 6; i++)
		{
			switch (i)
			{
				case 0:
					if (superior[index] > 20)
					{
						swimmingDaysSuperior++;
					}
					break;
					
				case 1:
					if (michigan[index] > 20)
					{
						swimmingDaysMichigan++;
					}
					break;
					
				case 2:
					if (huron[index] > 20)
					{
						swimmingDaysHuron++;
					}
					break;
					
				case 3:
					if (Erie[index] > 20)
					{
						swimmingDaysErie++;
					}
					break;
					
				case 4:
					if (ontario[index] > 20)
					{
						swimmingDaysOntario++;
					}
					break;
					
				case 5:
					if (clair[index] > 20)
					{
						swimmingDaysClair++;
					}
					break;
					
			}			
		}
	}
	
	for (i = 0; i < 6; i++)
	{
		switch (i)
		{
			case 0:
				printf ("\n\nThere are %d days during which the temperature in Lake Superior is comfortable enough to swim in.", swimmingDaysSuperior);
				break;
				
			case 1:
				printf ("\nThere are %d days during which the temperature in Lake Michigan is comfortable enough to swim in.", swimmingDaysMichigan);
				break;
				
			case 2:
				printf ("\nThere are %d days during which the temperature in Lake Huron is comfortable enough to swim in.", swimmingDaysHuron);
				break;
				
			case 3:
				printf ("\nThere are %d days during which the temperature in Lake Erie is comfortable enough to swim in.", swimmingDaysErie);
				break;
				
			case 4:
				printf ("\nThere are %d days during which the temperature in Lake Ontario is comfortable enough to swim in.", swimmingDaysOntario);
				break;
				
			case 5:
				printf ("\nThere are %d days during which the temperature in Lake Saint Clair is comfortable enough to swim in.", swimmingDaysClair);
				break;
				
		}
	}
	
	
	/* Calculates the amount of days the lakes are frozen. */
	
	int frozenDaysSuperior = 0;
	int frozenDaysMichigan = 0;
	int frozenDaysHuron = 0;
	int frozenDaysErie = 0;
	int frozenDaysOntario = 0;
	int frozenDaysClair = 0;
	
	for (index = 0; index < numOfDays; index++)
	{
		for (i = 0; i < 6; i++)
		{
			switch (i)
			{
				case 0:
					if (superior[index] < 0)
					{
						frozenDaysSuperior++;
					}
					break;
					
				case 1:
					if (michigan[index] < 0)
					{
						frozenDaysMichigan++;
					}
					break;
					
				case 2:
					if (huron[index] < 0)
					{
						frozenDaysHuron++;
					}
					break;
					
				case 3:
					if (Erie[index] < 0)
					{
						frozenDaysErie++;
					}
					break;
					
				case 4:
					if (ontario[index] < 0)
					{
						frozenDaysOntario++;
					}
					break;
					
				case 5:
					if (clair[index] < 0)
					{
						frozenDaysClair++;
					}
					break;
					
			}			
		}
	}
	
	for (i = 0; i < 6; i++)
	{
		switch (i)
		{
			case 0:
				printf ("\n\nThere are %d days during which Lake Superior is frozen.", frozenDaysSuperior);
				break;
				
			case 1:
				printf ("\nThere are %d days during which Lake Michigan is frozen.", frozenDaysMichigan);
				break;
				
			case 2:
				printf ("\nThere are %d days during which Lake Huron is frozen.", frozenDaysHuron);
				break;
				
			case 3:
				printf ("\nThere are %d days during which Lake Erie is frozen.", frozenDaysErie);
				break;
				
			case 4:
				printf ("\nThere are %d days during which Lake Ontario is frozen.", frozenDaysOntario);
				break;
				
			case 5:
				printf ("\nThere are %d days during which Lake Saint Clair is frozen.", frozenDaysClair);
				break;
				
		}
	}
	
	
	/* Average calculation for year 2019*/
	
	int numOfDays2019;
	
	
	FILE *yearlyData2019 = fopen("yearlyData2019.txt", "r");
	
	fscanf (yearlyData2019, "%d", &year);
	if (year % 4 == 0)
	{
		numOfDays2019 = 366;
	}
	else 
	{
		numOfDays2019 = 365;
	}
	rewind (yearlyData2019);
	
	
	/* The below code first initializes six arrays, one for each lake. This array has the same
	 * number of days as previously determined. Next, it initializes six variables that will hold
	 * the average temperatures of each lake, and then one array to hold those variables. */
	
	double superior2019[numOfDays];
	double michigan2019[numOfDays];
	double huron2019[numOfDays];
	double Erie2019[numOfDays];
	double ontario2019[numOfDays];
	double clair2019[numOfDays];
	
	double averageSuperior2019;
	double averageMichigan2019;
	double averageHuron2019;
	double averageErie2019;
	double averageOntario2019;
	double averageClair2019;
	double averageTotal2019;
	
	double arrayAverages2019[6];
	
	while (!feof(yearlyData2019))
	{
		
		fscanf (yearlyData2019, "%d", &year);
		fscanf (yearlyData2019, "%d", &day);
		
		dayIndex = day - 1;
		
		for (i = 0; i < 6; i++)
		{
			double temperature;
			fscanf (yearlyData2019, "%lf", &temperature);		
			
			switch (i)
			{
				case 0:
					superior2019[dayIndex] = temperature;
					break;
					
				case 1:
					michigan2019[dayIndex] = temperature;
					break;
				
				case 2:
					huron2019[dayIndex] = temperature;
					break;
					
				case 3:
					Erie2019[dayIndex] = temperature;
					break;
					
				case 4:
					ontario2019[dayIndex] = temperature;
					break;
				
				case 5:
					clair2019[dayIndex] = temperature;
					break;
					
			}
		}
	}
	
	averageSuperior2019 = average (numOfDays2019, ontario2019);
	averageMichigan2019 = average (numOfDays2019, Erie2019);
	averageHuron2019 = average (numOfDays2019, huron2019);	
	averageErie2019 = average (numOfDays2019, michigan2019);
	averageOntario2019 = average (numOfDays2019, superior2019);
	averageClair2019 = average (numOfDays2019, clair2019);
	
	printf ("\n\nThe average temperature of Lake Superior in 2019 is %.3lf.", averageSuperior2019);
	printf ("\nThe average temperature of Lake Michigan in 2019 is %.3lf.", averageMichigan2019);
	printf ("\nThe average temperature of Lake Huron in 2019 is %.3lf.", averageHuron2019);
	printf ("\nThe average temperature of Lake Erie in 2019 is %.3lf.", averageErie2019);
	printf ("\nThe average temperature of Lake Ontario in 2019 is %.3lf.", averageOntario2019);
	printf ("\nThe average temperature of Lake Saint Clair in 2019 is %.3lf.", averageClair2019);
	
	for (i = 0; i < 6; i++)
	{
		switch (i)
		{
			case 0:
				arrayAverages2019[i] = averageSuperior2019;
				break;
					
			case 1:
				arrayAverages2019[i] = averageMichigan2019;
				break;
				
			case 2:
				arrayAverages2019[i] = averageHuron2019;
				break;
					
			case 3:
				arrayAverages2019[i] = averageErie2019;
				break;
					
			case 4:
				arrayAverages2019[i] = averageOntario2019;
				break;
				
			case 5:
				arrayAverages2019[i] = averageClair2019;
				break;
				
		}		
	}
	
	averageTotal2019 = average (6, arrayAverages2019);
	printf ("\nThe average temperature of all of the lakes is %.3lf.", averageTotal2019);
	
	printf ("\n\n\n      Lake       |  Average 2019  |  Average 2020 ");
	printf ("\n-----------------|----------------|---------------");
	printf ("\n   Superior      |      %.2lf      |     %.2lf   ", averageSuperior2019, averageSuperior);
	printf ("\n   Michigan      |      %.2lf     |     %.2lf   ", averageMichigan2019, averageMichigan);
	printf ("\n   Huron         |      %.2lf      |     %.2lf   ", averageHuron2019, averageHuron);
	printf ("\n   Erie          |      %.2lf      |     %.2lf   ", averageErie2019, averageErie);
	printf ("\n   Ontario       |      %.2lf      |     %.2lf   ", averageOntario2019, averageOntario);
	printf ("\n   Saint Clair   |      %.2lf     |     %.2lf   ", averageClair2019, averageClair);
	
	
	
	return 0;

}




double average(int n, double arr[])
{
	/* Takes in an array of length n and returns the average of all values. */
	
	int i;
	double sum = 0;
	double average;
	
	
	for (i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	
	average = sum / n;
	return (average);
}

void coldestAndWarmest (double arr[], int *coldestIndex, int *warmestIndex)
{
	/* Determines the index of the warmest and coldest lakes of the six lakes.
	 * Only works for the averages array. */
	
	int i;
	double coldestTemperature = 9999;
	double warmestTemperature = -9999;
	*coldestIndex = 0;
	*warmestIndex = 0;
	
	for (i = 0; i < 6; i++)
	{
		if (arr[i] < coldestTemperature)
		{
			coldestTemperature = arr[i];
			*coldestIndex = i;
		}
		
		if (arr[i] > warmestTemperature)
		{
			warmestTemperature = arr[i];
			*warmestIndex = i;
		}
	}
}

void coldestWarmestAndTies (int days, double arr[], int *tiesColdest, int *tiesWarmest, double *coldest, double *warmest)
{
	/* Determines how many ties there are for each lake, as well as the temperature on those days. */
	
	int i;
	*tiesColdest = 0;
	*tiesWarmest = 0;
	double coldestTemperature = 9999;
	double warmestTemperature = -9999;
	
	for (i = 0; i < days; i++)
	{
		if (arr[i] < coldestTemperature)
		{
			coldestTemperature = arr[i];
		}
		
		if (arr[i] > warmestTemperature)
		{
			warmestTemperature = arr[i];
		}
	}
	
	*coldest = coldestTemperature;
	*warmest = warmestTemperature;
	
	for (i = 0; i < days; i++)
	{
		if ( (arr[i] == coldestTemperature) )
		{
			*tiesColdest = *tiesColdest + 1;
		}
		if ( (arr[i] == warmestTemperature) )
		{
			*tiesWarmest = *tiesWarmest + 1;
		}
	}
}

void coldestAndWarmestArray (int days, double arrTemps[], double coldest, double warmest, int coldestDaysArray[], int warmestDaysArray[])
{
	/* Determines the days with highest and lowest temps for each lake. */
	
	int i;
	int count = 0;
	

	for (i = 0; i < days; i++)
	{
		if ( (arrTemps[i] == coldest) )
		{
			coldestDaysArray[count] = i;
			count++;
		}
	}
	
	count = 0;
	for (i = 0; i < days; i++)
	{
		if ( (arrTemps[i] == warmest) )
		{
			warmestDaysArray[count] = i;
			count++;
		}
	}
}

void dayToDate (int leapYear, int *dayIndex)
{
	/* This function takes in the index of the array and turns it to the 
	 * day of the month with respect to the leap year status. */
	
	int day = *dayIndex;
	day = day + 1;
	
	if ( (leapYear == 1) )
	{
		if ( (day >= 1) && (day <= 31) )
		{
			day = day;
		}
		else if ( (day >= 32) && (day <= 60) )
		{
			day = day - 31;
		}
		else if ( (day >= 61) && (day <= 91) )
		{
			day = day - 60;
		}
		else if ( (day >= 92) && (day <= 121) )
		{
			day = day - 91;
		}
		else if ( (day >= 122) && (day <= 152) )
		{
			day = day - 121;
		}
		else if ( (day >= 153) && (day <= 182) )
		{
			day = day - 152;
		}
		else if ( (day >= 183) && (day <= 213) )
		{
			day = day - 182;
		}
		else if ( (day >= 214) && (day <= 244) )
		{
			day = day - 213;
		}
		else if ( (day >= 245) && (day <= 274) )
		{
			day = day - 244;
		}
		else if ( (day >= 275) && (day <= 305) )
		{
			day = day - 274;
		}
		else if ( (day >= 306) && (day <= 335) )
		{
			day = day - 305;
		}
		else if ( (day >= 336) && (day <= 366) )
		{
			day = day - 335;
		}
	}
	else
	{
		if ( (day >= 1) && (day <= 31) )
		{
			day = day;
		}
		else if ( (day >= 32) && (day <= 59) )
		{
			day = day - 31;
		}
		else if ( (day >= 60) && (day <= 90) )
		{
			day = day - 59;
		}
		else if ( (day >= 91) && (day <= 120) )
		{
			day = day - 90;
		}
		else if ( (day >= 121) && (day <= 151) )
		{
			day = day - 120;
		}
		else if ( (day >= 152) && (day <= 181) )
		{
			day = day - 151;
		}
		else if ( (day >= 182) && (day <= 212) )
		{
			day = day - 181;
		}
		else if ( (day >= 213) && (day <= 243) )
		{
			day = day - 212;
		}
		else if ( (day >= 244) && (day <= 273) )
		{
			day = day - 243;
		}
		else if ( (day >= 274) && (day <= 304) )
		{
			day = day - 273;
		}
		else if ( (day >= 305) && (day <= 334) )
		{
			day = day - 304;
		}
		else if ( (day >= 335) && (day <= 365) )
		{
			day = day - 334;
		}
	}
		
	*dayIndex = day;
		 
	}

const char *dayToMonth (int leapYear, int day)
{
	
	static char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	day = day +1;
	
	if ( (leapYear == 1) )
	{
		if ( (day >= 1) && (day <= 31) )
		{
			return month[0];
		}
		else if ( (day >= 32) && (day <= 60) )
		{
			return month[1];
		}
		else if ( (day >= 61) && (day <= 91) )
		{
			return month[2];
		}
		else if ( (day >= 92) && (day <= 121) )
		{
			return month[3];
		}
		else if ( (day >= 122) && (day <= 152) )
		{
			return month [4];
		}
		else if ( (day >= 153) && (day <= 182) )
		{
			return month[5];
		}
		else if ( (day >= 183) && (day <= 213) )
		{
			return month[6];
		}
		else if ( (day >= 214) && (day <= 244) )
		{
			return month[7];
		}
		else if ( (day >= 245) && (day <= 274) )
		{
			return month[8];
		}
		else if ( (day >= 275) && (day <= 305) )
		{
			return month[9];
		}
		else if ( (day >= 306) && (day <= 335) )
		{
			return month[10];
		}
		else if ( (day >= 336) && (day <= 366) )
		{
			return month[11];
		}
		else
		{
			return "Invalid Date.";
		}
	}
	else
	{
		if ( (day >= 1) && (day <= 31) )
		{
			return month[0];
		}
		else if ( (day >= 32) && (day <= 59) )
		{
			return month[1];
		}
		else if ( (day >= 60) && (day <= 90) )
		{
			return month[2];
		}
		else if ( (day >= 91) && (day <= 120) )
		{
			return month[3];
		}
		else if ( (day >= 121) && (day <= 151) )
		{
			return month[4];
		}
		else if ( (day >= 152) && (day <= 181) )
		{
			return month[5];
		}
		else if ( (day >= 182) && (day <= 212) )
		{
			return month[6];
		}
		else if ( (day >= 213) && (day <= 243) )
		{
			return month[7];
		}
		else if ( (day >= 244) && (day <= 273) )
		{
			return month[8];
		}
		else if ( (day >= 274) && (day <= 304) )
		{
			return month[9];
		}
		else if ( (day >= 305) && (day <= 334) )
		{
			return month[10];
		}
		else if ( (day >= 335) && (day <= 365) )
		{
			return month[11];
		}
		else
		{
			return "Invalid Date.";
		}
	}
}

double summerAveraging (double array[])
{
	
	double sum = 0.0;
	double average;
	int i;
	
	for (i = 171; i < 264; i++)
	{
		sum += array[i];
	}
	
	average = sum / 94.0;
	
	return (average);
	
}

double winterAveraging (double array[])
{
	
	double sum = 0.0;
	double average;
	int i;
	
	for (i = 0; i < 78; i++)
	{
		sum += array[i];
	}
	
	for (i = 354; i < 364; i++)
	{
		sum += array[i];
	}
	
	average = sum / 90.0;
	
	return (average);
	
}

void sortingWithIndex (int n, double array[], int index[])
{
	int i, j;
	double temp1;
	int temp2;
	
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-i-1; j++)
		{
			if (array[j] < array[j+1])
			{
				temp1 = array[j+1];
				array[j+1] = array[j];
				array[j] = temp1;
				
				temp2 = index[j+1];
				index[j+1] = index[j];
				index[j] = temp2;
			}
		}
	}
}
