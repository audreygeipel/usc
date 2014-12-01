++++++++++++++++++
++ Author : Oguz Bilgic
++ Date	  : 08-November-2010
++ Project: CS 100 - Programing Assignment #5 - The Social Network I
++++++++++++++++++


Known Bugs:
	1. Inputs are case sensitive
	2. Program does not check user inputs

Design Choices:
	a. User Class:
		1. std::vector<int> friend_connections
			I used vector class to create friend_connections array.
	b. Network Class: I added extra function to this class. These functions are:
		1. User *get_user(char *)
			This function return user pointer for given username.
		2. void print_user(int)
			This function prints user data for given user id.
		3. void print_friends_of_user(char *)
			This function prints all the friends of given user.
		4. void print_users()
			This function prints all the users in the network.
	c. Social Network:
		1. show_menu() :
			- I created a function called show_menu. 
			- This function shows the menu then waits for the user to write a command.
			- When user writes the command, function execute this command. Then function calls itself.