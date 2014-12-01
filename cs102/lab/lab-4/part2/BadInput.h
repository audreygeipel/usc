#ifndef BADINPUT_H
#define BADINPUT_H

class BadInput {
  int value;

  public:
    void set_value(int);
    int get_value();  

    BadInput();
    ~BadInput();
};

#endif
