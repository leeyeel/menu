#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "menu.h"

static int move_up()
{
    return 0;
}

static int move_down()
{
    return 0;
}

static int move_enter()
{
    return 0;
}

static int move_leave()
{
    return 0;
}

int printmenu(struct menu *pmenu)
{
    for(int i = 0; i < pmenu->level; i++){
        printf("%s", SPACE);
    }
    printf("%s\n", pmenu->name);
    if(pmenu->sub){
        printmenu(pmenu->sub);
    }

    return 0;
}
