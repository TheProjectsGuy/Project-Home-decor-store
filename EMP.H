#include "stocks.h"

int used_eid[100];
char *t;
void search_employee(),delete_employee();
class ADDR
{
	int houseno;
	long int pin;
	char line1[100];
	char line2[100],city[50];
public:
	friend void search_employee();
	void putaddr_table()
	{
		cout.setf(ios::left);
		cout<<setw(5)<<houseno<<setw(20)<<line1<<setw(25)<<line2<<setw(15)<<city
		    <<setw(8)<<pin;
		cout.unsetf(ios::left);
	}
	void getaddr()
	{
		cout<<"Enter House number : ";
		houseno=get_int();
		cout<<"Enter Address line 1 : ";
		gets(line1);
		cout<<"Enter Address line 2 : ";
		gets(line2);
		cout<<"Enter City : ";
		t=get_name();
		strcpy(city,t);
		cout<<"Enter Pin code : ";
		pin=get_long();
	}
	void putaddr()
	{
		cout<<"\nH No : "<<houseno<<"\nAddr. ln 1 : "<<line1<<"\nAddr. ln 2 : "<<line2<<"\nCity : "<<city<<"\nPin : "<<pin;
	}
};
int sn;        //keeps a tally of the number of employees

class EMPLOYEE
{
	long int salary;
	char name[50],mobno[15],sex;
	int sno,eid,age;
	ADDR address;
public:
	friend void employee_password();
	friend void employee_edit();
	friend void search_employee();
	friend void employee_menu();
	friend void initobj();
	friend void initfile();
	friend void delete_employee();
	void getdata(),putdata(),editdata(),putdata_table();
}obj[50],empl_junk;

void EMPLOYEE::putdata_table()
{
	cout.setf(ios::left);
	cout<<setw(3)<<sno+1<<setw(25)<<name<<setw(5)<<eid<<setw(11)<<mobno<<setw(4)<<age
	    <<setw(11)<<salary;
	cout<<endl;
	cout.unsetf(ios::left);
	address.putaddr_table();
}

void EMPLOYEE::putdata()
{
	cout<<"\nName : "<<name<<"\nAge : "<<age<<"\nGender : "<<sex<<"\nMobno : "<<mobno<<"\nE-ID : "<<eid<<"\nSalary : "<<salary;
	cout<<endl;
	address.putaddr();
}

void EMPLOYEE::getdata()
{
	sno=sn++;
	cout<<endl<<"S No : "<<sn;
	re:
	randomize();
	int veid=random(1991)+10;	//10 -> 2000
	for (int i=0;i<=sn;i++)
		if (used_eid[i]==veid) goto re;
	eid=veid;
	used_eid[sno]=eid;
	cout<<endl<<"E-ID : "<<eid;
	cout<<"\nEnter Name : ";
	t=get_name();
	strcpy(name,t);
	cout<<"Enter Age : ";
	age=get_int();
	cout<<"Enter Gender [M / F] : ";
	re_sex_entry:
	sex=toupper(getch());
	if (sex!='M'&&sex!='F') goto re_sex_entry;
	cout<<sex<<endl;
	re_mobno:
	cout<<"Enter 10 digit Mobile number : ";
	gets(mobno);
	if (strlen(mobno)!=10) { cout<<endl<<"Something went wrong, please try again";
	mobno[0]='\0';cout<<endl; goto re_mobno;}
	cout<<"Enter Salary : ";
	salary = get_long();
	cout<<"Enter Address  \n";
	address.getaddr();
}

