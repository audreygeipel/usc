#ifndef USER_H
#define USER_H

#include <vector>

class User {
	public:
		int id;
		char user_name[80];
		int birth_year;
		int zip_code;
		int num_of_friends;
		std::vector<int> friend_connections;
	
		void add_friend(int);
		void delete_friend(int);
		
		char *get_user_name();
		int *get_user_id();
		int *get_birth_year();
		int *get_zip_code();
		
	  User(char *user_name, int birth_year, int zip_code);
	  ~User();
};

#endif
