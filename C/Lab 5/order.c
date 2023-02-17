#include <stdio.h>

int
order(int n1, int n2, int n3)
{
    int od1, od2, od3, ods, ods1; 
    if (n1>n2){
        od1=n1;
        od3=n2;
    }
    else{
        od1=n2;
        od3=n1;
    }
    if (n3>od1){
        od2=od1;
        od1=n3;
    }
    else if(n3>od3){
        od2=n3;
    }
    else{
        od2=od3;
        od3=n3;
    }
    printf("%d,%d,%d", od1, od2, od3);
}


int main()
{
    int nm1, nm2, nm3;  
    printf("enter 3 integers: ");
    scanf("%d ", &nm1);
    scanf("%d ", &nm2);
    scanf("%d ", &nm3);
    order (nm1,nm2,nm3);
}
