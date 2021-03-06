#include "fnc.h"

int used_sno_stock; //tally of number of stocks available
int empv=false;

class STOCK
{
protected:
	char item_name[50];
	long int price;
	int number_available,sno;
	char warranty[50];
public:
	void getdata(),putdata_table();
	void putdata()
	{
		cout<<endl<<"Name : "<<item_name
		    <<endl<<"Price Per Piece : "<<price
		    <<endl<<"Number of items available : "<<number_available
		    <<endl<<"Warranty : "<<warranty<<endl;
	}
	friend void customer();
	friend void employee_stock();
	friend void initobj_stock();
	friend void initfile_stock();
	friend void billing_and_cart();
	char *_item_name() {return item_name; }
	long int _price() { return price; }
}obj_s[50],stock_junk;

class CART
{
	char name[50];
	int no_of_items;
	double totalprice,ppp;
public:
	friend void billing_and_cart();//code this
	void putitem(STOCK obj,int num)
	{
		strcpy(name,obj._item_name());
		ppp=obj._price();
		no_of_items=num;
		totalprice=double(ppp)*(double)no_of_items;
	}
	void putitem_table()
	{
		cout.setf(ios::left);
		cout<<setw(30)<<name<<setw(5)<<no_of_items<<setw(10)<<ppp<<setw(10)<<totalprice<<endl;
		cout.unsetf(ios::left);
	}
	void display()
	{
		cout<<"\nItem Name : "<<name<<endl<<"Number in Cart : "<<no_of_items<<endl<<"Price per item : "<<ppp
		    <<"\nTotal Price : "<<totalprice<<endl;
	}
}obj_cart;
void puttable_cart()
{
	cout.setf(ios::left);
	cout<<setw(30)<<"Name"<<setw(5)<<"No."<<setw(10)<<"PPP"<<setw(10)<<"Amount"<<endl;
	cout.unsetf(ios::left);
}
class BILL_REC
{
	int year,month,no_of_items;
	char name_cust[50],mobno[15];
	double amount;
public:
	friend void showsales(int,int);
	void init(char *name,char *_mobno,double final_bill_amount,int final_obj_count)
	{
		amount=(double)final_bill_amount;
		no_of_items=final_obj_count;
		strcpy(name_cust,name);
		strcpy(mobno,_mobno);
		time_t _time=time(0);
		char *now=ctime(&_time);
		month=getmonth(now);
		time(&_time);
		year=getyear(ctime(&_time));
		time(&_time);
	}
	void putdata_table()
	{
		cout.setf(ios::left);
		cout<<setw(30)<<name_cust<<setw(13)<<mobno<<setw(15)<<no_of_items<<setw(10)<<amount<<endl;
		cout.unsetf(ios::left);
	}
}obj_billrec;

void STOCK::getdata()
{
	sno=used_sno_stock+1;
	used_sno_stock++;
	cout<<"\nSerial Number "<<sno;
	cin.get();
	cout<<endl<<"Enter Name : ";
	gets(item_name);
	cout<<"Enter Item Price : ";
	price = get_long();
	cout<<"Enter Number of items available : ";
	number_available = get_int();
	cout<<"Enter Warranty period : ";
	gets(warranty);
}

void puttable()
{
	cout<<endl<<"PPP -> Price Per Piece"
	    <<endl<<"NO_AV -> Number of Products Available"<<endl<<endl;
	cout.setf(ios::left);
	cout<<setw(4)<<"SNo"<<setw(25)<<"Name"<<setw(10)<<"PPP"<<setw(10)<<"NO_AV"<<setw(20)<<"Warranty";
	cout.unsetf(ios::left);
}

void STOCK::putdata_table()
{
	cout.setf(ios::left);
	cout<<setw(25)<<item_name<<setw(10)<<price<<setw(10)<<number_available<<setw(20)<<warranty;
	cout.unsetf(ios::left);
}

