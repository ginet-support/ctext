#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINESIZE 80
#define FNAMESIZE LINESIZE
int main(int argc, char *argv[]){

  char line[LINESIZE];

  char filename[FNAMESIZE];
 
  FILE *fp_input; 
  FILE *fp_parse;
  FILE *fp_output;

 if (argc != 3) {
   fputs("Usage: merge sourcefile destfile\n",stderr);
    exit(-1);
 } else {

   if((fp_input=fopen(argv[1],"r"))){
     if(! (fp_output=fopen(argv[2],"w"))){
       fputs("Error writing outputfile\n",stderr);
       exit(-1);
     }
    
  while(! feof(fp_input)){
    fgets(line,LINESIZE,fp_input);
    snprintf(filename,strlen(line),"%s",line);
    if((fp_parse=fopen(filename,"r"))){

    while (! feof(fp_parse)){
      fgets(line,LINESIZE,fp_parse);
      fputs(line,fp_output);
    }
      fclose(fp_parse);
    }
  
  }} else {
     fputs("Inputfile does not exist\n",stderr);
     exit (-1);
   }
  
 }

  fclose(fp_output);
  fclose(fp_input);
  return 0;

}

