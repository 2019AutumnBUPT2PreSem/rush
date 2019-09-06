#ifndef DBFUNCTION_C
#define DBFUNCTION_C

#include<stdio.h>
#include"dbstruct.h"
#include"dboperation.c"
#include"dbio.c"

#define DBMEMORY_C int
#define MAX_CLIENT 30000
#define IGNR_NUM 30001
#define CompFunType int

extern int indent;
extern char diagL[80];

void ReadArray(DBMEMORY_C (*database)[2],int row_num,DBMEMORY_C* tempArray);
void genSeqL(int* array,int row);
void GetRtrnArray(int* compArray,int* rtrnArray,int row);
void SortFun(DBMEMORY_C (*database)[2],int row_num,int* rtrnArray,int (*CompFun)(CompFunType ch1,CompFunType ch2));
void setAllTable(tbl *pprovider, tbl *puser, tbl *pbillinfo, tbl *ptelerecord, tbl *pnetrecord, tbl *padmin, tbl *pset, tbl *pmoneyrecord);
void readAllTable(tbl *pprovider, tbl *puser, tbl *pbillinfo, tbl *ptelerecord, tbl *pnetrecord, tbl *padmin, tbl *pset, tbl *pmoneyrecord);
void writeAllTable(tbl *pprovider, tbl *puser, tbl *pbillinfo, tbl *ptelerecord, tbl *pnetrecord, tbl *padmin, tbl *pset, tbl *pmoneyrecord);
int existFirstTime(tbl provider, tbl user, tbl billinfo, tbl telerecord, tbl netrecord, tbl admin, tbl set, tbl moneyrecord);
void initAllTable(tbl *pprovider, tbl *puser, tbl *pbillinfo, tbl *ptelerecord, tbl *pnetrecord, tbl *padmin, tbl *pset, tbl *pmoneyrecord);

void ReadArray(DBMEMORY_C (*database)[2],int row_num,DBMEMORY_C* tempArray)//Read an array of two columns and N rows
{
	int counter=0;
	while(counter<row_num)
	{
		tempArray[counter]=database[counter][1];
		counter++;
	}
}

void genSeqL(int* array,int row)//Initialize a sequence array
{
	int counter=0;
	while(counter<row)
	{
		array[counter]=counter;
		counter++;
	}
}

void GetRtrnArray(int* compArray,int* rtrnArray,int row)
{
	int pass_counter=0;//Used to determine how many words have passed
	int trv_counter=0;//Used to loop through
	int locater=row-1;//This function uses reverse search
	int keyArray[row]; 
	int temp;
	genSeqL(keyArray,row);
	while(locater>=0)
	{
		temp=compArray[locater];
		pass_counter=0;
		trv_counter=0;
		while(pass_counter!=temp) 
		{
			if(keyArray[trv_counter]!=IGNR_NUM)//skip ignore_num,won't count in counter；
				pass_counter++;
			trv_counter++;
		}
		while(keyArray[trv_counter]==IGNR_NUM)//This is to solve the problem of reading IGNR_NUM if there are several successive IGNR_NUM.
			{
				trv_counter++;
			}
		rtrnArray[locater]=keyArray[trv_counter];
		keyArray[trv_counter]=IGNR_NUM;
		locater--;//Reverse Arrangement of Ordinal Sequences
	}
}

void SortFun(DBMEMORY_C (*database)[2],int row_num,int* rtrnArray,int (*CompFun)(CompFunType ch1,CompFunType ch2))//The final output is in a sequence from small to large.
{
	DBMEMORY_C tempArray[row_num];
	DBMEMORY_C compArray[row_num];
	ReadArray(database,row_num,tempArray);//Read the data needed to compare binary arrays into tempArray
	int row_counter=0;
	int row_locater=0;
	int comp_counter=0;
	
	while(row_counter!=row_num)//Get compArray (since the introduction of the CompFun function pointer, specific comparison method should be set by yourself
	{
		row_locater=0;
		comp_counter=0;
		while(row_locater<row_counter)
		{
			if(CompFun(tempArray[row_counter],tempArray[row_locater])==1)
				comp_counter++;
			row_locater++;
		}
		compArray[row_counter]=comp_counter;
		row_counter++;
	}
	GetRtrnArray(compArray,rtrnArray,row_num);
}

