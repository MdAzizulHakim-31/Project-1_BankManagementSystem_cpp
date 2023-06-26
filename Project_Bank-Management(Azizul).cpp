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
    char ret_Type() const;
    void update();
};

// ...Account creation
void Bank_Account::create_Bank_Account()
{
    system("CLS");
    cout << "\n\tEnter the Bank Account No. : ";
    cin >> accountNo;
    cout << "\n\n\tEnter the Bank Account Holder Name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n\tEnter Type Of the Bank Account (C/S) : ";
    cin >> type;
    type = toupper(type);
    cout << "\n\tEnter The Starting Money : ";
    cin >> Money_Deposit;
    cout << "\n\n\tCongratulations!!!";
    cout << "\n\n\tBank Account Created.";
}

// ...Account display
void Bank_Account::display_Account() const
{
    cout << "\n\tBank Account No. : " << accountNo;
    cout << "\n\tBank Account Holder Name : " << name;
    cout << "\n\tType of Bank Account : " << type;
    cout << "\n\tTotal Balance : " << Money_Deposit;
}

// ...Updation
void Bank_Account::update()
{
    cout << "\n\tBank Account No. : " << accountNo;
    cout << "\n\n\tUpdation Bank Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\tUpdation Type of Bank Account : ";
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
    cout << "\t" << accountNo << setw(10) << " " << name << setw(10) << " " << type << " " << setw(10) << Money_Deposit << " Tk" << endl;
}
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

// ...Main section
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
        system("CLS");
        cout << "\n\n\t\t***WELCOME TO BANK MANAGEMENT SYSTEM***";
        cout << "\n\n\t\t-------------------------------\n";
        cout << "\t\t    ::MAIN MENU::";
        cout << "\n\t\t-------------------------------\n";
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
            cout << "\n\n\tEnter The Bank Account No. : ";
            cin >> num;
            Money_Deposit_withdraw(num, 1);
            cout << "\n\n\n\n\n\tPress 'Enter' To Continue...";
            break;
        case '3':
            system("CLS");
            cout << "\n\n\tEnter The Bank Account No. : ";
            cin >> num;
            Money_Deposit_withdraw(num, 2);
            cout << "\n\n\n\n\n\tPress 'Enter' To Continue...";
            break;
        case '4':
            system("CLS");
            cout << "\n\n\tEnter The Bank Account No. : ";
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
            cout << "\n\n\tEnter The Bank Account No. : ";
            cin >> num;
            delete_Bank_Account(num);
            cout << "\n\n\n\n\n\tPress 'Enter' To Continue...";
            break;
        case '7':
            system("CLS");
            cout << "\n\n\tEnter The Bank Account No. : ";
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
    } 
    while (serial != '8');
    return 0;
}

// ...Write Account
void write_Bank_Account()
{
    Bank_Account ac;
    ofstream outFile;
    outFile.open("Bank_Account.dat", ios::binary | ios::app);
    ac.create_Bank_Account();
    outFile.write(reinterpret_cast<char *>(&ac), sizeof(Bank_Account));
    outFile.close();
}

// ...Account delete
void delete_Bank_Account(int n)
{
    Bank_Account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("Bank_Account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !!";
        cout << "\n\n\n\n\n\tPress 'Enter' To Continue...";
        return;
    }
    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Bank_Account)))
    {
        if (ac.ret_Acc_No() != n)
        {
            outFile.write(reinterpret_cast<char *>(&ac), sizeof(Bank_Account));
        }
    }
    inFile.close();
    outFile.close();
    remove("Bank_Account.dat");
    rename("Temp.dat", "Bank_Account.dat");
    cout << "\n\n\tRecord Deleted ..";
}

// ...Display details
void display_details(int n)
{
    Bank_Account ac;
    bool flag = false;
    ifstream inFile;
    inFile.open("Bank_Account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\n\tBALANCE DETAILS\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Bank_Account)))
    {
        if (ac.ret_Acc_No() == n)
        {
            ac.display_Account();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\n\tBank Account number does not exist.";
}

// ...Display details
void display_all()
{
    system("CLS");
    Bank_Account ac;
    ifstream inFile;
    inFile.open("Bank_Account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\n\n\t\tBank_Account HOLDER LIST\n\n";
    cout << "----------------------------------------------------------------\n";
    cout << "\tA/C NO.     NAME            TYPE      BALANCE";
    cout << "\n-----------------------------------------------------------------\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Bank_Account)))
    {
        ac.report();
    }
    inFile.close();
}

// ...Update account information
void update_Bank_Account(int n)
{
    bool found = false;
    Bank_Account ac;
    fstream File;
    File.open("Bank_Account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "\n\tFile could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(Bank_Account));
        if (ac.ret_Acc_No() == n)
        {
            ac.display_Account();
            cout << "\n\n\tPlease Enter The New Details of Bank_Account" << endl;
            ac.update();
            int pos = (-1) * static_cast<int>(sizeof(Bank_Account));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(Bank_Account));
            cout << "\n\n\tRecord Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n\tRecord Not Found.";
}

// ...Deposit & withdraw calculation
void Money_Deposit_withdraw(int n, int option)
{
    int amt;
    bool found = false;
    Bank_Account ac;
    fstream File;
    File.open("Bank_Account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "\n\tFile could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(Bank_Account));
        if (ac.ret_Acc_No() == n)
        {
            ac.display_Account();
            if (option == 1)
            {
                cout << "\n\n\tEnter The amount you want to deposit: ";
                cin >> amt;
                ac.deposit(amt);
            }
            if (option == 2)
            {
                cout << "\n\n\tEnter The amount you want to withdraw: ";
                cin >> amt;
                int bal = ac.ret_Money_Deposit() - amt;
                if (bal < 0)
                    cout << "\n\tInsufficient balance";
                else
                    ac.withdraw(amt);
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(Bank_Account));
            cout << "\n\n\tRecord Updated.";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n\tRecord Not Found.";
}