void EMPLOYEE::editdata()
{
	cout<<"\nEnter New details for Employee ID "<<eid<<endl;
	cout<<"Enter Name : ";
	t=get_name();
	name[0]='\0';
	strcpy(name,t);
	cout<<"Enter Age : ";
	age=get_int();
	cout<<"Enter Gender [M / F] : ";
	re_enter_sex:
	sex=getch();
	if (sex!='m'&&sex!='M'&&sex!='f'&&sex!='F') goto re_enter_sex;
	if (sex=='m'||sex=='f') sex-=32;
	cout<<sex<<endl;
	cout<<"Enter 10 Digit Mobile number : ";
	gets(mobno);
	cout<<"Enter Salary : ";
	salary = get_long();
	cout<<"Enter Address : \n";
	address.getaddr();
}
//here...
int attempt_pass=1;
void askpassword()
{
	char password_user[50],pass[50];
	strcpy(pass,"admin");
	fstream f;
	f.open("PASS.BIN",ios::in|ios::binary);
	if (!f)
	{
		remove("PASS.BIN");
		cout<<"File not found...";
		f.close();
		f.open("PASS.BIN",ios::binary|ios::out);
		f<<pass;
		f.close();
	}
	else
	{
		f>>pass;
		f.close();
	}
	cout<<"\n\nAttempt "<<attempt_pass<<" of 3"<<endl;
	cout<<"Enter Password : ";
	password_user[0]='\0';
	int i=0,k=false;
	char ch;
	ch=getch();
	if (ch!=13)
	{
		password_user[0]=ch;
		i++;
		do
		{
			cout<<ch;
			for (int j=1;j<=400;j++)
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
				ch=getch();
			if ((ch>125&&ch<33)||ch==' ')
			{
				cout<<endl<<endl<<"INVALID CHARACTER BEING ENTERED ..."<<endl<<endl;
				delay(2000);
				main_menu();
			}
			if (k==true) k=false;
			if (ch!=13)
				password_user[i]=ch;
			else
				password_user[i]='\0';
			i++;
		}while(ch!=13);
	}
	else
		password_user[0]='\0';
	if (strcmp(pass,password_user)==0)
	{
		setbkcolor(GREEN);
		cout<<endl<<"Authorized Entry"<<endl;
	}
	else
	{
		attempt_pass++;
		if (attempt_pass>3)
		{
			attempt_pass=1;
			inc_pass_screen();
			clrscr();
			cleardevice();
			setbkcolor(RED);
			puttext("Employee");
		}
		askpassword();
	}
	delay(2000);
}

//here
void employee_password(),employee_menu(),employee_edit(),getpassword_file();
void employee()
{
	clrscr();
	cleardevice();
	setbkcolor(RED);
	puttext("Employee");
	cout<<endl<<endl;
	attempt_pass=1;
	askpassword();
	clrscr();
	cleardevice();
	initobj();
	employee_menu();
	delay(2000);
	main_menu();
}

