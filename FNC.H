#include "all.h"

int string_compare(char *src,char *str)
{                                  //src is search string
	int current_pos=0,ret=0;
	char *sample;
	do {
		for (int i=current_pos,j=0;i<current_pos+strlen(src);i++,j++)
		{
			sample[j]=str[i];
		}
		current_pos++;
		sample[strlen(src)]='\0';
		if (strcmpi(sample,src)==0)
			ret=1;
	}
	while (current_pos<=strlen(str));
	return ret;
}

void puttext (char *str)
{
	cout<<char(201);
	for (int i=1;i<=65;i++)
		cout<<char(205);
	cout<<char(187)<<endl<<char(186);
	cout<<setw(25)<<"Welcome ";
	cout.setf(ios::left);
	cout<<setw(60-strlen("Welcome ")-12)<<str<<char(186)<<endl<<char(200);
	cout.unsetf(ios::left);
	for (i=1;i<=65;i++) cout<<char(205);
	cout<<char(188);
	cout<<endl;
}

char *get_name()
{
	char name[500];
	reenter_name:
	gets(name);
	for (int i=0;i<strlen(name);++i)
	{
		if ((!isalpha(name[i]))&&(name[i]!=' ')&&((name[i]!='.')||(name[i]=='.'&&name[i+1]=='.')))
		{
			cout<<"\nInvalid name entered"<<endl<<"Please Re-enter : ";
			goto reenter_name;
		}
		if (name[i]<='z'&&name[i]>='a'&&i==0)
			name[i]-=32;
		if (name[i]==' ')
		{
			if (name[i+1]>='a'&&name[i+1]<='z')
				name[i+1]-=32;
		}
	}
	return name;
}

int get_int()
{
	char str[100];
	retry:
	gets(str);
	for (int i=0;i<strlen(str);++i)
	{
		if (!isdigit(str[i]))
		{
			cout<<"\nPlease Re-Enter : ";
			cin.get();
			goto retry;
		}
	}
	if (strlen(str)>4)
	{
		cout<<"\nToo long integer"<<endl<<"Please Re-Enter : ";
		goto retry;

	}
	return atoi(str);
}

long int get_long()
{
	char ln[150];
	re:
	gets(ln);
	for (int i=0;i<strlen(ln);++i)
	{
		if (!isdigit(ln[i]))
		{
			cout<<"Please Re-Enter : ";
			goto re;
		}
	}
	if (strlen(ln)>9)
	{
		cout<<"Number out of limits, Please Re-Enter : ";
		goto re;
	}
	return atol(ln);
}

char *getpassword()
{
	char *password,ch;
	password[0]='\0';
	int i=0,k=false;
	ch=getch();
	password[0]=ch;
	i++;
	do
	{
		cout<<ch;
		for (int j=1;j<=500;j++)
		{
			delay(1);
			if (kbhit())
			{
				k=true;
				ch=getch();
				break;
			}
		}
		cout<<"\b*";
		if (k==false)
		{
			ch=getch();
		}
		if (k==true) k=false;
		if (ch!=13)
			password[i]=ch;
		else
			password[i]='\0';
		i++;
	}while(ch!=13);
	return password;
}

void inc_pass_screen()
{
	settextstyle(DEFAULT_FONT,HORIZ_DIR,6);
	setcolor(BLACK);
	for (int i=1;i<=900;i++)
	{
		clrscr();
		cleardevice();
		_re_color2:
		int  tc=random(6) + 56,c=random(6);
		if (c==0) goto _re_color2;
		setbkcolor(c);
		outtextxy(getmaxx()/2-190,getmaxy()/2-55,"BURGLAR");
		outtextxy(getmaxx()/2-160,getmaxy()/2+30,"ALERT");
		if (i%100==0)
		{
			cout<<"\a";
			setcolor(tc);
			settextstyle((random(2))?0:9,HORIZ_DIR,6);
		}
		delay(10);
	}
}

