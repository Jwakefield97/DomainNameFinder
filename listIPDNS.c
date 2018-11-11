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

    unsigned long int ip = inet_addr(dottedIp);
    unsigned long int subnet = inet_addr(subnetMask);   
    unsigned long int calc = ip & subnet; //get the network portion of the address
    struct in_addr ans = {calc}; //the dotted decimal of the netowrk portion of the address

    printf("getting dns for %s %s\n",subnetMask,dottedIp);
    printf("subnet: %lu\nip: %lu\nnet: %lu\nnet str: %s\nnum hosts: %lu\n",subnet,ip,calc,inet_ntoa(ans),subnet-calc);
    
    //TODO: get all of the valid ips from the given subnet
    //TODO: loop through valid ip's and get their dns info 
    //TODO: print out the ip and the host name for each ip.
}