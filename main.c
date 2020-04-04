#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
char *read_line();
char** parse(char* preparse);
char* fun_func();
int PtopLen(char **ptop);
void convptoptoarrp(char** ptop,int ln);
int main()
{

   char * ahma;
    char **code_parsed;
    int status;
    pid_t child_pid;
    pid_t waitvar;

while(1){

    ahma=read_line();
    code_parsed=parse(ahma);
    puts(code_parsed[0]);
    if (strcmp(code_parsed[0],"exit")==0){
    puts("ok");

    break;
    }
    else{
    puts("not ok");
    }


    child_pid=fork();
    if (child_pid==0){
    printf("\nchild:\ncurrent id:%d and child pid%d\n",getpid(),child_pid);
    puts(code_parsed[0]);
    //printf("\nthere%s",code_parsed[0]);

    //printf("%d",funny);
    //convptoptoarrp(code_parsed,funny);
    //char *argv[] = {"ls", "-a", "-h", NULL};

    if (execvp(code_parsed[0], code_parsed) < 0) {
                perror(code_parsed[0]);
                exit(1);
            }
    //

         // if (execvp(*code_parsed, code_parsed) < 0) {     /* execute the command  */
           //    printf("*** ERROR: exec failed\n");
             //  exit(1);
         // }
    }
    else{
    waitvar=waitpid(child_pid,&status,WUNTRACED);
    printf("\nparent\ncurrent id:%d and child pid%d\n",getpid(),child_pid);
    //puts(code_parsed[0]);

    }
}

    return 0;
}
