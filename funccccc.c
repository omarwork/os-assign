#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
char * convtoheap(char *arr);

char *read_line(){

    char ch;
    int i =0,n=10;
char *test=(char*) malloc(n);
puts("shell>>");
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
char** parse(char* preparse){
    char preparse_str[strlen(preparse)];
    char* parsed;
    char ** command;
    char *finalpar;
    int n=1;


    command=(char**)malloc(n*sizeof(char*));


    int i=0;
    strcpy(preparse_str,preparse);

    parsed=strtok(preparse_str," ");
  //  puts(parsed);
    // printf("\n%d parsed>>\n",(int)strlen(&parsed));
    //printf("\n%d\n",(int)strlen(command));


    while(parsed!=NULL){
if (i==n){
        n=n+1;
        command=realloc(command,n*sizeof(char*));
        }
        command[i]=convtoheap(parsed);
        puts(command[i]);
  //      printf("%d",(int)strlen(command));
//        printf("\n%d parsed>>\n",(int)strlen(&parsed));
        i++;
        parsed=strtok(NULL," ");

    }




    /*if(command=realloc(command,(i+1))){
puts("\n allah ynwr");
    }
    puts("tmam again");
    command[i]=NULL;
    printf("\nthere%s",command[0]);*/


    return command;
}
char * convtoheap(char *arr){
char*hamada=(char*)malloc(strlen(arr));
strcpy(hamada,arr);
return hamada;
}




