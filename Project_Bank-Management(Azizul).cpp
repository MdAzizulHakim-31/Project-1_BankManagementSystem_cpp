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