void animation_initobj(int sn)
{
	clrscr();
	cleardevice();
	graphdefaults();
	setbkcolor(WHITE);
	setbkcolor(WHITE);
	setcolor(GREEN);
	settextstyle(BOLD_FONT,HORIZ_DIR,2);
	outtextxy(getmaxx()/2,getmaxy()/2-55,"Fetching");
	setcolor(BLUE);
	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,4);
	char *csn;
	itoa(sn,csn,10);
	outtextxy(getmaxx()/2,getmaxy()/2-20,csn);
	setcolor(GREEN);
	settextstyle(BOLD_FONT,HORIZ_DIR,1);
	outtextxy(getmaxx()/2 + 50,getmaxy()/2-20,"Employee Records ");
	for (float i=0;i<=getmaxx();i+=0.5)
	{
		putpixel(i,getmaxy()*3/4-20,BLUE);
		putpixel(i,getmaxy()*3/4-20*sin((i+10*PI/2)/10),GREEN);
		putpixel(i,getmaxy()*3/4+20*sin((i+10*PI/2)/10),RED);
		putpixel(i,getmaxy()*3/4+20,BLUE);
		delay(3);
		if (kbhit()) break;
	}
	outtextxy(getmaxx()*1/2-20,getmaxy()*3/4+30,"DONE");
	outtextxy(getmaxx()/2,getmaxy()-20,"Please Wait...");
	delay(1000);
}

void animation_initfile(int sn)
{
	clrscr();
	cleardevice();
	setbkcolor(YELLOW);
	setcolor(GREEN);
	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,2);
	outtextxy(getmaxx()/2,getmaxy()/2-55,"Saving");
	setcolor(BLUE);
	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,4);
	char *csn;
	itoa(sn,csn,10);
	outtextxy(getmaxx()/2,getmaxy()/2-20,csn);
	setcolor(GREEN);
	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,1);
	outtextxy(getmaxx()/2 + 50,getmaxy()/2-20,"Employee Records");
	for (float i=2.0*PI;i>=-(8.0*PI);i-=PI/24.0)
	{
		moveto(getmaxx()*3/4,getmaxy()*3/4);
		if (i<=0.0) setcolor(RED);
		if (i<=-2.0*PI) setcolor(YELLOW);
		if (i<=-4.0*PI) setcolor(LIGHTGREEN);
		if (i<=-6.0*PI) setcolor(GREEN);
		linerel(50.0*cos(i),50.0*sin(i));
		delay(10);
	}
	outtextxy(getmaxx()/2,getmaxy()-20,"Please Wait...");
	delay(1000);
}

void animation_initobj_stock(int sn)
{
	clrscr();
	cleardevice();
	graphdefaults();
	setbkcolor(WHITE);
	setcolor(GREEN);
	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,2);
	outtextxy(getmaxx()/2-120,getmaxy()/2,"Fetching");
	setcolor(BLUE);
	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,4);
	char *csn;
	itoa(sn,csn,10);
	outtextxy(getmaxx()/2,getmaxy()/2,csn);
	setcolor(GREEN);
	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,1);
	outtextxy(getmaxx()/2 + 50,getmaxy()/2,"Stock Records");
	long int j;
	float i;
	randomize();
	for (i=0,j=1;i<=8.0*PI;j++)
	{
		putpixel(getmaxx()*1/2 + 100.0*cos(i) + random(j%5) ,150 + getmaxy()*1/2 - 20.0*sin(i) + random(j%5) ,random(16)+1);
		delay(10);
		if (i<2.0*PI) i+=PI/24.0;
		else if (i<4.0*PI) i+=PI/48.0;
		else if (i<6.0*PI) i+=PI/96.0;
		else if (i<=8.0*PI) i+=PI/192.0;
		if (kbhit()) break;
	}
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
	setcolor(GREEN);
	outtextxy(getmaxx()*1/2 -19 ,150 + getmaxy()*1/2 - 15, "DONE !!!");
	outtextxy(getmaxx()/2,getmaxy()-50,"Please Wait...");
	delay(1000);
}

