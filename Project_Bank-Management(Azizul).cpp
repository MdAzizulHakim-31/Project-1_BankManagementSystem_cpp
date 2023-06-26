#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>

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
    void display_Account() const;
    void deposit(int);
    void withdraw(int);
    int ret_Acc_No() const;
    void update();
    char ret_Type() const;
};

// ...Bank account creation
void Bank_Account::create_Bank_Account()
{
    system("CLS");
    cout << "\n\tEnter the Bank Account No. : ";
    cin >> accountNo;
    cout << "\n\n\tEnter the Bank Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n\tEnter Type Of the Bank Account (C/S) : ";
    cin >> type;
    type = toupper(type);
    cout << "\n\tEnter The Starting Money : ";
    cin >> Money_Deposit;
    cout << "\n\n\tcongratulations!!!";
    cout << "\n\tBank Account Created.";
}

// ...Account details display
void Bank_Account::display_Account() const
{
    cout << "\n\tBank Account No. : " << accountNo;
    cout << "\n\tBank Account Holder Name : " << name;
    cout << "\n\tType Of Bank Account : " << type;
    cout << "\n\tTotal Balance : " << Money_Deposit;
}

// ...Update account details
void Bank_Account::update()
{
    cout << "\n\tBank Account No. : " << accountNo;
    cout << "\n\n\tUpdation Bank Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\tUpdation Type Of Bank Account : ";
    cin >> type;
    type = toupper(type);
    cout << "\tUpdation Balance : ";
    cin >> Money_Deposit;
}

int Bank_Account::ret_Acc_No() const
{
    return accountNo;
}

char Bank_Account::ret_Type() const
{
    return type;
}

void Bank_Account::report() const
{
    cout << accountNo << setw(10) << " " << name << setw(10) << " " << type << setw(6) << Money_Deposit << endl;
}

// ...Deposit and withdraw
void Bank_Account::deposit(int x)
{
    Money_Deposit += x;
}
void Bank_Account::withdraw(int x)
{
    Money_Deposit -= x;
}
int Bank_Account::ret_Money_Deposit() const
{
    return Money_Deposit;
}