#include <iostream>
#include <fstream>
#include <sstream>

#include <sys/socket.h>
#include <arpa/inet.h>

#include "Captain.h"

using namespace std;

Captain::Captain (int id, char* major_port) {
  this->id = id;
  this->major_port = atoi(major_port);
}

Captain::~Captain () {

}

void Captain::start () {

  // ****  
  // socket      
  int sockfd;
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);

  char* message = create_message();
  struct sockaddr_in major_sockaddr;

  // ****
  // build major_sockaddr
  memset(&major_sockaddr, 0, sizeof major_sockaddr);
  major_sockaddr.sin_family = AF_INET;
  major_sockaddr.sin_port = htons(this->major_port);
  inet_pton(AF_INET, "127.0.0.1", &major_sockaddr.sin_addr);

  // ****
  // sendto
  cout << "Sending log file to the <Major>" << endl;
  sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&major_sockaddr, sizeof(major_sockaddr));

  // ****
  // getsockname
  struct sockaddr_in captain_sockaddr;  
  int captain_addrlen = sizeof(captain_sockaddr);
  getsockname(sockfd,(struct sockaddr *)&captain_sockaddr, (socklen_t *) &captain_addrlen);  
  cout << "<Captain#" << this->id  << "> has UDP port (" << ntohs(captain_sockaddr.sin_port);
  cout << ") and IP address 127.0.0.1" << endl;

  cout << "End of Phase 1 for <Captain#" << this->id << ">" << endl;
}


// Returns a message created using captain's own input file.
// 
// Input files:
//     ./input/Captain1.txt
//     ./input/Captain2.txt
// 
// File format:    
//     Resources$9
//     Confidence$5
// 
// Output:
//     C$1-Resources$3-Confidance$6
char* Captain::create_message(){
  ifstream logfile;
  string line0, line1, line2;
  stringstream message;

  if (this->id == 1){
    logfile.open ("input/Captain1.txt"); 
  } else {
    logfile.open ("input/Captain2.txt"); 
  }

  logfile >> line1;
  logfile >> line2;

  message << "C$" << this->id;
  message << "-" << line1;
  message << "-" << line2;

  return (char*) message.str().c_str();
}
