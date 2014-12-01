#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include "Major.h"

using namespace std;

Major::Major (char* port){
	this->port = port;
}

Major::~Major (){
	
}

void Major::start (){
	cout << "<Major> has UDP port (" << this->port << ") and IP address 127.0.0.1 for Phase 1" << endl;
 
  // ****
  // getaddrinfo 
  struct addrinfo hints;
  struct addrinfo *major_addrinfo;
  
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_DGRAM;
  
  getaddrinfo(0, this->port, &hints, &major_addrinfo);
 
  // ****
  // socket      
  int sockfd;
  sockfd = socket(major_addrinfo->ai_family, major_addrinfo->ai_socktype, major_addrinfo->ai_protocol);
  
  // ****
  // bind & listen  
  bind(sockfd, major_addrinfo->ai_addr, major_addrinfo->ai_addrlen);
  listen(sockfd, 10);

  // ****
  // recvfrom
  struct sockaddr_storage captain_sockaddr;
  int captain_sockaddr_len = sizeof(captain_sockaddr);
  char message[1000];

  while(1){
    recvfrom(sockfd, message, 1000, 0, (struct sockaddr *)&captain_sockaddr, (socklen_t *) &captain_sockaddr_len);
    parse_and_save_captain_message(message);
    if (is_captain_data_complete()){
      break;
    }
  }
  
  print_captain_data();

	cout << "End of Phase 1 for <Major>" << endl;
  
  // ****
  // close
  close(sockfd);
}

void Major::parse_and_save_captain_message(char captain_message[]){
  char * pch;
  captain_data captain_data;
  pch = strtok(captain_message, "$-");
  while(pch){
    if (string(pch) == "C"){
      pch = strtok(0, "$-");
      captain_data.captain_id = pch[0] - '0';
    } else if (string(pch) == "Resources"){
      pch = strtok(0, "$-");
      captain_data.resources = pch[0] - '0';
    } else if (string(pch) == "Confidence"){
      pch = strtok(0, "$-");
      captain_data.confidance = pch[0] - '0';
    }
    pch = strtok(0, "$-");
  }
  captain_datas[captain_data.captain_id - 1] = captain_data;
  cout << "<Major> is now connected to the Captain#" << captain_data.captain_id << endl;
}

bool Major::is_captain_data_complete() {
  if(captain_datas[0].captain_id == 1 && captain_datas[1].captain_id == 2){
    return true;
  } else {
    return false;
  }
}

void Major::print_captain_data(){
  cout << "<Major> has received following:" << endl;
  for (int i=0; i<2; i++){
    cout << "  " << i+1 << ". " << "Captain#" << captain_datas[i].captain_id << ": ";
    cout << "Resources - " << captain_datas[i].resources << ", ";
    cout << "Confidence - " << captain_datas[i].confidance << endl;
  }
}
