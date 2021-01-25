#include <stdio.h>
#include <string.h>
#include <unistd.h>

void ExecBatchFile(char* argv[]);
void ExecCmdLine();
char ** ParseWithSpace(char * buf);


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

        char * splitedCmd[10] = ParseWithDelimeter(buffer, ";")

        char ** splitedStr = ParseWithDelimeter(buffer, " ");
        
        
        if(execvp("ls", splitedStr) == -1)
            printf("execvp not activated\n"); 
    }
}

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
