#ifndef TICKETORDER_H
#define TICKETORDER_H

enum TType {A, B, C, D, E};

class TicketOrder {
	TType type;
	int quantity;

	public:
		void create(TType, int);
		int total_cost();
		TType get_type();
		int get_quantity();		

		TicketOrder();
		~TicketOrder();
};

#endif
