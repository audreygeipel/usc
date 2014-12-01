#include <iostream>
#include <sstream>
#include <fstream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "Major.h"

using namespace std;

Major::Major (char* port){
  this->port = port;

  ifstream passfile;
  
  // Read the pass and port from the input file
  passfile.open("input/passMj.txt"); 
  passfile >> this->general_port >> this->general_pass;
  passfile.close();
}

Major::~Major (){
	
}

void Major::start (){
  cout << "<Major> has UDP port (" << this->port
       << ") and IP address 127.0.0.1 for Phase 1" << endl;
 
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
  int sockfd = socket(major_addrinfo->ai_family, major_addrinfo->ai_socktype, major_addrinfo->ai_protocol);
  
  // ****
  // bind & listen  
  bind(sockfd, major_addrinfo->ai_addr, major_addrinfo->ai_addrlen);
  listen(sockfd, 10);

  // ****
  // build captain_sockaddr
  struct sockaddr_storage captain_sockaddr;
  int captain_sockaddr_len = sizeof(captain_sockaddr);
  char message[1000];

  // ****
  // recvfrom
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

  // Continue phase 2
  send_rates_to_general();
}

void Major::send_rates_to_general(){
  // ****  
  // socket      
  int sockfd;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // ****
  // build general_sockaddr
  struct sockaddr_in general_sockaddr;
  memset(&general_sockaddr, 0, sizeof general_sockaddr);
  general_sockaddr.sin_family = AF_INET;
  general_sockaddr.sin_port = htons(atoi(this->general_port));
  inet_pton(AF_INET, "127.0.0.1", &general_sockaddr.sin_addr);

  // create message
  stringstream message;
  message << this->general_pass << "-";
  message << this->captain_datas[0].success_rate << "-";
  message << this->captain_datas[1].success_rate ;

  // connect 
  connect(sockfd, (struct sockaddr *)&general_sockaddr, sizeof(general_sockaddr));

  // send 
  send(sockfd, (char*) message.str().c_str(), 100, 0);
}

// Parses and saves the message received from the captain socket.
//
// Message format:
//     C$1-Resources$3-Confidance$6
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

  // Calculate the success rate of the captain
  captain_data.success_rate = 5*captain_data.resources;
  captain_data.success_rate += 3*captain_data.confidance;
  if (captain_data.captain_id == 1) {
    captain_data.success_rate += 2 * 8;
  } else {
    captain_data.success_rate += 2 * 9;
  }

  captain_datas[captain_data.captain_id - 1] = captain_data;
  cout << "<Major> is now connected to the Captain#" << captain_data.captain_id << endl;
}

// Returns true if major has recieved the correct messages from the two captains
// otherwise returns false.
bool Major::is_captain_data_complete() {
  if(captain_datas[0].captain_id == 1 && captain_datas[1].captain_id == 2){
    return true;
  } else {
    return false;
  }
}

// Prints the data received from the captains.
void Major::print_captain_data(){
  cout << "<Major> has received following:" << endl;
  
  for (int i=0; i<2; i++){
    cout << "  " << i+1 << ". " << "Captain#" << captain_datas[i].captain_id << ": ";
    cout << "Resources - " << captain_datas[i].resources << ", ";
    cout << "Confidence - " << captain_datas[i].confidance << endl;
  }
}
