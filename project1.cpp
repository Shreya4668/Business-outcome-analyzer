#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<graphics.h>

void loginPage();
void welcome();
void barGraphs();
void Predictor();
void Month_info();
int Month_ProfitOrLoss(int,int,int,int);
void Monthly_Input(char);
void Tracker(int,int,int,int,int);
int Sales_Predictor(int,int);
void password();

void welcome()
{

    int gd=DETECT,gm,i=0,x,xx,y,yy;  
	DWORD screenWidth  = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"",-2,-3); 
    x=getmaxx();  
    y=getmaxy();
    while(i<15)  
    {  
        i++;  
      //    setfillstyle(random(i),random(30));  
  
        circle(xx=rand()%x,yy=rand()%y,rand()%30);  
        setfillstyle(rand()%i,rand()%30);  
        floodfill(xx,yy,getmaxcolor());  
        delay(200);  
    }  
    i=0;
    while(i<15)  
    {  
        i++;  
      //    setfillstyle(random(i),random(30));  
  
        circle(xx=rand()%x,yy=rand()%y,rand()%30);  
        setfillstyle(rand()%i,rand()%30);  
        floodfill(xx,yy,getmaxcolor());  
        delay(200);  
    }  
    settextstyle(BOLD_FONT,HORIZ_DIR,5);
    outtextxy(420,410,(char*)"OIL BUSINESS OUTCOME ANALYZER");
    getch(); 
    closegraph();
}
void loginPage()
{

    int gd=DETECT,gm,i=0,x,xx,y,yy;  
	DWORD screenWidth  = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"",-2,-3); 
    x=getmaxx();  
    y=getmaxy();
    while(i<15)  
    {  
        i++;  
      //    setfillstyle(random(i),random(30));  
  
        circle(xx=rand()%x,yy=rand()%y,rand()%30);  
        setfillstyle(rand()%i,rand()%30);  
        floodfill(xx,yy,getmaxcolor());  
        delay(200);  
    }  
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    outtextxy(420,360,(char*)"Welcome user....");
    outtextxy(420,400,(char*)"You will be directed to login page soon...");
    delay(2000); 
    closegraph();	
}

void gotoxy(short col, short row)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {col,row};
    SetConsoleCursorPosition(h,position);
}

