#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int  main(int argc, char *argv[]) {
  int ch, i;
  if(argc == 1){
    return 0;
  }
  if(argc > 1){
    for(i = 1; i < argc; i++){
      FILE *readData = fopen(argv[i], "r");
      if(readData == NULL){
	printf("wcat: cannot open file\n");
	return 1;
      }
      ch = getc(readData);
      while(ch != EOF){
	putchar(ch);
	
	ch = getc(readData);
      }
    }
  }
  return 0;
}
