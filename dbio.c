#ifndef DBIO_C
#define DBIO_C

#include<stdio.h>
#include"dbstruct.h"
#include"dboperation.c"

/*
in 1 file ther will be 16 char and 4 int to describe the chart follows.
16 char is for name,
the ints are:
1 intNum
2 namNum
3 timNum
4 rowNum
*/

extern int indent;
extern char diagL[80];

void readHead(FILE *pfile, tblinfo *pinfo);
// read the header from the file
void writeHead(FILE *pfile, tblinfo info);
// write the header into the file
void trscptHead(FILE *pfile, tblinfo *pinfo);
// support the function both apply space and copy content
void revtrsHead(FILE *pfile, tblinfo *pinfo);
// reverse transcription
void readNameL(FILE *pfile, int clmNum, char **pitem);
// read the data from the file 
void writeNameL(FILE *pfile, int clmNum, char **pitem);
// write the data into the file
void trscptItem(FILE *pfile, tbl *ptable);
// support the function both apply space and copy item
void revtrsItem(FILE *pfile, tbl *ptable);
// reverse transcription
void readChart(FILE *pfile, tblinfo info, tblclmh clm);
// read the chart from the file 
void writeChart(FILE *pfile, tblinfo info, tblclmh clm);
// write the chart into the file 
void trscptChart(FILE *pfile, tbl *ptable);
// support the function both apply space and copy chart
void revtrsChart(FILE *pfile, tbl *ptable);
// reverse transcription
void readTable(FILE *pfile, tbl *ptable);
// read the structure from the file 
void writeTable(FILE *pfile, tbl *ptable);
// write the structure into the file
void initTable(tbl *ptable);
// need "wb"
void exposeTable(tbl *ptable);
void encloseTable(tbl *ptable);
int isFirstTime(tbl table);

void readHead(FILE *pfile, tblinfo *pinfo) // read the header from the file
{
    fread(pinfo->name, sizeof(char), STRLENLIMIT, pfile);
    fread(&pinfo->intNum, sizeof(int), 1, pfile);
    fread(&pinfo->namNum, sizeof(int), 1, pfile);
    fread(&pinfo->timNum, sizeof(int), 1, pfile);
    fread(&pinfo->rowNum, sizeof(int), 1, pfile);    
}
void writeHead(FILE *pfile, tblinfo info) // write the header into the file
{
    fwrite(info.name, sizeof(char), STRLENLIMIT, pfile);
    fwrite(&info.intNum, sizeof(int), 1, pfile);
    fwrite(&info.namNum, sizeof(int), 1, pfile);
    fwrite(&info.timNum, sizeof(int), 1, pfile);
    fwrite(&info.rowNum, sizeof(int), 1, pfile);
}


void trscptHead(FILE *pfile, tblinfo *pinfo) // support the function both apply space and copy content
{
    sprintf(diagL, "[trying to transcript info of table %s]\n", pinfo->name);
    displayDiagnos();

    indent++;
    pinfo->name = (char*)malloc(sizeof(char) * STRLENLIMIT);
    if(pinfo->name != NULL)
    {
        sprintf(diagL, "[memory checked, trying to read head]\n", pinfo->name);
        displayDiagnos();

        indent++;
        readHead(pfile, pinfo);// read the chart head
        indent--;

        sprintf(diagL, "[read done, show info]\n");
        displayDiagnos();
        displayInfo(*pinfo);
    }
    else
    {
        sprintf(diagL, "[there is not enough memory for table name]\n");
        displayDiagnos();
        *pinfo = giveBlankInfo();// give a blank info
    }
    indent--;
}
void revtrsHead(FILE *pfile, tblinfo *pinfo) // reverse transcription
{
    sprintf(diagL, "[trying to revert transcript info of table %s]\n", pinfo->name);
    displayDiagnos();

    indent++;
    if(pinfo->name != NULL)
    {
        writeHead(pfile, *pinfo);// write the header into the file

        sprintf(diagL, "[the following info will be erased]\n");
        displayDiagnos();
        displayInfo(*pinfo);

        indent++;
        destroyD1_char(pinfo->name);
        *pinfo = giveBlankInfo();
        indent--;

        sprintf(diagL, "[erase done.]\n");
        displayDiagnos();
    }
    else
    {
        sprintf(diagL, "[the head is already empty.]\n");
        displayDiagnos();
    }
    indent--;
}

