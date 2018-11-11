# listIPDNS

## explanation 
    A subnet mask and IP are first passed into the program. They are then pasred into network address 
    (unsigned long int). The network address is then found by doing (subnet & IP) number of hosts 
    are then caclulated by doing maxIP/(subnet mask & ip). The number of hosts and network portion
    of the ip is then passed into a function that loops (until the number of hosts is reached),
    increments the ip, and prints the host name found for that ip in the subnet and "no host name found"
    for ip's that does not have a domain name.

## build/run
* run the command ``make``, ``make all``, ``make fresh``, or ``make listIPDNS`` to compile the project. 
* to clean the project run ``make clean``. 
* to run the project run ``./listIPDNS <subnet> <ip>`` or to run it on google run ``make run``.
* to pack the project into a tar run ``make pack``. 

## directory contents
* listIPDNS.c - the source code of the project. 
* README.md - the markdown file containing information about the project.
* MakeFile - the make file used to build/run/pack the project.