#include <iostream>
#include <fstream>
#include "user.h"
#include "network.h"

using namespace std;

// Main network variable
Network network;

void show_menu(int show_info){
	
	int option, birth_year, zip_code;
	char first[50], last[50], first2[50], last2[50], filename[100];
	
	if (show_info){
		cout << "MENU OPTIONS" << endl
				 << "--------------------" << endl
				 << "1. Add user" << endl
				 << "2. Add friend connection" << endl
				 << "3. Delete friend connection" << endl
				 << "4. Print Users" << endl
				 << "5. Print Friends of User" << endl
				 << "6. Export data" << endl
				 << "7. Exit" << endl
				 << "--------------------" << endl;
	}
	
	cout << "Enter Command : ";
	cin >> option;
	
	switch(option){
		case 1:
			cin >> first >> last >> birth_year >> zip_code;
			network.add_user(strcat(strcat(first, " "), last), birth_year, zip_code);
			cout << "User is added" << endl
					 << "--------------------" << endl;
			break;
		case 2:
			cin >> first >> last >> first2 >> last2;
			network.add_connection(strcat(strcat(first, " "), last), strcat(strcat(first2, " "), last2));
			cout << "Connection is created" << endl
					 << "--------------------" << endl;
			break;
		case 3:
			cin >> first >> last >> first2 >> last2;
			network.remove_connection(strcat(strcat(first, " "), last), strcat(strcat(first2, " "), last2));
			cout << "Connection is deleted" << endl
					 << "--------------------" << endl;
			break;
		case 4:
			cout << "Users:" << endl;
			network.print_users();
			cout << "--------------------" << endl;
			break;
		case 5:
			cin >> first >> last;
			cout << "Friends of User:" << endl;
			network.print_friends_of_user(strcat(strcat(first, " "), last));
			cout << "--------------------" << endl;
			break;
		case 6:
			cin >> filename;
			network.export_users(filename);
			cout << "Data is exported to a file" << endl
					 << "--------------------" << endl;
			break;
		case 7:
			return;
			break;
	}
	show_menu(0);
}

int main(int argc, char *argv[]){
	network.import_users(argv[1]);
	
	show_menu(1);
  return 0;
}
