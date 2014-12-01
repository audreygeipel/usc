#include "BadInput.h"

BadInput::BadInput(){

}

BadInput::~BadInput(){
  
}

void BadInput::set_value(int value){
  this->value = value;
}

int BadInput::get_value(){
  return this->value; 
}