void animation_initfile_stock(int sn)
{
	clrscr();
	cleardevice();
	setbkcolor(YELLOW);
	setcolor(GREEN);
	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,2);
	outtextxy(getmaxx()/2-120,getmaxy()/2,"Saving");
	setcolor(BLUE);
	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,4);
	char *csn;
	itoa(sn,csn,10);
	outtextxy(getmaxx()/2 - 20,getmaxy()/2,csn);
	setcolor(GREEN);
	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,1);
	outtextxy(getmaxx()/2 + 50,getmaxy()/2,"Stock Records");
	outtextxy(getmaxx()/2,getmaxy()-50,"Please Wait...");
	delay(1000);
}

void converttime(char *str)
{
	for (int i=0;i<16;i++)
	{
		cout<<str[i];
	}
	for (i=19;i<=23;i++)
	{
		cout<<str[i];
	}
}

int getmonth(char*);
int getyear(char*);
int isleap(int);
int getmonthlimit(int,int);
int getweekday(int,int,int);
void monthly_calendar();

void putdetails_month_year(int m,int y)
{
	cout<<setw(190)<<y<<", ";
	switch(m)
	{
		case 1: cout<<"January"; break;
		case 2: cout<<"February"; break;
		case 3: cout<<"March"; break;
		case 4: cout<<"April"; break;
		case 5: cout<<"May"; break;
		case 6: cout<<"June"; break;
		case 7: cout<<"July"; break;
		case 8: cout<<"August"; break;
		case 9: cout<<"September"; break;
		case 10: cout<<"October"; break;
		case 11: cout<<"November"; break;
		case 12: cout<<"December"; break;
		default: cout<<"\nINVALID MONTH, WRONG DETAILS ENTERED...";
		cin.get();
		cin.get();
		monthly_calendar();
	}
}

void monthly_calendar()
{
	reput:
	time_t _time=time(0);
	char *now=ctime(&_time);
	int monthno=getmonth(now);
	time(&_time);
	int year=getyear(ctime(&_time));
	repput:
	clrscr();
	cleardevice();
	setbkcolor(RED);
	puttext("to the Calendar");
	cout<<endl<<endl;
	putdetails_month_year(monthno,year);
	cout<<endl;
	cout<<"\tSu \tMo \tTu \tWe \tTh \tFr \tSa "<<endl;
	int monthlim=getmonthlimit(monthno,year);
	int wkday1=getweekday(1,monthno,year);
	int twkday=wkday1-1;
	cout<<endl<<endl;
	cout<<"\t";
	if (twkday==-1) twkday=6;
	for (int z=1;z<=twkday;z++) cout<<"\t";
	cout<<1<<"\t";
	for (int i=2,k=wkday1;i<=monthlim;i++)
	{
		k++;
		k%=7;
		if (k==1) cout<<endl<<endl<<"\t";
		cout<<i<<"\t";
	}   cout<<endl;
	setcolor(CYAN);
	line(50,145,480,145);
	line(50,170,480,170);
	line(50,200,480,200);
	line(50,230,480,230);
	line(50,260,480,260);
	line(50,290,480,290);
	line(50,320,480,320);
	line(50,350,480,350);
	setcolor(GREEN);
	line(50,145,50,350);
	line(100,145,100,350);
	line(160,145,160,350);
	line(220,145,220,350);
	line(285,145,285,350);
	line(350,145,350,350);
	line(420,145,420,350);
	line(480,145,480,350);
	if (monthno==2) cout<<endl<<endl;
	cout<<endl<<endl<<"Press N to go to next month, P to go to previous and C to go to Current"
	    <<endl<<"Press S to show this month's Sales Record"<<"\nPress G to go to Any month of any year"<<"\nPress E to go back";
	char ch;
	ch=getch();
	if (ch=='e'||ch=='E') main_menu();
	else if (ch=='s'||ch=='S') showsales(monthno,year);
	else if (ch=='n'||ch=='N') {
		if (monthno==12) (monthno=1,year++);
		else monthno++;
	}
	else if (ch=='p'||ch=='P') {
		if (monthno==1) (monthno=12,year--);
		else monthno--;
	}
	else if (ch=='c'||ch=='C') goto reput;
	else if (ch=='g'||ch=='G')
	{
		clrscr();
		cleardevice();
		puttext("Date input section");
		gotoxy(25,10);
		cout<<"Enter Month [Int] : ";
		monthno=get_int();
		gotoxy(26,13);
		cout<<"Enter Year [int] : ";
		year=get_int();
	}
	else { cout<<"\nInvalid...\n"; }
	goto repput;
}

