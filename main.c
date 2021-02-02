#include "menu.h"
#include <stdlib.h>
#include <string.h>

char commands[512];
int main()
{
    struct menu m;
    int argc = 0;
    char *argv[32] = {};
    char *pcmd;

    memset(&m, 0, sizeof(m));
    strncpy(m.name, "test0", sizeof(m.name) - 1);
    m.level = 0;
    m.sub = malloc(sizeof(struct menu));

    memset(m.sub, 0, sizeof(struct menu));
    strncpy(m.sub->name, "test1", sizeof(m.sub->name) - 1);
    m.sub->level = 1;

    for(;;){
        printf("\033[H \033[J");
        printf("===================== hello world =====================\n");
        memset(commands, 0, sizeof(commands));
        char *gets = fgets(commands, sizeof(commands) - 1, stdin);
        argc = 0;
        if(gets){
            commands[511] = '\0';
            for(pcmd = strtok(&commands[0], " "); pcmd != NULL; pcmd = strtok(NULL, " ")){
                argv[argc] = pcmd;
                argc++;
	        }
        }
        if(argc == 1 && (argv[0][0] == 'q' || !strncmp(argv[0], "quit", sizeof("quit")))){
            exit(0);
        }else{
            printmenu(&m);
        }
        fgets(commands, sizeof(commands) - 1, stdin);
    }
    return 0;
}
