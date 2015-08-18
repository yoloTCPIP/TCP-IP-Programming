#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

main(){

  FILE *fp;
  char *token;
  char returnData[64];
  char arr[80][80];
  int i=0;

  fp = popen("/sbin/ifconfig eth0", "r");

  while (fgets(returnData, 64, fp) != NULL){
    token=strtok(returnData," :"); 
        while(token!=NULL){
            strcpy(arr[i],token);
            i++;
        token=strtok(NULL," :");
        }
  }

printf("The Ethernet is : %s\n",arr[0]);
printf("The IP address is : %s\n",arr[14]);
pclose(fp);
}
