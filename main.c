#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include"dbstruct.h"
#include"arraysupport.c"
#include"dboperation.c"
#include"utilsupport.c"
#include"decoration.c" 
#include"service.c"
#include"FileReader.c"
#include"addition.c"
#include"procedure.c"

void clearscree(void)
{
	int a;
//	system("cls");
}

int main()
{
	/*get all table*/
	tbl provider,user,billinfo,telerecord,netrecord,admin,sets,moneyrecord;
	loadTable(&provider,&user,&billinfo,&telerecord,&netrecord,&admin,&sets,&moneyrecord);

	int quit_prog=0;
	int quit_menu=0;
	int IDu=-1;
	int IDa=-1;
	int type=0;
	char ID[STRLENLIMIT]={"\0"};
	char PW[STRLENLIMIT]={"\0"};
//	char *ID = IDarray;
//	char *PW = PWarray;
	
//	char **idpw = constructD2_char(2, STRLENLIMIT, '\0');
//	idpw[1]={}

	int status, statusu, statusa;
	while(quit_prog == 0)
	{
		procedure_login(&status);
		switch (status)// 0 for exit, 1 for admin, 2 for user, default for error
		{
		case 0:// quit
		{
			procedure_quit_login();
			quit_prog = 1;
			break;
		}
		case 1:// login as admin
		{
			procedure_login_admin(admin, &IDa, &quit_menu);
			while (quit_menu == 0)
			{
				procedure_admin_menu(admin, IDa, &statusa);
				switch(statusa)
				{
					case 1:
					{
						procedure_stat();
						break;
					}
					case 2:
					{
						procedure_stattele();	
						break;
					}
					case 3:
					{
						procedure_sortCallingByTimeSgmt();
						break;
					}
					case 4:
					{
						procedure_sortFee();
					}
					default:
					{
						procedure_error_admin(statusa)
					}

				}
			}
			IDa = -1;
			break;
		}	
		case 2:// login as user
		{
			procedure_login_user(user, &IDu, &quit_menu);
			while (quit_menu == 0)
			{
				procedure_user_menu(user, IDu, &statusu);
				switch (statusu)
				{
				case 1:
				{
					procedure_dial_user(&telerecord, &billinfo, IDu);
					break;
				}
				case 2:
				{
					procedure_net_user(&netrecord, &billinfo, IDu);
					break;
				}
				case 3:
				{
					procedure_changePersonInfo(&user, IDu);
					break;
				}
				case 4:
				{
					procedure_checkTeleRecord(telerecord, IDu);
					break;
				}
				case 5:
				{
					procedure_checkTeleRecordByTime(telerecord, IDu);
					break;
				}
				case 6:
				{
					procedure_checkNetRecord(netrecord, IDu);
					break;
				}
				case 7:
				{
					procedure_checkNetRecordByTime(netrecord, IDu);
					break;
				}
				case 8:
				{
					procedure_quit_user(user, IDu);
					quit_menu = 1;
					break;
				}
				default:
				{
					procedure_error_user(statusu);
					break;
				}
				}
			}
			IDu = -1;
			break;
		}	
		default:
		{
			procedure_login_type_error(status);
			break;
		}	
		}
	}
	saveTable(provider,user,billinfo,telerecord,netrecord,admin,sets,moneyrecord);

	return 0;



/*
	while(quit_prog==0)
	{
		quit_menu=0;
		IDu=-1;
		IDa=-1;
		type=loginType();
		if(type==1||type==2)
		{
			InputIDPW(ID,PW,type);//check whether the ID and PW is legal
		}
		if(type==2)
		{
			IDu=Check4User(user,ID,PW);
			if(IDu!=-1)
			{
				while(quit_menu==0)
				{
					clearscree();
					quit_menu=userMainBody(provider,user,billinfo,telerecord,netrecord,admin,sets,moneyrecord,IDu);
					clearscree();
				}
			}
			else
			{
				printf("You aren't a user of this system, press enter to continue\n");
				getchar();
				clearscree();
			}
				
		}
		else if(type==1)
		{
			IDa=Check4Admin(admin,ID,PW);
			if(IDa!=-1)
			{
				while(quit_menu==0)
				{
					clearscree();
					int provider=admin.clm.phint[IDa][2];
					quit_menu=admchoose(&admin,&telerecord, &netrecord,&moneyrecord,&sets,&user,provider,IDa);
					clearscree();
				}
			}
			else
			{
				printf("You aren't a admin of this system, press enter to continue\n");
				getchar();
				clearscree();
			}
		}
		else if(type==0)
		{
			clearscree();
			quit_prog=1;//quit the program
		}
		else
		{	
			clearscree();
			printf("You have input a wrong num,please retry! press enter to continue\n\n");
			getchar();
		}
	}
	*/
	/*write table*/
	//writeAllTable(&provider, &user, &billinfo, &telerecord, &netrecord, &admin, &sets, &moneyrecord);
	
}