void billing_and_cart();

void customer()
{
	clrscr();
	cleardevice();
	setbkcolor(BLUE);
	randomize();
	cout<<endl;
	puttext("Customer");
	cout<<endl<<endl;
	int temp_sno;
	if (empv==true)temp_sno=used_sno_stock;
	cout<<temp_sno<<" types of items available"<<endl;
	cout<<"\n\tChoose one of the following options :-"
	    <<endl<<"\t\tEnter 1 to View all items in the stock"
	    <<endl<<"\t\tEnter 2 to goto Billing and cart section"
	    <<endl<<"\t\tEnter 3 to Search for an item in the stock"
	    <<endl<<"\t\tEnter 4 to display any random item"
	    <<endl<<"\t\tEnter 5 to go to the Customer Feedback Section"
	    <<endl<<"\t\tEnter e to exit or to go back"
	    <<endl<<"\tEnter your choice : ";
	if (used_sno_stock==0) //if store is empty then...
	{
		int abc=getcolor();
		setcolor(RED);
		for (int l=1;l<=4;l++)
		line(70,152+16*(l-1),490,152+16*(l-1));
		setcolor(abc);
	}
	char ch;
	ch=getch();
	cout<<ch;
	if (ch>='1'&&ch<='4'&&used_sno_stock==0)
	{
		cout<<endl<<"The store has no Stock records !!!"
		    <<endl<<"Please tell an employee to initialise stock records"
		    <<endl<<"You may however give a review";
		cin.get();
		ch='\0';
		cin.get();
		customer();
	}
	if (ch=='1')
	{
		clrscr();
		cleardevice();
		puttable();
		cout<<endl;
		for (int i=0;i<used_sno_stock;++i)
		{
			cout<<setw(4)<<i+1;
			obj_s[i].putdata_table();
			cout<<endl;
		}
		cin.get();
		cin.get();
		customer();
	}
	else if (ch=='2') billing_and_cart();
	else if (ch=='3')
	{
		char src[100];
		cout<<"\nPlease enter the name of the item : ";
		gets(src);
		clrscr();
		cleardevice();
		cout<<"Searching for "<<src<<" in the available stock\n"<<endl;
		delay(1000);
		puttable();
		cout<<endl;
		for (int ii=0,j=0;ii<used_sno_stock;ii++)
		{
			if ((strcmpi(obj_s[ii].item_name,src)==0)&&obj_s[ii].number_available!=0)
			{
				cout<<setw(4)<<ii+1;
				obj_s[ii].putdata_table();
				cout<<endl;
				getch();
				j+=1;
			}
		}
		cout<<endl<<j<<" Records found";
		cin.get();
		customer();
	}
	else if (ch=='4')
	{
		re_stock1:
		int num=random(used_sno_stock);
		if (obj_s[num].number_available==0) goto re_stock1;
		obj_s[num].putdata();
		cin.get();
		getch();
		customer();
	}
	else if (ch=='e'||ch=='E') ;
	else if (ch=='5')
		feedback_customer();
	else
	{
		cout<<"\nInvalid Choice, Please retry...";
		cin.get();
		customer();
	}
	cin.get();
}

