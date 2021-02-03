#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


void ExecBatchFile(char* argv[]);
void ExecCmdLine();
//char * ParseWithDelimeter(char * buf, char * del)[10];


int main(int argc, char* argv[])
{
    if(argc > 1)
    {
        ExecBatchFile(argv);
    }
    else
        ExecCmdLine();
}

void ExecBatchFile(char* argv[])
{
    FILE *fp = fopen(argv[1], "r");

}

void ExecCmdLine()
{
    char buffer[100];
    while(1)
    {
        
        printf("prompt> ");
        if(fgets(buffer, 180 + 3, stdin) == NULL) 
        {
            printf("\n");
            return;
        }

        //char * splitedCmd[10] = ParseWithDelimeter(buffer, ";");
        int cmdPids[10];

        char *splitedCmd[10];
        splitedCmd[0] = strtok(buffer, ";\n");
        char *temp;
        int i;

        for(i=1; (temp = strtok(NULL, ";\n")) != NULL ; i++)
            splitedCmd[i] = temp;

        splitedCmd[i] = 0;

        int status;
        int pid[10];


       for(i=0; splitedCmd[i] != NULL ; i++)
       {
            char *splitedStr[10];
            splitedStr[0] = strtok(splitedCmd[i], " ");
            char *temp;
            int j;

            for(j=1; (temp = strtok(NULL, " ")) != NULL ; j++)
                splitedStr[j] = temp;

            splitedStr[j] = 0;

            pid[i] = fork();

            if(pid[i] == 0 )
            {
                if(execvp(splitedStr[0], splitedStr) == -1)
                    printf("execvp not activated\n");                     
            } 
       }

       
        for(int j = 0; j <=i; j++)
            waitpid(pid[j], &status, 0);
       
    }
}
