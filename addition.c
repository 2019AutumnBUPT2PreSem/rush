void star()
{
	printf("*********************************************************************************************************************");
}

int userchoose(tbl* telerecord, tbl* billinfo,tbl* netrecord, tbl* user,  int IDu)
{
	
	int choose=0;
	
	while(choose!=8)
	{
        system("cls");
		choose=0;
		star();
		printf("\nPlease choose a function:\n");
		printf("1.dial\n2.net\n3.change information\n4.checkTeleRecord\n5.checkTeleRecordByTime\n6.checkNetRecord\n7.checkNetRecordByTime\n8.quit\n");
		scanf("%d",&choose);
		star();
		switch(choose)
		{
		case 1:
		{
			dial_user(telerecord, billinfo, IDu);
			printf("\n");
            printf("press enter to continue");
            getchar();
			return 0;
		}
		case 2:
		{
			net_user(netrecord, billinfo, IDu);
			printf("\n");
            printf("press enter to continue");
            getchar();
			return 0;
		}
		case 3:
		{
			changePersonInfo(user, IDu);
			printf("\n");
            printf("press enter to continue");
            getchar();
			return 0;
		}
		case 4:
		{
			
			checkTeleRecord(telerecord, IDu);
			printf("\n");
            printf("press enter to continue");
            getchar();
			return 0;
		}
		case 5:
		{
	
			checkTeleRecordByTime(telerecord, IDu);
			printf("\n");
            printf("press enter to continue");
            getchar();
			return 0;
		}
		case 6:
		{
			
			checkNetRecord(netrecord, IDu);
			printf("\n");
            printf("press enter to continue");
            getchar();
			return 0;
		}
		case 7:
		{
			
			checkNetRecordByTime(netrecord, IDu);
			printf("\n");
            printf("press enter to continue");
            getchar();
			return 0;
		}
		case 8:
		{
			return 1;	
		}
		default:
		{
			printf("Error!\n");
			return 0;
		}
		}
	}

}

int admchoose(tbl* telerecord, tbl* netrecord,  tbl* moneyrecord,tbl* sets,tbl* user,int provider, int IDa)
{
	int choose=0;
    system("cls");
	while(choose!=8)
	{
		star();
		printf("\nPlease choose a function:\n");
		printf("1.inquire provider set\n2.state dial\n3.sort telephone service by time\n4.sort total telefee\n5.checkset\n6.addnewset\n7.changeuserinfo\n8.quit\n");
		scanf("%d",&choose);
		star();
		switch(choose)
		{
		case 1:
		{
			
			stat(user, moneyrecord, IDa);
			printf("\n");
            printf("press enter to continue");
            getchar();
			return 0;
		}
		case 2:
		{
			
			stattele(telerecord, IDa);
			printf("\n");
			printf("press enter to continue");
            getchar();
            return 0;
		}
		case 3:
		{
			int type;
			printf("Please enter type:1.bor  2.for\n Your choice:");
			scanf("%d",&type);
			sortCallingByTimeSgmt(telerecord, type);
			printf("\n");
			printf("press enter to continue");
            getchar();
			return 0;
		}
		case 4:
		{
			sortFee(user,telerecord, netrecord, IDa);
			printf("\n");
			printf("press enter to continue");
            getchar();
			return 0;
		}
		case 5:
		{
			checkSet(sets, provider);
			printf("\n");
			 printf("press enter to continue");
            getchar();
			return 0;
		}
		case 6:
		{
			addNewSet(sets, provider);
			printf("\n");
			printf("press enter to continue");
            getchar();
			return 0;
		}
		case 7:
		{
            printf("please input the IDu of the user\n");
            int tempIDu=-1;
            scanf("%d",&tempIDu);
			changeUserInfo(user, IDa, tempIDu);
			printf("\n");
			printf("press enter to continue");
            getchar();
			return 0;
		}
		case 8:
		{
			return 1;	
		}
		default:
		{
			printf("Error!");
			return 0;
		}
		}
	}
	
}