void password()
{
	XY:
	int i=0;
	char password[32], username[50],choice;
	FILE *fp;
    system("cls");
    gotoxy(30,15);
	system("COLOR 09");
	printf("If you are new user or want to edit your username or password enter 'e'");
	gotoxy(30,17);
	printf("If you are a existing user enter 'a'\n");
	gotoxy(30,19);
	printf("Your choice : ");
	scanf("\n%c",&choice);
    char ch;

	if(choice=='e')
	{
            system("cls");	
            system("COLOR 05"); 
	        gotoxy(40,15);	
	        printf("Enter the Username : ");
	        scanf("%s",username);
       	    printf("\n");
	        gotoxy(40,17);
	        printf("Enter the Password : ");
            do
	        { 
	            password[i]=_getch();
	            if(password[i] == 13)
                    {
                        password[i]='\0'; 
 	                    break;
	                }
	            else if(password[i] == ' ')
	                {
	                    continue;
                    }
                else if(password[i]== '\b')
	                {
	                    printf("\b \b");
		                i--;
	                }
	  	    
	            else	  
	                {
	                    printf("*");
                        i++;
	                }
	  
            }while(1);
	        fp=fopen("security.txt","w");
            fprintf(fp,"%s \n%s", username,password);
	        fclose(fp);
	        system("cls");
            system("COLOR 0C");
	        gotoxy(40,17); 
            printf("Your account is created/edited successfully\n");
	        gotoxy(40,19);
	        printf("Would you like to log in ? ");
	        gotoxy(40,21);
	        printf("If Yes enter y or enter any key for No/Quit:  ");
            scanf(" %c",&ch);
	        if(ch == 'y')
	        {
		            printf("%c\n",ch);
			        system("cls");
			        Monthly_Input('s');
            
	        }
	        system("cls");
            system("COLOR 07");

	}
	else if( choice=='a')
	{
	    Y:	
	    char check_username[50], check_password[32];	
	    i=0;
	    fp=fopen("security.txt","r");
	    system("cls");
	    system("COLOR 0D");
	    gotoxy(40,15);
        printf("Enter the Username : ");
	    scanf("\n%s",username);
       	printf("\n");
	    gotoxy(40,17);
	    printf("Enter the Password : ");
        do
	    { 
	        password[i] = _getch();
	        if(password[i] == 13)
            {
                password[i]='\0'; 
 	            break;
	        } 
	        else if(password[i] == ' ')
	        {
		        continue;
	        }
	        else if(password[i] == '\b')
            {
                printf("\b \b");
                i--;
	        }		
	        else	  
	       {	    
	            printf("*");
                i++;
	        }
	  
        }while(1); 
	    fscanf(fp,"%s \n%s",check_username,check_password);
        fclose(fp);
	    if(!(strcmp(check_username,username) || strcmp(check_password,password)))    
        {
          	int gd=DETECT,gm,i=0,x,xx,y,yy;  
           	DWORD screenWidth  = GetSystemMetrics(SM_CXSCREEN);
	        DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	        initwindow(screenWidth,screenHeight,"",-2,-3); 
            x=getmaxx();  
            y=getmaxy();
            while(i<12)  
            {  
                i++;  
                circle(xx=rand()%x,yy=rand()%y,rand()%30);  
                setfillstyle(rand()%i,rand()%30);  
                floodfill(xx,yy,getmaxcolor());   
            }  
            i=0;
           
            settextstyle(BOLD_FONT,HORIZ_DIR,3);
            outtextxy(420,430,(char*)"YOU HAVE LOGGED IN SUCCESSfULLY");
            _getch(); 
            closegraph();
		 
		    system("cls");
		    Sleep(50);
		    system("COLOR 0E");
		    Monthly_Input('s');
	    }
	    else
	    {
	        system("cls");
            system("COLOR 03");	     
	        int gd=DETECT,gm,i=0,x,xx,y,yy;  
	        DWORD screenWidth  = GetSystemMetrics(SM_CXSCREEN);
	        DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	        initwindow(screenWidth,screenHeight,"",-2,-3); 
            x=getmaxx();  
            y=getmaxy();
            while(i<13)  
            {  
                i++;  
                circle(xx=rand()%x,yy=rand()%y,rand()%30);  
                setfillstyle(rand()%i,rand()%30);  
                floodfill(xx,yy,getmaxcolor());   
            }  
            settextstyle(BOLD_FONT,HORIZ_DIR,3);
            outtextxy(480,440,(char*)"Invalid username/ password.");
            outtextxy(530,480,(char *)"Try again!!");
           _getch(); 
           closegraph();
	       goto Y;
           
	    }
	 
	}
	else
	{	  
       system("cls");
       system("COLOR 07");
       int gd=DETECT,gm,i=0,x,xx,y,yy;  
	   DWORD screenWidth  = GetSystemMetrics(SM_CXSCREEN);
	   DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	   initwindow(screenWidth,screenHeight,"",-2,-3); 
       x=getmaxx();  
       y=getmaxy();
        while(i<10)  
        {  
            i++;  
      //    setfillstyle(random(i),random(30));  
  
            circle(xx=rand()%x,yy=rand()%y,rand()%30);  
            setfillstyle(rand()%i,rand()%30);  
            floodfill(xx,yy,getmaxcolor());   
        }  
        settextstyle(BOLD_FONT,HORIZ_DIR,3);
        outtextxy(420,410,(char*)"Please enter a valid input");
        _getch(); 
        closegraph();
        goto XY;   
    } 
        return ;    
}

