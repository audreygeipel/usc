#include <iostream>
#include "intlist_g.h"

using namespace std;

extern IntItem *head;


bool is_empty()
{
  if (head == NULL)
    return 1;
  return 0;
}

void push_back(int new_val)
{
  IntItem  *new_ptr, *tmp;
  // Allocate a new item and set its value 
  //  and set its next pointer to NULL

  // Is the list empty and we need to update head
  //   or does it contain other items and we need
  //   to scan to the end and add the new item?
  if( is_empty() ){
    head = new IntItem;
    head->val = new_val;
    head->next = NULL;
  }
  else {
    tmp = head;
    while(tmp->next)
      tmp = tmp->next;
    tmp->next = new IntItem;
    tmp->next->val = new_val;
    tmp->next->next = NULL;
  }
}


int pop_front()
{
  IntItem *tmp;
  int data;
  
  if (is_empty()) return -1;

  tmp = head;
  data = head->val;
  head = head->next;
  
  delete tmp;
  return data;
}

int peek_front()
{
  // Remember to return -1 if the list is empty
  if (is_empty()) return -1;
  
  return head->val;
}

void print_list()
{
  IntItem *tmp;
  tmp = head;
  cout << "Current list => ";
  // print each item followed by a space...all on the same line
  while (tmp->next){
    cout << tmp->val << " ";
    tmp = tmp->next;
  }


  cout << endl;
}

IntItem *find(int find_val)
{
  IntItem *tmp;
  tmp = head;
  
  if (is_empty()) return NULL;

  while (tmp->next){
    if(tmp->val == find_val){
      return tmp;
    }
    tmp = tmp->next;
  }
  
  return NULL;
}

bool remove(int del_val)
{ 
  IntItem *tmp, *prev;
  tmp = head;
  
  if (is_empty()) return NULL;
  
  while(tmp->val != del_val){
    prev = tmp;
    tmp = tmp->next;
    if(tmp->next == NULL) return 0;
  }
  
  tmp = prev->next;
  
  prev->next = tmp->next;
  
  delete tmp;
  return 1;
}

int list_size()
{
  int mysize = 0;
  IntItem *tmp;
  tmp = head;
  
  while (tmp->next){
    mysize++;
    tmp = tmp->next;
  }

  return mysize;
}
