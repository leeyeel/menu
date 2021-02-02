#ifndef MENU_H
#define MENU_H

#include "list.h"

#define SPACE   "    "
#define ARROW   "--->"

struct menu
{
   char name[64];
   int level;
   int (*fun)(int argc, char *argv[]);
   int (*parse)(int argc, char *argv[]);
   struct menu *sub;
};

struct menu* addmenu(struct menu *pcurrent, struct menu *pnew);

int printmenu(struct menu *pmenu);

#endif
