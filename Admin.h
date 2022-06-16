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
void adminMenu(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
//show info
void customerInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
void driverInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
void adminInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
//show report
void allDataReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
void dailyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
void weeklyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
void monthlyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);
void inquiryReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);

//sign up
void adminSignup(vector <Admins> &admins);
void adminLogin(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries);







/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Menu)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void adminMenu(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){
    int option1, option2;

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
    cout << "------------------------\n";
    cout << "  Enter option: ";
    cin >> option1;
    cout << "\n\n";

    switch(option1){
        case 1:
        customerInfo(customers, drivers, admins, orders, inquiries);
        break;

        case 2:
        driverInfo(customers, drivers, admins, orders, inquiries);
        break;

        case 3:
        adminInfo(customers, drivers, admins, orders, inquiries);
        break;


        case 4:
        cout << "Please choose report type\n";
        cout << "  1.Daily\n";
        cout << "  2.Weekly\n";
        cout << "  3.Monthly\n";
        cout << "  4.All Data\n";
        cout << "  5.Inquiry\n";
        cout << "------------------------\n";
        cout << "  Enter option: ";
        cin >> option2;
        cout << "\n\n";

        switch(option2){
            case 1:
            dailyFareReport(customers, drivers, admins, orders, inquiries);
            break;

            case 2:
            weeklyFareReport(customers, drivers, admins, orders, inquiries);
            break;

            case 3:
            monthlyFareReport(customers, drivers, admins, orders, inquiries);
            break;

            case 4:
            allDataReport(customers, drivers, admins, orders, inquiries);
            break;

            case 5:
            inquiryReport(customers, drivers, admins, orders, inquiries);
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
void adminSignup(vector <Admins> &admins){
    struct Admins a;
    int option;
    int i = admins.size();      //List Size

    cout << "************************************************\n";
    cout << "Admin Sign Up\n";
    cout << "************************************************\n";
    cout << "Enter addmin information \n";
    cout << " Name: ";
    cin >> a.name;

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
    cout << "    Postal Code(e.g. 000-0000): ";
    cin >> a.postalCode;

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
        }
    }

    admins.push_back(a);

    cout << "\n\n";

    ofstream adminList("AdminList.csv", ios::app);

    adminList << admins[i].name << "," << admins[i].phone << "," << admins[i].email << "," << admins[i].street << "," << admins[i].city << "," << admins[i].state << "," << admins[i].country << "," << admins[i].postalCode << "," << admins[i].password << ",\n" ;
}

void adminLogin(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){
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

        for (int i = 1; i < admins.size(); i++){
            if (admins[i].email == userEmail){          //compare admin email with user input
                emailFlag = 1;
            }
            if (admins[i].password == userPassword){    //compare admin password with user input
                passwordFlag = 1;
            }
        }

        attemptCounts--;    
        
        //check results
        if (emailFlag == 1 && passwordFlag == 1){
            //Login successfully
            adminMenu(customers, drivers, admins, orders, inquiries);
            break;

        } else if (attemptCounts == 0){
            cout << "----------------------------------------------------------------\n";
            cout << "You have exceeded the number of login attempts.\n";
            cout << "Please wait a while and try again.\n";
        } else {
            if (emailFlag == 0 && passwordFlag == 0){
                cout << "\n  ❗️Your email address and password are wrong (or you are not authorized)\n";
                cout << "    Please try again.\n\n";
            } else if (emailFlag == 0 && passwordFlag == 1){
                cout << "\n  ❗️Your email address is wrong\n";
                cout << "    Please try again.\n\n";
            } else {
                cout << "\n  ❗️Your password is wrong\n";
                cout << "    Please try again.\n\n";
            }
        }
    }
    cout << "\n";
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Information)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void customerInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){
    cout << "************************************************\n";
    cout << "Customer Information\n";
    cout << "************************************************\n";

    cout << "Name\tPhone\t\tEmail\t\t\tStreet\t\tCity\t\tState\t\tCountry\t\tPostal Code\tPayment Method\n";
    for (int i = 1; i < customers.size(); i++){
        cout << customers[i].name << "  \t" << customers[i].phone << "  \t"<< customers[i].email << "  \t" << customers[i].street << "   \t" << customers[i].city << "   \t" << customers[i].state << "   \t" << customers[i].country << "   \t" << customers[i].postalCode << "\t" << customers[i].payment <<"   \n";
    }
    

    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries);
}

void driverInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){
    cout << "************************************************\n";
    cout << "Driver Information\n";
    cout << "************************************************\n";

    cout << "Name\t\tPhone\t\tEmail\t\t\tStreet\t\tCity\t\tState\t\tCountry\t\tPostal Code\tLicense\t\tArea\n";
    for (int i = 1; i < drivers.size(); i++){
        cout << drivers[i].name << "  \t" << drivers[i].phone << "  \t"<< drivers[i].email << "  \t" << drivers[i].street << "   \t" << drivers[i].city << "   \t" << drivers[i].state << "   \t" << drivers[i].country << "   \t" << drivers[i].postalCode << "\t" << drivers[i].license << "\t" << drivers[i].area <<"   \n";
    }


    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries);
}