void Monthly_Input(char choice)
{
        FILE  *fp,*fp1,*fpm; int cost;
        X:
        system("cls"); 
        system("COLOR 0E");   
        gotoxy(40,20);
        printf("If this is initial investment enter 's'");
        gotoxy(40,22);
        printf("If this the feed for the monthly input ,enter 'n'");
        gotoxy(40,24);
        printf("Enter your choice: ");
        scanf("\n%c",&choice);
        if(choice == 's')
        {
            
                fp=fopen("monthlyData.txt","w");
 	            system("cls");
                gotoxy(40,20);
                system("COLOR 0A");	      
                printf("Enter initial investment   :   ");
                scanf("%d",&cost);
	            fprintf(fp,"%d\n",cost); 
	            fclose(fp);
	            fpm=fopen("month.txt","w");
	            fprintf(fpm,"%d",0);
	            fclose(fpm);
	            system("cls");
                system("COLOR 07");
        }


       else if(choice == 'n')
       {

	        fp  = fopen("monthlyData.txt","a");
	        int month,sales,weight,Material_Cost,Labour_cost,bill,rent,output,price,previous_month_sales=0,Pft_B,month_return;
	        fpm=fopen("month.txt","r");
            fscanf(fpm,"%d",&month);
            fclose(fpm);
            month=month+1;
            fpm=fopen("month.txt","w");
            fprintf(fpm,"%d",month);
            fclose(fpm);

	        if(month == 1)
	            {	      
                    fp1 = fopen("stock_monitor.txt","w"); 

		            system("cls");
	                gotoxy(50,6);
	                printf("ENTER 1st MONTH DETAILS ");
	                gotoxy(40,10);
	                system("COLOR 07");

                    printf("Enter material cost                    :  ");
	                scanf("%d",&Material_Cost);
	                fprintf(fp,"%d ",Material_Cost);
                      
		            gotoxy(40,12);
                    printf("Enter weight of material               :  ");
		            scanf("%d",&weight);
		            fprintf(fp,"%d ",weight); 
	    
		            gotoxy(40,14); 
                    printf("Enter Labour charge                    :  ");
	                scanf("%d",&Labour_cost);
	                fprintf(fp,"%d ",Labour_cost);
               
	                gotoxy(40,16);
                    printf("Enter electricity bill                 :  ");
	                scanf("%d",&bill);
	                fprintf(fp,"%d ",bill);

	                gotoxy(40,18);
                    printf("Enter Rent                             :  ");
	                scanf("%d",&rent);
	                fprintf(fp,"%d ",rent);    
		    
		            gotoxy(40,20);
                    printf("Enter manfacturing cost of each bottle :  ");
	                scanf("%d",&cost);
	                fprintf(fp,"%d ",cost);

	                gotoxy(40,22);
                    printf("Enter selling price per bottle         :  ");
	                scanf("%d",&price);
	                fprintf(fp,"%d ",price);

	                gotoxy(40,24); 
                    printf("Enter no of bottles produced           :  ");
	                scanf("%d",&output);
	                fprintf(fp,"%d ",output);

		            gotoxy(40,26);
		            printf("Enter the no of bottles sold           :  ");
		            scanf("%d",&sales);
		            fprintf(fp,"%d ",sales);
             
                    Pft_B = price - cost;
                    month_return  = Month_ProfitOrLoss(0,sales,Pft_B,0);
                    fprintf(fp,"%d\n",month_return);   
                    fprintf(fp1,"%d %d %d %d %d %d",output-sales,sales,Material_Cost,weight,output,Pft_B);
               
		            fclose(fp);
		            fclose(fp1);
		            Tracker(weight,Material_Cost,output,sales,previous_month_sales);

		            system("cls");
		            system("COLOR 02");
		            gotoxy(40,17);
		            printf("Would you like to view month-data?");
		            char chn;
		            gotoxy(40,19);
		            printf("if yes enter 's' or any other key to skip");
		            gotoxy(40,21);
		            printf("Enter your choice : ");
		            scanf("\n%c",&chn);
		            if(chn=='s')
		                Month_info();
		            else
		     	        {
		     		        system("cls");
		     		        system("COLOR 07");
		     		        Sleep(200);
		     	          	Predictor();
		                    barGraphs();
		                }
                                    
                }
	        else
		       {
                    int instock; char ch;
			
                    system("cls");
	                gotoxy(50,6);
	                printf("ENTER %d MONTH DETAILS ",month);
	                gotoxy(40,10);
	                system("COLOR 07");
			     
                    printf("Enter material cost                    :  ");
	                scanf("%d",&Material_Cost);
	                fprintf(fp,"%d ",Material_Cost);
                     
                    gotoxy(40,12);
                    printf("Enter weight of material               :  ");
		            scanf("%d",&weight);
		            fprintf(fp,"%d ",weight); 

                    gotoxy(40,14); 
                    printf("Enter Labour charge                    :  ");
	                scanf("%d",&Labour_cost);
	                fprintf(fp,"%d ",Labour_cost);
               
	                gotoxy(40,16);
                    printf("Enter electricity bill                 :  ");
	                scanf("%d",&bill);
	                fprintf(fp,"%d ",bill);
      
	                gotoxy(40,18);
                    printf("Enter Rent                             :  ");
	                scanf("%d",&rent);
	                fprintf(fp,"%d ",rent);

                    gotoxy(40,20);
                    printf("Enter manfacturing cost of each bottle :  ");
	                scanf("%d",&cost);
	                fprintf(fp,"%d ",cost);

	                gotoxy(40,22);
                    printf("Enter selling price per bottle         :  ");
	                scanf("%d",&price);
	                fprintf(fp,"%d ",price);

                    gotoxy(40,24); 
                    printf("Enter no of bottles produced           :  ");
	                scanf("%d",&output);
	                fprintf(fp,"%d ",output);
		    
		            gotoxy(40,26);
		            printf("Enter the no of bottles sold           :  ");
		            scanf("%d",&sales);
		            fprintf(fp,"%d ",sales);
                      
		            fp1=fopen("stock_monitor.txt","r");
		      
		            int n,pm_Material_Cost ,pm_weight,pm_output,pm_Pft_B; 
		            fscanf(fp1,"%d %d %d %d %d %d",&n,&previous_month_sales,&pm_Material_Cost,&pm_weight,&pm_output,&pm_Pft_B);
		            fclose(fp1);
		            instock=(output+n)-sales;
		            if(output != 0)
		                {
		                    Pft_B = price-cost;	                 
		                }
                    month_return = Month_ProfitOrLoss(n,sales,Pft_B,pm_Pft_B);
                    if(Material_Cost!=0)
                       {
            	            pm_Material_Cost=Material_Cost;
                         	pm_weight = weight;
            	            pm_output=output;
            	            pm_Pft_B=Pft_B;
                        } 

                    fp1=fopen("stock_monitor.txt","w");
	   	            fprintf(fp1,"%d %d %d %d %d %d",instock,sales,pm_Material_Cost,pm_weight,pm_output,pm_Pft_B);
                     
                    fprintf(fp,"%d\n",month_return) ;       
                    fclose(fp);
		            fclose(fp1);
		            Tracker(pm_weight,pm_Material_Cost,pm_output,sales,previous_month_sales);
		            system("cls");
		            gotoxy(40,17);
		            system("COLOR 02");
		            printf("Would you like to view month-data?");
		            char r;
		            gotoxy(40,19);
		            printf("if yes enter 's' or any other key to skip");
		            gotoxy(40,21);
		            printf("Enter your choice : ");
		            scanf("\n%c",&r);
		            system("cls");
		            Sleep(50);
		            if(r=='s')
		                Month_info();
		            else
		                { 
		    	            system("cls");
		    	            Sleep(50);
		    	            Predictor();
		                    barGraphs();
		                }

	          	}
	    
                    
       }
       else 
       {
            system("cls");
	        int gd=DETECT,gm,i=0,x,xx,y,yy;  
           	DWORD screenWidth  = GetSystemMetrics(SM_CXSCREEN);
	        DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	        initwindow(screenWidth,screenHeight,"",-2,-3); 
            x=getmaxx();  
            y=getmaxy();
            while(i<10)  
            {  
                i++;  
                circle(xx=rand()%x,yy=rand()%y,rand()%30);  
                setfillstyle(rand()%i,rand()%30);  
                floodfill(xx,yy,getmaxcolor());    
            }
            settextstyle(BOLD_FONT,HORIZ_DIR,3);
            outtextxy(440,440,(char*)"Please enter a valid input");
            _getch(); 
            closegraph();  
            goto X;

        }

}

