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
bool isPostalCodeValid(string& postalCode);
bool isEmailValid(string& email);
bool isPasswordValid(string& password);
bool isIntegerValid(string& number);
bool isYesNoValid(string& answer);
bool isMultiDigitValid(string& number);
bool isNameValid(string& name);
bool isLicenseValid(string& number);
// bool isOptionValid(int firstOption, int lastOption, int userInput);


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
    string strOption;
    // int intOption1,intOption2;
    int menuOption, accountOption;

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

    //integer & option validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << "  Enter option: ";
        getline(cin, strOption);                                                //integer validation
        if(isIntegerValid(strOption) == false){
            cout << " ------------------------------------------------\n";
            cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (strOption == "1" || strOption == "2" || strOption == "3" || strOption == "4"){   //option validation
            cout << "\n\n";
            // cin.clear();
            // cin.ignore(10000, '\n');
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n ❗️Select a number from the menu. (Press any key to go back) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    menuOption = stoi(strOption);
    

    switch (menuOption) {
        case 1:
        customerMenu(customers, orders, inquiries, sId);
        break;
        
        case 2:
        cout << " ------------------------------------------------\n";
        cout << " Do you have Yoobee Taxi Driver Account?: \n";
        cout << "  1. Login       (if you have our account)\n";
        cout << "  2. Sign up     (if you don't have our account and want to create(free))\n";
        cout << "  3. Exit\n";

        while(true) {
            cout << " ------------------------------------------------\n";
            cout << "  Enter option: ";
            getline(cin, strOption);                                                
            if(isIntegerValid(strOption) == false){
                cout << " ------------------------------------------------\n";
                cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            } else if (strOption == "1" || strOption == "2" || strOption == "3"){
                cout << "\n\n";
                break;
            } else {
                cout << " ------------------------------------------------\n";
                cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        accountOption = stoi(strOption);
        

        switch (accountOption){
            case 1:
            *sId = driverLogin(drivers, orders, inquiries);
            if (*sId != 0){
                driverMenu(drivers, orders, inquiries, sId);
            }
            break;

            case 2:
            driverSignup(drivers, sId);
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
        adminLogin(customers, drivers, admins, orders, inquiries, sId);
        break;
        
        case 4:
        break;
    }
    
}