#include <stdio.h>
#include <string.h>



int main(int argc, char **argv){
    char *subnetMask = argv[1];
    char *dottedIp = argv[2]; 
    printf("getting dns for %s %s",subnetMask,dottedIp);
}