int getweekday(int d,int m,int y)
{
	unsigned long int total=0,sum1,sum2,sum3;
	total+=d;
	sum3=0;
	switch(m)
	{
		case 12: sum3+=30;	//date in Dec
		case 11: sum3+=31;	//date in Nov	//Oct
		case 10: sum3+=30;	//date in Oct   //Sept
		case 9: sum3+=31;        //date in Sept  //Aug
		case 8: sum3+=31; 	//date in Aug	//Jul
		case 7: sum3+=30;	//date in Jul	//June
		case 6:	sum3+=31;	//date in June  //May
		case 5: sum3+=30;	//date in May	//April
		case 4: sum3+=31;	//date in April //March
		case 3:               	//date in March //Feb
			if (isleap(y)) sum3+=29;
			else sum3+=28;
		case 2: sum3+=31;	//date in Feb   //Jan
		case 1: sum3+=0;	//date in jan   //null
	}
	total+=sum3;
	sum1=long(365)*long(y);
	total+=sum1;
	int yn=y;
	if (isleap(y)) yn--;
	sum2=int(int(yn/4)-int(yn/100))+int(yn/400);
	total+=sum2;
	return total%7;
}
int isleap(int y)
{
	if (y%4==0)    {
		if (y%100!=0)
			return true;
		else if (y%100==0&&y%400==0)
			return true;	}
	return false;
}
int getmonthlimit(int month,int year)
{
	if (month==1||month==3||month==5||month==7||month==8||month==10||month==12) return 31;
	else if (month==2)   {
		if (isleap(year)) return 29;
		else if (!isleap(year)) return 28;   }
	return 30;
}
int getyear(char *string)
{
	char str[4];
	for (int i=0,j=20;j<=23;i++,j++)
		str[i]=string[j];
	int abc=atoi(str);
	return abc;
}
int getmonth (char *string)
{
	char* month_str;
	for (int i=4,j=0;i<=6;j++,i++)
		month_str[j]=string[i];
	month_str[3]='\0';
	if (strcmpi(month_str,"Jan")==0)      return 1;
	else if (strcmpi(month_str,"Feb")==0) return 2;
	else if (strcmpi(month_str,"Mar")==0) return 3;
	else if (strcmpi(month_str,"Apr")==0) return 4;
	else if (strcmpi(month_str,"May")==0) return 5;
	else if (strcmpi(month_str,"Jun")==0) return 6;
	else if (strcmpi(month_str,"Jul")==0) return 7;
	else if (strcmpi(month_str,"Aug")==0) return 8;
	else if (strcmpi(month_str,"Sep")==0) return 9;
	else if (strcmpi(month_str,"Oct")==0) return 10;
	else if (strcmpi(month_str,"Nov")==0) return 11;
	else if (strcmpi(month_str,"Dec")==0) return 12;
	else cout<<"Error";
	return 0;
}

//code for feedback

class FEEDBACK
{
	int no_lines_other;
	char name[50],tele[15],comments_main[200],string_other[50][50];
public:
	friend void copyinfo_feedback();
	friend void showreview();
};

void copyinfo_feedback();
void _window(int,int,int,int,int); // code to make a window and a rectangle
void makewindow();
char *getentry(int,int);	//it'll goto the point and take entry and return it as a string
void move_cursor();
void shade(int,int);

char string_position[3][100];
inline void _function_correct(int);
char string_junk[50][50];
int count_junk=0;
void textinput(int);
int c[3]={0,0,0};
void _main_code();