void Tracker(int weight,int Material_Cost,int output,int sales,int previous_month_sales)
{
    system("cls");
    Sleep(50);  
	FILE *fp1;
	fp1=fopen("stock_monitor.txt","r");
    float costPerKg,KgPerBottle; int leftOverBottles,inStock,next_month,cost; char arr[500]; 

	costPerKg = (float) Material_Cost/weight;

	KgPerBottle = (float)weight/output;

    fscanf(fp1,"%d",&inStock);

	leftOverBottles = inStock; // output - sales;

	next_month = Sales_Predictor(sales,previous_month_sales);
	int gd=DETECT,gm,i=0,x,xx,y,yy;  
    DWORD screenWidth  = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"",-2,-3); 
    x=getmaxx();  
    y=getmaxy();
    while(i<15)  
    {  
            i++;  
            circle(xx=rand()%x,yy=rand()%y,rand()%30);  
            setfillstyle(rand()%i,rand()%30);  
            floodfill(xx,yy,getmaxcolor());    
    }  
    i=0;
    settextstyle(BOLD_FONT,HORIZ_DIR,3);

	if(leftOverBottles > next_month)
	{
	 	
            sprintf(arr,"Prediction    :    %d bottles",next_month);
            outtextxy(420,410,arr);

            sprintf(arr,"InStock       :    %d",inStock);
            outtextxy(420,440,arr);            

		    outtextxy(400,470,(char *)"No material required!!");
		    
	}
    else
    {
	           
		   
		    cost = ceil(KgPerBottle*(next_month-leftOverBottles));

		    sprintf(arr,"Prediction     :   %d bottles",next_month);
		    outtextxy(420,390,arr);

                   
		    sprintf(arr,"InStock        :   %d bottles",leftOverBottles);
            outtextxy(420,420,arr);


		    sprintf(arr,"New Bottles    :   %d bottles",next_month - leftOverBottles);
            outtextxy(420,450,arr);

		    sprintf(arr,"Advised to buy :   %d kgs of material",cost);
            outtextxy(420,480,arr);

		    int amount = ceil(cost*costPerKg);

		    
	        sprintf(arr,"Cost           :   %d/-",amount);
	        outtextxy(420,510,arr);	
			outtextxy(400,540,(char *)"(taking the cost of material same as the previous month)");	   
	}  
    _getch(); 
    closegraph();
    fclose(fp1);

}

