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
#include <sys/socket.h>

//struct to hold the number of hosts and the network portion of an address
struct subnet_struct {
    unsigned long int networkAddr; //network portion of the address
    unsigned long int numHosts;    //number of hosts in the network
};

//********************************************************************
//
// Find and Print Host Names Function
//
// This function finds all of the domain names for the ip addresses in 
// a given subnet and prints them.
//
// Return Value
// ------------
// Void                  
//
// Value Parameters
// ----------------
// numHosts     unsigned long int   The number of hosts in the subnet.
// networkAddr  unsigned long int   The network portion of the address.
//
// Reference Parameters
// --------------------
// None
//
// Local Variables
// ---------------
// addr         unsigned long int   The network address of the current ip in the for loop.
// info         hostent*            The struct to store the dns info.
//
//*******************************************************************
void findAndPrintHostNames(unsigned long int numHosts, unsigned long int networkAddr) {
    for (int i=0; i<numHosts; i++) {
        unsigned long int addr = ntohl(networkAddr);//flip byte order
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

//********************************************************************
//
// Get Network Address Function
//
// This function gets the network portion of an address as well as
// the number of hosts in the network. 
//
// Return Value
// ------------
// Void                  
//
// Value Parameters
// ----------------
// None
//
// Reference Parameters
// --------------------
// subnetMask   char*                   The subnet mask of the network in dotted decimal.
// dottedIp     char*                   The IP address in dotted decimal.
// subnet_s     struct subnet_struct    The struct to store the results in.
//
// Local Variables
// ---------------
// max          unsigned long int       The max number for ip addresses i.e. 255.255.255.255
// ip           unsigned long int       The ip address in network form.
// subnet       unsigned long int       The subnet mask in network form.
//
//*******************************************************************
void getNetworkAddr(char *subnetMask, char *dottedIp, struct subnet_struct *subnet_s) {
    unsigned long int max = 4294967295; //max ip 255.255.255.255
    unsigned long int ip = inet_addr(dottedIp);
    unsigned long int subnet = inet_addr(subnetMask);   
    subnet_s->networkAddr = ip & subnet;
    subnet_s->numHosts = max/(subnet & max);
}
     
int main(int argc, char **argv) {
    char *subnetMask = argv[1];
    char *dottedIp = argv[2]; 

    struct subnet_struct subnet;

    getNetworkAddr(subnetMask,dottedIp,&subnet); //get the number of hosts and the network portion of the address

    findAndPrintHostNames(subnet.numHosts,subnet.networkAddr); //print out all of the host names for the hosts in the ip
}