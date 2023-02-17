#include<stdio.h>
int main()
{
int ln
int empnum, shfnum, i,j; 
int hw = 0, tot = 0;
double bwr, pay; 

FILE *epinfo;
epinfo = fopen("epinfo.txt","r");

for(j=1; j<= 8; j++){
fscanf(epinfo,"%d,", &empnum);
printf("Employee number: %d \n", empnum);
fscanf(epinfo,"%d,", &shfnum);
printf("number of shifts: %d \n", shfnum);
fscanf(epinfo,"%lf,", &bwr);
printf("base wage rate: %.2lf \n", bwr);
for(i=1; i<=shfnum; i++){
	fscanf(epinfo,"%d,", &hw);
	printf("Hours worked shift number %d: %d \n", i, hw);
	tot = tot + hw;
}
printf("%d \n", tot);

if(tot<=15){
	pay = bwr*tot;
}
else if(tot<=25){
	pay=1.05*(bwr*tot);
}
else if(tot>25){
	pay=1.1*(bwr*tot);
}
printf("Gross pay: %.2lf \n", pay);
}

fclose(epinfo);


return 0;
}

