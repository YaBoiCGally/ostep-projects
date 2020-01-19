#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

  int i;
  char *buffer;
  size_t bufsize = 4096;
  char *search = argv[1];

  buffer = (char *)malloc(bufsize * sizeof(char));
  
  if(argc == 1){
    printf("wgrep: searchterm [file ...]\n");
    return 1;
  }
    
  if(argc == 2){
    while(fgets(buffer, bufsize, stdin)){
      if(strstr(buffer, search)){
	printf("%s", buffer);
      }
    }
  }

  else{
    for(i = 2; i < argc; i++){
      FILE *readData = fopen(argv[i], "r");
      if(readData == NULL){
	printf("wgrep: cannot open file\n");
	return 1;
      }
      while(fgets(buffer, bufsize, readData)){
	if(strstr(buffer, search)){
	  printf("%s", buffer);
        }
      }
    }
  }
  return 0;

}
