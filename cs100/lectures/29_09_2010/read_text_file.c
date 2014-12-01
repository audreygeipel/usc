#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *read_file_to_string(char *filename)
{
  FILE *fp;
  int num_of_char;
  char *text_buf, ch;
  fp = fopen(filename, "r");
  
  if (fp == NULL){
  	printf("No file");
  }
  
  fseek(fp, 0, SEEK_END);
  num_of_char = ftell(fp);
  
  printf("Number of characters: %d", num_of_char);
    
  text_buf = (char*) malloc (num_of_char+1);
  fseek(fp, 0, SEEK_SET);
  
  int i = 0;
  while ( (ch = getc(fp)) != EOF){
	text_buf[i++] = tolower(ch);
  }
  text_buf[i] = 0;
  
  fclose(fp);
  
  


  return text_buf;
}



int main(int argc, char *argv[])
{
  char *text_buf;
  int i, num_targets;
  if(argc < 2){
    fprintf(stderr,"Usage: ./%s text_file\n", argv[0]);
    exit(1);
  }
  if(argc > 2){
    fprintf(stderr,"Error:  Too many arguments\n.");
    exit(1);
  }

  text_buf = read_file_to_string(argv[1]);
  printf("\nDone reading text file.  Contents are:\n\n");
  printf("%s",text_buf);
  free(text_buf);
  return 0;
}

