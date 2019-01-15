#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int readFile(FILE  *inputfile, char *searchString, int count);
int printFile(FILE *outputfile, int count, FILE *input);
int compare(char* buffer, char*searchString, int count);
int rescan(FILE inputfile);

int main(int argc, char** argv){
    /*
     *declaration of variables needed to use the program
     */
    FILE *inputFile, *outputFile;
    int count;
    char *searchString;
    int rc,out;

    searchString=argv[2];
    /*
     *check the files see if they are valid files to be opened
     */
    if((inputFile=fopen(argv[1],"rb"))==NULL){
        printf("Could not open the file");
        exit(1);
    }
    if((outputFile=fopen(argv[3],"w"))==NULL){
        printf("Could not open the file");
        exit(1);
    }
    rc=readFile(inputFile,searchString,count);
    return 0;
}
/*
 *reads the file chunks into the buffer and will then compare them with the comparefunction to the search string
 */
int readFile(FILE *inputfile, char *searchString,int count){
    char buff[100];
    while((fread(buff,1,100,inputfile))!=0){
        count=compare(buff,searchString,count);
        printf("%c\n",buff[0]);
        printf("%ld\n",ftell(inputfile));
    }
    
   return 0;
}
int compare(char* buffer, char*ss,int count){
    int i=0;
    int stingmatch=strlen(ss);
    int potential=0;
    int matchingchars=0;
    int sspos=0;
    /*
     * variable that were needed for this function
     */
    /*
     *loop that checks for what equal characters and will add to the count if they are equal.
     */
    for (i;i<=100;i++){
        if(buffer[i]==ss[sspos++]){
            sspos++;
            matchingchars=0;
        }else{
            sspos=0;
        }
       /* if(matchingchars==stringmatch){
            count++;
            sspos=0;
            matchingchars=0;
        }*/
    return count;
    }
}
int outputfile(FILE *outputfile, int count, FILE *input){
    int size=ftell(input);
    char* sizee="The file size is";
    char*counts= "The number of matching words is";
    fputs(sizee, outputfile);
    fputs(counts,outputfile);
    fclose(outputfile);
    fclose(input);
    return 0;
}
