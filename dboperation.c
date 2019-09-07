#ifndef DBOPERATION_C
#define DBOPERATION_C

#include"arraysupport.c"
#include"dbstruct.h"
#include"displaysupport.c"
#include<string.h>

tblclmh giveBlankClmh(void);
tblinfo giveBlankInfo(void);
tbl giveBlankTbl(void);
tim giveBlankTim(void);

char* fillnam(const char *p);  // support the function fill name
void setInfo(tblinfo *pinfo, int intNum, int strNum, int timNum, int rowNum); //set info
int getClmNum(tblinfo info); // get the number of each column

int myxor(int a, int b);

int** assignChart_int(int rowNum);
char*** assignChart_nam(int rowNum);
tim** assignChart_tim(int rowNum);

void resignChart_int(int **ppint, int rowNum);
void resignChart_nam(char ***pppchar, int rowNum);
void resignChart_tim(tim **pptim, int rowNum);

void addrow(tbl *table, int *introw, char **namrow, tim *timrow); // add a new row to chart

tblclmh giveBlankClmh(void)
{
    tblclmh newclmh;
    newclmh.phint = NULL;
    newclmh.phnam = NULL;
    newclmh.phtim = NULL;
}
//give the form a new blank column head

tblinfo giveBlankInfo(void)
{
    tblinfo info;
    info.intNum = 0;
    info.namNum = 0;
    info.timNum = 0;
    info.rowNum = 0;
    return info;
}
//give the form new blank info

tbl giveBlankTbl(void)
{
    tbl table;
    table.info = giveBlankInfo();
    table.lrn = 0;
    table.clm = giveBlankClmh(); 
    return table;
}
//give a new blank form

tim giveBlankTim(void)
{
    tim blankTim;
    blankTim.yea = 0;
    blankTim.mon = 0;
    blankTim.day = 0;
    blankTim.hou = 0;
    blankTim.min = 0;
    blankTim.sec = 0;
    return blankTim;
}
// give a new time to the form

char* fillnam(const char *p) //you need to free the pointer // support the function fill name
{
    char* newnam = (char*)malloc(sizeof(char) * STRLENLIMIT);
    if(newnam != NULL)
    {
        strncpy(newnam, p, STRLENLIMIT);
    }
    return newnam;
}
void setInfo(tblinfo *pinfo, int intNum, int namNum, int timNum, int rowNum) // set infoo
{
    pinfo->intNum = intNum;
    pinfo->namNum = namNum;
    pinfo->timNum = timNum;
    pinfo->rowNum = rowNum;
}

int getClmNum(tblinfo info) // get the number of each column
{
    return info.intNum + info.namNum + info.timNum;
}

int myxor(int a, int b)
{
	return (!a && b) || (a && !b);
}

int** assignChart_int(int rowNum)
{
    int **ppi = constructD2_int(rowNum, 11, 0);
    if(ppi == NULL)
        printf("[NULL int]\n");
    return ppi;
}
char*** assignChart_nam(int rowNum)
{
    char ***pppc;
    pppc = constructD3_char(rowNum, 5, STRLENLIMIT,'\0');
    if(pppc == NULL)
        printf("[NULL nam]\n");
    return pppc;
}

tim** assignChart_tim(int rowNum)
{
    tim **ppt;
    ppt = constructD2_tim(rowNum, 2, giveBlankTim());
    if(ppt == NULL)
        printf("[NULL tim]\n");
    return ppt;
}

