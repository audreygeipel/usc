#ifndef NETWORK_H
#define NETWORK_H

#include "user.h"
#include <vector>

class Network {
	public:	
		std::vector<User> users;
		int num_of_users;
	
		void import_users(char *);
		void export_users(char *);
		void add_user(char *, int, int);
		
		int add_connection(char *, char *);
		int remove_connection(char *, char *);
		int get_user_id(char *);
		
		User *get_user(char *);
	  void print_user(int);
	  void print_friends_of_user(char *);
	  void print_users();
	  
	  Network();
	  ~Network();
};


#endif
