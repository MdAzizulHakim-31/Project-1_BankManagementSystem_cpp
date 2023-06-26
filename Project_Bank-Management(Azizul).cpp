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


// ...Main function
void write_Bank_Account();
void display_details(int);
void display_all();
void delete_Bank_Account(int);
void Money_Deposit_withdraw(int, int);
void update_Bank_Account(int);

int main()
{
    char serial;
    int num;
    do
    {
        cout << "\n\n\t\t***WELCOME TO BANK MANAGEMENT SYSTEM***";
        cout << "\n\n\t\t-------------------------------\n";
        cout << "\t\t    ::MAIN MENU::";
        cout << "\n\t\t-------------------------------";

        cout << "\n\t\t1. NEW BANK ACCOUNT";
        cout << "\n\t\t2. DEPOSIT";
        cout << "\n\t\t3. WITHDRAW";
        cout << "\n\t\t4. BALANCE ENQUIRY";
        cout << "\n\t\t5. ALL BANK ACCOUNT HOLDER LIST";
        cout << "\n\t\t6. CLOSE A BANK ACCOUNT";
        cout << "\n\t\t7. UPDATE A BANK ACCOUNT";
        cout << "\n\t\t8. EXIT";
        cout << "\n\n\t\tSelect Your Option (1-8): ";
        cin >> serial;

        switch (serial)
        {
        case '1':
            write_Bank_Account();
            cout << "\n\n\n\n\n\tPress 'Enter' To Continue...";
            break;
        case '2':
            system("CLS");
            cout << "\n\n\tPlease Enter The Bank Account No. : ";
            cin >> num;
            Money_Deposit_withdraw(num, 1);
            cout << "\n\n\n\n\n\tPress 'Enter' To Continue...";
            break;
        case '3':
            system("CLS");
            cout << "\n\n\tPlease Enter The Bank_Account No. : ";
            cin >> num;
            Money_Deposit_withdraw(num, 2);
            cout << "\n\n\n\n\n\tPress 'Enter' To Continue...";
            break;
        case '4':
            system("CLS");
            cout << "\n\n\tPlease Enter The Bank_Account No. : ";
            cin >> num;
            display_details(num);
            cout << "\n\n\n\n\n\tPress 'Enter' To Continue...";
            break;
        case '5':
            display_all();
            cout << "\n\n\n\n\n\tPress 'Enter' To Continue...";
            break;
        case '6':
            system("CLS");
            cout << "\n\n\tPlease Enter The Bank_Account No. : ";
            cin >> num;
            delete_Bank_Account(num);
            cout << "\n\n\n\n\n\tPress 'Enter' To Continue...";
            break;
        case '7':
            system("CLS");
            cout << "\n\n\tPlease Enter The Bank_Account No. : ";
            cin >> num;
            update_Bank_Account(num);
            cout << "\n\n\n\n\n\tPress 'Enter' To Continue...";
            break;
        case '8':
            system("CLS");
            cout << "\n\n\tThanks For Visiting My Bank Management System.";
            cout << "\n\n\tCreated By Azizul Hakim.\n";
            break;
        default:
            cout << "\a";
        }
        cin.ignore();
        cin.get();
    } while (serial != '8');
    return 0;
}