#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<fstream>
using namespace std;
class vehicle;

class vegetables
{
public:
	string name;
	int  k, id;
public:
	
	void display()
	{
		ofstream fout;
		fout.open("fdetails", ios::app);
		fout << "\nName: " << name << " Vegetable Id: " << setw(18) << id << "\nQuantity in kgs: " << k << endl;
		fout.close();
	}
	virtual void show()
	{
		cout << setw(70) << setiosflags(ios::internal) << setfill(' ') << "WELCOME TO THE GARDEN HARVEST HUB\n";
		cout << setw(40) << " " << endl;

	}
};
class exportt
{
public:
	string depart, arrive;
	int month = 1 + (rand() % 12);
	int yr = 2024, time, x;
	int day = 1 + (rand() % 31);
public:
	void displays()
	{
		cout << "\nCHOOSE DESTINATION " << endl;
		cout.setf(ios::left, ios::adjustfield);
		cout << setw(10);
		cout << "  From" << "\t" << "To" << endl;
		cout << "---------------------------------------" << endl;
		cout << " 1. Margao" << "\t" << "Panaji" << endl;
		cout << setw(10);
		cout << " 2. Margao" << "\t" << "Vasco" << endl;
		cout << setw(10);
		cout << " 3. Margao" << "\t" << "Mapusa" << endl ;

	}
	
	void getdestinfo()
	{
		cout << "\nEnter choice: ";
		cin >> x;
		switch (x)
		{
		case 1:
		{
			depart = "Margao";arrive = "Panaji";
			break;
		}
		case 2:
		{
			depart = "Margao";arrive = "Vasco";
			break;
		}
		case 3:
		{
			depart = "Margao";arrive = "Mapusa";
			break;
		}
		default:
		{
			cout << "Wrong choice!" << endl;
			getdestinfo();
			break;
		}
		}
	}
	void ddisplay()
	{
		ofstream fout;
		fout.open("fdetails", ios::app);
		fout << "FROM:" << depart << setw(10) << "TO:" << setw(10) << arrive /*<< setw(10)*/;
		fout << "\nDATE: " << day << "/" << month << "/" << yr << endl;
		fout.close();
	}
};
class transport : public vegetables
{
public:
	int i, tot;
public:

	void transs()
	{
		cout << "\nEnter name: ";
		cin >> name;
		cout << "\nEnter the quantity in kgs: ";
		cin >> k;
		cout << "\nEnter the vegetable Id you want to transport:";
		cin >> id;
		display();
		cal();
	}
	void cal()
	{
		switch (id)
		{
		case 101:
		{
			tot = 60 * k;
			cout << "\nYour transportation cost is: " << tot;
			break;
		}
		case 102:
		{
			tot = 20 * k;
			cout << "\nYour transportation cost is: " << tot;
			break;
		}
		case 103:
		{
			tot = 40 * k;
			cout << "\nYour transportation cost is: " << tot;
			break;
		}
		case 104:
		{
			tot = 30 * k;
			cout << "\nYour transportation cost is: " << tot;
			break;
		}
		case 105:
		{
			tot = 20 * k;
			cout << "\nYour transportation cost is: " << tot;
			break;
		}
		case 106:
		{
			tot = 20 * k;
			cout << "\nYour transportation cost is: " << tot;
			break;
		}
		default:
		{
			cout << "\nWrong choice! ";
			transs();
			break;
		}
		}
	}

};
class supermarket :public exportt
{
public:
	string sname;
	string s1 = "JV SHETTY", s2 = "D MART", s3 = "VEGGIES";
	int weight;
	int w1 = 50, w2 = 60, w3 = 80;
	float distance;
	float s1d = 10.5, s2d = 7.9, s3d = 12.0;
public:
	float famount;
	void flist()
	{
		cout << setw(25) << setiosflags(ios::internal) << setfill(' ') << "\nAvailable supermarkets " << endl;
		cout << flush;

		cout.setf(ios::left, ios::adjustfield);
		cout << setw(10);
		cout << "SR.NO." << setw(15) << "NAME" << setw(10) << "DISTANCE" << setw(20) << "VEHICLE CAPACITY" << endl;
		cout << "------------------------------------------------------------------" << endl;
		if (x == 1 || x == 2 || x == 3)
		{
			cout.setf(ios::left, ios::adjustfield);
			cout << setw(10);
			cout << setw(10) << setiosflags(ios::left) << " a" << setw(18) << s1 << setw(10) << s1d << setw(20) << w1 << endl;
			cout << setw(10);
			cout << setw(10) << setiosflags(ios::left) << " b" << setw(18) << s2 << setw(10) << s2d << setw(20) << w2 << endl;
			cout << setw(10);
			cout << setw(10) << setiosflags(ios::left) << " c" << setw(18) << s3 << setw(10) << s3d << setw(20) << w3 << endl;

		}
		else
		{
			cout << "\nWrong Choice";
			flist();
		}
	}
	void travel()
	{
		int r = 108070403 + (rand() % 1000000000);
		char choice;
		cout << "\nChoose the supermarket(enter char): ";
		cin >> choice;
		switch (choice)
		{
		case 'a':
		{
			sname = s1;
			distance = s1d;
			weight = w1;
			break;
		}
		case 'b':
		{
			sname = s2;
			distance = s2d;
			weight = w2;
			break;
		}
		case 'c':
		{
			sname = s3;
			distance = s3d;
			weight = w3;
			break;
		}
		
		default:
		{
			cout << "\nWrong choice! ";
			travel();
			break;
		}
		}
	}
};

