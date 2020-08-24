#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fct(char *str, char *name){
  char c;
  FILE *fp=fopen(str, "rb");

  if(!fp){
    printf("\nFailed to open file");
    exit(EXIT_FAILURE);
  }

FILE *out=fopen(name,"w");
  while((c=fgetc(fp)) != EOF){

      //printf("%c\n",c);
      if(c != '\n'){
      fprintf(out, "%c",c );
      printf( "%c",c );

      }
      else {
        fprintf(out, "%c%c",'\r',c );
        printf("%d%c",'\r',c );
      }
  }

  fclose(fp);
  fclose(out);
}

char *name_out(char *s){
  int l=strlen(s);
  int i=0;
  while(s[l-i]!='.') i++;

char *p=malloc(l+5);
  strncpy(p,s,l-i);
  strcat(p,".out");
  return p;
}


int main(int argc, char **argv){

  if(argc<2){
    printf("\nInvalide number of arguments" );
    exit(EXIT_FAILURE);
  }
  else{

    for(int i=1; i<2; ++i){
      char *name=name_out(argv[i]);
      fct(argv[i],name);
    }

  }

return 0;
}