int accum(int *p, int n,  int *acsmap)
{
    int acmres = 0;
    for(int i = 0; i < n; i++)
    {
        acmres = p[acsmap[i]];
    }
	return acmres;
}

void setAllTable(tbl *pprovider, tbl *puser, tbl *pbillinfo, tbl *ptelerecord, tbl *pnetrecord, tbl *padmin, tbl *pset, tbl *pmoneyrecord)
{
	char *name,**iteml;

	tbl provider = giveBlankTbl();
	name=fillnam("provider");
	setInfo(&provider.info,name,2,1,0,0);
	iteml=constructD1_charp(getClmNum(provider.info),NULL);
	iteml[0]=fillnam("IDp");
	iteml[1]=fillnam("validp");
	iteml[2]=fillnam("provName");
	provider.pitem=iteml;

	tbl user = giveBlankTbl();
	name=fillnam("user");
	setInfo(&user.info,name,5,5,0,0);
	iteml=constructD1_charp(getClmNum(user.info),NULL);
	iteml[0]=fillnam("IDu");
	iteml[1]=fillnam("validu");
	iteml[2]=fillnam("gender");
	iteml[3]=fillnam("accType");
	iteml[4]=fillnam("IDp");
	iteml[5]=fillnam("userName");
	iteml[6]=fillnam("userID");
	iteml[7]=fillnam("teleNum");
	iteml[8]=fillnam("userPWphnam");
	iteml[9]=fillnam("userEmailphnam");
	user.pitem=iteml;
	
	tbl billinfo = giveBlankTbl();
	name=fillnam("billinfo");
	setInfo(&billinfo.info,name,11,0,0,0);
	iteml=constructD1_charp(getClmNum(billinfo.info),NULL);
	iteml[0]=fillnam("IDu");
	iteml[1]=fillnam("IDs");
	iteml[2]=fillnam("validb");
	iteml[3]=fillnam("borUse");
	iteml[4]=fillnam("forUse");
	iteml[5]=fillnam("netUse");
	iteml[6]=fillnam("borRem");
	iteml[7]=fillnam("forRem");
	iteml[8]=fillnam("netRem");
	iteml[9]=fillnam("sumFee");
	iteml[10]=fillnam("moneyRem");
	billinfo.pitem = iteml;
	
	tbl telerecord = giveBlankTbl();
	name=fillnam("telerecord");
	setInfo(&telerecord.info,name,5,1,2,0);
	iteml=constructD1_charp(getClmNum(telerecord.info),NULL);
    iteml[0]=fillnam("IDt");
	iteml[1]=fillnam("validt");
	iteml[2]=fillnam("type");
	iteml[3]=fillnam("teleFee");
	iteml[4]=fillnam("IDu");
	iteml[5]=fillnam("to");
	iteml[6]=fillnam("startTime");
	iteml[7]=fillnam("endTime");
	telerecord.pitem = iteml;
	
	tbl netrecord = giveBlankTbl();
	name=fillnam("netrecord");
	setInfo(&netrecord.info,name,5,0,1,0);
    iteml=constructD1_charp(getClmNum(netrecord.info),NULL);
    iteml[0]=fillnam("IDn");
    iteml[1]=fillnam("validn");
	iteml[2]=fillnam("comAmout");
	iteml[3]=fillnam("netFee");
	iteml[4]=fillnam("IDU");
	iteml[5]=fillnam("time");
	netrecord.pitem = iteml;
	
	tbl admin = giveBlankTbl();
	name=fillnam("admin");
	setInfo(&admin.info,name,3,4,0,0);
	iteml=constructD1_charp(getClmNum(admin.info),NULL);
	iteml[0]=fillnam("IDa");
	iteml[1]=fillnam("valida");
	iteml[2]=fillnam("IDp");
	iteml[3]=fillnam("adminID");
	iteml[4]=fillnam("adminName");
	iteml[5]=fillnam("adminPW");
	iteml[6]=fillnam("adminEmail");
	admin.pitem = iteml;

    tbl set = giveBlankTbl();
	name=fillnam("set");
	setInfo(&set.info,name,6,2,0,0);
	iteml=constructD1_charp(getClmNum(set.info),NULL);
	iteml[0]=fillnam("IDs");
	iteml[1]=fillnam("valids");
	iteml[2]=fillnam("IDp");
	iteml[3]=fillnam("price");
	iteml[4]=fillnam("borTime");
	iteml[5]=fillnam("forTime");
	iteml[6]=fillnam("setname");
    iteml[7]=fillnam("description");
	set.pitem = iteml;
	
    tbl moneyrecord = giveBlankTbl();
    name=fillnam("moneyrecord");
	setInfo(&moneyrecord.info,name,5,0,1,0);
	iteml=constructD1_charp(getClmNum(moneyrecord.info),NULL);
	iteml[0]=fillnam("IDd");
	iteml[1]=fillnam("validd");
	iteml[2]=fillnam("IDu");
	iteml[3]=fillnam("IDs");
	iteml[4]=fillnam("fee");
	iteml[5]=fillnam("dealTime");
	moneyrecord.pitem = iteml;

	*pprovider = provider;
	*puser = user;
	*pbillinfo = billinfo;
	*ptelerecord = telerecord;
	*pnetrecord = netrecord;
	*padmin = admin;
	*pset = set;
	*pmoneyrecord = moneyrecord;

	name = NULL;
	iteml = NULL;
}

