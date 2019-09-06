//Scarecrow and abyssdust
#ifndef ARRAYSUPPORT_C
#define ARRAYSUPPORT_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dbstruct.h"

/*______________________________________________________________________________________________*/
// construct supportive function that deals with int
#define _db_type int

#define _constructD1 constructD1_int
#define _constructD2 constructD2_int
#define _constructD3 constructD3_int
#define _destroyD1 destroyD1_int
#define _destroyD2 destroyD2_int
#define _destroyD3 destroyD3_int
#define _initD1 initD1_int
#define _initD2 initD2_int
#define _initD3 initD3_int
#define _extendD1 extendD1_int
#define _extendD2N extendD2N_int
#define _extendD2M extendD2M_int
#define _extendD3M extendD3M_int
#define _extendD3L extendD3L_int
#define _transpose transpose_int

#include "multitype.c"
/*______________________________________________________________________________________________*/
// construct supportive function that deals with char
#define _db_type char

#define _constructD1 constructD1_char
#define _constructD2 constructD2_char
#define _constructD3 constructD3_char
#define _destroyD1 destroyD1_char
#define _destroyD2 destroyD2_char
#define _destroyD3 destroyD3_char
#define _initD1 initD1_char
#define _initD2 initD2_char
#define _initD3 initD3_char
#define _extendD1 extendD1_char
#define _extendD2N extendD2N_char
#define _extendD2M extendD2M_char
#define _extendD3M extendD3M_char
#define _extendD3L extendD3L_char
#define _transpose transpose_char

#include "multitype.c"
/*______________________________________________________________________________________________*/
// construct supportive function that deals with tim
#define _db_type tim

#define _constructD1 constructD1_tim
#define _constructD2 constructD2_tim
#define _constructD3 constructD3_tim
#define _destroyD1 destroyD1_tim
#define _destroyD2 destroyD2_tim
#define _destroyD3 destroyD3_tim
#define _initD1 initD1_tim
#define _initD2 initD2_tim
#define _initD3 initD3_tim
#define _extendD1 extendD1_tim
#define _extendD2N extendD2N_tim
#define _extendD2M extendD2M_tim
#define _extendD3M extendD3M_tim
#define _extendD3L extendD3L_tim
#define _transpose transpose_tim

#include "multitype.c"
/*______________________________________________________________________________________________*/
// construct supportive function that deals with int*
//typedef int* intp;
#define _db_type int*

#define _constructD1 constructD1_intp
#define _constructD2 constructD2_intp
#define _constructD3 constructD3_intp
#define _destroyD1 destroyD1_intp
#define _destroyD2 destroyD2_intp
#define _destroyD3 destroyD3_intp
#define _initD1 initD1_intp
#define _initD2 initD2_intp
#define _initD3 initD3_intp
#define _extendD1 extendD1_intp
#define _extendD2N extendD2N_intp
#define _extendD2M extendD2M_intp
#define _extendD3M extendD3M_intp
#define _extendD3L extendD3L_intp
#define _transpose transpose_intp

#include "multitype.c"
/*______________________________________________________________________________________________*/
// construct supportive function that deals with char*
//typedef char* charp;
#define _db_type char*

#define _constructD1 constructD1_charp
#define _constructD2 constructD2_charp
#define _constructD3 constructD3_charp
#define _destroyD1 destroyD1_charp
#define _destroyD2 destroyD2_charp
#define _destroyD3 destroyD3_charp
#define _initD1 initD1_charp
#define _initD2 initD2_charp
#define _initD3 initD3_charp
#define _extendD1 extendD1_charp
#define _extendD2N extendD2N_charp
#define _extendD2M extendD2M_charp
#define _extendD3M extendD3M_charp
#define _extendD3L extendD3L_charp
#define _transpose transpose_charp

#include "multitype.c"
/*______________________________________________________________________________________________*/
// construct supportive function that deals with int
//typedef tim* timp;
#define _db_type tim*

#define _constructD1 constructD1_timp
#define _constructD2 constructD2_timp
#define _constructD3 constructD3_timp
#define _destroyD1 destroyD1_timp
#define _destroyD2 destroyD2_timp
#define _destroyD3 destroyD3_timp
#define _initD1 initD1_timp
#define _initD2 initD2_timp
#define _initD3 initD3_timp
#define _extendD1 extendD1_timp
#define _extendD2N extendD2N_timp
#define _extendD2M extendD2M_timp
#define _extendD3M extendD3M_timp
#define _extendD3L extendD3L_timp
#define _transpose transpose_timp

#include "multitype.c"
/*______________________________________________________________________________________________*/
// construct supportive function that deals with int
//typedef char** charpp;
#define _db_type char**

#define _constructD1 constructD1_charpp
#define _constructD2 constructD2_charpp
#define _constructD3 constructD3_charpp
#define _destroyD1 destroyD1_charpp
#define _destroyD2 destroyD2_charpp
#define _destroyD3 destroyD3_charpp
#define _initD1 initD1_charpp
#define _initD2 initD2_charpp
#define _initD3 initD3_charpp
#define _extendD1 extendD1_charpp
#define _extendD2N extendD2N_charpp
#define _extendD2M extendD2M_charpp
#define _extendD3M extendD3M_charpp
#define _extendD3L extendD3L_charpp
#define _transpose transpose_charpp

#include "multitype.c"
/*_________________________________function list_____________________________________________________________*/
int cmp_int(int a, int b);
int cmp_nam(char *a, char *b);
int cmp_tim(tim a, tim b);
//int cmp_float(float a, float b);
/*______________________________________________________________________________________________*/
int CompFun4Int(int comp,int comped)
{
	if(comp>comped)
		return 1;
	else if(comp==comped)
		return 0;
	else
		return -1;
}

int cmp_tim(tim a,tim b)
{
	if(a.yea>b.yea)
	{
		return 1;
	}
	else if(a.yea==b.yea)
	{
		if(a.mon>b.mon)
		{
			return 1;
		}
		else if(a.mon==b.mon)
		{
			if(a.day>b.day)
			{
				return 1;
			}
			else if(a.day==b.day)
			{
				if(a.hou>b.hou)
				{
					return 1;
				}
				else if(a.hou==b.hou)
				{
					if(a.min>b.min)
					{
						return 1;
					}
					else if(a.min==b.min)
					{
						if(a.sec>b.sec)
						{
							return 1;
						}
						else if(a.sec==b.sec)
						{
							return 0;
						}
						else if(a.sec<b.sec)
						{
							return -1;
						}
					}
					else
					{
						return -1;
					}
				}
				else
				{
					return -1;
				}
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
}

#endif
