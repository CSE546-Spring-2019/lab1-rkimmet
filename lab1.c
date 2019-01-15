#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int readFile(FILE  *inputfile, char *searchString, int count, FILE *out);
int printFile(int count, FILE *input);
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
    if((outputFile=fopen(argv[3],"wb"))==NULL){
        printf("Could not open the file");
        exit(1);
    }
    rc=readFile(inputFile,searchString,count,outputFile);
    out=printFile(count,inputFile);
    fclose(outputFile);
    return 0;
}
/*
 *reads the file chunks into the buffer and will then compare them with the comparefunction to the search string
 */
int readFile(FILE *inputfile, char *searchString,int count, FILE *out){
    char buff[100];
    while((fread(buff,1,100,inputfile))!=0){
        fwrite(buff,1,100,out);
        count=compare(buff,searchString,count);
    }
    
   return 0;
}
int compare(char* buffer, char*ss,int count){
    int i=0;
    int stringmatch=sizeof(ss);
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
        if(matchingchars==stringmatch){
            count++;
            sspos=0;
            matchingchars=0;
        }
    return count;
    }
}
int printFile(int count, FILE *input){
    int size=ftell(input);
    printf("The size is %d\n",size);
    printf("matching number of words is %d\n",count);
    fclose(input);
    return 0;
}