void clear_all_feedback_data()
{
	int i;
	for (i=0;i<50;i++)
		string_junk[i][0]='\0';
	count_junk=0;
	for (i=0;i<3;i++)
	{
		c[i]=0;
		string_position[i][0]='\0';
	}

}

void feedback_customer()
{
	clear_all_feedback_data();
	_main_code();
	cin.get();
	cin.get();
}

void _main_code()
{
	clrscr();
	cleardevice();
	setbkcolor(WHITE);
	makewindow();
	moveto(230,45);
	shade(BLUE,LIGHTGREEN);
	move_cursor();	//tells which block the cursor is in and all the I/O operations
	getch();
}

void _window(int x1,int x2,int y1,int y2,int color)
{
	int x=getbkcolor(),y=getcolor();
	setcolor(color);
	putpixel(x1,y1,color);
	putpixel(x1,y2,color);
	putpixel(x2,y1,color);
	putpixel(x2,y2,color);
	line(x1,y1,x2,y1);
	line(x2,y1,x2,y2);
	line(x2,y2,x1,y2);
	line(x1,y2,x1,y1);
	setcolor(y);
	setbkcolor(x);
}

void  makewindow()
{
	setcolor(RED);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
	outtextxy(getmaxx()/2-65,0,"FEEDBACK");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(5,40,"Name :");
	_window(60,400,35,55,BLUE); 	//block 1 (230,45)
	outtextxy(5,65,"Tele : ");
	_window(60,400,60,80,BLUE);	//block 2 (230,70)
	outtextxy(5,95,"COMMENTS & FEEDBACK");
	_window(5,500,110,400,BLUE);	//block 3 (252,255)
	//button code
	_window(5,30,410,430,BLUE);	//block 4 (17,420)
	outtextxy(9,416,"RE");
	_window(40,100,410,430,BLUE);	//block 5 (70,420)
	outtextxy(45,416,"CANCEL");
	_window(110,300,410,430,BLUE);	//block 6 (205,420)
	outtextxy(180,416,"SUBMIT");
}

int tellposition(int x,int y)	// tells the block in which the graphical pointer is
{
	if ((x>60&&x<400)&&(y>35&&y<55))
		return 1;
	else if ((x>60&&x<400)&&(y>60&&y<80))
		return 2;
	else if ((x>5&&x<500)&&(y>110&&y<400))
		return 3;
	else if ((x>5&&x<30)&&(y>410&&y<430))
		return 4;
	else if ((x>40&&x<100)&&(y>410&&y<430))
		return 5;
	else if ((x>110&&x<300)&&(y>410&&y<430))
		return 6;
	else return 0;
}

