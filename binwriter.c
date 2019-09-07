#include"dbstruct.h"
#include"dboperation.c"
#include"arraysupport.c"

#include<stdio.h>
#define STRLENLIMIT 16



int main()
{
    tblinfo info;
    tblclmh clm;
    scanf("%d%d%d%d", &info.rowNum, &info.intNum, &info.namNum, &info.timNum);
    printf("please enter %d ints in one row, and write %d rows\n", info.intNum + 6 * info.timNum, info.rowNum);
    
    clm.phint = assignChart_int(info.rowNum);
    clm.phtim = assignChart_tim(info.rowNum);
    clm.phnam = assignChart_nam(info.rowNum);
    for(int i = 0; i < info.rowNum; i++)
    {
        for(int j = 0; j < info.intNum; j++)
        {
            scanf("%d", &clm.phint[i][j]);
        }
        for(int j = 0; j < info.timNum; j++)
        {
            scanf("%d", &clm.phtim[i][j].yea);
            scanf("%d", &clm.phtim[i][j].mon);
            scanf("%d", &clm.phtim[i][j].day);
            scanf("%d", &clm.phtim[i][j].hou);
            scanf("%d", &clm.phtim[i][j].min);
            scanf("%d", &clm.phtim[i][j].sec);
        }
    }
    printf("please enter %d str.\n", info.rowNum * info.namNum);
    for(int i = 0; i < info.rowNum; i++)
    {
        for(int j = 0; j < info.namNum; j++)
        {
            scanf("%s", clm.phnam[i][j]);
        }
    }
    FILE* pfile = fopen("netecord.idat", "wb");
    writeidat(pfile, info, &clm, 30);
    fclose(pfile);
    
    pfile = fopen("netrecord.cdat", "wb");
    writecdat(pfile, info, &clm, 30);
    fclose(pfile);
    return 0;
}