void employee_menu()
{
	retake_e1:
	clrscr();
	cleardevice();
	retake_e2:
	cout<<endl;
	setbkcolor(RED);
	puttext("to Employee Menu");
	cout<<endl<<endl;
	gotoxy(17,6);
	cout<<"Press";
	gotoxy(19,7);
	cout<<"1 - to enter a new record";
	gotoxy(19,8);
	cout<<"2 - to view records";
	gotoxy(19,9);
	cout<<"3 - to edit a record";
	gotoxy(18,10);
	cout<<"\'D\' or \'d\' - to Delete a record";
	gotoxy(19,11);
	cout<<"4 - to change password";
	gotoxy(19,12);
	cout<<"5 - to goto STOCK handling and to open\\close store";
	gotoxy(18,13);
	cout<<"\'b\' or \'B\' to backup all files";
	gotoxy(19,14);
	cout<<"6 - to Delete any data and exit";
	gotoxy(19,15);
	cout<<"7 - to View Customer Reviews";
	gotoxy(19,16);
	cout<<"e or E - to exit to the main menu";
	gotoxy(20,18);
	cout<<"Please make an entry : ";
	gotoxy(20+strlen("Please make an entry : "),18);
	char ch='z';
	ch=getch();
	cout<<ch;
	clrscr();cleardevice();
	if (ch=='d'||ch=='D')
		delete_employee();	//function to delete an employee record...
	else if (ch=='b'||ch=='B')
	{
		if (empv==false)
		{
			cout<<"An employee has to open the store to backup the files...";
			cin.get();
			cin.get();
			goto retake_e1;
		}
		ofstream fout;
		fout.open("EMPBAK.bin",ios::out);//sn
		int i;
		for (i=0;i<sn;i++)
			fout.write((char*)&obj[i],sizeof(empl_junk));
		fout.close();
		fout.open("STKBAK.bin",ios::out);
		for (i=0;i<used_sno_stock;i++)
			fout.write((char*)&obj_s[i],sizeof(stock_junk));
		fout.close();
		gotoxy(20,12);
		cout<<"Data has been Backed Up"<<endl;
		cin.get();
		cin.get();
		goto retake_e1;
	}
	else if (ch=='e'||ch=='E')
	{
		initfile();
		main_menu();
	}
	else if (ch=='6')
	{
		retake_delete_menu:
		clrscr();
		cleardevice();
		setcolor(RED);
		cout<<"Enter The Database you want to delete : "<<endl
		    <<"\t1 for deleting Employee Database"<<endl
		    <<"\t2 for deleting Stocks Database"<<endl
		    <<"\t3 for deleting Bill History"<<endl
		    <<"\t4 to delete Password and reset"<<endl
		    <<"\t5 to clear FEEDBACK Data"<<endl
		    <<"\t6 to Exit"<<endl
		    <<"Enter Your choice : ";
		int nt;
		ofstream fout1;
		nt=get_int();
		if (nt==1)
			remove("EMP.BIN");
		else if (nt==2)
			remove("STOCK.BIN");
		else if (nt==3)
			remove("BILLH.dat");
		else if (nt==4)
			remove("PASS.BIN");
		else if (nt==5)
			remove("FEEDS.DAT");
		else if (nt==6)
			exit(0);
		else goto retake_delete_menu;
		delay(2000);
		exit(0);
	}
	else if (ch=='1')
	{
		setbkcolor(GREEN);
		obj[sn].getdata();
		cin.get();
		goto retake_e1;
	}
	else if (ch=='2')
	{
		re_view_home:
		clrscr();
		cleardevice();
		puttext("to Employee View DB");
		cout<<endl<<endl<<endl
		    <<"What do you want to do ? "
		    <<endl<<"\tEnter :-"
		    <<endl<<"\t1 to View all records one by one"
		    <<endl<<"\t2 to Search for an employee"
		    <<endl<<"\t3 to View employees of a particular gender"
		    <<endl<<"\nEnter your Choice : ";
		cin>>ch;
		if (ch=='1')
		{
			clrscr();
			cleardevice();
			cout.setf(ios::left);
			cout<<setw(3)<<"No"<<setw(25)<<"Name"<<setw(5)<<"EID"<<setw(11)<<"Mobile No."<<setw(4)<<"Age"
			    <<setw(11)<<"Salary"<<endl<<setw(5)<<"HNo"<<setw(20)<<"Addr Line 1"<<setw(25)<<"Addr Line 2"<<setw(15)<<"City"
			    <<setw(8)<<"Pin"<<endl<<endl;
			cout.unsetf(ios::left);
			for (int i=0;i<sn;i++)
			{
				cout<<endl;
				obj[i].putdata_table();
				delay(500);
			}
			cout<<endl<<endl<<sn<<" Records found"<<endl;
			cin.get();
		}
		else if (ch=='2')
		{
			setbkcolor(BROWN);
			search_employee();
		}
		else if (ch=='3')
		{
			clrscr();
			cleardevice();
			retake_gender:
			cout<<"\nEnter Gender [M/F] : ";
			char ssex;
			ssex=toupper(getch());
			if (ssex!='M'&&ssex!='F') goto retake_gender;
			cout<<ssex<<endl;
			cout.setf(ios::left);
			cout<<setw(3)<<"No"<<setw(25)<<"Name"<<setw(5)<<"EID"<<setw(11)<<"Mobile No."<<setw(4)<<"Age"
			    <<setw(11)<<"Salary"<<endl<<setw(5)<<"HNo"<<setw(20)<<"Addr Line 1"<<setw(25)<<"Addr Line 2"<<setw(15)<<"City"
			    <<setw(8)<<"Pin"<<endl<<endl;
			cout.unsetf(ios::left);
			int j=0;
			for (int i=0;i<sn;i++)
			{
				if (obj[i].sex==ssex)
				{
					cout<<endl;
					obj[i].putdata_table();
					getch();
				}
			}
			cout<<endl<<endl<<j<<" Records found"<<endl;
		}
		else goto re_view_home;
		cin.get();
		goto retake_e1;
	}
	else if (ch=='3')
	{
		setbkcolor(BLUE);
		employee_edit();
		getch();
		goto retake_e1;
	}
	else if (ch=='4')
	{
		clrscr();
		cleardevice();
		attempt_pass=1;
		askpassword();
		char *password,ch;
		re_password:
		clrscr();
		cleardevice();
		puttext("Password Reset Menu");
		cout<<endl<<"Enter New password : ";
		password[0]='\0';
		int i=0,k=false;
		ch=getch();
		if (ch!=13)
		{
			password[0]=ch;
			i++;
			do
			{
				cout<<ch;
				for (int j=1;j<=400;j++)
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
				if (ch>125&&ch<33)
				{
					cout<<endl<<endl<<"Invalid Characters entered"<<endl   //33 to 125
					    <<"Please Re-Try : ";
					delay(1000);
					goto re_password;
				}
				if (k==true) k=false;
				if (ch!=13)
					password[i]=ch;
				else
					password[i]='\0';
				i++;
			}while(ch!=13);
		}
		else
			password[0]='\0';
		char *repassword;
		//confirm password here
		cout<<endl<<"\nReter New password : ";
		repassword[0]='\0';
		i=0,k=false;
		ch=getch();
		if (ch!=13)
		{
			repassword[0]=ch;
			i++;
			do
			{
				cout<<ch;
				for (int j=1;j<=400;j++)
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
					ch=getch();
				if (ch>125&&ch<33)
				{
					cout<<endl<<endl<<"Invalid Characters entered"<<endl   //33 to 125
					    <<"Please Re-Try : ";
					delay(1000);
					goto re_password;
				}
				if (k==true) k=false;
				if (ch!=13)
					repassword[i]=ch;
				else
					repassword[i]='\0';
				i++;
			}while(ch!=13);
		}
		else
			repassword[0]='\0';
		//here
		if (strcmp(repassword,password)!=0)
		{
			cout<<endl<<endl<<"Both The Passwords Don't Match, Please retry ...";
			cin.get();
			cin.get();
			goto re_password;
		}
		if (strcmp(repassword,password)==0)
		ofstream("PASS.BIN",ios::out|ios::binary)<<password;
		cout<<endl<<"Done...";
		delete password,repassword;
		delay(2000);
		goto retake_e1;
	}
	else if (ch=='5')
	{
		employee_stock();
		//here is where the user comes after employee_stock
		initfile_stock();
		goto retake_e1;
	}
	else if (ch=='7')
		showreview();
	else
	{
		cout<<"\nSomething went wrong \nPlease Re Enter ...";
		getch();
		cin.get();
		cin.get();
		goto retake_e1;
	}
}

