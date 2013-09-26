#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <sys/types.h>
#include <string>
#include <unistd.h>
#include <fstream>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>



using namespace std;
int main( int argc, char *argv[] )

{

	// Vars
	 string manu;
	 manu = "usage: randfuzz server port \n example: ./randfuzz google.com 80 \n";
	// End of Vars
	 
	  if ( argc != 3 )
   
    	{
        	system("clear");
        	cout << manu;
        	return 1;
        	
    	}
    	
      
     //  Main Code goes here:
    int portno = atoi(argv[2]);
  
  	// Make the Socket
  	
    char buf[1000]; 
    struct sockaddr_in client; 
    int sock_desc,k; 
    sock_desc = socket(AF_INET,SOCK_STREAM,0);
    memset(&client,0,sizeof(client)); 
    client.sin_family = AF_INET; 
    client.sin_addr.s_addr = inet_addr(argv[1]); 
    client.sin_port = htons(portno); 
    k = connect(sock_desc,(struct sockaddr*)&client,sizeof(client)); 
  	// Socket made
 

      
	for(;;)
	{
	//usleep (10000);
	ofstream myfile;
    myfile.open ("/dev/random");
    k = send(sock_desc,myfile,1000,0);
    if(strcmp(buf,"exit")==0)         
            break; 
    myfile.close();
//    close(sock_desc);
//    k = connect(sock_desc,(struct sockaddr*)&client,sizeof(client)); 
	}
 
//  	  while(1)
//    {     
//        //gets(buf);     
//        k = send(sock_desc,buf,100,0);     
//        if(strcmp(buf,"exit")==0)         
//            break; 
//    } 
   	
  	// Close socket
  	close(sock_desc); 
  	// Socket Closed
 
  return 0;
}      		
      	
      	
   
    
   
    