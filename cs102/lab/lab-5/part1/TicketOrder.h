#ifndef TICKETORDER_H
#define TICKETORDER_H

#include <iostream>

enum TType {A, B, C, D, E};

class TicketOrder {
	TType type;
	int quantity;

	public:
		void create(TType, int);
		int total_cost();
		TType get_type();
    std::string print_type();
		int get_quantity();		

		TicketOrder();
		~TicketOrder();
};

std::ostream& operator<<(std::ostream& out, TicketOrder& to);

#endif
