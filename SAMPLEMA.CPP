/*
	Password is : qwerty
*/

#include "emp.h"

void start()
{
	int gm= DETECT,dg,p=0;
	initgraph(&gm,&dg,"C:\\TC\\BGI");
	setbkcolor(WHITE);
	setcolor(RED);
	moveto(0,0);
	randomize();
	setcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL,RED);
	for (int x = 40,y = 80,n=1;x<=getmaxx();x+=40,++n)
	{
		lineto(x,y);
		if (n%2==0)
		{
			floodfill(x-20,0,LIGHTGRAY);
			y=80;
		}
		else y=0;
	}
	lineto(getmaxx(),0);
	floodfill(getmaxx()-6,0,LIGHTGRAY);
	int i,c;
	for (x=0,y=30,i=1;y<=getmaxy();y+=60,i++)
	{
		re_color:
		int s=random(2);
		if (s==0) c=random(6);
		else if (s==1) c=random(6) + 56;
		if (c==0||c==p||(i==1&&c==RED)) goto re_color;
		setcolor(c);
		circle(x,y,30);
		setfillstyle(SOLID_FILL,c);
		floodfill(x,y,c);
		circle(getmaxx(),y,30);
		floodfill(getmaxx(),y,c);
		p=c;
	}
	setcolor(BLUE);
	settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
	outtextxy(getmaxx()/2 - 60,getmaxy()/2 - 50,"Hello World");
	getch();
	setcolor(GREEN);
	//Version Tag
	settextstyle(COMPLEX_FONT,VERT_DIR,1);
	outtextxy(getmaxx()/2 - 50,80,"Version");
	settextstyle(COMPLEX_FONT,HORIZ_DIR,7);
	outtextxy(getmaxx()/2,90,"5.1.1");
	settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(getmaxx()/2+155,150,"(beta)");
	//Version Tag ended
	settextstyle(SCRIPT_FONT,HORIZ_DIR,4);
	outtextxy(getmaxx()/2 - 256,getmaxy()/2 - 10,"Welcome To the Home Decor Store");
	//load graphics...
	settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
	outtextxy(getmaxx()/2 - 70,getmaxy()/2+40,"Press Anything...");
	int co=true;
	randomize();
	char ch;
	int a=0,pp;
	for (float theta=0;;theta+=PI/96.0)
	{
		re_generate:
		pp=random(9)+1;
		if (theta>PI&&co==true)
		{
			if (pp==a) goto re_generate;
			else a=pp;
			setcolor(pp);
			co=false;
		}
		if (theta>2.0*PI)
		{	theta=0.0;
			co=true;
		}
		moveto(getmaxx()/2,getmaxy()/2+100);
		linerel(100*cos(theta),-25*sin(theta));
		delay(10);
		if (kbhit())
		{
			ch=getch();
			break;
		}
	}
	settextstyle(SCRIPT_FONT,HORIZ_DIR,3);
	setcolor(RED);
	outtextxy(getmaxx()/2 - 0,getmaxy() - 30,"Press \"Enter\" to proceed");
	do ch=getch();
	while(ch!=13);
}

void main()
{
	check_files();
	clrscr();
	start();
	main_menu();
}

void main_menu()
{
	_start:
	graphdefaults();
	clrscr();
	cleardevice();
	cout<<"Please press Enter or Return again ...";
	cin.get();
	char ch;
	setbkcolor(BLUE);
	time_t tn;
	bool fall=false;
for (int i=1;;++i)
{       clrscr();
	cleardevice();
	setbkcolor(BLUE);
	cout<<endl;
	puttext("to Home Decor Store");
	time(&tn);
	char *now=ctime(&tn);
	cout<<endl<<"The time is : ";converttime(now);
	cout<<endl<<endl<<"The store is ";
	if (empv==true) cout<<"Open";
	else if (empv==false) cout<<"Closed";
	cout<<endl<<"Who are you ? "<<endl
	    <<"\t\"E\" or \"e\" if you are an Employee\n"
	    <<"\t\"1\" to View the Monthly Calendar and sales\n"
	    <<"\t\"C\" or \"c\" if you are a Customer\n"
	    <<"\tPress 0 to exit\n"
	    <<"\nPlease make an entry : ";
	gotoxy(24,15);
	for (int j=1;j<=60;j++)
	{
		if (kbhit())
		{
			ch=toupper(getch());
			cout<<ch;
			cin.get();
			fall=true;
			break;
		}
		delay(1000);
	}
	if (fall) break;
}
	if (ch=='e'||ch=='E')
		employee();
	else if (ch=='c'||ch=='C')
	{
		if (empv==true)
		customer();
		else if (empv==false)
		{
			cout<<"\nStore is closed\n"
			    <<"\nPlease tell an employee to goto stocks section"
			    <<"\nYou may try Again, However for security purposes, Stock items will not be loaded"
			    <<"\nYou'll only be able to give feedback...";
			empv=true;
			getch();
		cin.get();
		}
	}
	else if (ch=='0')
	{
		clrscr();
		cleardevice();
		graphdefaults();
		setbkcolor(WHITE);
		setcolor(RED);
		settextstyle(COMPLEX_FONT,HORIZ_DIR,6);
		outtextxy(getmaxx()/2-90,getmaxy()/3,"Thank");
		setcolor(GREEN);
		outtextxy(getmaxx()/2-70,getmaxy()/2+10,"You");
		thankyou();
		getch();
		closegraph();
		delay(1500);
		exit(0);
	}
	else if (ch=='1')
		monthly_calendar();
	else
	{
		cout<<endl<<"\""<<ch<<"\" is an invalid chioce, please select an item from the list";
		cin.get();
	}
	clrscr();
	cleardevice();
	cin.get();
	goto _start;
}