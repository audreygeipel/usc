#include <iostream>
#include <vector>


using namespace std;

int request_number(){
	int i;
	cout << "Enter quantity:" << endl;
	cin >> i;
	return i;
}

char request_command(){
	char command; 
	cin >> command;
	return  command;
}

void print_bill(vector<int> ticketTotals){
	cout << "$" << (ticketTotals[0]*2) << ".00" << endl;
	cout << "$" << (ticketTotals[1]*3) << ".00" << endl;
	cout << "$" << (ticketTotals[2]*5) << ".00" << endl;
	cout << "$" << (ticketTotals[3]*20) << ".00" << endl;
	cout << "$" << (ticketTotals[4]*10) << ".00" << endl;
}

void print_intro(){
	cout << "(A) Students without an activity card	$2.00" << endl;
    cout << "(B) Faculty and staff	$3.00" << endl;
    cout << "(C) USC alumni	$5.00" << endl;
    cout << "(D) UCLA students and alumni	$20.00" << endl;
    cout << "(E) Everyone else	$10.00" << endl;
    cout << "(S) Print tickets and exit" << endl;
}

int main() {
	vector<int> ticketTotals(5,0);
	char type;
	bool cont=true;
	
	print_intro();
	while(cont){
		cout << "Select ticket type, or print ticket(s):" << endl ;
		type = request_command();
	
		switch(type){
			case 'A':
			case 'a':
				ticketTotals[0] += request_number();
				break;
			case 'B':
			case 'b':
				ticketTotals[1] += request_number();
				break;
			case 'C':
			case 'c':
				ticketTotals[2] += request_number();
				break;
			case 'D':
			case 'd':
				ticketTotals[3] += request_number();
				break;
			case 'E':
			case 'e':
				ticketTotals[4] += request_number();
				break;
			case 'S':
			case 's':
				print_bill(ticketTotals);
			    cont = false;
				break;
		}
	}
}
