#include <stdio.h>
#include <string.h>
#include <unistd.h>

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
        splitedCmd[0] = strtok(buffer, ";");
        char *temp;
        int i;

        for(i=1; (temp = strtok(NULL, ";")) != NULL ; i++)
            splitedCmd[i] = temp;

        splitedCmd[i] = 0;



       for(int i=0; splitedCmd[i] != NULL ; i++)
       {
            char *splitedStr[10];
            splitedStr[0] = strtok(splitedCmd[i], " ");
            char *temp;
            int i;

            for(i=1; (temp = strtok(NULL, " ")) != NULL ; i++)
                splitedStr[i] = temp;

            splitedStr[i] = 0;

            int pid = fork();
        
            if(pid == 0 && execvp("ls", splitedStr) == -1)
                printf("execvp not activated\n"); 
       }    
    }
}
/*
char * ParseWithDelimeter(char * buf, char * del)[10]
{
    char *splitedStr[10];
    splitedStr[0] = strtok(buf, del);
    char *temp;
    int i;

    for(i=1; (temp = strtok(NULL, del)) != NULL ; i++)
        splitedStr[i] = temp;

    splitedStr[i] = 0;
    return splitedStr;
}
*/
