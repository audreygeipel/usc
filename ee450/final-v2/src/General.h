#ifndef GENERAL_H
#define GENERAL_H 

class General {

  char port[99];
  char pass[99];
  int success_rates[2];

public:
  General ();
  ~General ();

  void start();
  bool parse_message(char*);
};

#endif

