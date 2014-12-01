#ifndef MAJOR_H
#define MAJOR_H 


struct captain_data {
  int confidance;
  int resources;
  int captain_id;
};

class Major {
  
  captain_data captain_datas[2];
  char* port;
  
	public:
		Major (char*);
		~Major ();
    
    void start();
    void parse_and_save_captain_message(char[]);
    bool is_captain_data_complete();
    void print_captain_data();
};

#endif
