//********************************************************************
// Jacob Wakefield
// Course: Computer Networks
// Programming Project #1: List IP DNS
// Due date: November 17, 2018 
// Instructor: Dr. Ajay K. Katangur
//********************************************************************

#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char **argv){
    char *subnetMask = argv[1];
    char *dottedIp = argv[2]; 
    unsigned long int max = 4294967295; //max ip 255.255.255.255

    unsigned long int ip = inet_addr(dottedIp);
    unsigned long int subnet = inet_addr(subnetMask);   
    unsigned long int numHosts = max/(subnet & max);   
    unsigned long int network = ip & subnet; //get the network portion of the address
   
    for (int i=0; i<numHosts; i++) {
        unsigned long int addr = ntohl(network);//flip byte order
        addr = addr+i; //increment ip
        addr = htonl(addr); //flip byte order back
        struct in_addr addr_in = {addr};
        struct hostent *info;
        info = gethostbyaddr((char *) &addr_in, 4, AF_INET); //get host struct
        if(info != NULL){
            printf("%s:\t%s\n",inet_ntoa(addr_in),info->h_name); //if found print out host name
        }else{
            printf("%s:\tno host name found\n",inet_ntoa(addr_in)); //if null print out no host found
        }
    }
}