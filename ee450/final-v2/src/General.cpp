#include <iostream>
#include <fstream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include "General.h"

using namespace std;

General::General (){
  ifstream passfile;
  
  // Read the pass and port from the input file
  passfile.open("input/passGn.txt"); 
  passfile >> this->port >> this->pass;
  passfile.close();
}

General::~General (){
	
}

void General::start (){
  cout << "The <General> has TCP port (" << this->port << ") and IP address 127.0.0.1 for Phase 2" << endl;
 
  // ****
  // getaddrinfo 
  struct addrinfo hints;
  struct addrinfo *major_addrinfo;
  
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  
  getaddrinfo(0, this->port, &hints, &major_addrinfo);
 
  // ****
  // socket      
  int sockfd;
  sockfd = socket(major_addrinfo->ai_family, major_addrinfo->ai_socktype, major_addrinfo->ai_protocol);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // ****
  // bind  
  if (bind(sockfd, major_addrinfo->ai_addr, major_addrinfo->ai_addrlen) == -1) {
    perror("bind");
    exit(1);
  }

  // ****
  // listen  
  if (listen(sockfd, 10) == -1) {
    perror("listen");
    exit(1);
  }

  // ****
  // accept
  int new_fd;
  struct sockaddr_storage captain_sockaddr;
  int captain_sockaddr_len = sizeof(captain_sockaddr);
  char message[1000];
  memset(&message, 0, sizeof message);

  while(1){
    new_fd = accept(sockfd, (struct sockaddr *)&captain_sockaddr, (socklen_t *) &captain_sockaddr_len);

    recv(new_fd, message, 1000, 0);
    cout << "Received the password from <Major>" << endl;
    close(new_fd);

    if (parse_message(message)){
      break;
    } else {
      cout << "Wrong password from <Major>, try again" << endl;
    }
  }

  cout << "Correct password from <Major>" << endl;
  
  cout << "End of Phase 2 for <General>" << endl;

  // ****
  // close
  close(sockfd);
}

// Returns true if the message has the correct password and the data
//
// Message format ():
//     passwd-int-int
bool General::parse_message (char* message){
  char * pch = strtok(message, "-");

  // Check for the password
  if (string(pch) != string(this->pass)){
    return false;
  } 

  pch = strtok(0, "-");
  this->success_rates[0] = atoi(pch);

  pch = strtok(0, "-");
  this->success_rates[1] = atoi(pch);

  return true;
}

