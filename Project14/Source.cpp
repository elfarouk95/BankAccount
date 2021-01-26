#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Account
{
private:
	int aco;
	string name;
	char type;
	double amount;

public:
	Account()
	{
		aco = 0;
		name = "";
		type = 'c';
		amount = 0;
	}

	void setAco(int _aco)
	{
		aco = _aco;
	}

	void setName(string _name)
	{
		name = _name;
	}

	void setAmount(double _amount)
	{
		amount = _amount;
	}

	void setType(char _type)
	{
		type = _type;
	}


	int getAco()
	{
		return aco;
	}

	string getName()
	{
		return name;
	}

	double getAmount()
	{
		return amount;
	}

	char getType()
	{
		return type;
	}

	void showRowAccount()
	{
		//22        .test
		//777       .test

		cout << aco << setw(10) << " " << name << setw(10) << " " << type << setw(6) << amount << endl;
	}

	void showAccount()
	{
		cout << "\nAccount No. : " << aco;
		cout << "\nAccount Holder Name : ";
		cout << name;
		cout << "\nType of Account : " << type;
		cout << "\nBalance amount : " << amount;
	}

	// ايداع
	void dep(double x)
	{
		amount += x;
	}
	// سحب 
	void draw(double x)
	{
		amount -= x;
	}
};
//////////////////////////////////////////

Account  accounts[1000];
int pos = 0;


void Intro();
char menu();

void createNewAccount();
void displayAllAccount();
void displayAccount();

void DEPOSIT();
void WITHDRAW();


void modify_account();
void delete_Account();

int Input(string msg, int min, int max)
{
	int x;
	do
	{
		cout << msg;
		cin >> x;
		if (x >= min && x <= max)
		{
			return x;
		}

	} while (true);

}

int findAccountPos()
{
	int x = Input("\n\n\tEnter The account No. : ", 0, 10000);

	for (int i = 0; i < pos; i++)
	{
		if (accounts[i].getAco() == x)
		{
			return i;
		}
	}

	return -1;
}


void main()
{
	Intro();
	char ch;

	do
	{
		ch = menu();
		system("cls");

		switch (ch)
		{
		case '1':
			createNewAccount();
			break;

		case '2':
			DEPOSIT();
			break;

		case '3':
			WITHDRAW();
			break;

		case '4':
			displayAccount();
			break;

		case '5':
			displayAllAccount();
			break;

		case '6':
			delete_Account();
			break;

		case '7':
			modify_account();
			break;
		}


	} while (ch != '8');


	system("pause");

}

void Intro()
{
	cout << "\n\n\n\t  BANK";
	cout << "\n\n\tMANAGEMENT";
	cout << "\n\n\t  SYSTEM";
	cout << "\n\n\n\nMADE BY : Alfarouk Omar";
	cin.get();
	system("cls");
}

char menu()
{
	char ch;
	system("cls");
	cout << "\n\n\n\tMAIN MENU";
	cout << "\n\n\t01. NEW ACCOUNT";
	cout << "\n\n\t02. DEPOSIT AMOUNT";
	cout << "\n\n\t03. WITHDRAW AMOUNT";
	cout << "\n\n\t04. BALANCE ENQUIRY";
	cout << "\n\n\t05. ALL ACCOUNT HOLDER LIST";
	cout << "\n\n\t06. CLOSE AN ACCOUNT";
	cout << "\n\n\t07. MODIFY AN ACCOUNT";
	cout << "\n\n\t08. EXIT";
	cout << "\n\n\tSelect Your Option (1-8) ";

	cin >> ch;
	if (ch >= '1' && ch <= '8')
	{
		return ch;
	}
	else
	{
		cout << "Wrong Number " << endl;
		cin.get();
		system("cls");
		menu();
	}
}


void  createNewAccount()
{
	Account c;

	int id = Input("\nEnter The account No. :", 0, 10000);

	//cin >> id;// account number;

	cin.ignore();

	string name;
	cout << "\n\nEnter The Name of The account Holder : ";
	getline(cin, name);

	char t;
	cout << "\nEnter Type of The account (C/S) : ";
	cin >> t;// type of account

	double amount = Input("\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ", 500, 10000);


	c.setAco(id);
	c.setName(name);
	c.setType(t);
	c.setAmount(amount);


	accounts[pos] = c;

	pos++; //1

	cout << "\n\n\nAccount Created..";

	cin.get();
}

void displayAllAccount()
{
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "====================================================\n";
	cout << "A/c no.      NAME           Type  Balance\n";
	cout << "====================================================\n";


	for (int i = 0; i < pos; i++)
	{
		accounts[i].showRowAccount();
	}

	cin.get();
}

void displayAccount()
{
	int y = findAccountPos();

	if (y == -1)
	{
		cout << "\n\nAccount number does not exist";
		cin.get();
		return;
	}
	else
	{
		cout << "\nBALANCE DETAILS\n";
		accounts[y].showAccount();
	}
	cin.get();
}

void DEPOSIT()
{
	int y = findAccountPos();

	if (y == -1)
	{
		cout << "\n\nAccount number does not exist";
		cin.get();
		return;
	}
	else
	{
		double x = Input("\n\nEnter The amount to be deposited", 0, 10000);

		accounts[y].dep(x);
	}

	cout << "\n\n\t Record Updated";
	cin.get();

}

void WITHDRAW()
{
	int y = findAccountPos();

	if (y == -1)
	{
		cout << "\n\nAccount number does not exist";
		cin.get();
		return;
	}
	else
	{
		double x = Input("\n\nEnter The amount to be draw", 0 , accounts[y].getAmount() - 500 );

		accounts[y].draw(x);
	}

	cout << "\n\n\t Record Updated";
	cin.get();
}

void modify_account()
{

	int y = findAccountPos();
	if (y == -1)
	{
		cout << "\n\nAccount number does not exist";
		cin.get();
		return;
	}
	else
	{
		accounts[y].showAccount();
		
		string name;
		cout << "\n\nEnter The Modify  Name of The account Holder : ";
		getline(cin, name);

		accounts[y].setName(name);

		cout << "\n\n\nAccount Updated..";
		cin.get();
	}
}


void delete_Account()
{
	int y = findAccountPos();
	if (y == -1)
	{
		cout << "\n\nAccount number does not exist";
		cin.get();
		return;
	}

	swap(accounts[y],accounts[pos-1]);

	pos--;

	cout << "\n\n\tRecord Deleted ..";
	cin.get();

}