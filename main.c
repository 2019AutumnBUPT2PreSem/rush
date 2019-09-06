#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include"dbstruct.h"
#include"arraysupport.c"
#include"dboperation.c"
#include"dbio.c"
#include"utilsupport.c"
#include"decoration.c" 
#include"service.c"
#include"FileReader.c"
#include"addition.c"
int main()
{
	/*get all table*/
	tbl provider,user,billinfo,telerecord,netrecord,admin,sets,moneyrecord;
	provider.info.intNum=2;
	provider.info.namNum=1;
	provider.info.timNum=0;
	provider.info.rowNum=3;
	provider.lrn=provider.info.rowNum;
	provider.clm=assignTblChart(provider.info);
	
	admin.info.intNum=3;
	admin.info.namNum=4;
	admin.info.timNum=0;
	admin.info.rowNum=3;
	admin.clm=assignTblChart(admin.info);
	admin.lrn=admin.info.rowNum;
	
	user.info.intNum=5;
	user.info.namNum=5;
	user.info.timNum=0;
	user.info.rowNum=3;
	user.clm=assignTblChart(user.info);
	user.lrn=user.info.rowNum;
	
	telerecord.info.intNum=7;
	telerecord.info.namNum=1;
	telerecord.info.timNum=2;
	telerecord.info.rowNum=3;
	telerecord.clm=assignTblChart(telerecord.info);
	telerecord.lrn=telerecord.info.rowNum;
	
	billinfo.info.intNum=11;
	billinfo.info.namNum=0;
	billinfo.info.timNum=0;
	billinfo.info.rowNum=3;
	billinfo.clm=assignTblChart(billinfo.info);
	billinfo.lrn=billinfo.info.rowNum;
	
	netrecord.info.intNum=4;
	netrecord.info.namNum=1;
	netrecord.info.timNum=1;
	netrecord.info.rowNum=3;
	netrecord.clm=assignTblChart(netrecord.info);
	netrecord.lrn=netrecord.info.rowNum;
	
	sets.info.intNum=7;
	sets.info.namNum=1;
	sets.info.timNum=0;
	sets.info.rowNum=5;
	sets.clm=assignTblChart(sets.info);
	sets.lrn=sets.info.rowNum;
	
	moneyrecord.info.intNum=5;
	moneyrecord.info.namNum=0;
	moneyrecord.info.timNum=1;
	moneyrecord.info.rowNum=3;
	moneyrecord.clm=assignTblChart(moneyrecord.info);
	moneyrecord.lrn=moneyrecord.info.rowNum;
	
	FILE* pfile;
	pfile=fopen("provider.dat","r");
	FileReader(pfile,&provider);
	fclose(pfile);
	
	pfile=fopen("admin.dat","r");
	FileReader(pfile,&admin);
	fclose(pfile);

	
	pfile=fopen("telerecord.dat","r");
	FileReader(pfile,&telerecord);
	fclose(pfile);

	
	pfile=fopen("netrecord.dat","r");
	FileReader(pfile,&netrecord);
	fclose(pfile);

	
	fflush(pfile);
	pfile=fopen("sets.dat","r");
	FileReader(pfile,&sets);
	fclose(pfile);

	
	fflush(pfile);
	pfile=fopen("moneyrecord.dat","r");
	FileReader(pfile,&moneyrecord);
	fclose(pfile);

	
	pfile=fopen("billinfo.dat","r");
	FileReader(pfile,&billinfo);
	fclose(pfile);

	pfile=fopen("user.dat","r");
	FileReader(pfile,&user);
	fclose(pfile);


	system("cls");
	/*we gonna read all table there*/
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
					system("cls");
					quit_menu=userMainBody(provider,user,billinfo,telerecord,netrecord,admin,sets,moneyrecord,IDu);
					system("cls");
				}
			}
			else
			{
				printf("You aren't a user of this system, press enter to continue\n");
				getchar();
				system("cls");
			}
				
		}
		else if(type==1)
		{
			IDa=Check4Admin(admin,ID,PW);
			if(IDa!=-1)
			{
				while(quit_menu==0)
				{
					system("cls");
					int provider=admin.clm.phint[IDa][2];
					quit_menu=admchoose(telerecord, netrecord,moneyrecord,&sets,&user,provider,IDa);
					system("cls");
				}
			}
			else
			{
				printf("You aren't a admin of this system, press enter to continue\n");
				getchar();
				system("cls");
			}
		}
		else if(type==0)
		{
			system("cls");
			quit_prog=1;//quit the program
		}
		else
		{	
			system("cls");
			printf("You have input a wrong num,please retry! press enter to continue\n\n");
			getchar();
		}
	}
	/*write table*/
	//writeAllTable(&provider, &user, &billinfo, &telerecord, &netrecord, &admin, &sets, &moneyrecord);

	
	pfile=fopen("provider.dat","w");
	FileWriter(pfile,provider);
	fclose(pfile);
	
	pfile=fopen("admin.dat","w");
	FileWriter(pfile,admin);
	fclose(pfile);
	
	pfile=fopen("telerecord.dat","w");
	FileWriter(pfile,telerecord);
	fclose(pfile);
	
	pfile=fopen("netrecord.dat","w");
	FileWriter(pfile,netrecord);
	fclose(pfile);
	
	pfile=fopen("sets.dat","w");
	FileWriter(pfile,sets);
	fclose(pfile);
	
	pfile=fopen("moneyrecord.dat","w");
	FileWriter(pfile,moneyrecord);
	fclose(pfile);
	
	pfile=fopen("billinfo.dat","w");
	FileWriter(pfile,billinfo);
	fclose(pfile);
	
	pfile=fopen("user.dat","w");
	FileWriter(pfile,user);
	fclose(pfile);
	printf("Thank you for using!\n");
	
	return 0;
}