void readNameL(FILE *pfile, int n, char **pitem) // read the data from the file 
{
    for(int i = 0; i < n; i++)
    {
        fread(pitem[i], sizeof(char), STRLENLIMIT, pfile);
    }
}
void writeNameL(FILE *pfile, int n, char **pitem) // write the data into the file
{
    for(int i = 0; i < n; i++)
    {
        fwrite(pitem[i], sizeof(char), STRLENLIMIT, pfile);
    }
}

void trscptItem(FILE *pfile, tbl *ptable) // support the function both apply space and copy item
{
    sprintf(diagL, "[trying to transcript item list of table %s]\n", ptable->info.name);
    displayDiagnos();

    indent++;
    char **newiteml = constructD2_char(getClmNum(ptable->info), STRLENLIMIT, '\0');
    if(newiteml != NULL)
    {
        sprintf(diagL, "[memory checked, start to read item list]\n");
        displayDiagnos();

        indent++;
        readNameL(pfile, getClmNum(ptable->info), newiteml);
        ptable->pitem = newiteml;
        indent--;

        sprintf(diagL, "[read done, show item list]\n");
        displayDiagnos();
        displayInfo(ptable->info);
        displayItem(getClmNum(ptable->info), ptable->pitem);
    }
    else
    {
        sprintf(diagL, "[stire all]\n");
        displayDiagnos();
        
        indent++;
        *ptable = giveBlankTbl();
        indent--;
    }
    indent--;
}
void revtrsItem(FILE *pfile, tbl *ptable) // reverse transcription
{
    sprintf(diagL, "[trying to revert transcript item list of table %s]\n", ptable->info.name);
    displayDiagnos();

    indent++;
    if(ptable->pitem != NULL)
    {
        sprintf(diagL, "[item list fine, show item list]\n");
        displayDiagnos();
        displayItem(getClmNum(ptable->info), ptable->pitem);

        indent++;
        writeNameL(pfile, getClmNum(ptable->info), ptable->pitem);
        destroyD2_char(ptable->pitem, getClmNum(ptable->info));
        ptable->pitem = NULL;
        indent--;

        sprintf(diagL, "[write done, erased]\n");
        displayDiagnos();
    }
    else
    {
        sprintf(diagL, "[the item is already empty]\n");
        displayDiagnos();
    }
    indent--;
}

void readChart(FILE *pfile, tblinfo info, tblclmh clm) // read the chart from the file 
{
    sprintf(diagL, "[try to assign and copy row pointer]\n");
    displayDiagnos();

    tblclmh temp = assignTblclmh(info);
    cpyTblclmh(info, clm, temp);

    sprintf(diagL, "[assign and copy row pointer done]\n");
    displayDiagnos();
    
    for(int i = 0; i < info.rowNum; i++)
    {
        for (int j = 0; j < info.intNum; j++)
        {
            fread(temp.phint[j],sizeof(int), 1, pfile);
            temp.phint[j]++;
        }
        for (int j = 0; j < info.namNum; j++)
        {
            fread(temp.phnam[j],sizeof(char), STRLENLIMIT, pfile);
            temp.phnam[j]++;
        }
        for (int j = 0; j < info.timNum; j++)
        {
            fread(temp.phtim[j],sizeof(tim), 1, pfile);
            temp.phtim[j]++;
        }
    }

    sprintf(diagL, "[try to resign temp row pointer]\n");
    displayDiagnos();

    resignTblclmh(temp);

    sprintf(diagL, "[resign temp row pointer done]\n");
    displayDiagnos();
}
void writeChart(FILE *pfile, tblinfo info, tblclmh clm) // write the chart into the file 
{
    sprintf(diagL, "[writting chart, assigning and copying row pointer]\n");
    displayDiagnos();

    indent++;
    tblclmh temp = assignTblclmh(info);
    cpyTblclmh(info, clm, temp);
    indent--;

    sprintf(diagL, "[assign and copy row pointer done, write %d row]\n", info.rowNum);
    displayDiagnos();

    for(int i = 0; i < info.rowNum; i++)
    {
        for (int j = 0; j < info.intNum; j++)
        {
            fwrite(temp.phint[j],sizeof(int), 1, pfile);
            temp.phint[j]++;
        }
        for (int j = 0; j < info.namNum; j++)
        { 
            fwrite(temp.phnam[j],sizeof(char), STRLENLIMIT, pfile);
            temp.phnam[j]++;
        }
        for (int j = 0; j < info.timNum; j++)
        {
            fwrite(temp.phtim[j],sizeof(tim), 1, pfile);
            temp.phtim[j]++;
        }
    }
    resignTblclmh(temp); //need to be done
}