void search_employee()
{
	clrscr();
	cleardevice();
	setbkcolor(BROWN);
	cout<<"Enter name, number or eid of the employee : ";
	char search_string[100];
	gets(search_string);
	int j=0;
	for (int i=0;i<=sn;i++)
	{
		char *string_pin;
		ltoa(obj[i].address.pin,string_pin,10);
		if (string_compare(search_string,obj[i].name)||string_compare(search_string,obj[i].mobno)||string_compare(search_string,string_pin))	//name matches
		{
			cout<<endl<<j+1<<endl;
			obj[i].putdata();
			getch();
			j++;
		}
		else if (string_compare(search_string,obj[i].address.city))//address search
		{
			cout<<endl<<j+1<<endl;
			obj[i].putdata();
			getch();
			j++;
		}
		else
		{
			char *str_eid;
			itoa(obj[i].eid,str_eid,10);
			if (string_compare(search_string,str_eid))
			{
				cout<<endl<<j+1<<endl;
				obj[i].putdata();
				getch();
				j++;
			}
		}
		cout<<endl<<endl;
	}
	cout<<"\n\n\nTotally "<<j<<" matches found"<<endl;
	cin.get();
	cin.get();
	employee_menu();
}

void employee_edit()
{
	clrscr();
	cleardevice();
	cout<<"Enter the employee ID of the employee : ";
	int temp;
	char ch;
	temp=get_int();
	for (int i=0;i<=sn;i++)
	{
		if (obj[i].eid == temp)
		{
			cout<<endl;
			obj[i].putdata();
			cout<<endl;
			cout<<"Is this the one ?? [y/n] : ";
			cin>>ch;
			if (ch=='y')
				obj[i].editdata();
		}
	}
	cin.get();
}