void move_cursor()
{
	int x,y,ret,block;
	re1:
	(x=getx(),y=gety());
	char ch;
	do
	{
		ch=getch();
		block=tellposition(x,y);
		if (ch=='w'||ch=='W'||ch=='a'||ch=='A'||ch=='d'||ch=='D'||ch=='s'||ch=='S'||ch==27||ch==13)
		{
			shade(BLUE,WHITE);
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			_function_correct(block);
		}
		if (ch=='w'||ch=='W'||ch=='a'||ch=='A')
		{
			switch (block)
			{
				case 1:        //if it's 1 moveto block 6
					moveto(205,420);
					(x=205,y=420);
				break;
				case 2:	       //if it's 2 moveto block 1
					moveto(230,45);
					(x=203,y=45);
				break;
				case 3:	       //if it's 3 moveto block 2
					moveto(230,70);
					(x=230,y=70);
				break;
				case 4:	       //if it's 4 moveto block 3
					moveto(252,255);
					(x=252,y=255);
				break;
				case 5:        //if it's 5 moveto block 4
					moveto(17,420);
					(x=17,y=420);
				break;
				case 6:	       //if it's 6 moveto block 5
					moveto(70,420);
					(x=70,y=420);
				break;
			}
		}
		else if (ch=='s'||ch=='S'||ch=='d'||ch=='D')
		{
			switch (block)
			{
				case 1:        //if it's 1 moveto block 2
					moveto(230,70);
					(x=230,y=70);
				break;
				case 2:	       //if it's 2 moveto block 3
					moveto(252,255);
					(x=252,y=255);
				break;
				case 3:	       //if it's 3 moveto block 4
					moveto(17,420);
					(x=17,y=420);
				break;
				case 4:	       //if it's 4 moveto block 5
					moveto(70,420);
					(x=70,y=420);
				break;
				case 5:        //if it's 5 moveto block 6
					moveto(205,420);
					(x=205,y=420);
				break;
				case 6:	       //if it's 6 moveto block 1
					moveto(230,45);
					(x=230,y=45);
				break;
			}
		}
		else if (ch==27)
			shade(BLUE,WHITE);
		else if (ch==13)
		{
			shade(BLUE,GREEN);
			switch(tellposition(x,y))
			{
				case 1: case 2:
				case 3:
					textinput(tellposition(x,y));
				break;
				case 4:
					ret=1;
				break;
				case 5:
					ret=2;
				break;
				case 6:
					ret=3;
				break;
			}
		}
		if (ch=='a'||ch=='A'||ch=='d'||ch=='D'||ch=='w'||ch=='W'||ch=='S'||ch=='s'||ch==27||ch==13)
		{
			if (ch!=27&&ch!=13)
				shade(BLUE,LIGHTGREEN);
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			_function_correct(tellposition(x,y));
		}
		if (tellposition(x,y)==0);
			//re code
	}while(ret!=1&&ret!=2&&ret!=3);//condition
	switch(ret)
	{
		case 1:              //re
			clrscr();
			cleardevice();
			_main_code();
		case 2:              //cancel
			clear_all_feedback_data();
			main_menu();
		case 3:              //submit
			copyinfo_feedback();
			clear_all_feedback_data();
			clrscr();
			cleardevice();
			outtextxy(getmaxx()/2,getmaxy()/2,"Thank You");
			getch();
			main_menu();
	}
}

void shade(int border_color,int color_tofill)
{
	int x=getx(),y=gety();
	setfillstyle(SOLID_FILL,color_tofill);
	floodfill(x,y,border_color);
}

void textinput(int number)
{
	int ix=getx(),iy=gety();
	int x,y;
	switch(number)
	{
		case 1: (x=60,y=35);break;
		case 2: (x=60,y=60);break;
		case 3: (x=5,y=110);break;
	}
	int i=0,n=0;
	moveto(x+2,y+5);
	string_position[number-1][0]='\0';
	char cha;
	if (c[number-1])
	{
		c[number-1]=0;
		if (number==3)
		{
			for (int ii=0;ii<50;ii++)
				string_junk[i][0]='\0';
		}
		count_junk=0;
		string_position[number-1][0]='\0';
	}
	do
	{
		cha=getch();
		char str[2];
		str[0]=cha;
		str[1]='\0';
		if (cha==13&&number==3)
		{
			moveto(x+2,y+5);
			n++;
			string_junk[n-1][0]='\0';
			count_junk=n;
			moverel(0,n*10);
		}
		if ((cha>='a'&&cha<='z')||(cha>='A'&&cha<='Z')||cha==' '||(cha>=39&&cha<=58))
		{
			if (n==0)
				strcat(string_position[number-1],str);
			else if (number==3)
				strcat(string_junk[n-1],str);
		}
		if ((cha>='a'&&cha<='z')||(cha>='A'&&cha<='Z')||cha==' '||(cha>=39&&cha<=58))
		{
			outtext(str);
			++i;
		}
		if (cha==27)
		{
			string_position[number-1][i]='\0';
		}
	}while(cha!=27);
	moveto(ix,iy);
	c[number-1]=1;
}