void trscptChart(FILE *pfile, tbl *ptable) // support the function both apply space and copy chart
{
    sprintf(diagL, "[trying to transcript chart of table %s]\n", ptable->info.name);
    displayDiagnos();

    ptable->clm = assignTblChart(ptable->info);

    indent++;
    if(myxor(ptable->clm.phint == NULL, ptable->info.intNum == 0) || 
        myxor(ptable->clm.phnam == NULL, ptable->info.namNum == 0) || 
        myxor(ptable->clm.phtim == NULL, ptable->info.timNum == 0))
    {
        sprintf(diagL, "[memory not enough, fail, stire all]\n");
        displayDiagnos();

        indent++;
        resignTblChart(ptable->clm, ptable->info);
        ptable->clm = giveBlankClmh();
        ptable->lrn = 0;
        indent--;
    }
    else
    {
        sprintf(diagL, "[memory checked, start to read]\n");
        displayDiagnos();

        indent++;
        ptable->lrn = ptable->info.rowNum;
        readChart(pfile, ptable->info, ptable->clm);
        indent--;

        sprintf(diagL, "[read done]\n");
        displayDiagnos();
    }
    indent--;
}
void revtrsChart(FILE *pfile, tbl *ptable) // reverse transcription
{
    sprintf(diagL, "[trying to revert transcript chart of table %s]\n", ptable->info.name);
    displayDiagnos();

    indent++;
    if((myxor(ptable->clm.phint == NULL, ptable->info.intNum == 0) || 
        myxor(ptable->clm.phnam == NULL, ptable->info.namNum == 0) || 
        myxor(ptable->clm.phtim == NULL, ptable->info.timNum == 0)) && ptable->info.rowNum != 0)
    {
        sprintf(diagL, "[the chart has lost blocks, write denied, stire all]\n");
        displayDiagnos();
    }
    else
    {
        sprintf(diagL, "[memory checked, start write]\n");
        displayDiagnos();

        indent++;
        writeChart(pfile, ptable->info, ptable->clm);
        indent--;

        sprintf(diagL, "[write done]\n");
        displayDiagnos();
    }
    indent++;
    resignTblChart(ptable->clm, ptable->info);
    ptable->clm = giveBlankClmh();
    indent--;
    
    indent--;
}

void readTable(FILE *pfile, tbl *ptable) //read the structure from the file 
{
    sprintf(diagL, "[trying to read table %s]\n", ptable->info.name);
    displayDiagnos();

    indent++;
    trscptHead(pfile, &ptable->info);
    if(ptable->info.name == NULL)
    {
        sprintf(diagL, "[read table abort since read head failed]\n");
        displayDiagnos();
    }
    else
    {
        trscptItem(pfile, ptable);
        if(ptable->pitem == NULL)
        {
            sprintf(diagL, "[read table abort since read item list failed]\n");
            displayDiagnos();
        }
        else
        {
            trscptChart(pfile, ptable);
            if(myxor(ptable->clm.phint == NULL, ptable->info.intNum == 0) || 
               myxor(ptable->clm.phnam == NULL, ptable->info.namNum == 0) || 
               myxor(ptable->clm.phtim == NULL, ptable->info.timNum == 0))
            {
                sprintf(diagL, "[read table abort since read chart failed]\n");
                displayDiagnos();
            }
            else
            {
                sprintf(diagL, "[read table done]\n");
                displayDiagnos();
            }
        }
    }
    indent--;

    sprintf(diagL, "[read table %s procedure done]\n", ptable->info.name);
    displayDiagnos();
}
void writeTable(FILE *pfile, tbl *ptable) // write the structure into the file
{
    sprintf(diagL, "[trying to write table %s]\n", ptable->info.name);
    displayDiagnos();
    
    indent++;
    if(ptable->info.name != NULL && ptable->pitem != NULL && 
        ((!myxor(ptable->clm.phint == NULL, ptable->info.intNum == 0) &&
        !myxor(ptable->clm.phnam == NULL, ptable->info.namNum == 0) && 
        !myxor(ptable->clm.phtim == NULL, ptable->info.timNum == 0)) || ptable->info.rowNum == 0) &&
		ptable->lrn >= ptable->info.rowNum)
    {
        sprintf(diagL, "[all checked, start to write info]\n");
        displayDiagnos();
        displayInfo(ptable->info);

        indent++;
        writeHead(pfile, ptable->info);
        indent--;

        sprintf(diagL, "[write info done]\n");
        displayDiagnos();

        revtrsItem(pfile, ptable);
        revtrsChart(pfile, ptable);

        sprintf(diagL, "[erase info]\n");
        displayDiagnos();

        indent++;
        destroyD1_char(ptable->info.name);
        ptable->info = giveBlankInfo();
        indent--;

        sprintf(diagL, "[info erased]\n");
        displayDiagnos();
    }
    else
    {
        sprintf(diagL, "[table wrong, write denied, stire all]\n");
        displayDiagnos();

        indent++;
        resignTblChart(ptable->clm, ptable->info);
        destroyD2_char(ptable->pitem, getClmNum(ptable->info));
        destroyD1_char(ptable->info.name);
        indent--;

        sprintf(diagL, "[table stired]\n");
        displayDiagnos();
    }
    *ptable = giveBlankTbl();
    indent--;
}

