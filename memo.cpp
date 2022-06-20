
string strOption;

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
    intOption1 = stoi(strOption);


    //Yes or No Validation
    while(true){
        cout << " ------------------------------------------------\n";
        cout << " Request Now? (y/n): ";
        cin >> requestNow;

        if (isYesNoValid(requestNow) == true){
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        } else {
            cout << "\n  ❗️Please answer with y or n\n\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }


    //reset user input
    cin.clear();
    cin.ignore(10000, '\n');





    //confirm order
    string confirm;
    ofstream inquiryList("InquiryList.csv", ios::app);


    while(true){
        cout << " ------------------------------------------------\n";
        cout << "Confirm order (y/n): ";
        cin >> confirm;

        if (isYesNoValid(confirm) == true){
            if (confirm == "y"){
                cout << "------------------------------------------------\n";
                cout << "\n  Thank you!\n  See you later!\n";
                inquiryList << inquiries[i].year << "," << inquiries[i].month << "," << inquiries[i].day << "," << inquiries[i].name << "," << inquiries[i].userType << "," << inquiries[i].phone << "," << inquiries[i].email << "," << inquiries[i].topic << "," << inquiries[i].detail << ",\n" ;
                cin.clear();
                cin.ignore(10000, '\n');
            } else {
                cout << "\n  Your inquiry was canceled.\n";
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