void _function_correct(int num)
{
	switch (num)
	{
		case 1:
			if (c[0])
			{
				int ix=getx(),iy=gety();
				moveto(62,40);
				outtext(string_position[0]);
				moveto(ix,iy);
			}
		break;
		case 2:
			if (c[1])
			{
				int ix=getx(),iy=gety();
				moveto(62,65);
				outtext(string_position[1]);
				moveto(ix,iy);
			}
		break;
		case 3:
			if (c[2])
			{
				int ix=getx(),iy=gety();
				moveto(7,115);
				outtext(string_position[2]);
				for (int i=1;i<=count_junk;i++)
				{
					moveto(7,115);
					moverel(0,i*10);
					outtext(string_junk[i-1]);
				}
				moveto(ix,iy);
			}
		break;
		case 4:
			outtextxy(9,416,"RE");
		break;
		case 5:
			outtextxy(45,416,"CANCEL");
		break;
		case 6:
			outtextxy(180,416,"SUBMIT");
		break;
	}
}

void copyinfo_feedback() //to copy everything
{
	FEEDBACK obj;
	obj.no_lines_other=count_junk;
	int i=0;
	for (i=0;i<50;i++)
		obj.string_other[i][0]='\0';
	i=0;
	do
	{
		strcat(obj.string_other[i],string_junk[i]);
		++i;
	}while (i<count_junk);
	strcpy(obj.name,string_position[0]);
	strcpy(obj.tele,string_position[1]);
	strcpy(obj.comments_main,string_position[2]);
	ofstream fout("FEEDS.bin",ios::binary|ios::app);
	fout.write((char*)&obj,sizeof(obj));
	fout.close();
	clear_all_feedback_data();
}

void showreview()
{
	FEEDBACK obj;
	setbkcolor(RED);
	ifstream fin("FEEDS.bin",ios::binary|ios::in);
	do
	{
		clrscr();
		cleardevice();
		puttext("FEEDBACK section");
		fin.read((char*)&obj,sizeof(obj));
		if (!fin) break;
		cout<<endl<<endl<<"\tName : "<<obj.name<<"\n\tTelephone : "<<obj.tele<<"\n\tNOL : "<<obj.no_lines_other
		    <<"\n\t Comments : \n"<<"\t"<<obj.comments_main;
		for (int i=0;i<obj.no_lines_other;i++)
			cout<<endl<<"\t"<<obj.string_other[i];
		cout<<endl<<"Press anything to proceed...";
		getch();
	}while(fin);
	cin.get();
	fin.close();
	employee();
}

void change_and_payment(long amount)
{
	long calc;
	char ch,str[10];
	str[0]='\0';
	char *strn;
	strn[0]='\0';
	setcolor(WHITE);
	outtextxy(getmaxx()/2-100,getmaxy()/2+20,"BALANCE : ");
	cout<<endl<<"Enter Amount : ";
	do
	{
		ch=getch();
		if (isdigit(ch))
		{
			cout<<ch;
			char cha[2];
			cha[0]=ch;
			cha[1]='\0';
			strcat(str,cha);
			calc=atol(str);
			_window(getmaxx()/2,getmaxx()/2+150,getmaxy()/2,getmaxy()/2+50,BLUE);
			moveto(getmaxx()/2+20,getmaxy()/2+20);
			shade(BLUE,WHITE);
			setcolor(RED);
			ltoa(amount-calc,strn,10);
			if (amount-calc==0)
				shade(BLUE,GREEN);
			else if (amount-calc<0)
				shade(BLUE,YELLOW);
			else
				shade(BLUE,CYAN);
			if (strlen(strn)>=9) ch='c';
			else
			outtextxy(getmaxx()/2+20,getmaxy()/2+20,strn);
		}
		if (ch==8||ch=='c'||ch=='C')
		{
			for (int j=0;j<strlen(str);j++) cout<<"\b \b";
			strn[0]='\0';
			str[0]='\0';
		}
		if (ch==13&&amount-calc>0)
		{
			for (int j=1;j<=50;j++)
			{       rer:
				int r=random(6);
				if (r==BLUE) goto rer;
				shade(BLUE,r);
				outtextxy(getmaxx()/2+20,getmaxy()/2+20,strn);
				delay(10);
			}
			shade(BLUE,CYAN);
			outtextxy(getmaxx()/2+20,getmaxy()/2+20,strn);
			ch=' ';
		}
	}while(ch!=13);
	cin.get();
	cin.get();
}

