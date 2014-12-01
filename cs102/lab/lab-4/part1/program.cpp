#include <iostream>
#include <vector>
#include "TicketOrder.h"

using namespace std;


int request_number(){
	int i;
	try {
	  cout << "Enter quantity:" << endl;
    cin >> i;
  } catch (iostream::failure &ex){
    cin.clear();
    cin.ignore(1000,'\n');
    cout << "Bad input!" << endl;
    return request_number();
  } 
	return i;
}

int request_command(){
	int command; 
  try {
    cin >> command;
  } catch (iostream::failure &ex){
    cin.clear();
    cin.ignore(1000, '\n');
  }
	return	command;
}

void print_bill(vector<TicketOrder> ticketTotals){
	int total[5] = {0,0,0,0,0}, quantity[5] = {0,0,0,0,0};	
	
	for(unsigned int k=0; k<ticketTotals.size(); k++){
			cout << "deneme" << endl;
			switch(ticketTotals[k].get_type()){
				case A:
					total[0] += ticketTotals[k].total_cost();
					quantity[0] += ticketTotals[k].get_quantity();
					break;
				case B:
					total[1] += ticketTotals[k].total_cost();
					quantity[1] += ticketTotals[k].get_quantity();
					break;
				case C:
					total[2] += ticketTotals[k].total_cost();
					quantity[2] += ticketTotals[k].get_quantity();
					break;
				case D:
					total[3] += ticketTotals[k].total_cost();
					quantity[3] += ticketTotals[k].get_quantity();
					break;
				case E:
					total[4] += ticketTotals[k].total_cost();
					quantity[4] += ticketTotals[k].get_quantity();
					break;
			}
	}	
	
	cout << quantity[0] << " tickets costs $" << total[0] << ".00" << endl;
	cout << quantity[1] << " tickets costs $" << total[1] << ".00" << endl;
	cout << quantity[2] << " tickets costs $" << total[2] << ".00" << endl;
	cout << quantity[3] << " tickets costs $" << total[3] << ".00" << endl;
	cout << quantity[4] << " tickets costs $" << total[4] << ".00" << endl;
}

void print_intro() {
		cout << "(0) Students without an activity card	$2.00" << endl;
		cout << "(1) Faculty and staff	$3.00" << endl;
		cout << "(2) USC alumni	$5.00" << endl;
		cout << "(3) UCLA students and alumni	$20.00" << endl;
		cout << "(4) Everyone else	$10.00" << endl;
		cout << "(5) Print tickets and exit" << endl;
}

int main() {
	vector<TicketOrder> tickets;
	TicketOrder new_ticket_order;
	int type;
	bool cont=true;

  cin.exceptions(iostream::failbit);
	
	print_intro();
	while(cont){
		cout << "Select ticket type, or print ticket(s):" << endl ;
		type = request_command();
	
		switch(type){
			case 0:
				new_ticket_order.create(A, request_number());
				tickets.push_back(new_ticket_order);
				break;
			case 1:
				new_ticket_order.create(B, request_number());
				tickets.push_back(new_ticket_order);
				break;
			case 2:
				new_ticket_order.create(C, request_number());
				tickets.push_back(new_ticket_order);
				break;
			case 3:
				new_ticket_order.create(D, request_number());
				tickets.push_back(new_ticket_order);
				break;
			case 4:
				new_ticket_order.create(E, request_number());
				tickets.push_back(new_ticket_order);
				break;
			case 5:
				print_bill(tickets);
				return 0;
				break;
      default:
        cout << "Error!" << endl;
        return 0;
        break;
		}
	}
}