void initobj()
{
	ifstream fin;
	fin.open("EMP.BIN",ios::in|ios::binary);
	if (!fin) {::sn=0;
	cout<<"\nFile not found, a new file has been created\n";
	}
	else { fin>>::sn; }
	for (int i=0;i<sn;i++)
	{
		fin.read((char*)&empl_junk,sizeof(empl_junk));
		obj[i]=empl_junk;
	}
	animation_initobj(sn);
	fin.close();
}

void initfile()
{
	ofstream fout("EMP.BIN",ios::out|ios::binary);
	fout<<sn;
	for (int i=0;i<sn;i++)
	{
		empl_junk=obj[i];
		fout.write((char*)&empl_junk,sizeof(empl_junk));
	}
	animation_initfile(sn);
	fout.close();
}

void delete_employee()
{
	attempt_pass=1;
	askpassword();
	clrscr();
	cleardevice();
	setbkcolor(BROWN);
	puttext("Deletion Module");
	cout<<endl<<endl;
	cout<<"Enter S No or eid of the employee you want to delete : ";
	int sno=get_int(),f=false;
	for (int i=0;i<sn;i++)
	{
		if (obj[i].sno+1==sno||obj[i].eid==sno)
		{
			confirm_delete:
			cout<<endl<<"A Record has been found..."
			    <<endl<<"Employee Name : "<<obj[i].name
			    <<endl<<"Is this the one you want to delete ? [y/n] : ";
			char ch;
			ch=toupper(getch());
			cout<<ch;
			if (ch=='Y')
			{
				for (i=i;i<sn;i++)
				{
					obj[i]=obj[i+1];
					obj[i].sno=i;
				}
				f=true;
				sn--;
				cout<<"\nDeleted...";
				break;
			}
			else if (ch=='N') continue;
			else
			{
				cout<<"\nInvalid Entry ...\nPlease Retry ...";
				cin.get();
				cin.get();
				goto confirm_delete;
			}
		}
	}
	cout<<endl;
	if (f==true)
		cout<<"Job Done successfully...";
	else if (f==false)
		cout<<"Job not done successfully...";
	cin.get();
	clrscr();
	cleardevice();
	cout<<endl<<"Do you want to view the employees left in the database ? [y/n] : ";
	char ch;
	ch=getch();
	if (ch=='y'||ch=='Y')
		for (int j=0;j<sn;j++)
		{
			cout<<endl;
			obj[j].putdata_table();
			cout<<endl;
		}
	cin.get();
	cin.get();
	initfile();
	employee_menu();
}