#ifndef DBSTRUCT_H
#define DBSTRUCT_H
#define STRLENLIMIT 16
#define TBLINFONUM 8
#define EXPPT 20// expand per tim

int indent = 0;
char diagL[80];

typedef struct yymmddhhmmss
{
    int yea;
    int mon;
    int day;
    int hou;
    int min;
    int sec;
} tim;
// support the function to store the time 

typedef struct tableinfo
{
    char *name;
    int intNum;
    int namNum;
    int timNum;
    int rowNum;
} tblinfo;
//support the function to store the number of data

typedef struct tablecolumn
{
    int **phint; // pointer to the head of a list of int, all the same.
    char ***phnam;
    tim **phtim;
} tblclmh; // column head
//support the function to store each column head

typedef struct table
{
    tblinfo info;
    char **pitem;
    int lrn; // located row number
    tblclmh clm;
} tbl;
//support the function to store the record about the form

#endif
