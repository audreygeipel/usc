#include "TicketOrder.h"

TicketOrder::TicketOrder(){

}

TicketOrder::~TicketOrder(){

}

void TicketOrder::create(TType type, int quantity){
	this->type = type;
	this->quantity = quantity;
}

int TicketOrder::total_cost(){
	switch(type){
			case A:
				return quantity * 2 ;
			case B:
				return quantity * 3 ;
			case C:
				return quantity * 5 ;
			case D:
				return quantity * 20 ;
			case E:
				return quantity * 10 ;
	}
}

TType TicketOrder::get_type(){
	return type;
}

int TicketOrder::get_quantity(){
	return quantity;
}
