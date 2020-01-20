#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

  char binary[32] = {0};
  
  if(argc == 1){
    printf("wzip: file1 [file2 ...]\n");
    return 1;
  }

  else{
    for(int c = 1; c < argc; c++){
      
      int count = 63;
      int i;

      for(i = 0; i < 32; i++){
	binary[31 - i] = count % 2;
	count = count / 2;
      }
    
      for(i = 0; i < 32; i++){
	printf("%d", binary[i]);
      }
    
      printf("end of else");

    }
  }
  
  return 0;
}
