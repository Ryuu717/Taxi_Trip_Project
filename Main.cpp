#include <iostream>
#include <vector>
#include <fstream>      //for ofstream, ifstream
#include <sstream>      //for istringstream
#include "Common.h"
#include "Admin.h"
#include "Customer.h"
#include "Driver.h"

using namespace std;




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declare function prototypes
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mainMenu(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);

//validation
bool isPhoneValid(string& phone);
bool isEmailValid(string& email);
bool isPasswordValid(string& password);
bool isIntegerValid(string& number);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Main
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    vector <Customers> customers;
    vector <Drivers> drivers;
    vector <Admins> admins;
    vector <Orders> orders;
    vector <Inquiries> inquiries;
    

    readCustomerList(customers);
    readDriverList(drivers);
    readAdminList(admins);
    readOrderList(orders);
    readInquiryList(inquiries);


    //store session user id
    int sessionId = 0;          //initial value is 0 (= no session)
    int* sId = &sessionId;



    mainMenu(customers, drivers, admins, orders, inquiries, sId);


    return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mainMenu(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    int option;

    cout << "===============================================================================================\n";
    cout << "_____.___.            ___.                   ________________  ____  ___.___\n\\__  |   | ____   ____\\_ |__   ____   ____   \\__    ___/  _  \\ \\   \\/  /|   |\n /   |   |/  _ \\ /  _ \\| __ \\_/ __ \\_/ __ \\    |    | /  /_\\  \\ \\     / |   |\n \\____   (  <_> |  <_> ) \\_\\ \\  ___/\\  ___/    |    |/    |    \\/     \\ |   |\n / ______|\\____/ \\____/|___  /\\___  >\\___  >   |____|\\____|__  /___/\\  \\|___|\n\n";
    cout << "===============================================================================================\n\n";
    cout << "************************************************\n";
    cout << "Welcome to Yoobee Taxi!\n";
    cout << "Please select a number from the menu\n";
    cout << "************************************************\n";
    cout << "Menu\n";
    cout << "  1.Customer\n";
    cout << "  2.Driver\n";
    cout << "  3.Admin\n";
    cout << "  4.Exit\n";
    cout << "------------------------\n";
    cout << "  Enter option: ";
    cin >> option;
    cout << "\n\n";

    switch (option) {
        case 1:
        customerMenu(customers, orders, inquiries, sId);
        break;
        
        case 2:
        cout << " ------------------------------------------------\n";
        cout << " Do you have Yoobee Taxi Driver Account?: \n";
        cout << "  1. Login       (if you have our account)\n";
        cout << "  2. Sign up     (if you don't have our account and want to create(free))\n";
        cout << "  3. Exit\n";
        cout << " ------------------------------------------------\n";
        cout << "  Enter option: ";
        cin >> option;

        switch (option){
            case 1:
            *sId = driverLogin(drivers, orders, inquiries);
            if (*sId != 0){
                driverMenu(drivers, orders, inquiries, sId);
            }
            break;

            case 2:
            driverSignup(drivers);
            *sId = drivers.size() -1;

            if (*sId != 0){
                driverMenu(drivers, orders, inquiries, sId);
            }
            break;

            case 3:
            break;
        }
        break;

        case 3:
        adminLogin(customers, drivers, admins, orders, inquiries);
        break;
        case 4:
        break;
    }

}