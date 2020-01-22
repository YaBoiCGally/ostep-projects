#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

  int c, count = 0, i;
  char ch = ' ';
  
  if(argc == 1){
    printf("wunzip: file1 [file2 ...]\n");
    return 1;
  }

  for(c = 1; c < argc; c++){
    
    FILE *unzip = fopen(argv[c], "r");
    if(unzip == NULL){
      return 1;
    }

    while(!feof(unzip)){
      fread(&count, 4, 1, unzip);
      fread(&ch, 1, 1, unzip);
      
      for(i = 0; i < count; i++){
	printf("%c", ch);
      }
      count = 0;
    }
  }
  return 0;
}
