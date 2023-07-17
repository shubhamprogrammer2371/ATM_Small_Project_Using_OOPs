/*ATM Functionalities using OOPs
1 Check balance
2 Cash Withdraw
3 User Details
4 Update Mobile No.*/

#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

class atm
{
private:
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;

public:
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a) // setting private members
    {
        account_No = account_No_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }
    // Getter functions
    long int getAccountNo()
    {
        return account_No;
    }
    string getName()
    {
        return name;
    }
    int getPIN()
    {
        return PIN;
    }
    double getBalance()
    {
        return balance;
    }
    string getMobileNo()
    {
        return mobile_No;
    }
    // update the mobile number
    void setMobileNo(string mob_prev, string mob_new)
    {
        if (mob_prev == mobile_No)
        {
            mobile_No = mob_new;
            cout << endl
                 << "Successfully updated Mobile No.";
            _getch();
        }
        else
        {
            cout << endl
                 << "Please enter a valid old Mobile No.";
            _getch();
        }
    }

    void cashWithdraw(int amount_a)
    {
        if ((amount_a > 0) && (amount_a < balance))
        {
            balance -= amount_a;
            cout << endl
                 << "Please Collect Your Cash";
            cout << endl
                 << "Available Balance :- " << balance;
            _getch();
        }
        else
        {
            cout << endl
                 << "Invalid Amount Entered or Insufficient Balance";
            _getch();
        }
    }
};

int main()
{
    int choice = 0, enterPIN;
    long int enterAccountNo;

    system("cls");

    atm user1;
    user1.setData(1234567, "Shubham", 1111, 100000.87, "123456789");

    do
    {
        system("cls");

        cout << "********* Welcome To ATM ************";
        cout << endl
             << "Enter your Account No. :- ";
        cin >> enterAccountNo;

        cout << endl
             << "Enter your PIN :- ";
        cin >> enterPIN;

        if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;
                system("cls");

                cout << "*********** Welcome To ATM *************";
                cout << endl
                     << "Select Options :-";
                cout << endl
                     << "1) Check Balance";
                cout << endl
                     << "2) Cash Withdraw";
                cout << endl
                     << "3) Show User Details";
                cout << endl
                     << "4) Update Mobile No.";
                cout << endl
                     << "5) Exit" << endl;
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout
                         << "Your Bank Balance is :- " << user1.getBalance() << endl;
                    _getch();
                    break;
                case 2:
                    cout << endl
                         << "Enter the amount :- ";
                    cin >> amount;
                    user1.cashWithdraw(amount);
                    _getch();
                    break;
                case 3:
                    cout << "****** User Details are **********";
                    cout << endl
                         << "-> User Account Number :- " << user1.getAccountNo();
                    cout << endl
                         << "-> User Name :- " << user1.getName();
                    cout << endl
                         << "-> User Balance :- " << user1.getBalance();
                    cout << endl
                         << "-> User Mobile Number :- " << user1.getMobileNo();
                    _getch();
                    break;
                case 4:
                    cout << endl
                         << "Enter your Old Mobile Number :- ";
                    cin >> oldMobileNo;
                    cout << endl
                         << "Enter your New Mobile Number :- ";
                    cin >> newMobileNo;
                    user1.setMobileNo(oldMobileNo, newMobileNo);
                    break;
                case 5:
                    exit(0);

                default:
                    cout << endl
                         << "Invalid Option Selected";
                    break;
                }
            } while (1);
        }
        else
        {
            cout << endl
                 << "Enter a valid Account Number or PIN";
            _getch();
        }
    } while (1);
}