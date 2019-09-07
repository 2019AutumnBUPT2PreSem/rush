#include<stdio.h>
void FileReader(FILE *pfile,tbl *ptable)
{
	int int_num=ptable->info.intNum;
	int nam_num=ptable->info.namNum;
	int time_num=ptable->info.timNum;
	int row_num=ptable->info.rowNum;
	int row=0;
	int line=0;
	char a;
	while(row<row_num)
	{
		line=0;
		while(line<int_num+nam_num+time_num)
		{
			if(line<int_num)
			{
				fscanf(pfile,"%d",&ptable->clm.phint[row][line]);
				a=fgetc(pfile);
			}
			else if((line>=int_num)&&(line<int_num+nam_num))
			{
				fscanf(pfile,"%s",ptable->clm.phnam[row][line-int_num]);
				a=fgetc(pfile);
			}
			else if(line>=int_num+nam_num)
			{
				fscanf(pfile,"%d/%d/%d %d:%d:%d",&ptable->clm.phtim[row][line-int_num-nam_num].yea,&ptable->clm.phtim[row][line-int_num-nam_num].mon,&ptable->clm.phtim[row][line-int_num-nam_num].day,&ptable->clm.phtim[row][line-int_num-nam_num].hou,&ptable->clm.phtim[row][line-int_num-nam_num].min,&ptable->clm.phtim[row][line-int_num-nam_num].sec);
				a=fgetc(pfile);
			}
			line++;
		}
		row++;
	}
	a=fgetc(pfile);	
}

int FileWriter(FILE *pfile, tbl table)
{
	for(int i = 0; i < table.info.rowNum; i++)
	{
		for(int j = 0; j < table.info.intNum; j++)
		{
			fprintf(pfile, "%d ", table.clm.phint[i][j]);
			if((j + 1) < table.info.intNum)
			{
				fprintf(pfile, " ");
			}
		}
		for(int j = 0; j < table.info.namNum; j++)
		{
			if(table.info.intNum > 0 || j > 0)
			{
				fprintf(pfile, " ");
			}
			fprintf(pfile, "%s", table.clm.phnam[i][j]);
		}
		for(int j = 0; j < table.info.timNum; j++)
		{
			if(table.info.namNum > 0 || j > 0)
			{
				fprintf(pfile, " ");
			}
			fprintf(pfile, "%02d/%02d/%02d %02d:%02d:%02d", table.clm.phtim[i][j].yea, table.clm.phtim[i][j].mon, table.clm.phtim[i][j].day, table.clm.phtim[i][j].hou, table.clm.phtim[i][j].min, table.clm.phtim[i][j].sec);
		}
		fprintf(pfile, "\n");
	}
}