void barGraphs()
{

    	FILE *fp,*fpm; int inv,sales,extra,n,i=0; char str[100],str1[100];
    	fpm=fopen("month.txt","r");
    	fscanf(fpm,"%d",&n);
    	fclose(fpm);
    	int gd = DETECT, gm=0;
		DWORD screenWidth  = GetSystemMetrics(SM_CXSCREEN);
		DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
		initwindow(screenWidth,screenHeight,"",-2,-3);
		int left,top,right,bottom;
	    fp=fopen("monthlyData.txt","r");
	    fscanf(fp,"%d\n",&inv);
	    
	    if(n>0)
            {

                settextstyle(BOLD_FONT,HORIZ_DIR,5);
                outtextxy(500,50,(char*)"ANALYSIS OF SALES"); 
                setcolor(WHITE);
	            line(100,50,100,700);
		        line(100,700,1100,700);

                fscanf(fp,"%d %d %d %d %d %d %d %d %d",&sales,&sales,&sales,&sales,&sales,&sales,&sales,&sales,&sales);
                fscanf(fp,"%d\n",&extra);

		        setfillstyle(XHATCH_FILL,BLUE);
		        sprintf(str,"%d",sales);
		        settextstyle(BOLD_FONT,HORIZ_DIR,3);
		        outtextxy(160,(700-5*sales)-35,str);
		        sprintf(str1,"%d",i+1);
		        outtextxy(160,710,str1);
		        setbkcolor(GREEN);
		        bar3d(left=150,top = 700-5*sales,right = 190,bottom = 700,15,1);
		    }

	    for(i=1;i<n;i++)
        {
        	int s;
        	settextstyle(BOLD_FONT,HORIZ_DIR,5);
        	fscanf(fp,"%d %d %d %d %d %d %d %d %d",&sales,&sales,&sales,&sales,&sales,&sales,&sales,&sales,&sales);
            fscanf(fp,"%d\n",&extra);

            setfillstyle(XHATCH_FILL,BLUE);
            sprintf(str,"%d",sales);
            setbkcolor(BLACK);
            settextstyle(BOLD_FONT,HORIZ_DIR,3);
		    outtextxy((left+=70)+10,(700-5*sales)-35,str);
		    sprintf(str1,"%d",i+1);
		    s=left+10;
		    outtextxy(s,710,str1);
            setbkcolor(GREEN);
		    bar3d(left,700-(5*sales),right+=70,bottom = 700,15,1);

        } 
        
		_getch();
		closegraph();
		fclose(fp);
		
}