void resignChart_int(int **ppi, int rowNum)
{
    destroyD2_int(ppi, rowNum);
}
void resignChart_nam(char ***pppc, int rowNum)
{
    destroyD3_char(pppc, rowNum, 2);
}
void resignChart_tim(tim **ppt, int rowNum)
{
    destroyD2_tim(ppt, rowNum);
}
tblinfo readidat(FILE *pfile, tblclmh *pclm, int lrn)
{
    tblinfo info;
    fread(&info.rowNum, sizeof(int), 1, pfile);
    fread(&info.intNum, sizeof(int), 1, pfile);
    fread(&info.namNum, sizeof(int), 1, pfile);
    fread(&info.timNum, sizeof(int), 1, pfile);
    pclm->phint = assignChart_int(lrn);
    pclm->phtim = assignChart_tim(lrn);
    for(int i = 0; i < info.rowNum; i++)
    {
        fread(pclm->phint[i], sizeof(int), info.intNum, pfile);
        for(int j = 0; j < info.timNum; j++)
        {
            fread(&pclm->phtim[i][j].yea, sizeof(int), 1, pfile);
            fread(&pclm->phtim[i][j].mon, sizeof(int), 1, pfile);
            fread(&pclm->phtim[i][j].day, sizeof(int), 1, pfile);
            fread(&pclm->phtim[i][j].hou, sizeof(int), 1, pfile);
            fread(&pclm->phtim[i][j].min, sizeof(int), 1, pfile);
            fread(&pclm->phtim[i][j].sec, sizeof(int), 1, pfile);  
        } 
    }
    return info;
}

void readcdat(FILE *pfile, tblinfo info, tblclmh *pclm, int lrn)
{
    pclm->phnam = assignChart_nam(lrn);
    for(int i = 0; i < info.rowNum; i++)
    {
        for(int j = 0; j < info.namNum; j++)
        {
            fread(pclm->phnam[i][j], sizeof(char), STRLENLIMIT, pfile);
        }
    }
}

void writeidat(FILE *pfile, tblinfo info, tblclmh *pclm, int lrn)
{
    fwrite(&info.rowNum, sizeof(int), 1, pfile);
    fwrite(&info.intNum, sizeof(int), 1, pfile);
    fwrite(&info.namNum, sizeof(int), 1, pfile);
    fwrite(&info.timNum, sizeof(int), 1, pfile);
    for(int i = 0; i < info.rowNum; i++)
    {
        fwrite(pclm->phint[i], sizeof(int), info.intNum, pfile);
        for(int j = 0; j < info.timNum; j++)
        {
            fwrite(&pclm->phtim[i][j].yea, sizeof(int), 1, pfile);
            fwrite(&pclm->phtim[i][j].mon, sizeof(int), 1, pfile);
            fwrite(&pclm->phtim[i][j].day, sizeof(int), 1, pfile);
            fwrite(&pclm->phtim[i][j].hou, sizeof(int), 1, pfile);
            fwrite(&pclm->phtim[i][j].min, sizeof(int), 1, pfile);
            fwrite(&pclm->phtim[i][j].sec, sizeof(int), 1, pfile);  
        } 
    }
    //resignChart_int(pclm->phint, lrn);
    //resignChart_tim(pclm->phtim, lrn);
}

void writecdat(FILE *pfile, tblinfo info, tblclmh *pclm, int lrn)
{
    for(int i = 0; i < info.rowNum; i++)
    {
        for(int j = 0; j < info.namNum; j++)
        {
            fwrite(pclm->phnam[i][j], sizeof(char), STRLENLIMIT, pfile);
        }
    }
    //resignChart_nam(pclm->phnam, lrn);
}

void cpyrow(tbl *ptable, int *introw, char **namrow, tim *timrow)
{
	for(int i = 0; i < ptable->info.intNum; i++)
    {
        ptable->clm.phint[i][ptable->info.rowNum] = introw[i];
    }

    for(int i = 0; i < ptable->info.namNum; i++)
    {
        strncpy(ptable->clm.phnam[i][ptable->info.rowNum], namrow[i], STRLENLIMIT);
    }
    
    for(int i = 0; i < ptable->info.timNum; i++)
    {
        ptable->clm.phtim[i][ptable->info.rowNum] = timrow[i];
    }

    ptable->info.rowNum = ptable->info.rowNum + 1;
}

void display_tbl(tbl table)
{
    int **ppint = table.clm.phint;
    char ***ppnam = table.clm.phnam;
    tim **pptim = table.clm.phtim;
    for(int i = 0; i < table.info.rowNum; i++)
    {
        for (int j = 0; j < table.info.intNum; j++)
        {
            display_int(ppint[i][j]);
            printf("|");
        }
        for (int j = 0; j < table.info.namNum; j++)
        { 
            display_nam(ppnam[i][j]);
            printf("|");
        }
        for (int j = 0; j < table.info.timNum; j++)
        {
            display_tim(pptim[i][j]);
            printf("|");
        }
        printf("\n");    
    }
}
#endif
