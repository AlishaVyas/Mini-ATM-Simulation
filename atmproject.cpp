#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

/*
Mini Project -ATM
    -> Check Balance
    -> Cash Withdraw
    -> User Details
    -> Updates Mobile No.
*/

class atm
{  
private:
    long int account_No;
    string name;
    int PIN;
    double balance;
    string Mobile_No;

public:

    void setData(long int account_No, string name, int PIN, double balance, string Mobile_No){
        this->account_No = account_No;
        this->name = name;
        this->PIN = PIN;
        this->balance = balance;
        this->Mobile_No = Mobile_No;
    }

    long int getAccountNo(){
        return account_No;
    }

    string getName(){
        return name;
    }

    int getPIN(){
        return PIN;
    }

    double getBalance(){
        return balance;
    }

    string getMobileNo(){
        return Mobile_No;
    }

    void setMobileNo(string Mobile_No){
        this->Mobile_No = Mobile_No;
    }

    void cashWithdraw(double amount){
        if(balance < amount && amount < 0){
            cout << "Insufficient Balance" << endl;
            _getch();
        }else{
            balance -= amount;
            cout << "Withdrawal Successful" << endl;
            cout << "Available Balance: " << balance << endl;
            _getch();
        }
    }

};

int main(){
    int PIN;
    long int account_No;

    system("cls"); 

    atm user1;
    user1.setData(123456789, "lily", 1234, 50000, "9876543210");

    do{
        system("cls");
        cout << "**** ATM ****" << endl;
        cout << "Enter Account No.: ";
        cin >> account_No;
        cout << "Enter PIN: ";
        cin >> PIN;

        if((account_No == user1.getAccountNo()) && (PIN == user1.getPIN())){
            do{
                int choice;
                double amount;
                string new_Mobile_No;

                system("cls");
                cout << "**** Welcome to ATM ****" << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Cash Withdraw" << endl;
                cout << "3. Show User Details" << endl;
                cout << "4. Update Mobile No." << endl;
                cout << "5. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

               
                switch(choice){
                    case 1:
                        cout << "Your Account Balance is: " << user1.getBalance() << endl;
                        _getch();
                        break;
                    case 2:
                        cout << "Enter the amount to withdraw: ";
                        cin >> amount;
                        user1.cashWithdraw(amount);
                        break;
                    case 3:
                        cout << "Account No.: " << user1.getAccountNo() << endl;
                        cout << "Name: " << user1.getName() << endl;
                        cout << "Balance: " << user1.getBalance() << endl;
                        cout << "Mobile No.: " << user1.getMobileNo() << endl;
                        break;
                    case 4:
                        cout << "Enter New Mobile No.: ";
                        cin >> new_Mobile_No;
                        user1.setMobileNo(new_Mobile_No);
                        cout << "Mobile No. Updated Successfully" << endl;
                        break;
                    case 5:
                        exit(0);
                        break;
                    default:
                        cout << "Invalid Choice" << endl;
                }

                cout << "Press any key to continue..." << endl;
                getch();

            }while(1);
        }else{
            cout << "Invalid Account No. or PIN" << endl;
            cout<< user1.getAccountNo() << " " << user1.getPIN();
            _getch();
        }
    }while(1);

}