void employee_stock()
{
	initobj_stock();
	empv=true;
	delay(1000);
	re_employee_stock1:
	clrscr();
	cleardevice();
	setbkcolor(BLUE);
	puttext("to STOCK Handling module");
	cout<<endl<<endl<<used_sno_stock<<" Item(s) found"<<endl;
	cout<<"Please select from the menu\n"
	    <<endl<<"\tEnter 1 to enter a new record"
	    <<endl<<"\tEnter 2 to edit the count of an item"
	    <<endl<<"\tEnter 3 to goto Customer's Module"
	    <<endl<<"\tEnter 4 to close store"
	    <<endl<<"\tEnter \"e\" to exit"
	    <<endl<<"Please make an entry : ";
	char ch;
	cin>>ch;
	cin.get();
	if (ch=='1')
	{
		obj_s[used_sno_stock].getdata();
		cin.get();
		goto re_employee_stock1;
	}
	else if (ch=='2')
	{
		clrscr();
		cleardevice();
		setbkcolor(CYAN);
		char temp[50];
		cout<<endl<<"Enter Name : ";
		gets(temp);
		int j=0;
		for (int ii=0;ii<used_sno_stock;ii++)
		{
			if (string_compare(temp,obj_s[ii].item_name))
			{
				re1:
				cout<<"\nMatch found ..."<<endl<<++j<<")\n";
				obj_s[ii].putdata();
				getch();
				cout<<endl<<endl<<"Enter your choice : "
				    <<"\n\t1 to decrease it's tally by \"n\""
				    <<"\n\t2 to increase it's tally by \"n\""
				    <<"\n\t3 to completely edit this item"
				    <<"\n\t4 to skip this item and continue"
				    <<"\nEnter choice : ";
				cin>>ch;
				int n;
				if (ch=='1')
				{
					cout<<"Enter \"n\" : ";
					cin>>n;
					if (n<=obj_s[ii].number_available)
						obj_s[ii].number_available-=n;
					else
					{
						re2:
						cout<<endl<<n<<">"<<obj_s[ii].number_available<<", make it 0 [y/n] : ";
						cin>>ch;
						if (ch=='y'||ch=='Y') obj_s[ii].number_available=0;
						else if (ch=='n'||ch=='N') cout<<"\nOk, I'll lea\ve it\n";
						else goto re2;
					}
				}
				else if (ch=='2')
				{
					cout<<"Enter \"n\" : ";
					cin>>n;
					obj_s[ii].number_available+=n;
				}
				else if (ch=='3')
				{
					cout<<"\nEnter New details of SNo "<<obj_s[ii].sno<<" :-> "<<"\nEnter Name : ";
					gets(obj_s[ii].item_name);
					cout<<"Enter Price : ";
					obj_s[ii].price=get_long();
					cout<<"Enter Tally : ";
					obj_s[ii].number_available=get_int();
					cout<<"Enter Warranty : ";
					gets(obj_s[ii].warranty);
				}
				else if (ch=='4') continue;
				else goto re1;
			}
		}
		cout<<endl<<j<<" records found..."<<endl;
		getch();
		goto re_employee_stock1;
	}
	else if (ch=='e'||ch=='E')
	{
		initfile_stock();//code
	}
	else if (ch=='3')
	{
		customer();
		getch();
		goto re_employee_stock1;
	}
	else if (ch=='4')
	{
		empv=false;
	}
	else
	{
		cout<<"\nInvalid choice.. Please Retry"<<endl;
		getch();
		goto re_employee_stock1;
	}
}

void initobj_stock()
{
	ifstream fin;
	fin.open("STOCK.BIN",ios::binary|ios::in);
	if (!fin) {
	::used_sno_stock=0;
	cout<<"File Not found, new one is created";
	delay(1000);
	}
	else {
	empv=true;
	fin>>used_sno_stock;
	}
	for (int i=0;i<used_sno_stock;i++)
	{
		fin.read((char*)&stock_junk,sizeof(stock_junk));
		obj_s[i]=stock_junk;
	}
	animation_initobj_stock(used_sno_stock);
	fin.close();
}

void initfile_stock()
{
	ofstream fout("STOCK.BIN",ios::binary|ios::out); //out clears the file;
	fout<<used_sno_stock;
	for (int i=0;i<used_sno_stock;i++)
	{
		stock_junk=obj_s[i];
		fout.write((char*)&stock_junk,sizeof(stock_junk));
	}
	animation_initfile_stock(used_sno_stock);
	fout.close();
}

