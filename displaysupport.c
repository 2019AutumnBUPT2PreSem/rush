#ifndef DISPLAYSUPPORT_C
#define DISPLATSUPPORT_C

#include"arraysupport.c"
#include"dbstruct.h"

void display_int(int n)// support to justify
{
    printf("%16d", n);
}
void display_nam(char* name)// display the name on screen
{
    for(int j = 0; j < STRLENLIMIT; j++)
        if(name[j] == '\0')
        {
            printf(" ");
        }
        else
            printf("%c", name[j]);
}
void display_tim(tim time)// display the time on screen
{
    printf("%02d/%02d/%02d%02d:%02d:%02d", time.yea, time.mon, time.day, time.hou, time.min, time.sec);
}
#endif