void Month_info()
{
	FILE *fpm,*fp; int month,user_month,i=0,inv;
	fpm=fopen("month.txt","r");
	fscanf(fpm,"%d",&month);
	system("cls");
	system("COLOR 05");
	gotoxy(40,20);
	printf("Which month details you want to view:  ");
	scanf("%d",&user_month);
	system("cls");

    if(month<user_month)
    	{
    		gotoxy(40,20);
    		printf("Dear user it hasn't been %d months, since the business is started",user_month);
    		_getch();
    		system("cls");
            Sleep(200);
            Predictor();
            barGraphs();
            system("cls");
            system("COlOR 07");
    	}
    else
    {
    	int Material_Cost,weight,Labour_cost,bill,rent,cost,price,output,sales,returns;
        fp=fopen("monthlyData.txt","r");
        fscanf(fp,"%d\n",&inv);
        if(user_month==0)
        	{
        		gotoxy(40,20);
        		printf("Your initial investment is %d",inv);
        		fclose(fp);
        		_getch();
        		return;
        	}
    	while(i<user_month)
    	{
    		fscanf(fp,"%d %d %d %d %d %d %d %d %d %d\n",&Material_Cost,&weight,&Labour_cost,&bill,&rent,&cost,&price,&output,&sales,&returns);
    		i++;
    	}
    	        gotoxy(40,5);
    	        system("COLOR 03");
    	        printf("COMPLETE DETAILS OF %d MONTH",user_month);

    		    gotoxy(40,10);
       		    printf("Material cost                          :   %d ",Material_Cost);
                     
                gotoxy(40,12);
                printf("Weight of material                     :   %d ",weight); 

                gotoxy(40,14); 
                printf("Labour charge                          :   %d",Labour_cost);
               
	            gotoxy(40,16);
                printf("Electricity bill                       :   %d",bill);
	             
	            gotoxy(40,18);
                printf("Rent                                   :   %d",rent);

                gotoxy(40,20);
                printf("Manfacturing cost of each bottle       :   %d ",cost);

	            gotoxy(40,22);
                printf("Selling price per bottle               :   %d ",price);

                gotoxy(40,24); 
                printf("No of bottles produced                 :   %d ",output);
		    
                gotoxy(40,26);
		        printf("No of bottles sold                     :   %d ",sales);
                                    
		        gotoxy(40,28);
		        if(returns < 0)
		        printf("Your loss in this month                :   %d",returns);
                else
                printf("Your profit in this month              :   %d",returns);
        
                _getch();
                fclose(fp);
                system("cls");
                Sleep(200);
                Predictor();
                barGraphs();
                system("cls");
                system("COlOR 07");
    	
    }

}

