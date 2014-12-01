#include <iostream>
#include <vector>
#include "TicketOrder.h"
#include "BadInput.h"

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
  
  if (i <= 0){
    BadInput err;
    err.set_value(i);
    throw err;
  } 
	return i;
}

int request_command(){
	int command; 

  try {
		cout << "Select ticket type, or print ticket(s):" << endl ;
    cin >> command;
  } catch (iostream::failure &ex){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Bad input!" << endl;
    return request_command();
  }
  
  if (command < 0 || command >5){
    BadInput err;
    err.set_value(command);
    throw err;
  }

	return	command;
}

void print_bill(vector<TicketOrder> ticketTotals){
	int total[5] = {0,0,0,0,0}, quantity[5] = {0,0,0,0,0};	
	
	for(unsigned int k=0; k<ticketTotals.size(); k++){
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
	int type, quantity;
	bool cont=true;

  cin.exceptions(iostream::failbit);
	
	print_intro();
	while(cont){

    try {
      type = request_command();
    } catch (BadInput &err) {
      cout << "Invalid menu option : " << err.get_value() << endl;
      cout << "Command is aborted!" << endl;
      continue;
    }

    try {
      quantity = request_number();
    } catch (BadInput &err) {
      cout << "Invalid quantity : " << err.get_value() << endl;
      cout << "Command is aborted!" << endl;
      continue;
    }

		switch(type){
			case 0:
				new_ticket_order.create(A, quantity);
				tickets.push_back(new_ticket_order);
				break;
			case 1:
				new_ticket_order.create(B, quantity);
				tickets.push_back(new_ticket_order);
				break;
			case 2:
				new_ticket_order.create(C, quantity);
				tickets.push_back(new_ticket_order);
				break;
			case 3:
				new_ticket_order.create(D, quantity);
				tickets.push_back(new_ticket_order);
				break;
			case 4:
				new_ticket_order.create(E, quantity);
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
