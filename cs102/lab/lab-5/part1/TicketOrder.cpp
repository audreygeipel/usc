#include "TicketOrder.h"
#include <iostream>

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

std::string TicketOrder::print_type(){
	switch(type){
			case A:
				return "A" ;
			case B:
				return "B" ;
			case C:
				return "C" ;
			case D:
				return "D" ;
			case E:
				return "E" ;
	}
}

int TicketOrder::get_quantity(){
	return quantity;
}

std::ostream& operator<<(std::ostream& out, TicketOrder& to){
  out << "You succesfully ordered " << to.get_quantity() << " tickets of type " << to.print_type();  
  return out;
}
