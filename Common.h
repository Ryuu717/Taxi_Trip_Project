#include <iostream>
#include <vector>
#include <fstream>      //for ofstream, ifstream
#include <sstream>      //for istringstream
#include <regex>    //include regular expressions library
#include <ctime>

using namespace std;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Declare structures
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Customers{
    string name;
    string phone;
    string email;
    string street;
    string city;
    string state;
    string country;
    string postalCode;
    string password;
    string payment;
    // string creditCardNumber;
    string pickupLocation;
    string destination;
    int selectedService;

    //constructor
    Customers(string n="name", string pn="000-0000-0000", string e="email@email.com", string p="password", string str="street", string cit="city", string sta="state", string cou="country", string pc="000-0000", string pm="credit", string ccn="NA", string pl="area1",string des="area2",int ss=1){
        name = n;
        phone = pn;
        email = e;
        street = str;
        city = cit;
        state = sta;
        country = cou;
        postalCode = pc;
        password = p;
        payment = pm;
        // creditCardNumber = ccn;
        pickupLocation = pl;
        destination = des;
        selectedService = ss;
    }
};

struct Drivers{
    string name;
    string phone;
    string email;
    string street;
    string city;
    string state;
    string country;
    string postalCode;
    string password;
    string license;
    string area;

    //constructor
    Drivers(string n="name", string pn="000-0000-0000", string e="email@email.com", string p="password", string str="street", string cit="city", string sta="state", string cou="country", string pc="000-0000", string li="0000-0000", string a="area"){
        name = n;
        phone = pn;
        email = e;
        street = str;
        city = cit;
        state = sta;
        country = cou;
        postalCode = pc;
        password = p;
        license = li;
        area = a;
    }
};

struct Admins{
    string name;
    string phone;
    string email;
    string street;
    string city;
    string state;
    string country;
    string postalCode;
    string password;
    string payment;

    //constructor
    Admins(string n="name", string pn="000-0000-0000", string e="email@email.com", string p="password", string str="street", string cit="city", string sta="state", string cou="country", string pc="000-0000", string pm="credit"){
        name = n;
        phone = pn;
        email = e;
        street = str;
        city = cit;
        state = sta;
        country = cou;
        postalCode = pc;
        password = p;
        payment = pm;
    }
};

struct Orders{
    int year;
    int month;
    int day;
    int days;
    int week;
    string customerName;
    string driverName;
    string carType;
    string pickupLocation;
    string destination;
    float fare;
    int selectedService;

    Orders(int y=2022, int m=01, int d=01, int ds=01, int w=01, string cn="customer name", string dn="driver name", string ct="taxi", string pl="pickup location", string des="destination", float fa=10.00, int ss=1){
        year = y;
        month = m;
        day = d;
        days = ds;
        week = w;
        customerName = cn; 
        driverName = dn; 
        carType = ct;
        pickupLocation = pl; 
        destination = des;
        fare = fa;
        selectedService = ss;
    }
};

struct Inquiries{
    int year;
    int month;
    int day;
    string name;
    string userType;
    string phone;
    string email;
    string topic;
    string detail;

    Inquiries(int y=2022, int m=01, int d=01, string n="name", string ut="user type", string p="000-0000-0000", string e="email@email.com", string t="topic", string de="detail"){
        year = y;
        month = m;
        day = d;
        name = n; 
        userType = ut; 
        phone = p;
        email = e; 
        topic = t;
        detail = de;
    }
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Read Files)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void readOrderList(vector <Orders> &orders){
    ifstream orderList("OrderList.csv");
    string line, item;
    struct Orders o;

    while (getline(orderList, line)) {    
        istringstream i_stream(line);
        
        //String to integer conversion
        getline(i_stream, item, ',');
        o.year = atoi(item.c_str());
        getline(i_stream, item, ',');
        o.month = atoi(item.c_str());
        getline(i_stream, item, ',');
        o.day = atoi(item.c_str());
        getline(i_stream, item, ',');
        o.days = atoi(item.c_str());
        getline(i_stream, item, ',');
        o.week = atoi(item.c_str());

        getline(i_stream, o.customerName, ',');
        getline(i_stream, o.driverName, ',');
        getline(i_stream, o.carType, ',');
        getline(i_stream, o.pickupLocation, ',');
        getline(i_stream, o.destination, ',');
        getline(i_stream, item, ',');
        o.fare = atoi(item.c_str());
        
        orders.push_back(o);
    }
}

void readInquiryList(vector <Inquiries> &inquiries){
    ifstream inquiryList("InquiryList.csv");
    string line, item;
    struct Inquiries i;

    while (getline(inquiryList, line)) {    
        istringstream i_stream(line);
        
        getline(i_stream, item, ',');
        i.year = atoi(item.c_str());
        getline(i_stream, item, ',');
        i.month = atoi(item.c_str());
        getline(i_stream, item, ',');
        i.day = atoi(item.c_str());

        getline(i_stream, i.name, ',');
        getline(i_stream, i.userType, ',');
        getline(i_stream, i.phone, ',');
        getline(i_stream, i.email, ',');
        getline(i_stream, i.topic, ',');
        getline(i_stream, i.detail, ',');

        inquiries.push_back(i);
    }
}

