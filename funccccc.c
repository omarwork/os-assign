#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
char * convtoheap(char *arr);

char *read_line(){
char s[100];
    char ch;
    int i =0,n=10;
char *test=(char*) malloc(n);
printf(" %s :~$  ",getcwd(s,100));
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
char** parse(char* preparse,int* st){
    char preparse_str[strlen(preparse)];
    char* parsed;
    char ** command;
    int n=1;
    //printf("\n%d",strlen(command));

    command=(char**)malloc(n*sizeof(char*));


    int i=0;
    strcpy(preparse_str,preparse);


    parsed=strtok(preparse_str," ");

  //  puts(parsed);
    // printf("\n%d parsed>>\n",(int)strlen(&parsed));
    //printf("\n%d\n",(int)strlen(command));

    while(parsed!=NULL){
if (strcmp(parsed,"&")!=0)
{
command[i]=convtoheap(parsed);
  //      printf("%d",(int)strlen(command));
//        printf("\n%d parsed>>\n",(int)strlen(&parsed));
        i++;
        parsed=strtok(NULL," ");
if (i==n){
        n=n+1;
        command=realloc(command,n*sizeof(char*));
        }
}
    else{
    *st=1;
    parsed=strtok(NULL," ");
    }
    }

command=realloc(command,n*sizeof(char*));
command[i]=NULL;


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




