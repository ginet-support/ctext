#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINESIZE 80

int main(int argc, char *argv[]){

  char line[LINESIZE];
  char filename[255];
  char ext[6];

  FILE *fp; 
  FILE *fp_output;

  int count = 1;

if (argc > 1) {

  if((fp=fopen(argv[1],"r"))){
    fp_output=fopen("/dev/null","w");
  } else {
    puts("File does not exist.");
    exit(-1);
  }

  while(! feof(fp)){

    fgets(line,LINESIZE,fp);

      if(strncmp(line,"--",2) == 0){ 
         fclose(fp_output);
	 snprintf(ext,6,"%05d",count++);
	 snprintf(filename,32,"%s.%s.txt",argv[1],ext);
//	 printf("cat %s >> checklist\n",filename);
	 fp_output=fopen(filename,"w");
      }
    
    fputs(line,fp_output);

  }


  fclose(fp_output);
  fclose(fp);

 } else {
	puts("usage: splitit <formatfile>");
	}

 return 0;
}