void readCustomerList(vector <Customers> &customers){
    ifstream customerList("CustomerList.csv");
    string line, item;
    struct Customers c;

    while (getline(customerList, line)) {    
        istringstream i_stream(line);

        getline(i_stream, c.name, ',');
        getline(i_stream, c.phone, ',');
        getline(i_stream, c.email, ',');
        getline(i_stream, c.street, ',');
        getline(i_stream, c.city, ',');
        getline(i_stream, c.state, ',');
        getline(i_stream, c.country, ',');
        getline(i_stream, c.postalCode, ',');
        getline(i_stream, c.password, ',');
        getline(i_stream, c.payment, ',');

        customers.push_back(c);  
    }
}

void readDriverList(vector <Drivers> &drivers){
    ifstream driverList("DriverList.csv");
    string line, item;
    struct Drivers d;

    while (getline(driverList, line)) {    
        istringstream i_stream(line);

        getline(i_stream, d.name, ',');
        getline(i_stream, d.phone, ',');
        getline(i_stream, d.email, ',');
        getline(i_stream, d.street, ',');
        getline(i_stream, d.city, ',');
        getline(i_stream, d.state, ',');
        getline(i_stream, d.country, ',');
        getline(i_stream, d.postalCode, ',');
        getline(i_stream, d.password, ',');
        getline(i_stream, d.license, ',');
        getline(i_stream, d.area, ',');

        drivers.push_back(d); 
    }
}

void readAdminList(vector <Admins> &admins){
    ifstream adminList("AdminList.csv");
    string line, item;
    struct Admins a;

    while (getline(adminList, line)) {    
        istringstream i_stream(line);

        getline(i_stream, a.name, ',');
        getline(i_stream, a.phone, ',');
        getline(i_stream, a.email, ',');
        getline(i_stream, a.street, ',');
        getline(i_stream, a.city, ',');
        getline(i_stream, a.state, ',');
        getline(i_stream, a.country, ',');
        getline(i_stream, a.postalCode, ',');
        getline(i_stream, a.password, ',');

        admins.push_back(a); 
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions (Validation)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool isPhoneValid(string& phone){
   regex pattern("(\\d+)(\\-)(\\d+)(\\-)(\\d+)");               // define a regular expression
   
   return regex_match(phone, pattern);                          // try to match the string with the regular expression
}

bool isEmailValid(string& email){
   regex pattern("(\\w+)(\\.|_)?@(\\w+)(\\.(\\w+))");       
   
   return regex_match(email, pattern);                           
}

bool isPasswordValid(string& password){
    bool digit, upperCase, lowerCase, specialCharacter, number, result; 
    int digitFlag = 0, upperFlag = 0, lowerFlag = 0, specialCharacterFlag = 0, numberFlag = 0;

    regex digitExpression( ".{8,}" );
    regex upperCaseExpression( "[A-Z]+" );
    regex lowerCaseExpression( "[a-z]+" );
    regex specialCharacterExpression( "[@!?#]+");
    regex numberExpression( "[0-9]+" );

    digit = regex_match(password, digitExpression);                         //Determine if the password is 8 characters or more
    upperCase = regex_search(password, upperCaseExpression);                //Determine if there is a part that matches the upper case
    lowerCase = regex_search(password, lowerCaseExpression);                //Determine if there is a part that matches the lower case
    specialCharacter = regex_search(password, specialCharacterExpression);  //Determine if there is a part that matches the special character
    number = regex_search(password, numberExpression);                      //Determine if there is a part that matches the number

    if (digit == false){
        cout << "  ❗️At least 8 characters\n";
        digitFlag = 1;
    }
    if (upperCase == false){
        cout << "  ❗️At least one upper case character\n";
        upperFlag = 1;
    }
    if (lowerCase == false){
        cout << "  ❗️At least one lower case character\n";
        lowerFlag = 1;
    }
    if (specialCharacter == false){
        cout << "  ❗️At least one special character (@, !, ?, #)\n";
        specialCharacterFlag = 1;
    } 
    if (number == false){
        cout << "  ❗️At least one number\n";
        numberFlag = 1;
    }

    int totalFlagNum = digitFlag + upperFlag + lowerFlag + numberFlag + specialCharacterFlag; 

    if (totalFlagNum == 0){
        result = true;
    } else {
        result = false;
    }

    return result;
}

bool isIntegerValid(string& number){
   regex pattern("[0-9]");                  //Determine if the number is integer

   return regex_match(number, pattern);                    
}