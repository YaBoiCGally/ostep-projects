#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

  int count = 0;
  int ascii;
  char ch, chNext;
  
  if(argc == 1){
    printf("wzip: file1 [file2 ...]\n");
    return 1;
  }
  
  else{
    for(int c = 1; c < argc; c++){

      FILE *newStream = fopen(argv[c], "r");
      if(newStream == NULL){
	return 1;
      }

      ch = fgetc(newStream);
      while(!feof(newStream)){
	
	chNext = fgetc(newStream);
	if(count == 0){
	  count = 1;
	}
	while(ch == chNext){
	  chNext = fgetc(newStream);
	  count = count + 1;
	}

	ascii = ch;

	if(feof(newStream) && c != argc - 1){
	  count++;
	  break;
	}
	if(ascii != -1){
	  fwrite(&count, 4, 1, stdout);
	  fwrite(&ascii, 1, 1,  stdout);
	}
	ch = chNext;
	count = 0;
      }
    } //End of argv for
  } //End of else
  
  return 0;
} //End of Prgm
