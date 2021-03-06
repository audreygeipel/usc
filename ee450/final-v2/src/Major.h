#ifndef MAJOR_H
#define MAJOR_H 

struct captain_data {
  int confidance;
  int resources;
  int captain_id;
  int success_rate;
};

class Major {

  captain_data captain_datas[2];
  char* port;
  char general_port[99];
  char general_pass[99];

public:
  Major (char*);
  ~Major ();

  void start();
  void parse_and_save_captain_message(char[]);
  bool is_captain_data_complete();
  void print_captain_data();
  void send_rates_to_general();
};

#endif

