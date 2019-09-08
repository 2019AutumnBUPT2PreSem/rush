#ifndef PROCEDURE_C
#define PROCEDURE_C

#include "dboperation.c"
#include "interface.c"

/* You can find all you need in main.c, including the ignored part in the end, in service.c, in addition.c.
 * just set up procedures, which cotain multiple pages and services, pages are what the computer shows, 
 * while services are dirty works for computer to do such as list the ID and sort them.
 */

int loadTable(tbl *pprovider, tbl *puser, tbl *pbillinfo, tbl *ptelerecord, tbl *pnetrecord, tbl *padmin, tbl *psets, tbl *pmoneyrecord);
int saveTable(tbl provider, tbl user, tbl billinfo, tbl telerecord, tbl netrecord, tbl admin, tbl sets, tbl moneyrecord);


int loadTable(tbl *pprovider, tbl *puser, tbl *pbillinfo, tbl *ptelerecord, tbl *pnetrecord, tbl *padmin, tbl *psets, tbl *pmoneyrecord)
{
	FILE *pfile;

    pprovider->lrn = 30;
	pfile=fopen("provider.idat","rb");
	pprovider->info = readidat(pfile, &pprovider->clm, pprovider->lrn);
	fclose(pfile);

	pfile=fopen("provider.cdat","rb");
	readcdat(pfile, pprovider->info, &pprovider->clm, pprovider->lrn);
	fclose(pfile);

	///////////////////
	padmin->lrn =30;
	pfile=fopen("admin.idat","rb");
	padmin->info = readidat(pfile, &padmin->clm, padmin->lrn);
	fclose(pfile);

	pfile=fopen("admin.cdat","rb");
	readcdat(pfile, padmin->info, &padmin->clm, padmin->lrn);
	fclose(pfile);

	///////////////////
	ptelerecord->lrn = 30;
	pfile=fopen("telerecord.idat","rb");
	ptelerecord->info = readidat(pfile,&ptelerecord->clm, ptelerecord->lrn);
	fclose(pfile);	

	pfile=fopen("telerecord.cdat","rb");
	readcdat(pfile, ptelerecord->info, &ptelerecord->clm, ptelerecord->lrn);
	fclose(pfile);

	////////////////////
	pnetrecord->lrn = 30;
	pfile=fopen("netrecord.idat","rb");
	pnetrecord->info= readidat(pfile,&pnetrecord->clm,pnetrecord->lrn);
	fclose(pfile);

	pfile=fopen("netrecord.cdat","rb");
	readcdat(pfile,pnetrecord->info,&pnetrecord->clm,pnetrecord->lrn);
	fclose(pfile);

	////////////////////
	psets->lrn = 30;
	pfile=fopen("sets.idat","rb");
	psets->info= readidat(pfile,&psets->clm,psets->lrn);
	fclose(pfile);

	pfile=fopen("sets.cdat","rb");
	readcdat(pfile,psets->info,&psets->clm,psets->lrn);
	fclose(pfile);

	////////////////////
	puser->lrn = 30;
	pfile=fopen("user.idat","rb");
	puser->info = readidat(pfile,&puser->clm,puser->lrn);
	fclose(pfile);

	pfile=fopen("user.cdat","rb");
	readcdat(pfile,puser->info,&puser->clm,puser->lrn);
	fclose(pfile);

	////////////////////
	pmoneyrecord->lrn = 30;
	pfile=fopen("moneyrecord.idat","rb");
	pmoneyrecord->info = readidat(pfile,&pmoneyrecord->clm,pmoneyrecord->lrn);
	fclose(pfile);

	pfile=fopen("moneyrecord.cdat","rb");
	readcdat(pfile,pmoneyrecord->info,&pmoneyrecord->clm,pmoneyrecord->lrn);
	fclose(pfile);

	/////////////////////
	pbillinfo->lrn = 30;
	pfile=fopen("billinfo.idat","rb");
	pbillinfo->info=readidat(pfile,&pbillinfo->clm,pbillinfo->lrn);
	fclose(pfile);

	pfile=fopen("billinfo.cdat","rb");
	readcdat(pfile,pbillinfo->info,&pbillinfo->clm,pbillinfo->lrn);
	fclose(pfile);
}

int saveTable(tbl provider, tbl user, tbl billinfo, tbl telerecord, tbl netrecord, tbl admin, tbl sets, tbl moneyrecord)
{
    FILE *pfile;

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
}

int procedure_login();

#endif