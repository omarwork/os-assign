#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
char *read_line();
char** parse(char* preparse,int *st);
char* fun_func();
int PtopLen(char **ptop);
void convptoptoarrp(char** ptop,int ln);
int maxindex(char** useless);

int main()
{
int useful=0;
int temp=0;
char s[100];
   char * ahma;
    char **code_parsed;
    int status;
    pid_t child_pid;
    pid_t waitvar;

while(1){

    ahma=read_line();
    code_parsed=parse(ahma,&useful);

        if (strcmp(code_parsed[0],"exit")==0){
       exit(0);


        }
        else{

        }
if  (strcmp(code_parsed[0],"cd")==0)
            {

             // printing current working directory

                if (code_parsed[1]==NULL){

                    chdir("/home");


            }

                   else  if (strcmp(code_parsed[1],"..")==0)
                    {
                    // using the command
                  chdir("..");

                    // printing current working directory
                    printf("BS: %s\n", getcwd(s, 100));

                    // after chdir is executed


                    }


                    else if (chdir(code_parsed[1])==0)
                    {



                    }
           }
else{
    child_pid=fork();
    if (child_pid==0)
    {
    printf("\nchild:\ncurrent id:%d and child pid=%d\n",getpid(),child_pid);






      if ( (execvp(code_parsed[0], code_parsed) < 0))
            {
                perror(code_parsed[0]);

            }

            exit(0);

}
   else
    {
if(useful!=1)
{
    waitvar=waitpid(child_pid,&status,WUNTRACED);

}
    printf("\nparent\ncurrent id:%d and child pid%d\n",getpid(),child_pid);

    //puts(code_parsed[0]);

    }
}
}
    return 0;
}










