#ifndef INTERFACE_C
#define INTERFACE_C

#include"service.c"

void clearscreen(void); // cls
void getintline();
void getstrline();
void 

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
    int type = 0;
    char c[16];
    printf("Enter your identity: \n 1.Admin;\n 2.User;\nOr press 0 to exit this programme. Your choice:");
    scanf("%d",&type);
    gets(c);
    return type;
}


#endif