#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

char *read_file_to_string(char *filename);
void match_strings(char *text_buf, char *targets[], int *occ, int num_targets);

int main(int argc, char *argv[])
{
  char *text_buf;

  int *target_occ;
  int i, num_targets;

  if(argc < 3){
    printf("Usage: ./%s text_file target_string_1 [... target_string_n]\n", argv[0]);
    exit(1);
  }

  // Call read_file_to_string() passing the filename provided on the command line
  text_buf  = read_file_to_string(argv[1]);
  
  printf("\nDone reading text file\n");

  // Calculate num_targets
  num_targets = argc - 2;
  
  // Allocate target_occ array and then initialize each element to 0
  target_occ = new int[num_targets];
  for (i=0; i<num_targets; i++){
    target_occ[i] = 0;
  }

  // Call match strings
  match_strings(text_buf, &argv[2], target_occ, num_targets);
  
  // print out each string and its occurrences
  for(i=0; i<num_targets; i++){
  	cout << argv[i+2] << " - " << target_occ[i] << endl ;
  }

  // free the target_occ array

  free(text_buf);
  return 0;
}



char *read_file_to_string(char *filename)
{
  FILE *fp;
  int start,end,count,i;
  char *text_buf;
  char ch;
  if ((fp = fopen(filename,"rb")) == NULL){
    printf("Can't open file %s\n", filename);
    exit(1);
  }
  start = ftell(fp);
  fseek(fp,0L, SEEK_END);
  end = ftell(fp);
  count = end-start;
  printf("Byte count of file is %d\n",count);
  text_buf = (char *)malloc(count+1);
  fseek(fp,0L,SEEK_SET);
  i = 0;
  while( (ch = getc(fp)) != EOF){
    text_buf[i++] = tolower(ch);
  }
  text_buf[i] = 0;
  fclose(fp);
  return text_buf;

}



void match_strings(char *text_buf, char *targets[], int *occ, int num_targets)
{
  int i,j;
  int buflen;


  buflen = strlen(text_buf);

  for(i=0; i<buflen; i++){
    for (j=0; j<num_targets; j++){
      if (strncmp(&text_buf[i], targets[j], strlen(targets[j]))){
        occ[j]++;
      }
    }
  }

}

