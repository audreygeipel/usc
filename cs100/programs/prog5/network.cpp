#include <iostream>
#include <iomanip>
#include <fstream>
#include "user.h"
#include "network.h"

using namespace std;

Network::Network(){
	num_of_users = 0;
}

Network::~Network(){

}

void Network::import_users(char *file_name){
	int i, data_size, id, birth_year, zip_code, friend_id;;
	ifstream data_file(file_name, ifstream::in);
	char first[80], last[80];
	
	if(!data_file.good()){
		cout << "Please enter a valid file name as a command line argument" << endl;
		exit(1);
	}
	
	data_file >> data_size;

	for(i=0; i<data_size; i++){
		while(data_file.get() != '\n');
		data_file >> id;
		while(data_file.get() != '\t'); 
		data_file >> first >> last;
		while(data_file.get() != '\t'); 
		data_file >> birth_year;
		while(data_file.get() != '\t'); 
		data_file >> zip_code;
		while(data_file.get() != '\t'); 
		add_user(strcat(strcat(first, " "), last), birth_year, zip_code);

		while(data_file.peek() != '\n'){
			data_file >> friend_id;
			users[i].friend_connections.push_back(friend_id);
		}
		users[i].num_of_friends = users[i].friend_connections.size();
	}	
	
}

void Network::export_users(char *file_name){
	int i, j;
	ofstream data_file(file_name, ifstream::out);
		
	data_file << num_of_users << endl;
	 	
	for(i=0; i<num_of_users; i++){
		data_file << users[i].id << endl;
		data_file << "\t" << users[i].user_name << endl;
		data_file << "\t" << users[i].birth_year << endl;
		data_file << "\t" << users[i].zip_code << endl;
		data_file << "\t";
		for(j=0; j<users[i].num_of_friends; j++){
			data_file << users[i].friend_connections[j];
			if (j != (users[i].num_of_friends-1))
				data_file << " ";
		}
		data_file << endl;
	}	
}

void Network::add_user(char *user_name, int birth_year, int zip_code){
	User new_user(user_name, birth_year, zip_code);
	new_user.id = users.size()+1;
	users.push_back(new_user);
	num_of_users = users.size();
}

int Network::add_connection(char *user_name1, char *user_name2){
	if (get_user_id(user_name1) == -1 || get_user_id(user_name2) == -1){
		return -1;
	}
	users[get_user_id(user_name1) - 1].add_friend(get_user_id(user_name2));
	users[get_user_id(user_name2) - 1].add_friend(get_user_id(user_name1));
	return 1;
}

int Network::remove_connection(char *user_name1, char *user_name2){
	if (get_user_id(user_name1) == -1 || get_user_id(user_name2) == -1){
		return -1;
	}
	users[get_user_id(user_name1) - 1].delete_friend(get_user_id(user_name2));
	users[get_user_id(user_name2) - 1].delete_friend(get_user_id(user_name1));
	return 1;
}

int Network::get_user_id(char *user_name){
	if(get_user(user_name)){
		return get_user(user_name)->id;
	}
	return -1;
}

User *Network::get_user(char *user_name){
	int i;
	for(i=0; i<num_of_users; i++){
		if(!strcmp(user_name, users[i].user_name)){
			return &users[i];
		}
	}
	return false;
}

void Network::print_users(){
	int i;
	for(i = 1; i <= num_of_users; i++){
		print_user(i);
	}
}

void Network::print_friends_of_user(char *user_name){
	User *user;
	int i;

	user = get_user(user_name);
	
	for(i=0; i < user->num_of_friends; i++){
		print_user(user->friend_connections[i]);
	}
}

void Network::print_user(int user_id){
	User *user;
	
	user = &users[user_id - 1];
	cout << setw (5) << left << user->id << setw (25) << left << user->user_name << setw (10);
	cout << user->birth_year << setw (10) << user->zip_code << endl;
}