void adminInfo(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){
    string option;

    cout << "************************************************\n";
    cout << "Admin Information\n";
    cout << "************************************************\n";

    cout << "Name\t\tPhone\t\tEmail\t\t\tStreet\t\tCity\t\tState\t\tCountry\t\tPostal Code\n";
    for (int i = 1; i < admins.size(); i++){
        cout << admins[i].name << "  \t" << admins[i].phone << "  \t"<< admins[i].email << "  \t" << admins[i].street << "   \t" << admins[i].city << "   \t" << admins[i].state << "   \t" << admins[i].country << "   \t" << admins[i].postalCode <<"   \n";
    }

    cout << "\nDo you want to add Admin?(y/n): ";
    cin >> option;

    if (option == "y"){
        adminSignup(admins);
    } 
    adminMenu(customers, drivers, admins, orders, inquiries);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Report)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void allDataReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){

    cout << "************************************************\n";
    cout << "All Data\n";
    cout << "************************************************\n";

    cout << "Date\t\t Customer\tDriver\t\tCar Type\t\tPickup Location\t\tDestination\t\tFare\n";
    for (int i = 1; i < orders.size(); i++){
        cout << orders[i].year << "/" << orders[i].month << "/"<< orders[i].day << "  \t" << orders[i].customerName << "   \t" << orders[i].driverName << "   \t" << orders[i].carType << "   \t" << orders[i].pickupLocation << "   \t" << orders[i].destination << "\t" << orders[i].fare <<"   \n";
        // cout << right << setw(25) << fixed << orders[i].year << "/" << orders[i].month << "/"<< orders[i].day << "\t" << orders[i].customerName << "\t" << orders[i].driverName << "\t" << orders[i].carType << "\t" << orders[i].pickupLocation << "\t" << orders[i].destination << "\t" << orders[i].fare <<"   \n";
    }


    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries);
}

void dailyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){

    float totalDayCost = 0;
    float totalYearCost = 0;

    cout << "************************************************\n";
    cout << "Daily Report\n";
    cout << "************************************************\n";
    cout << "Day\tFare(NZD)\n";

    for (int i = 0; i < 365; i++){   //1 year = 365 days
        totalDayCost = 0;        //initialize total day cost

        for (int j = 0; j < orders.size(); j++){
            if (i + 1 == orders[j].days){            //calculate from week1 (Day1,2,3,4,5,6,7)
                totalDayCost += orders[j].fare;
            }
        }
        if (totalDayCost > 0){
            cout << i + 1 << "\t" << totalDayCost << "\n";
            totalYearCost += totalDayCost; 

        } else {
            //Show all day cost including 0
            // cout << "Day " << i + 1 << " :\t" << 0 << "\n";
        }
    }
    cout << "Total\t" << totalYearCost << "\n";


    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries);

}

void weeklyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){

    float totalWeekCost = 0;
    float totalYearCost = 0;

    cout << "************************************************\n";
    cout << "Weekly Report\n";
    cout << "************************************************\n";
    cout << "Week\tFare(NZD)\n";

    for (int i = 0; i < 53; i++){   //1 year = 53 weeks
        totalWeekCost = 0;        //initialize total day cost

        for (int j = 0; j < orders.size(); j++){
            if (i + 1 == orders[j].week){            //calculate from week1 (Day1,2,3,4,5,6,7)
                totalWeekCost += orders[j].fare;
            }
        }
        if (totalWeekCost > 0){
            cout << i + 1 << "\t" << totalWeekCost << "\n";
            totalYearCost += totalWeekCost; 

        } else {
            //Show all day cost including 0
            // cout << "Day " << i + 1 << " :\t" << 0 << "\n";
        }
    }
    cout << "Total\t" << totalYearCost << "\n";

    
    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries);
}

void monthlyFareReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){

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
            cout << i + 1 << "\t" << totalMonthCost << "\n";
            totalYearCost += totalMonthCost; 

        } else {
            //Show all day cost including 0
            // cout << "Day " << i + 1 << " :\t" << 0 << "\n";
        }
    }
    cout << "Total\t" << totalYearCost << "\n";


    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries);
}


void inquiryReport(vector <Customers> &customers, vector <Drivers> &drivers, vector <Admins> &admins, vector <Orders> &orders, vector <Inquiries> &inquiries){

    cout << "************************************************\n";
    cout << "Inquiry Report\n";
    cout << "************************************************\n";
    cout << "Date\t\tCustomer\tUser Type\tPhone\t\t\tEmail\t\t\tTopic\t\tDetail\n";
    for (int i = 1; i < inquiries.size(); i++){
        cout << inquiries[i].year << "/" << inquiries[i].month << "/"<< inquiries[i].day << "  \t" << inquiries[i].name << "   \t" << inquiries[i].userType << "   \t" << inquiries[i].phone << "   \t" << inquiries[i].email << "   \t" << inquiries[i].topic << "\t" << inquiries[i].detail <<"   \n";
    }

    //go back to the admin menu
    cout << "\nPress any key to go back to the Admin Menu\n";
    system("read");
    adminMenu(customers, drivers, admins, orders, inquiries);
}
