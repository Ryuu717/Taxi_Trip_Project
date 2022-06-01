#include <iostream>
using namespace std;

//declare structures
struct Customer{
    string name;
    int phoneNumber;
    string email;
    string address;
    string password;
    string paymentMethod;

    //constructor
    Customer(string n="customer", int pn=123456789, string e="email@email.com", string p="password", string a="address"){
        name = n;
        phoneNumber = pn;
        email = e;
        password = p;
        address = a;
    }
};

// struct Driver{};
// struct Admin{};


//declare function prototypes
void mainMenu();
void customerMenu();
void driverMenu();
void adminMenu();
void ride();
void signup();
void login();
void guestOrder();
void myPage();




int main(){
    mainMenu();
    // customerMenu();
    // driverMenu();
    // adminMenu();
    // ride();
    // signup();
    // login();
    // guestOrder();
    // myPage();
    





    return 0;
}


//functions

void mainMenu(){
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
    // cout << "************************************************\n";
    cout << "\n\n";

}

void customerMenu(){
    cout << "************************************************\n";
    cout << "Welcome Yoobee Customers!\n";
    cout << "Please select a number from the menu\n";
    cout << "************************************************\n";
    cout << "Menu\n";
    cout << "  1.Ride\n";
    cout << "  2.My Page\n";
    cout << "  3.Contact\n";
    // cout << "************************************************\n";
    cout << "\n\n";
}

void driverMenu(){
    cout << "************************************************\n";
    cout << "Welcome Yoobee Drivers!\n";
    cout << "Please select a number from the menu\n";
    cout << "************************************************\n";
    cout << "Menu\n";
    cout << "  1.Resister\n";
    cout << "  2.My Page\n";
    cout << "  3.Contact\n";
    // cout << "************************************************\n";
    cout << "\n\n";
}

void adminMenu(){
    cout << "************************************************\n";
    cout << "Welcome Yoobee Admin!\n";
    cout << "Please select a number from the menu\n";
    cout << "************************************************\n";
    cout << "Menu\n";
    cout << "  1.Customer Info\n";
    cout << "  2.Driver Info\n";
    cout << "  3.Report\n";
    cout << "  4.Add Admin\n";
    // cout << "************************************************\n";
    cout << "\n\n";
}

void ride(){
    cout << "************************************************\n";
    cout << "Ride\n";
    cout << "************************************************\n";
    // cout << " Please enter a destination: \n";
    cout << " Enter pickup location: \n";
    cout << " Enter destination: \n";
    cout << " ------------------------------------------------\n";
    cout << " Request Now? (y/n): \n";
    // cout << " Schedule for later? (y/n) \n";
    cout << " ------------------------------------------------\n";
    cout << " Please select a service: \n";
    cout << "  1. Taxi\t\t4 people\t$10.00\t10:30AM(Pick up) \n";
    cout << "  2. Van\t\t5 people\t$15.00\t10:35AM(Pick up) \n";
    cout << "  3. Premium Van\t6 people\t$20.00\t10:40AM(Pick up) \n";
    cout << " ------------------------------------------------\n";
    cout << " Please tell us your information: \n";
    cout << "  1. Login (if you are a member)\n";
    cout << "  2. Sign up (if not a member)\n";
    cout << "  3. Guest Order (no registration)\n";
    cout << " ------------------------------------------------\n";
    cout << " Login: \n";
    cout << "  Enter your email address\n";
    cout << "  Enter your password\n";
    cout << " ------------------------------------------------\n";
    cout << " Please confirm your order \n";
    cout << "  Your Name:\tCustomer1\n";
    cout << "  Your Phone number:\t000-0000-0000\n";
    cout << "  Pickup location:\tAirport\n";
    cout << "  Destination:\t\tHotel\n";
    cout << "  Car:\t\t\tTaxi(4 people)\n";
    cout << "  Fare:\t\t\t$10.00\n";
    cout << "  Pick up time:\t\t10:30AM\n";
    cout << "  Driver Name:\t\tDriver1\n";
    cout << "  Driver Rate:\t\t★★★☆☆\n";
    cout << "  Contact:\t\t111-1111-1111\n";
    cout << "  License Plate:\t111-111\n\n";
    cout << "  Request now?(y/n): \n\n";
    cout << "  Thank you! \n";
    cout << "\n\n";
}

void signup(){
    cout << "************************************************\n";
    cout << "Sign up\n";
    cout << "************************************************\n";
    cout << "Enter your information \n";
    cout << " Name: \n";
    cout << " Phone number: \n";
    cout << " Email address: \n";
    cout << " Home address: \n";
    cout << " Password: \n";
    cout << " Password (confirm): \n";
    cout << " Payment method: \n";
    cout << "  1. Cash \n";
    cout << "  2. Credit Card \n";
    cout << "  3. Online Payment \n";
    cout << "  4. - \n";
    cout << " ------------------------------------------------\n";

    cout << "\n\n";
}

void login(){
    cout << "************************************************\n";
    cout << "Login\n";
    cout << "************************************************\n";
    cout << "Enter your information \n";
    cout << " Email address: \n";
    cout << " Password: \n";
    cout << " Password (confirm): \n";
    cout << " ------------------------------------------------\n";

    cout << "\n";
}

void guestOrder(){
    cout << "************************************************\n";
    cout << "Guest order\n";
    cout << "************************************************\n";
    cout << "Enter your information \n";
    cout << " Name: \n";
    cout << " Phone number: \n";
    cout << " Payment method: \n";
    cout << "  1. Cash \n";
    cout << "  2. Credit Card \n";
    cout << "  3. Online Payment \n";
    cout << "  4. Cryptocurrency \n";
    cout << " ------------------------------------------------\n";

    cout << "\n\n";
}

void myPage(){
    cout << "************************************************\n";
    cout << "My Page\n";
    cout << "************************************************\n";
    cout << "Please login \n";
    cout << "  1. Login (if you are a member)\n";
    cout << "  2. Sign up (if not a member)\n";
    cout << "  3. Go Back to Home\n\n";

    login();

    cout << "************************************************\n";
    cout << "Welcome back Customer1 \n";
    cout << "************************************************\n";
    cout << "Menu \n";
    cout << "  1. Account Info\n";
    cout << "  2. Trip history \n";
    cout << "  3. Coupon \n";
    cout << "  4. - \n";
    cout << " ------------------------------------------------\n";

    cout << "\n\n";
}