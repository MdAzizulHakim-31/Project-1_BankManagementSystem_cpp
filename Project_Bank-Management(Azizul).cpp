#include<iostream>
#include<fstream>
#include<iomanip>
#include<cctype>

using namespace std;
class Bank_Account
{
    int Money_Deposit;
    char type;
    int accountNo;
    char name[50];

    public:

    void report() const;
	int ret_Money_Deposit() const;
	void create_Bank_Account();
	void deposit(int);
	int ret_Acc_No() const;
	void display_Account() const;
	void update();
	char ret_Type() const;
	void withdraw(int);
};

void Bank_Account::create_Bank_Account()
{
    system("CLS");
    cout<<"\n\tEnter the Bank Account No. : ";
    cin>>accountNo;
    cout<<"\n\n\tEnter the Bank Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout<<"\n\tEnter Type Of the Bank Account (C/S) : ";
    cin>>type;
    type=toupper(type);
    cout<<"\n\tEnter The Starting Money : ";
    cin>>Money_Deposit;
    cout<<"\n\n\tcongratulations!!!.";
    cout<<"\n\tBank Account Created.";
    cout<<"\n\n\n\n\n\tPress 'Enter' To Continue..";
}