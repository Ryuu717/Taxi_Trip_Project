#include <iostream>
#include <vector>
#include <fstream>      //for ofstream, ifstream
#include <sstream>      //for istringstream
#include <regex>    //include regular expressions library
#include <iomanip>

using namespace std;




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declare function prototypes
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Admin//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void adminMenu(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
//show info
void customerInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void driverInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void adminInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
//show report
void allDataReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void dailyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void weeklyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void monthlyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);
void inquiryReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);

//sign up
void adminSignup(vector <Admins> &admins, int* sId);
void adminLogin(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId);







/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Menu)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void adminMenu(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    int option1, option2;
    string adminMenuOptS, reportOptS;
    int adminMenuOptI, reportOptI;

    cout << "\n************************************************\n";
    cout << "Welcome Yoobee Admin!\n";
    cout << "Please select a number from the menu\n";
    cout << "************************************************\n";
    cout << "Menu\n";
    cout << "  1.Customer Information\n";
    cout << "  2.Driver Information\n";
    cout << "  3.Admin Information\n";
    cout << "  4.Report\n";
    cout << "  5.Exit\n";

    //integer & option validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << "  Enter option: ";
        getline(cin, adminMenuOptS);                                                                    //integer validation
        if(isIntegerValid(adminMenuOptS) == false){
            cout << " ------------------------------------------------\n";
            cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (adminMenuOptS == "1" || adminMenuOptS == "2" || adminMenuOptS == "3" || adminMenuOptS == "4" || adminMenuOptS == "5"){   //option validation
            cout << "\n\n";
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    adminMenuOptI = stoi(adminMenuOptS);



    // cout << "------------------------\n";
    // cout << "  Enter option: ";
    // cin >> option1;
    // cout << "\n\n";

    switch(adminMenuOptI){
        case 1:
        customerInfo(customers, drivers, admins, orders, inquiries, sId);
        break;

        case 2:
        driverInfo(customers, drivers, admins, orders, inquiries, sId);
        break;

        case 3:
        adminInfo(customers, drivers, admins, orders, inquiries, sId);
        break;


        case 4:
        cout << "Please choose report type\n";
        cout << "  1.Daily\n";
        cout << "  2.Weekly\n";
        cout << "  3.Monthly\n";
        cout << "  4.All Data\n";
        cout << "  5.Inquiry\n";

        //integer & option validation
        while(true){
            cout << " ------------------------------------------------\n";
            cout << "  Enter option: ";
            getline(cin, reportOptS);                                                                    //integer validation
            if(isIntegerValid(reportOptS) == false){
                cout << " ------------------------------------------------\n";
                cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            } else if (reportOptS == "1" || reportOptS == "2" || reportOptS == "3" || reportOptS == "4" || reportOptS == "5"){   //option validation
                cout << "\n\n";
                break;
            } else {
                cout << " ------------------------------------------------\n";
                cout << "\n ❗️Select a number from the menu. (Press any key) \n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        reportOptI = stoi(reportOptS);


        // cout << "------------------------\n";
        // cout << "  Enter option: ";
        // cin >> reportOptI;
        cout << "\n\n";

        switch(reportOptI){
            case 1:
            dailyFareReport(customers, drivers, admins, orders, inquiries, sId);
            break;

            case 2:
            weeklyFareReport(customers, drivers, admins, orders, inquiries, sId);
            break;

            case 3:
            monthlyFareReport(customers, drivers, admins, orders, inquiries, sId);
            break;

            case 4:
            allDataReport(customers, drivers, admins, orders, inquiries, sId);
            break;

            case 5:
            inquiryReport(customers, drivers, admins, orders, inquiries, sId);
            break;
        }
        break;

        case 5:
        cout << "Thank you!\n\n";
        break;
    }
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Sign up, Login)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void adminSignup(vector <Admins> &admins, int* sId){
    struct Admins a;
    int option;
    int i = admins.size();      //List Size
    string adminNameS;

    a.adminId = i;

    cout << "************************************************\n";
    cout << "Admin Sign Up\n";
    cout << "************************************************\n";
    cout << "Enter addmin information \n";
    
    while(true){
        cout << " ------------------------------------------------\n";
        cout << " Name: ";
        getline(cin, adminNameS);                                            
        if(isNameValid(adminNameS) == true){
            a.name = adminNameS;
            break;
        } else {
            cout << " ------------------------------------------------\n";
            cout << "\n ❗️Enter your name. (Press any key) \n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    //phone validation
    while (true){
        cout << " Phone number (e.g. 000-0000-0000): ";
        cin  >> a.phone;

        if (isPhoneValid(a.phone) == true){
            break;
        } else {
            cout << "\n  ❗️Please enter a valid phone number\n\n";
        }
    }

    //email validation
    while (true){
        cout << " Email address (e.g. test@email.com): ";
        cin  >> a.email;

        if (isEmailValid(a.email) == true){
            break;
        } else {
            cout << "\n  ❗️Please enter a valid email address\n\n";
        }
    }

    cout << " Home address: \n";
    cout << "    Street: ";
    cin >> a.street;
    cout << "    City: ";
    cin >> a.city;
    cout << "    State: ";
    cin >> a.state;
    cout << "    Country: ";
    cin >> a.country;

    while (true){
        cout << "    Postal Code(e.g. 000-0000): ";
        cin  >> a.postalCode;

        if (isPostalCodeValid(a.postalCode) == true){
            break;
        } else {
            cout << "\n  ❗️Please enter a valid postal code\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    //password validation
    cout << "\nEnter your password: \n";
    cout << "  -At least 8 characters\n";
    cout << "  -At least one upper case character\n";
    cout << "  -At least one lower case character\n";
    cout << "  -At least one special character (@, !, ?, #)\n";
    cout << "  -At least one number\n";
    
    while (true){
        cout << "---------------------------------------------------------\n";
        cout << "   Your password is: ";
        cin  >> a.password;
        cout << "\n";

        if (isPasswordValid(a.password) == true){
            break;
        } else {
            cout << "\nPlease enter a valid password.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    admins.push_back(a);

    cout << "\n\n";

    cout << " ------------------------------------------------\n";
    cout << " Please check and confirm your information \n\n";
    cout << "  Name:\t\t\t" << a.name <<"\n";
    cout << "  Phone:\t\t" << a.phone << "\n";
    cout << "  Email:\t\t" << a.email << "\n";
    cout << "  Street:\t\t" << a.street << "\n";
    cout << "  City:\t\t\t" << a.city << "\n";
    cout << "  State:\t\t" << a.state << "\n";
    cout << "  Country:\t\t" << a.country << "\n";
    cout << "  Postal Code:\t\t" << a.postalCode << "\n";


    //confirm order
    string confirm;
    ofstream adminList("AdminList.csv", ios::app);

    while(true){
        cout << " ------------------------------------------------\n";
        cout << "Confirm sign up (y/n): ";
        cin >> confirm;

        if (isYesNoValid(confirm) == true){
            if (confirm == "y"){
                cout << "------------------------------------------------\n";
                cout << "\n  Registred successfully!\n\n\n";
                adminList << admins[i].adminId << "," << admins[i].name << "," << admins[i].phone << "," << admins[i].email << "," << admins[i].street << "," << admins[i].city << "," << admins[i].state << "," << admins[i].country << "," << admins[i].postalCode << "," << admins[i].password << ",\n" ;
                cin.clear();
                cin.ignore(10000, '\n');
            } else {
                cout << "\n  Your register was canceled.\n\n\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            break;
        } else {
            cout << "\n  ❗️Please answer with y or n\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

void adminLogin(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    string userEmail, userPassword;
    int attemptCounts = 3;          //limit of attempts

    cout << "************************************************\n";
    cout << "Admin Login\n";
    cout << "************************************************\n";
    cout << "Enter your information \n";
    
    while (attemptCounts > 0){
        cout << " Email address: ";
        cin >> userEmail;
        cout << " Password: ";
        cin >> userPassword;

        int emailFlag = 0, passwordFlag = 0;            //initialize flag

        for (int i = 1; i < customers.size(); i++){        
            if (admins[i].email == userEmail && admins[i].password == userPassword){
                emailFlag = 1;
                passwordFlag = 1;
                break;
            }
            if (admins[i].email == userEmail && admins[i].password != userPassword){
                emailFlag = 1;
                passwordFlag = 0;
                break;
            }
            if (admins[i].email != userEmail){
                emailFlag = 0;
                passwordFlag = 0;
            }
        }

        attemptCounts--;    
        
        //check results
        if (emailFlag == 1 && passwordFlag == 1){
            //Login successfully
            cin.clear();
            cin.ignore(10000, '\n');
            adminMenu(customers, drivers, admins, orders, inquiries, sId);
            break;

        } else if (attemptCounts == 0){
            cout << "----------------------------------------------------------------\n";
            cout << "❗️You have exceeded the number of login attempts.\n";
            cout << "  Please wait a while and try again.\n";
        } else {
            if (emailFlag == 1 && passwordFlag == 0){
                cout << "\n  ❗️Your password is wrong\n";
                cout << "    Please try again.\n\n";
            } else if (emailFlag == 0 & passwordFlag == 0){
                cout << "\n  ❗️Your email address is not registered.\n";
                cout << "    Please try again.\n\n";
            } 
        }
    }
    cout << "\n";
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Information)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void customerInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    cout << "************************************************\n";
    cout << "Customer Information\n";
    cout << "************************************************\n";
    cout << "ID\tName\t\tPhone\t\tEmail\t\t\tStreet\t\tCity\t\tState\t\tCountry\t\tPostal Code\tPayment Method\n";
    for (int i = 1; i < customers.size(); i++){
        const char *str1 = customers[i].name.c_str();      //convert string to char*
        const char *str2 = customers[i].phone.c_str();
        const char *str3 = customers[i].email.c_str();
        const char *str4 = customers[i].street.c_str();
        const char *str5 = customers[i].city.c_str();
        const char *str6 = customers[i].state.c_str();
        const char *str7 = customers[i].country.c_str();
        const char *str8 = customers[i].postalCode.c_str();
        const char *str9 = customers[i].payment.c_str();

        printf("%-8d%-16s%-16s%-20s\t%-16s%-16s%-16s%-16s%-16s%-16s\n", customers[i].customerId,str1,str2,str3,str4,str5,str6,str7,str8,str9);
    }
    

    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries, sId);
}

void driverInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    cout << "************************************************\n";
    cout << "Driver Information\n";
    cout << "************************************************\n";
    cout << "ID\tName\t\tPhone\t\tEmail\t\t\tStreet\t\tCity\t\tState\t\tCountry\t\tPostal Code\tLicense No.\tArea\n";
    for (int i = 1; i < drivers.size(); i++){
        const char *str1 = drivers[i].name.c_str();      //convert string to char*
        const char *str2 = drivers[i].phone.c_str();
        const char *str3 = drivers[i].email.c_str();
        const char *str4 = drivers[i].street.c_str();
        const char *str5 = drivers[i].city.c_str();
        const char *str6 = drivers[i].state.c_str();
        const char *str7 = drivers[i].country.c_str();
        const char *str8 = drivers[i].postalCode.c_str();
        const char *str9 = drivers[i].license.c_str();
        const char *str10 = drivers[i].area.c_str();

        printf("%-8d%-16s%-16s%-20s\t%-16s%-16s%-16s%-16s%-16s%-16s%-16s\n", drivers[i].driverId,str1,str2,str3,str4,str5,str6,str7,str8,str9,str10);
    }


    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries, sId);
}

void adminInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    string option;

    cout << "************************************************\n";
    cout << "Admin Information\n";
    cout << "************************************************\n";
    cout << "ID\tName\t\tPhone\t\tEmail\t\t\tStreet\t\tCity\t\tState\t\tCountry\t\tPostal Code\n";
    for (int i = 1; i < drivers.size(); i++){
        const char *str1 = admins[i].name.c_str();      //convert string to char*
        const char *str2 = admins[i].phone.c_str();
        const char *str3 = admins[i].email.c_str();
        const char *str4 = admins[i].street.c_str();
        const char *str5 = admins[i].city.c_str();
        const char *str6 = admins[i].state.c_str();
        const char *str7 = admins[i].country.c_str();
        const char *str8 = admins[i].postalCode.c_str();

        printf("%-8d%-16s%-16s%-20s\t%-16s%-16s%-16s%-16s%-16s\n", drivers[i].driverId,str1,str2,str3,str4,str5,str6,str7,str8);
    }

    string confirm;

    while(true){
        cout << " ------------------------------------------------\n";
        cout << "\nDo you want to add Admin?(y/n): ";
        cin >> confirm;

        if (isYesNoValid(confirm) == true){
            if (confirm == "y"){
                cin.clear();
                cin.ignore(10000, '\n');

                cout << "\n\n";
                adminSignup(admins, sId);
                adminMenu(customers, drivers, admins, orders, inquiries, sId);
            } else {
                cin.clear();
                cin.ignore(10000, '\n');
                adminMenu(customers, drivers, admins, orders, inquiries, sId);
            }
            break;
        } else {
            cout << "\n  ❗️Please answer with y or n\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Report)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void allDataReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){


    cout << "************************************************\n";
    cout << "All Data\n";
    cout << "************************************************\n";

    cout << "Order ID  Date(Pickup)\t\tCustomer\tDriver\t\tCar Type\t\tArea(from)  Area(to)\tPickup Location\tDestination\tFare\n";
    for (int i = 1; i < orders.size(); i++){
        const char *str1 = orders[i].customerName.c_str();      //convert string to char*
        const char *str2 = orders[i].driverName.c_str();
        const char *str3 = orders[i].carType.c_str();
        const char *str4 = orders[i].pickupLocation.c_str();
        const char *str5 = orders[i].destination.c_str();

        printf("%-8d  %d/%d/%d %02d:%02d  \t%-15s\t%-15s\t%-24s%-12d%-12d%-15s\t%-15s %-2.2f\n", orders[i].orderId,orders[i].year,orders[i].month,orders[i].day,orders[i].hour,orders[i].min,str1,str2,str3,orders[i].pickupArea,orders[i].destinationArea,str4,str5,orders[i].fare);
    }


    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries, sId);
}

void dailyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){
    float totalDayCost = 0;
    float totalYearCost = 0;

    cout << "************************************************\n";
    cout << "Daily Report\n";
    cout << "************************************************\n";
    cout << "  Day\tFare(NZD)\n";

    for (int i = 0; i < 365; i++){   //1 year = 365 days
        totalDayCost = 0;        //initialize total day cost

        for (int j = 0; j < orders.size(); j++){
            if (i + 1 == orders[j].days){            //calculate from week1 (Day1,2,3,4,5,6,7)
                totalDayCost += orders[j].fare;
            }
        }
        if (totalDayCost > 0){
            int day = i + 1;

            printf("%5d\t%8.2f\n", day,totalDayCost);

            totalYearCost += totalDayCost; 
        } 
    }
    printf("Total\t%8.2f\n", totalYearCost);


    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries, sId);

}

void weeklyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){

    float totalWeekCost = 0;
    float totalYearCost = 0;

    cout << "************************************************\n";
    cout << "Weekly Report\n";
    cout << "************************************************\n";
    cout << " Week\tFare(NZD)\n";

    for (int i = 0; i < 53; i++){   //1 year = 53 weeks
        totalWeekCost = 0;        //initialize total day cost

        for (int j = 0; j < orders.size(); j++){
            if (i + 1 == orders[j].week){            //calculate from week1 (Day1,2,3,4,5,6,7)
                totalWeekCost += orders[j].fare;
            }
        }
        if (totalWeekCost > 0){
            int week = i + 1;

            printf("%5d\t%8.2f\n", week,totalWeekCost);

            totalYearCost += totalWeekCost; 
        } 
    }
    printf("Total\t%8.2f\n", totalYearCost);

    
    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries, sId);
}

void monthlyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){

    float totalMonthCost = 0;
    float totalYearCost = 0;

    cout << "************************************************\n";
    cout << "Monthly Report\n";
    cout << "************************************************\n";
    cout << "Month\tFare(NZD)\n";

    for (int i = 0; i < 53; i++){   //1 year = 53 weeks
        totalMonthCost = 0;        //initialize total day cost

        for (int j = 0; j < orders.size(); j++){
            if (i + 1 == orders[j].month){            //calculate from week1 (Day1,2,3,4,5,6,7)
                totalMonthCost += orders[j].fare;
            }
        }
        if (totalMonthCost > 0){
            int month = i + 1;

            printf("%5d\t%8.2f\n", month,totalMonthCost);

            totalYearCost += totalMonthCost; 
        } 
    }
    printf("Total\t%8.2f\n", totalYearCost);


    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries, sId);
}


void inquiryReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries, int* sId){

    cout << "************************************************\n";
    cout << "Inquiry Report\n";
    cout << "************************************************\n";
    // cout << "Date\t\tCustomer\tUser Type\tPhone\t\t\tEmail\t\t\tTopic\t\tDetail\n";
    // for (int i = 1; i < inquiries.size(); i++){
    //     cout << inquiries[i].year << "/" << inquiries[i].month << "/"<< inquiries[i].day << "  \t" << inquiries[i].name << "   \t" << inquiries[i].userType << "   \t" << inquiries[i].phone << "   \t" << inquiries[i].email << "   \t" << inquiries[i].topic << "\t" << inquiries[i].detail <<"   \n";
    // }

    cout << "Date\t\tCustomer\tUser Type\tPhone\t\tEmail\t\t\tTopic\t\tDetail\n";
    for (int i = 1; i < inquiries.size(); i++){
        const char *str1 = inquiries[i].name.c_str();      //convert string to char*
        const char *str2 = inquiries[i].userType.c_str();
        const char *str3 = inquiries[i].phone.c_str();
        const char *str4 = inquiries[i].email.c_str();
        const char *str5 = inquiries[i].topic.c_str();
        const char *str6 = inquiries[i].detail.c_str();

        printf("%d/%d/%d\t%-16s%-16s%-16s%-24s%-16s%-16s\n", inquiries[i].year,inquiries[i].month,inquiries[i].day,str1,str2,str3,str4,str5,str6);
    }

    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries, sId);
}
