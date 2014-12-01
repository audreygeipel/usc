#include <string>
#include "user.h"

User::User(char *myname, int myyear, int myzip){
	strcpy(user_name, myname);
	birth_year = myyear;
	zip_code = myzip;
	num_of_friends = 0;
}

User::~User(){

}

void User::add_friend(int friend_id){
	friend_connections.push_back(friend_id);
	num_of_friends = friend_connections.size();
}

void User::delete_friend(int friend_id){
	int i;
	for(i=0; i<num_of_friends; i++){
		if (friend_connections[i] == friend_id){
			friend_connections.erase(friend_connections.begin() + i);
			break;
		}
	}
	num_of_friends = friend_connections.size();
}

char *User::get_user_name(){
	return user_name;
}

int *User::get_user_id(){
	return &id;
}

int *User::get_birth_year(){
	return &birth_year;	
}

int *User::get_zip_code(){
	return &zip_code;
}