void Predictor()
{
	FILE *fp,*fpm;
    int n,i=0,a1,total_amount=0,months,inv;
    fp= fopen("monthlyData.txt","r");
    fpm=fopen("month.txt","r");
    fscanf(fpm,"%d",&n);
    fclose(fpm);
    fscanf(fp,"%d\n",&inv);
    while(i<n)
    {
       	i++;
	    fscanf(fp,"%d %d %d %d %d %d %d %d %d %d\n",&a1,&a1,&a1,&a1,&a1,&a1,&a1,&a1,&a1,&a1);
	    total_amount+=a1;
    }
    int gd=DETECT,gm,x,xx,y,yy;  char arr[100];
    DWORD screenWidth  = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth,screenHeight,"",-2,-3); 
    x=getmaxx();  
    y=getmaxy();
    i=0;
    while(i<12)  
    {  
        i++;  
        circle(xx=rand()%x,yy=rand()%y,rand()%30);  
        setfillstyle(rand()%i,rand()%30);  
        floodfill(xx,yy,getmaxcolor());    
           
    }  
    i=0;
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    sprintf(arr,"Dear User, till date your returns are %d",total_amount);
    outtextxy(420,410,arr);
    _getch();
    closegraph();
    initwindow(screenWidth,screenHeight,"",-2,-3); 
    i=0;
    while(i<12)  
    {  
            i++;  
            circle(xx=rand()%x,yy=rand()%y,rand()%30);  
            setfillstyle(rand()%i,rand()%30);  
            floodfill(xx,yy,getmaxcolor());    
            
    }  
    i=0;

    if(total_amount>inv)
    {
    	system("cls");
    	settextstyle(BOLD_FONT,HORIZ_DIR,3);
    	outtextxy(420,430,(char *)"Dear User, you are currently running in profits");
    	outtextxy(420,460,(char *)"It is sugested to run your business as usual");
    	_getch();
    	closegraph();

    }

    else if(total_amount == 0)
    {
    	system("cls");
      	settextstyle(BOLD_FONT,HORIZ_DIR,3);
    	outtextxy(420,430,(char *)"All your investments are returned");
    	outtextxy(420,460,(char *)"you earned 0/- or lost 0/-");
    	outtextxy(420,430,(char *)"It is suggested to adverstise a little more for the sales increment to run in profits");
        _getch();
    	closegraph();

    }

   else
    {
   	    if(total_amount<=0)
   		{
   			settextstyle(BOLD_FONT,HORIZ_DIR,3);
   			outtextxy(420,430,(char *)"Dear user you are in loss.");
   			outtextxy(420,460,(char *)"it's better if you stop running the business");
   			_getch();
   			closegraph();
   		}

   		else
   		{
   			
   			float rupee = (float)n/total_amount;
            months = ceil(rupee*(inv-total_amount));
   			sprintf(arr,"Dear User it will take you %d months long to get returns",months);
   			settextstyle(BOLD_FONT,HORIZ_DIR,3);
   			outtextxy(420,430,arr);
            _getch();
            closegraph();
   		}

    } 

    fclose(fp);	   
   
}

int Month_ProfitOrLoss(int n,int sales, int Pft_B, int pm_Pft_B)
{
	int gd=DETECT,gm,i=0,x,xx,y,yy;  
    DWORD screenWidth  = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth,screenHeight,"",-2,-3); 
    x=getmaxx();  
    y=getmaxy();
    while(i<12)  
    {  
            i++; 
            circle(xx=rand()%x,yy=rand()%y,rand()%30);  
            setfillstyle(rand()%i,rand()%30);  
            floodfill(xx,yy,getmaxcolor());    
    }  
    i=0;
           
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
           
    int PftOrLoss;char arr[100];
    if(sales<n)
            PftOrLoss = sales*pm_Pft_B;
    else
        	PftOrLoss = (n*pm_Pft_B) + (sales-n)*Pft_B;
    if(PftOrLoss<0)
    {
        	sprintf(arr,"Dear user, your loss in this month is %d",PftOrLoss);
        	outtextxy(420,430,arr);
    }
    else
    {
       		sprintf(arr,"Dear user, your profit in this month is %d",PftOrLoss);
       	    outtextxy(420,430,arr);	
    }  
           
    _getch(); 
    closegraph();
		
     return PftOrLoss;

}

int Sales_Predictor(int sales,int previous_month_sales)
{
        float incOrDec; int next_month;

        if(previous_month_sales == 0)
	       return sales;

 
        incOrDec=(sales - previous_month_sales)*100/previous_month_sales;

        next_month = ceil((100+incOrDec)*sales/100);
		  
        return  next_month;

}

int main()
{
	welcome();
	system("cls");
	Sleep(100);
	loginPage();
	password();
	system("cls");
	system("COLOR 07");
}