void thankyou()
{
	char ch=char(1);
	re_anim_thanks:
	int i1=random(10)+1,i2=random(10)+1,i3=random(10)+1,i4=random(10)+1;
	for (float i=2.0*PI;i>=-(8.0*PI);i-=PI/96.0)
	{
		if (i<=0.0) setcolor(i2);
		if (i<=-2.0*PI) setcolor(i3);
		if (i<=-4.0*PI) setcolor(i1);
		if (i<=-6.0*PI) setcolor(i4);
		moveto(getmaxx()/4,getmaxy()/4);
		linerel(50.0*cos(i),50.0*sin(i));
		moveto(getmaxx()*3/4,getmaxy()/4);
		linerel(50.0*cos(i),50.0*sin(i));
		moveto(getmaxx()/4,getmaxy()*3/4);
		linerel(50.0*cos(i),50.0*sin(i));
		moveto(getmaxx()*3/4,getmaxy()*3/4);
		linerel(50.0*cos(i),50.0*sin(i));
		_window(getmaxx()/4-50,getmaxx()*3/4+50,getmaxy()/4-50,getmaxy()*3/4+50,random(6));
		delay(12);
		if (kbhit())
		{
			ch=getch();
			break;
		}
	}
	if (ch==char(1)) goto re_anim_thanks;
}

void check_files()
{
	clrscr();
	char ch;
	cout<<"\nChecking Files ...";
	delay(10);
	cout<<endl<<"Checking Stock file...";
	delay(10);
	if (!fstream("STOCK.bin",ios::binary|ios::in).good())
	{
		remove("STOCK.bin");
		cout<<endl<<"Stock file is Corrupted"
		    <<endl<<"Do you want to replace the file from backup ??? : ";
		ch=toupper(getch());
		if (ch=='Y')
		{
			cout<<"\nReplacing File from the backup file...";
			delay(10);
			if (!ofstream("stkbak.bin"))
			{
				cout<<"\nFILE NOT FOUND ...";
				delay(10);
				ch='N';
			}
			else
				rename("STKBAK.BIN","STOCK.BIN");
		}
		if (ch=='N')
		{
			cout<<"\nOk, stock database is left blank...";
			delay(10);
		}
	}
	else
	{
		cout<<"\nStock file is proper...";
		delay(10);
	}
	cout<<endl<<"Checking Employee File...";
	delay(10);
	if (!fstream("EMP.bin",ios::binary|ios::in).good())
	{
		remove("EMP.bin");
		cout<<endl<<"Employee file is Corrupted"
		    <<endl<<"Do you want to replace the file from backup ??? : ";
		ch=toupper(getch());
		if (ch=='Y')
		{
			cout<<"\nReplacing File from the backup file...";
			delay(10);
			if (!ofstream("empbak.bin"))
			{
				cout<<"\nFILE NOT FOUND ...";
				delay(10);
				ch='N';
			}
			else
				rename("EMPBAK.BIN","EMP.BIN");
		}
		if (ch=='N')
		{
			cout<<"\nOk, Employee database is left blank...";
			delay(10);
		}
	}
	else
	{
		cout<<endl<<"Employee file is proper...";
		delay(10);
	}
	cout<<endl<<"Checking Feedback forms...";
	delay(10);
	if (!fstream("feeds.bin",ios::binary|ios::in).good())
	{
		remove("feeds.bin");
		cout<<endl<<"Feedback File not found or Corrupted...";
	}
	else
		cout<<endl<<"Feedback File is proper...";
	if (!fstream("pass.bin",ios::binary|ios::in).good())
	{
		remove("pass.bin");
		cout<<endl<<"Password file not found ..."<<endl<<"Default password is set...";
	}
	else
	{
		cout<<endl<<"Password file has been verified...";
	}
	delay(20);
	cout<<endl<<endl<<"Press enter please...";
	cin.get();
}