#ifndef INTERFACE_C
#define INTERFACE_C

#include<stdio.h>
#include<string.h>
#include"service.c"

void clearscreen(void); // cls
int retintline(); // return tne only 1 int in one line
int filstrline(char *str); // fill the str repository with STRLEN from one %s, and return character count
tim rettimline(); // as retintline

int page_login_select(void); // return login type
void page_login_user(); // fill in ID, PW
void page_login_user_fail();
void page_login_admin();
void page_login_admin_fail();

void user_menu();
void admin_menu();

void clearscreen(void)
{
    system("cls");
}

int page_login_select(void)
{
    int sel = 0;
    do
    {
        if(sel != 0)
        {
            clearscreen();
            printf("wrong input :%d, try again please.\n", sel);
        }
        printf("Enter your identity: \n 1.Admin;\n 2.User;\nOr press 0 to exit this programme. Your choice:");
        sel = getintline();
    } while (sel == 0 || sel == 1 || sel == 2);
    return sel;
}

int retintline() // return tne only 1 int in one line
{
    int n;
    char c[20];
    scanf("%d", &n);
    gets(c);
    return n;
}

int filstrline(char *str) // fill the str repository with STRLEN from one %s
{
    char c[17];
    int count = 0;
    for(int i = 0; i <= STRLENLIMIT; i ++)
    {
        if(i == 0 || c[i - 1] != '\0')
        {
            scanf("%c", &c[i]);
            if(c[i] == '\n')
            {
                c[i] = '\0';
                count = i;
            }
        }
        else
        {
            c[i] = '\0';
        }
    }
    strncpy(str, c, STRLENLIMIT);
    return count;
}

tim rettimline() // as retintline
{
    tim t;
    char c[20];
    scanf("%d%d%d%d%d%d", &t.yea, &t.mon, &t.day, &t.hou, &t.min, &t.sec);
    gets(c);
    return t;
}

#endif