#include <stdio.h>

struct address_t{
     int aa;
     int bb;
     int cc;
     int dd;
     char nickname[15];
};
int localnet(struct address_t ip1,struct address_t ip2){
    if (ip1.aa == ip2.aa && ip1.bb == ip2.bb){
        return 1;
    }
    return 0;
}
int main()
{
   int i=0;
   struct address_t iplist[300];
   FILE *data= fopen("L8_ip.txt", "r");
   while(!feof(data)){
       fscanf(data,"%d.%d.%d.%d %s",&iplist[i].aa,&iplist[i].bb,&iplist[i].cc,&iplist[i].dd,&iplist[i].nickname);
       printf("%d.%d.%d.%d %s \n",iplist[i].aa,iplist[i].bb,iplist[i].cc,iplist[i].dd,iplist[i].nickname);
       i++;
   }
   for(int j=0;j<i;j++){
       for(int k=j+1;k<i;k++){
           int result = localnet(iplist[j],iplist[k]);
           if (result==1){
               printf("Servers %s and %s are on the same local network \n",iplist[j].nickname, iplist[k].nickname);
           }
       }
   }
    return 0;
}