int existFirstTime(tbl provider, tbl user, tbl billinfo, tbl telerecord, tbl netrecord, tbl admin, tbl set, tbl moneyrecord)
{
	return (isFirstTime(provider) || isFirstTime(set) || isFirstTime(user) || isFirstTime(billinfo) || 
	   isFirstTime(telerecord) || isFirstTime(netrecord) || isFirstTime(moneyrecord) || isFirstTime(admin));
}

void initAllTable(tbl *pprovider, tbl *puser, tbl *pbillinfo, tbl *ptelerecord, tbl *pnetrecord, tbl *padmin, tbl *pset, tbl *pmoneyrecord)
{
	initTable(pprovider);
	initTable(pset);
	initTable(puser);
	initTable(pbillinfo);
	initTable(ptelerecord);
	initTable(pnetrecord);
	initTable(pmoneyrecord);
	initTable(padmin);
}

void readAllTable(tbl *pprovider, tbl *puser, tbl *pbillinfo, tbl *ptelerecord, tbl *pnetrecord, tbl *padmin, tbl *pset, tbl *pmoneyrecord)
{
	exposeTable(pprovider);
	exposeTable(puser);
	exposeTable(pbillinfo);
	exposeTable(ptelerecord);
	exposeTable(pnetrecord);
	exposeTable(padmin);
	exposeTable(pset);
	exposeTable(pmoneyrecord);
}

void writeAllTable(tbl *pprovider, tbl *puser, tbl *pbillinfo, tbl *ptelerecord, tbl *pnetrecord, tbl *padmin, tbl *pset, tbl *pmoneyrecord)
{
	encloseTable(pprovider);
	encloseTable(puser);
	encloseTable(pbillinfo);
	encloseTable(ptelerecord);
	encloseTable(pnetrecord);
	encloseTable(padmin);
	encloseTable(pset);
	encloseTable(pmoneyrecord);
}


#endif