void billing_and_cart()
{
	ofstream fout("BILL.DAT",ios::out); fout.close();
	int no_cart=0;
	fstream fout1,fout2,fin1;
	re_bill:
	bool pass_cont=true;
	clrscr();
	cleardevice();
	randomize();
	setbkcolor(RED);
	puttext(" to Billing And Cart");
	cout<<endl<<endl;
	cout<<"Hello Customer"<<endl<<"Cart has "<<no_cart<<" types of items"<<endl
	    <<"Enter : "
	    <<endl<<"\t1 to View all items and then choose one by one"
	    <<endl<<"\t2 to Search for an item"
	    <<endl<<"\t\'r\' or \'R\' to View a random item"
	    <<endl<<"\t3 to go to Final BILLING section and to leave"
	    <<endl<<"\t4 to Confirm Cart"
	    <<endl<<"Enter Your Choice : ";
	char ch,cho;
	cin>>ch;
	cin.get();
	if (ch=='1')
	{
		clrscr();
		cleardevice();
		setbkcolor(RED);
		puttable();
		cout<<endl;
		for (int i=0;i<used_sno_stock;++i)
		{
			cout<<setw(4)<<i+1;
			obj_s[i].putdata_table();
			cout<<endl;
			_re1:
			cout<<"\nWould You Like to buy this Item ? [Y/anything else] : ";
			cho=getch();
			if (cho=='y'||cho=='Y')
			{
				cout<<cho;
				int num;
				_re2:
				cout<<"\nEnter Number of pieces you want to buy : ";
				cin>>num;
				if (num<=0)
				{
					cout<<"\n-ve number not expected here, smart fellow..."<<char(2);
					cin.get();
					cin.get();
					goto _re2;
				}
				if (num>obj_s[i].number_available)
				{
					cout<<endl<<"Only "<<obj_s[i].number_available<<" pieces of this item are available"
					    <<endl<<"Please Re Enter number .."<<endl;
					goto _re2;
				}
				cout<<"\nAdding item to cart\n";
				obj_cart.putitem(obj_s[i],num);
				obj_s[i].number_available-=num;
				fout1.open("BILL.dat",ios::app);
				fout1.write((char*)&obj_cart,sizeof(obj_cart));
				fout1.close();
				cout<<"\nItem Added to Cart";
				no_cart++;
				cout<<endl;
			}
			else
				cout<<cho<<endl<<"Ok, here's the next one...\n";
		}
	}
	else if (ch=='r'||ch=='R')
	{
		int number = random(used_sno_stock);
		obj_s[number].putdata();
		cout<<"\nWould you like to buy this item ? [Y/N] : ";
		char ch;
		cin>>ch;
		if (ch=='y'||ch=='Y')
		{
			cout<<"\nEnter Number of pieces you want to buy : ";
			int num;
			__rer:
			cin>>num;
			if (num<=0)
			{
				cout<<"\n-ve number not expected here, smart fellow..."<<char(2)<<endl
				    <<"Enter Again : ";
				cin.get();
				cin.get();
				goto __rer;
			}
			if (num>obj_s[number].number_available)
			{
				cout<<endl<<"Only "<<obj_s[number].number_available<<" pieces of this item are available"
				    <<endl<<"Please Re Enter number : ";
				goto __rer;
			}
			cout<<"\nAdding item to cart\n";
			obj_cart.putitem(obj_s[number],num);
			obj_s[number].number_available-=num;
			fout2.open("BILL.dat",ios::app);
			fout2.write((char*)&obj_cart,sizeof(obj_cart));
			fout2.close();
			cout<<"\nItem Added to Cart";
			no_cart++;
			cout<<endl;
		}
	}
	else if (ch=='2')
	{
		clrscr();
		cleardevice();
		setbkcolor(RED);
		cout<<endl<<"Enter Item SNo or Name : ";
		char str[50];
		gets(str);
		int sno=atoi(str);
		for (int i=0;i<used_sno_stock;i++)
		{
			if (strcmpi(str,obj_s[i].item_name)==0||obj_s[i].sno==sno)
			{
				cout<<"\nItem Found\n";
				obj_s[i].putdata();
				cout<<endl<<"Do You wish to buy this Item ? : [y/n] : ";
				cin>>cho;
				if (cho!='y'&&cho!='Y') continue;
				else
				cout<<endl<<"Enter Number Of Pieces You wish to buy : ";
				int num;
				__re2:
				cin>>num;
				if (num<=0)
				{
					cout<<"\n-ve number not expected here, smart fellow..."<<char(2);
					cin.get();
					cin.get();
					goto __re2;
				}
				if (num>obj_s[i].number_available)
				{
					cout<<endl<<"Only "<<obj_s[i].number_available<<" pieces of this item are available"
					    <<endl<<"Please Re Enter number : ";
					goto __re2;
				}
				cout<<"\nAdding item to cart\n";
				obj_cart.putitem(obj_s[i],num);
				obj_s[i].number_available-=num;
				fout1.open("BILL.dat",ios::app);
				fout1.write((char*)&obj_cart,sizeof(obj_cart));
				fout1.close();
				cout<<"\nItem Added to Cart";
				no_cart++;
				cout<<endl;
			}
		}
	}
	else if (ch=='4')
	{
		ifstream fin("bill.dat",ios::in);
		ofstream fout("TEMPB.dat",ios::out);
		clrscr();
		cleardevice();
		setbkcolor(RED);
		cout<<"\nYour Cart is as follows : ";
		cout<<endl;
		do {
			fin.read((char*)&obj_cart,sizeof(obj_cart));
			if (!fin) break;
			obj_cart.display();
			cout<<"\nChoose an option : "
			    <<endl<<"\tEnter 1 to increase count"
			    <<endl<<"\tEnter 2 to decrease count"
			    <<endl<<"\tEnter 3 to remove item"
			    <<endl<<"\tEnter anything else to continue"
			    <<endl<<"Enter your choice : ";
			char ch;
			cin>>ch;
			//to get object of stock...
			int no,obj_num;
			int obj_number;
			for (int k=0;k<used_sno_stock;k++)
			{
				if (strcmpi(obj_s[k].item_name,obj_cart.name)==0)
				{
					obj_number=obj_s[k].number_available;
					obj_num=k;
					break;
				}
			}
			if (ch=='1')
			{
				cout<<endl<<"Enter number of Products you want to add : ";
				no=get_int();
				if (no<=obj_number&&no>0)
				{
					obj_cart.no_of_items+=no;
					obj_cart.totalprice+=double(no)*obj_cart.ppp;
					obj_s[obj_num].number_available-=no;
					cout<<endl<<"Job Done..."<<endl;
				}
				else if (no!=0)
				{
					cout<<"\n"<<no<<" is greater than the number of items available - "<<obj_number<<endl<<"Job Not done"<<endl;
				}
				else
				{
					cout<<"\nInvalid request.. \nJob not done\n";
				}
				fout.write((char*)&obj_cart,sizeof(obj_cart));
			}
			else if (ch=='2')
			{
				cout<<endl<<"Enter number of Products you want to remove : ";
				no=get_int();
				if (no<obj_cart.no_of_items&&no>0)
				{
					obj_cart.no_of_items-=no;
					obj_cart.totalprice-=double(no)*obj_cart.ppp;
					obj_s[obj_num].number_available+=no;
					cout<<endl<<"Job Done..."<<endl;
				}
				else
				{
					cout<<"\n"<<no<<" is lesser than (or equal or -ve) to the number of items int the cart - "<<obj_cart.no_of_items<<endl<<"Job Not done"<<endl;
				}
				fout.write((char*)&obj_cart,sizeof(obj_cart));
			}
			else if (ch=='3')
			{
				obj_s[obj_num].number_available+=obj_cart.no_of_items;
				cout<<"\nItem Deleted.."<<endl<<"Job Done Successfully"<<endl;
				getch();
			}
			else
				fout.write((char*)&obj_cart,sizeof(obj_cart));
			getch();
		}while (fin);
		fin.close();
		fout.close();
		remove("bill.dat");
		rename("tempb.dat","bill.dat");
	}
	else if (ch=='3')
	{
		//just as a precaution
		double final_bill_amount=0;
		int final_obj_count=0;
		fin1.open("BILL.dat",ios::in);
		fout1.open("TEMPB.dat",ios::out);
		do {
			fin1.read((char*)&obj_cart,sizeof(obj_cart));
			if (!fin1) break;
			final_bill_amount+=obj_cart.totalprice;
			final_obj_count+=obj_cart.no_of_items;
			fout1.write((char*)&obj_cart,sizeof(obj_cart));
		}while (fin1);
		fin1.close();
		fout1.close();
		remove("BILL.dat");
		rename("TEMPB.dat","BILL.dat"); //bill prepared
		if (final_obj_count==0)
		{
			cout<<"Do you wan't to leave, There's Nothing in your cart...";
			cout<<"\nPress anything to goto main menu...\n";
			cin.get();
			cin.get();
			main_menu();
		}
		//code for bill generation
		fout2.open("BILLH.dat",ios::app);
		fin1.open("BILL.dat",ios::in);
		clrscr();
		cleardevice();
		setbkcolor(RED);
		cout<<endl;
		puttable_cart();
		cout<<endl;
		do{
			fin1.read((char*)&obj_cart,sizeof(obj_cart));
			if (!fin1) break;
			obj_cart.putitem_table();
			getch();
		}while (fin1);
		cout<<endl<<"Your Final Bill Amount is : "<<final_bill_amount<<" INR";
		//calc change and payment
		change_and_payment(final_bill_amount);
		cin.get();
		cin.get();
		fin1.close();
		clrscr();
		cleardevice();
		setbkcolor(RED);
		cout<<endl<<"Thank You For Shopping with us ..."<<endl;
		cout<<"Please Enter Your Name : ";
		char mobno[15],name[40];
		char *t;
		t=get_name();
		strcpy(name,t);
		cout<<"Please Enter Your Contact Number : ";
		gets(mobno);
		obj_billrec.init(name,mobno,final_bill_amount,final_obj_count);
		fout2.write((char*)&obj_billrec,sizeof(obj_billrec));
		fout2.close();
		cout<<endl<<"Good Bye "<<name<<", We look forward to serving you again"<<endl;
		fout1.open("BILL.dat",ios::out);
		fout1.close();
		no_cart=0;
		re_ask_1:
		cout<<"\nREDO ? [Y/N] : ";
		cin>>ch;
		if (ch=='n'||ch=='N') pass_cont=false;
		else if (ch!='y'&&ch!='Y')
		{	cout<<"\nRetry please...\n";
			cin.get();
			goto re_ask_1;
		}
	}
	if (pass_cont==true) goto re_bill;
	initfile_stock();
}

void showsales(int month,int year)
{
	clrscr();
	cleardevice(); setbkcolor(RED);
	ifstream fin("billh.dat",ios::in);
	long int nof=0,totamount=0;
	cout.setf(ios::left);
	cout<<endl<<setw(30)<<"Customer Name"<<setw(13)<<"Mobile No."<<setw(15)<<"No. Purchased"<<"Amount"<<endl<<endl;
	do
	{
		fin.read((char*)&obj_billrec,sizeof(obj_billrec));
		if (!fin) break;
		if (obj_billrec.year==year&&obj_billrec.month==month)
		{
			nof++;
			obj_billrec.putdata_table();
			totamount+=obj_billrec.amount;
			getch();
		}
	}while(fin);
	fin.close();
	cout<<endl<<"Totally "<<nof<<" records found \nAmounting To sales of "<<totamount<<" /-"<<endl;
	getch();
}