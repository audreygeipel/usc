#include <vector>

#ifndef TABLE_H
#define TABLE_H

class Table{
	public:
    int size_of_y;
    int size_of_x;
    std::vector< std::vector<bool> > table;
    std::vector< std::vector<bool> > next_table;

    void clear();
    void toggle_point(int, int);
    void print();
    
    void forward();
    
    void update_point(int, int);
    int num_of_alive_neighbours(int, int);

    Table(int, int);
};

#endif
