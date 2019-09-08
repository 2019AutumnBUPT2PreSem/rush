#ifndef INTERFACE_C
#define INTERFACE_C

#include<stdio.h>
#include<string.h>
#include"dboperation.c"

/* Be aware, every page will alway cleanscreen before its end or return sth.
 * And it shouldn't do cleanscreen anywhere else.
 */

void clearscreen(void); // cls
int retintline(); // return tne only 1 int in one line
int filstrline(char *str); // fill the str repository with STRLEN from one %s, and return character count
tim rettimline(); // as retintline

int isrightID(char *pID); // 6-10, character and number

int page_login_select(void); // return login type
int page_login_user(char *pID, char *pPW); // fill in ID, PW, return 1 for authorise, 0 for wrong code
void page_login_user_fail();
void page_login_admin();
void page_login_admin_fail();

void user_menu();
void admin_menu();

void clearscreen(void)
{
    system("cls");
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

int isRightID(char *pID)
{
	int count1=0;
	int count2=0;
	for(int i = 0 ; i < STRLENLIMIT && pID[i] != '\0'; i++)
    {
        if(pID[i] >= '0' && pID[i] <= '9')
		    count1++;
		if(pID[i] >= 'a' && pID[i] <= 'z')
		    count2++;
    }
	return count1 != 0 && count2 != 0 && count1 + count2 >= 6 && count1 + count2 <= 10;
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
    clearscreen();
    return sel;
}

int page_login_user_get(char *pID, char *pPW) // fill in ID, PW, try 3 times. return 0 for fail, 1 for success to get ID and PW.
{   
    int try = 3;
    do
    { 
        printf("\nPlease input your ID: ");
        filstrline(pID);
        if(isRightID(pID))
        {
            printf("\nPlease input your password: ");
            filstrline(pPW);
            try = -1;
        }
        else
        {
            try--;
            printf("\nYou have written in a invalid user name.\nYou can try %d more times.\nPress ENTER to continue.\n", try);
            getchar();
        }
    } while (try > 0);

    clearscreen();
    
    if(try == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void page_login_user_fail();
void page_login_admin();
void page_login_admin_fail();

#endif
