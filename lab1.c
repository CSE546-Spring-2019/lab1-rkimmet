#include <stdlib.h>
#include <stdio.h>

int readFile(FILE  *inputfile, char *searchString);
int printToFile(int size, int count, FILE outputfile);
int compare();
int rescan(FILE inputfile);

int main(int argc, char** argv){
    /*
     *declaration of variables needed to use the program
     */
    FILE *inputFile, *outputFile;
    int size,count;
    char *searchString;
    int rc;

    searchString=argv[2];
    /*
     *check the files see if they are valid files to be opened
     */
    if((inputFile=fopen(argv[1],"rb"))==NULL){
        printf("Could not open the file");
        exit(1);
    }
    if((outputFile=fopen(argv[3],"wb"))==NULL){
        printf("Could not open the file");
        exit(1);
    }
    rc=readFile(inputFile,searchString);
    return 0;
}
/*
 *reads the file chunks into the buffer and will then compare them with the comparefunction to the search string
 */
int readFile(FILE *inputfile, char *searchString){
    char buff[100];
    while((fread(buff,1,100,inputfile))!=0){
    printf("%c\n",buff[0]);
    printf("%ld\n",ftell(inputfile));
    }
   return 0;
}
