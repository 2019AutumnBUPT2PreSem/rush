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

void clearscree(void)
{
	int a;
//	system("cls");
}

int main()
{
	/*get all table*/
	tbl provider,user,billinfo,telerecord,netrecord,admin,sets,moneyrecord;
	FILE *pfile;

	provider.lrn = 30;
	pfile=fopen("provider.idat","rb");
	provider.info = readidat(pfile, &provider.clm, provider.lrn);
	fclose(pfile);

	pfile=fopen("provider.cdat","rb");
	readcdat(pfile, provider.info, &provider.clm, provider.lrn);
	fclose(pfile);

	///////////////////
	admin.lrn =30;
	pfile=fopen("admin.idat","rb");
	admin.info = readidat(pfile, &admin.clm,admin.lrn);
	fclose(pfile);

	pfile=fopen("admin.cdat","rb");
	readcdat(pfile,admin.info, &admin.clm,admin.lrn);
	fclose(pfile);

	///////////////////
	telerecord.lrn = 30;
	pfile=fopen("telerecord.idat","rb");
	telerecord.info = readidat(pfile,&telerecord.clm,telerecord.lrn);
	fclose(pfile);	

	pfile=fopen("telerecord.cdat","rb");
	readcdat(pfile,telerecord.info,&telerecord.clm,telerecord.lrn);
	fclose(pfile);

	////////////////////
	netrecord.lrn = 30;
	pfile=fopen("netrecord.idat","rb");
	netrecord.info= readidat(pfile,&netrecord.clm,netrecord.lrn);
	fclose(pfile);

	pfile=fopen("netrecord.cdat","rb");
	readcdat(pfile,netrecord.info,&netrecord.clm,netrecord.lrn);
	fclose(pfile);

	////////////////////
	sets.lrn = 30;
	pfile=fopen("sets.idat","rb");
	sets.info= readidat(pfile,&sets.clm,sets.lrn);
	fclose(pfile);

	pfile=fopen("sets.cdat","rb");
	readcdat(pfile,sets.info,&sets.clm,sets.lrn);
	fclose(pfile);

	////////////////////
	user.lrn = 30;
	pfile=fopen("user.idat","rb");
	user.info = readidat(pfile,&user.clm,user.lrn);
	fclose(pfile);

	pfile=fopen("user.cdat","rb");
	readcdat(pfile,user.info,&user.clm,user.lrn);
	fclose(pfile);

	////////////////////
	moneyrecord.lrn = 30;
	pfile=fopen("moneyrecord.idat","rb");
	moneyrecord.info = readidat(pfile,&moneyrecord.clm,moneyrecord.lrn);
	fclose(pfile);

	pfile=fopen("moneyrecord.cdat","rb");
	readcdat(pfile,moneyrecord.info,&moneyrecord.clm,moneyrecord.lrn);
	fclose(pfile);

	/////////////////////
	billinfo.lrn = 30;
	pfile=fopen("billinfo.idat","rb");
	billinfo.info=readidat(pfile,&billinfo.clm,billinfo.lrn);
	fclose(pfile);

	pfile=fopen("billinfo.cdat","rb");
	readcdat(pfile,billinfo.info,&billinfo.clm,billinfo.lrn);
	fclose(pfile);
	
	//clearscree();
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
	/*write table*/
	//writeAllTable(&provider, &user, &billinfo, &telerecord, &netrecord, &admin, &sets, &moneyrecord);
	provider.lrn =30;
	pfile=fopen("provider.idat","wb");
	writeidat(pfile,provider.info, &provider.clm,provider.lrn);
	fclose(pfile);

	pfile=fopen("provider.cdat","wb");
	writecdat(pfile,provider.info,&provider.clm,provider.lrn);
	fclose(pfile);
	admin.lrn = 30;
	pfile=fopen("admin.idat","wb");
	writeidat(pfile,admin.info, &admin.clm,admin.lrn);
	fclose(pfile);

	pfile=fopen("admin.cdat","wb");
	writecdat(pfile,admin.info,&admin.clm,admin.lrn);
	fclose(pfile);

	telerecord.lrn = 30;
	pfile=fopen("telerecord.idat","wb");
	writeidat(pfile,telerecord.info,	&telerecord.clm,telerecord.lrn);
	fclose(pfile);	

	pfile=fopen("telerecord.cdat","wb");
	writecdat(pfile,telerecord.info,&telerecord.clm,telerecord.lrn);
	fclose(pfile);
netrecord.lrn = 30;
	pfile=fopen("netrecord.idat","wb");
	 writeidat(pfile,netrecord.info,&netrecord.clm,netrecord.lrn);
	fclose(pfile);

	pfile=fopen("netrecord.cdat","wb");
	writecdat(pfile,netrecord.info,&netrecord.clm,netrecord.lrn);
	fclose(pfile);
sets.lrn = 30;
	pfile=fopen("sets.idat","wb");
	writeidat(pfile,sets.info,&sets.clm,sets.lrn);
	fclose(pfile);

	pfile=fopen("sets.cdat","wb");
	writecdat(pfile,sets.info,&sets.clm,sets.lrn);
	fclose(pfile);
user.lrn = 30;
	pfile=fopen("user.idat","wb");
	writeidat(pfile,user.info,&user.clm,user.lrn);
	fclose(pfile);

	pfile=fopen("user.cdat","wb");
	writecdat(pfile,user.info,&user.clm,user.lrn);
	fclose(pfile);
moneyrecord.lrn = 30;
	pfile=fopen("moneyrecord.idat","wb");
	writeidat(pfile,moneyrecord.info,&moneyrecord.clm,moneyrecord.lrn);
	fclose(pfile);

	pfile=fopen("moneyrecord.cdat","wb");
	writecdat(pfile,moneyrecord.info,&moneyrecord.clm,moneyrecord.lrn);
	fclose(pfile);
billinfo.lrn = 30;
	pfile=fopen("billinfo.idat","wb");
	writeidat(pfile,billinfo.info,&billinfo.clm,billinfo.lrn);
	fclose(pfile);

	pfile=fopen("billinfo.cdat","wb");
	writecdat(pfile,billinfo.info,&billinfo.clm,billinfo.lrn);
	fclose(pfile);

	return 0;
}
