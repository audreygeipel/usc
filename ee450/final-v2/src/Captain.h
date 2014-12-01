#ifndef CAPTAIN_H
#define CAPTAIN_H

class Captain {

  int id;
  int major_port;

public:
  Captain (int, char*);
  ~Captain ();

  void start();
  char* create_message();
};

#endif

