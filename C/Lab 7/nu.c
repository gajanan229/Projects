#include <stdio.h>
#include <string.h>
#include <ctype.h>


void strip (char original[], char stripped[]){
    int max = strlen(original);
    int i;
    for(i=0;i<max;i++){
        char t =original[i];
        int n=0;
        if (isalpha(t) && isupper(t)){
            t = tolower(t);
        }
        stripped[i] = t;
    }
    int j=0,k,good;
    while(stripped[j]!='\0') {
      good=0;
      if(stripped[j]==' '||ispunct(stripped[j])) {
         k=j;
         while(stripped[k-1]!='\0') {
            stripped[k] = stripped[k+1];
            k++;
         }
         good = 1;
      }
      if(good==0)
      j++;
   }
   stripped[j]='\0';
}
void reverse(char original[],char reversed[]){ 
  static int i = 0;
  long int len = strlen(original);
  if (i <= len) {
    reversed[i] = original[len - 1 - i];
    i++;
    reverse(original, reversed);
  }
}

int main()
{
    char array[50];
    printf("Enter your statement: ");
    fgets(array,sizeof(array),stdin);
    char stripped[50];
    char reversed[50];
    strip (array,stripped);
    printf("The string after being striped of spaces and punctuation: %s \n", stripped);
    reverse (stripped, reversed);
    printf("The string after being reversed: %s\n", reversed);
    int len=strlen(stripped),i,look;
    if(strcmp(stripped,reversed)==0){
        printf("This string is a palindrome");
    }
    else{
        printf("This string is not a palindrome");
    }

    return 0;
}
