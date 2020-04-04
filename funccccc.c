#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *read_line(){
    char ch;
    int i =0,n=10;
char *test=(char*) malloc(n);
ch=getchar();
while (ch!='\n' ){
    test[i]=ch;
    ch=getchar();
    i++;
    if (i==n){
            n=n+2;
        test=realloc(test,n);
    }
}
test[i]='\0';
return test;
}
void parse(char* preparse){
    char preparse_str[strlen(preparse)];
    char* parsed;
    char ** command=(char**)malloc(8*sizeof(char*));
    int i=0;
    strcpy(preparse_str,preparse);


    parsed=strtok(preparse_str," ");
    puts(preparse_str);
    puts(parsed);
    while(parsed!=NULL){

        command[i]=parsed;
        puts(command[i]);
        i++;
        parsed=strtok(NULL," ");
    }
}