void initTable(tbl *ptable)
{
	sprintf(diagL, "[tring to init table %s]\n", ptable->info.name);
    displayDiagnos();

    ptable->info.rowNum = 0;
    ptable->lrn = 0;
    if(ptable->info.name != NULL)
    {
        char *filename = fillfilenam(ptable->info.name);
        if(filename != NULL)
        {
            FILE *pfile = fopen(filename, "wb");

            indent++;
            ptable->clm =  assignTblChart(ptable->info);
            writeTable(pfile, ptable);
            indent--;

            fclose(pfile);
            destroyD1_char(filename);
        }
        else
        {
            sprintf(diagL, "[file name not yet assigned]\n");
            displayDiagnos();
        }
    }
    else
    {
        sprintf(diagL, "[idiot, you've written wrong info]\n");
        displayDiagnos();
    }
}

void exposeTable(tbl *ptable)
{
	sprintf(diagL, "[tring to open file and read table %s]\n", ptable->info.name);
    displayDiagnos();

    if(ptable->info.name != NULL)
    {
        char *filename = fillfilenam(ptable->info.name);
        if(filename != NULL)
        {
            FILE *pfile = fopen(filename, "rb");

            indent++;
            readTable(pfile, ptable);
            indent--;

            fclose(pfile);
            destroyD1_char(filename);

            sprintf(diagL, "[open file and read table done]\n");
            displayDiagnos();
        }
        else
        {
            sprintf(diagL, "[file name not yet assigned]\n");
            displayDiagnos();
        }
    }
    else
    {
        sprintf(diagL, "[idiot, you've written wrong info]\n");
        displayDiagnos();
    }
}

void encloseTable(tbl *ptable)
{
	sprintf(diagL, "[tring to write table %s and close file]\n", ptable->info.name);
    displayDiagnos();

    if(ptable->info.name != NULL)
    {
        char *filename = fillfilenam(ptable->info.name);
        if(filename != NULL)
        {
            FILE *pfile = fopen(filename, "wb");

            indent++;
            writeTable(pfile, ptable);
            indent--;

            fclose(pfile);
            destroyD1_char(filename);

            sprintf(diagL, "[write table and close file done]\n");
            displayDiagnos();
        }
        else
        {
            sprintf(diagL, "[file name not yet assigned]\n");
            displayDiagnos();
        }
    }
    else
    {
        sprintf(diagL, "[idiot, you've written wrong info]\n");
        displayDiagnos();
    }
}

int isFirstTime(tbl table)
{
	char c;
    char *filename = fillfilenam(table.info.name);
    FILE *pfile = fopen(filename, "rb");
    free(filename);
    fread(&c, sizeof(char), 1, pfile);
    if(feof(pfile))
    {
		fclose(pfile);
        sprintf(diagL, "[The programme is running for the first time.]\n");
        displayDiagnos();
        return 1;
    }
    else
    {
    	fclose(pfile);
        return 0;
    }
    
}
#endif