class vehicle :virtual public transport,virtual public supermarket
{
public:
	int tw;
	float stot;
	float pay = 100;
	void payex()
	{
		pay = pay + stot * 100;
		cout<<"\nAmount Paid : "<<pay;
	}
	void chechwg()
	{
		cout << "\nEnter the extra weight you want to give the vehicle: " << endl;
		cin >> tw;
		stot = tw + k;
		try {
			if (stot > weight)
			{
				int vw;
				cout << "\nYour total weight is over load!" << endl;
				cout << "Choose 1.To reduce weight\t\t2.Pay for extra weight" << endl;
				cin >> vw;
				throw vw;
			}
			else
			{
				cout << "\nYou can transport!" << endl;
				payex();
			}
		}
		catch (int vw)
		{
			if (vw == 1)
			{
				stot = weight;
			}
			else
			{
				payex();
			}
		}
	}

	void display1()
	{
		ofstream fout;
		fout.open("fdetails,ios::app");
		fout << "Supermarket name " << sname << setw(15) << "Product Id:" << setw(10) << id << "Extra load" << weight << "Total charge: Rs" << pay << endl;
		fout.close();

	}
};
template<class T>
class total_payment :public vegetables
{
public:
	float amount;
public:
	void operator *(T tax)
	{
		amount = amount * tax;
		cout << fixed << "\nTotal Amount : " << amount;
	}
	void display2()
	{
		ofstream fout;
		fout.open("fdetails", ios::app);
		fout << "Your total amount to be paid is:\t" << "Rs." << amount << endl;
		for (int i = 0;i < 90;i++)
		{
			fout << "+";
		}
		fout << "\n";
		fout.close();
		ifstream fin;
		int n = 100;
		char line[100];
		fin.open("fdetails");
		while (fin)
		{
			fin.getline(line, n);
			cout << line << endl;
		}
		fin.close();
	}
	

};
class bill : public vehicle,public vegetables,public total_payment<float>
{
public:
	void show()
	{
		cout << "\nThe tax you paid..\n";
	}
	bill()
	{
		amount = 0;
		cout << "\nYour total amount:";
	}
	void display()
	{
		ofstream fout;
		fout.open("fdetails", ios::app);
		for (int i = 0;i < 90;i++)
		{
			fout << "-";
		}
		fout << "\n";
		fout << setw(40) << setiosflags(ios::internal) << setfill(' ') << "GARDEN HARVEST HUB BILL" << endl;
		fout.close();

		exportt::displays();
		vehicle::display1();
		total_payment::display2();
	}
	
	void mydetails()
	{
		amount = tot + stot + pay;
	} 
	friend void last();
	~bill()
	{
		cout<<"\nBill recieved successfully!";
	}
};
void last()
{
	cout << "\nTHANK YOU FOR THE PURCHASE..!!";
}
void main()
{
	vegetables* ptr;
	vegetables V;
	ptr=&V;
	ptr->show();
	char ch='a';
	do {

		cout << setw(68) << setiosflags(ios::internal) << setfill(' ') << "YOU CAN TRANSPORT VEGETABLES HERE\n";
		cout << setw(40) << " " << endl;
		cout << setw(80) << setiosflags(ios::internal) << setfill(' ') << "THE VEGETABLES AVAILABLE ARE\n";
		cout << setw(40) << " " << endl;
		cout << flush;

		cout << "Vegetable Id" << setw(10) << setfill(' ') << "Name " << setw(15) << setfill(' ') << "      Transportation cost(per kg)" << setw(20) << setfill(' ')/* << "Quantity(kgs)"*/ << "\n";
		cout << "--------------------------------------------------------------------\n";
		cout << " 101" << setw(20) << setfill(' ') << "Onions" << setw(15) << setfill(' ') << "   60" << setw(30) << setfill(' ') <<  "\n";
		cout << " 102" << setw(20) << setfill(' ') << "Tomato" << setw(15) << setfill(' ') << "   20" << setw(30) << setfill(' ') <<"\n";
		cout << " 103" << setw(20) << setfill(' ') << "Chillies" << setw(15) << setfill(' ') << "   60" << setw(30) << setfill(' ') << "\n";
		cout << " 104" << setw(20) << setfill(' ') << "Potato" << setw(15) << setfill(' ') << "   30" << setw(30) << setfill(' ') << "\n";
		cout << " 105" << setw(20) << setfill(' ') << "Carrot" << setw(15) << setfill(' ') << "   20" << setw(30) << setfill(' ') << "\n";
		cout << " 106" << setw(20) << setfill(' ') << "Cabbage" << setw(15) << setfill(' ') << "   20" << setw(30) << setfill(' ') << "\n";
		bill b;
		b.transs();
		b.displays();
		b.getdestinfo();
		b.ddisplay();
		b.flist();
		b.travel();
		b.chechwg();
		bill P;
		ptr = &P;
		ptr->show();
		b.mydetails();	
		int tax;
		cout << "\nEnter tax %:";
		cin >> tax;
		b*tax;
		cout << "\nDo you want to Transport more vegetable(y/n) : ";
		cin >> ch;
		last();
	} while (ch == 'y' || ch == 'Y');
	_getch();
}
