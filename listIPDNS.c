//********************************************************************
// Jacob Wakefield
// Course: Computer Networks
// Programming Project #1: List IP DNS
// Due date: November 17, 2018 
// Instructor: Dr. Ajay K. Katangur
//********************************************************************

#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>



int main(int argc, char **argv){
    char *subnetMask = argv[1];
    char *dottedIp = argv[2]; 
    unsigned long int max = 4294967295; //max ip 255.255.255.255

    unsigned long int ip = inet_addr(dottedIp);
    unsigned long int subnet = inet_addr(subnetMask);   
    unsigned long int numHosts = max/(subnet & max);   

    unsigned long int network = ip & subnet; //get the network portion of the address
    struct in_addr ans = {network}; //the dotted decimal of the netowrk portion of the address

    printf("getting dns for %s %s\n",subnetMask,dottedIp);
    printf("subnet: %lu\nip: %lu\nnet: %lu\nnet str: %s\nnum hosts: %lu\n",subnet,ip,network,inet_ntoa(ans),numHosts);
    for (int i=0; i<numHosts; i++) {
        unsigned long int addr = ntohl(network);//flip byte order
        addr = addr+i; //increment ip
        addr = htonl(addr); //flip byte order back

        struct in_addr x = {addr};
        printf("%d:\t%s\n",i,inet_ntoa(x));
    }
    
    //TODO: get all of the valid ips from the given subnet
    //TODO: loop through valid ip's and get their dns info 
    //TODO: print out the ip and the host name for each ip.
}