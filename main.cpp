#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<windows.h>

using namespace std;

struct Customer {
    string name, address, phone, cnic, id, password;
};

struct Admin{
	string adm_id, adm_password;
};

struct Car{
	string regNum, companyName, model;
	double rent_12_hr, rent_24_hr; 
};

string currentUser;

void setUser(string& username) {
    currentUser = username;
}



void logo();
int menu();
void customer_login();
int customer_menu();
void admin_login();
int admin_menu();
void change_adam_pass();
void show_all_users();
void change_user_pass();
void add_user();
void rem_user();
void add_car();
void rem_car();
void show_all_cars();
void available_cars();
void rented_cars();
void rent_car();
void invoice(string& duration, string& currentUser, double& rent);
void return_car();
void report_menu();
void gen_report(string& username, bool isAdmin);




int main() {
    int choice;
    bool loggedIn = false;

    do {
        choice = menu();

        switch (choice) {
            case 1:
                customer_login();
                loggedIn = true;
                while (loggedIn) {
                    int c = customer_menu();
                    switch (c) {
                        case 1:
                            rent_car();
                            break;
                        case 2:
                            return_car();
                            break;
                        case 3:
                            report_menu();
                            break;
                        case 4:
                            loggedIn = false; // Logout
                            break;
                        default:
                            cout << "Invalid input. Enter again:";
                            system("pause");
                            break;
                    }
                }
                break;
            case 2:
                admin_login();
                loggedIn = true;
                while (loggedIn) {
                    int a = admin_menu();
                    switch (a) {
                        case 1:
                            change_adam_pass();
                            break;
                        case 2:
                            show_all_users();
                            break;
                        case 3:
                            change_user_pass();
                            break;
                        case 4:
                            add_user();
                            break;
                        case 5:
                            rem_user();
                            break;
                        case 6:
                            show_all_cars();
                            system("pause");
                            break;
                        case 7:
                            available_cars();
                            system("pause");
                            break;
                        case 8:
                            rented_cars();
                            system("pause");
                            break;
                        case 9:
                            add_car();
                            break;
                        case 10:
                            rem_car();
                            break;
                        case 11:
                            report_menu();
                            break;
                        case 12:
                            loggedIn = false; // Logout
                            break;
                        default:
                            cout << "Invalid input. Enter again:";
                            system("pause");
                            break;
                    }
                }
                break;
            case 3:
                return 0;
            default:
                cout << "\nInvalid choice." << endl;
                system("pause");
        }
    } while (true);

    return 0;
}





void logo() {
    system("cls");
    cout << "\n\t\t\t\t*****************************************" << endl;
    cout << "\t\t\t\t*        WELCOME TO CAR RENTAL          *" << endl;
    cout << "\t\t\t\t*          MANAGEMENT SYSTEM            *" << endl;
    cout << "\t\t\t\t*****************************************" << endl;
    cout << "\t\t\t\t*      Explore. Rent. Drive. Repeat.    *" << endl;
    cout << "\t\t\t\t*****************************************" << endl;
}


int menu() {
    logo();

    cout << "\n\n\tSelect one option below: " << endl;
    cout << "\t1. Customer Login " << endl;
    cout << "\t2. Admin Login " << endl;
    cout << "\t3. Exit " << endl;

    int choice;
    cout << "\n Enter your choice: ";
    cin >> choice;

    return choice;
}

void customer_login() {
    logo();

    Customer cust;

    cout << "\n\n\tEnter your username: ";
	cin >> cust.id;

    cout << "\n\tEnter your password: ";
	cin >> cust.password;


    ifstream userfile("customer_user.txt");

    if (userfile.is_open()) {
        bool loginSuccess = false;
        string storedId, storedPassword;

        while (userfile >> storedId >> storedPassword) {
            if (cust.id == storedId && cust.password == storedPassword) {
                loginSuccess = true;
                break;
            }
        }

        if (loginSuccess) {
            cout << "\n\tLogin successful" << endl;
            
        } else {
            cout << "\n\tInvalid username or password" << endl;
            system("pause");
            customer_login();
        }

        userfile.close();
    } else {
        cout << "Error opening file." << endl;
        system("pause");
    }
	
	setUser(cust.id);
}

void admin_login() {
    logo();

    Admin adam;

    cout << "\n\n\tEnter your username: "; 
	cin >> adam.adm_id;

    cout << "\n\tEnter your password: ";
	cin >> adam.adm_password;


    ifstream adminfile("admin_user.txt");

    if (adminfile.is_open()) {
        bool loginSuccess = false;
        string storedId, storedPassword;

        while (adminfile >> storedId >> storedPassword) {
            if (adam.adm_id == storedId && adam.adm_password == storedPassword) {
                loginSuccess = true;
                break;
            }
        }

        if (loginSuccess) {
            cout << "\n\tLogin successful" << endl;
        } else {
            cout << "\n\tInvalid username or password" << endl;
        }

        adminfile.close();
    } else {
        cout << "Error opening file." << endl;
        system("pause");
    }
    
    setUser(adam.adm_id);
}

int customer_menu(){
	logo();
	cout<<"\n\n\t\tAvailable Services:"<<endl;
	cout<<"\n\t1. Rent a Car."<<endl;
	cout<<"\t2. Return a Car."<<endl;
	cout<<"\t3. Generate Rental Report."<<endl;
	cout<<"\t4. Log out."<<endl;
	
	int option;
	cout<<"\nWhat service do you want: ";
	cin>>option;
	
	return option;
}

int admin_menu() {
	logo();
    int choice;

    cout << "\n\n\t\tAdmin Portal" << endl;
    cout << "\n\t1. Change Admin Pass"<< endl;
    cout << "\t2. Show all Users"<< endl;
    cout << "\t3. Change User Pass"<< endl;
    cout << "\t4. Add New User" << endl;
    cout << "\t5. Remove User" << endl;
    cout << "\t6. Show all Cars" << endl;
    cout << "\t7. Show available Cars" << endl;
    cout << "\t8. Show rented Cars" << endl;
    cout << "\t9. Add New Car"<< endl;
    cout << "\t10. Remove Car"<< endl;
    cout << "\t11. Generate Report" << endl;
    cout << "\t12. Logout" << endl;
    
	cout << "\n\tEnter your choice: ";
	cin >> choice;
        
	return choice;
}

void add_user() {
	logo();
    Customer newCust;

    // Input Customer information
    bool validUsername;
    do {
        validUsername = true;
        cout << "\n\nEnter a username (only lowercase letters, no spaces): ";
        cin >> newCust.id;

        // Check for valid username
        for (size_t i = 0; i < newCust.id.length(); i++) {
            char c = newCust.id[i];
            if (!islower(c)) {
                validUsername = false;
                break;
            }
        }
        if (!validUsername) {
            cout << "Invalid username format. Enter Again: \n";
            system("pause");
        }
    } while (!validUsername);

    // Check for existing username
    bool usernameExists;
    do {
        usernameExists = false;
        ifstream userFile("customer_user.txt");
        string storedUsername, storedPassword;

        while (userFile >> storedUsername >> storedPassword) {
            if (storedUsername == newCust.id) {
                usernameExists = true;
                break;
            }
        }

        userFile.close();

        if (usernameExists) {
            cout << "Username already exists. Try another username: \n";
            system("pause");
        }
    } while (usernameExists);

    // Input Password
    cout << "Enter a password (up to 8 characters, no spaces): ";
    cin >> newCust.password;

    if (newCust.password.length() > 8) {
        cout << "Invalid password format. Enter again: \n";
        system("pause");
    }

    cin.ignore();
	
	if (!usernameExists) {
          
        cout << "\nEnter customer's name: ";
        getline(cin, newCust.name);
        cout << "Enter customer's CNIC: ";
        cin >> newCust.cnic;
        cout << "Enter customer's address: ";
        cin.ignore();
        getline(cin, newCust.address);
        cout << "Enter customer's phone number: ";
        cin >> newCust.phone;
        
        // Append the new user to the file
        ofstream outFile("customer_user.txt", ios::app);
        outFile << newCust.id << ' ' << newCust.password << '\n';
        outFile.close();

        // Append the additional details to the customer_details.txt file
        ofstream detailsFile("customer_details.txt", ios::app);
        detailsFile << newCust.id << ';' << newCust.name << ';' << newCust.cnic << ';' << newCust.address << ';' << newCust.phone << '\n';
        detailsFile.close();

        cout << "User and details added successfully.\n";
        system("pause");
    }
}

void rem_user() {
    logo();
    Customer remCust;

    // Input username
    cout << "\n\nEnter the username to remove: ";
    cin >> remCust.id;


    ifstream inFile("customer_user.txt");

    if (inFile.is_open())
	{
    ofstream outFile("temp.txt");
	string storedUsername, storedPassword;
    
    while (inFile >> storedUsername >> storedPassword) {
        if (storedUsername != remCust.id) {
            outFile << storedUsername << ' ' << storedPassword << '\n';
        }
    }

    inFile.close();
    outFile.close();

    
    remove("customer_user.txt");
    rename("temp.txt", "customer_user.txt");

    cout << "User removed successfully.\n";
    system("pause");
}
else{
	cout << "Error opening file." << endl;
    system("pause");
    return;
	}

}

void show_all_users(){
	logo();

    ifstream userFile("customer_user.txt");
    ifstream detailsFile("customer_details.txt");

    if (!userFile.is_open() || !detailsFile.is_open()) {
        cout << "Error opening file." << endl;
        system("pause");
        return;
    }

    cout << "\n\t\tAll Users:" << endl << endl;
    cout << left << setfill('-') << setw(98) << "-" << setfill(' ') << endl;
    cout << left << setw(15) << "|  Username" << setw(20) << " |  Name" << setw(15) << " |  CNIC" << setw(30) << " |  Address" << setw(15) << " |  Phone Number" << " |" << endl;
    cout << left << setfill('-') << setw(98) << "-" << setfill(' ') << endl;
    string storedUsername, storedPassword;

    while (userFile >> storedUsername >> storedPassword) {
        Customer customer;

        // Read customer details
        string customerDetails;
        getline(detailsFile, customerDetails);

        istringstream iss(customerDetails);
        getline(iss, customer.id, ';');
        getline(iss, customer.name, ';');
        getline(iss, customer.cnic, ';');
        getline(iss, customer.address, ';');
        getline(iss, customer.phone, ';');

        // Display the information in a table
        cout << left << setw(15) <<  "| "  + storedUsername << setw(20) <<  " | "  +  customer.name << setw(15) <<  " | "  +  customer.cnic << setw(30) <<  " | "  +  customer.address << setw(15) <<  " | "  +  customer.phone << "  |" << endl;
        
    }
	cout << left << setfill('-') << setw(98) << "-" << setfill(' ') << endl;
	
    userFile.close();
    detailsFile.close();
    system("pause");
}

void change_adam_pass(){
	logo();
	
	Admin modifyAdmin;
	
O:	cout<<"\nEnter old password: ";
	cin>>modifyAdmin.adm_password;
	
	ifstream inFile("admin_user.txt",ios::in);
	string storedId, storedPass, newPass;
	if(inFile.is_open())
	{
		while(inFile >> storedId >> storedPass)
		{
			if(storedPass == modifyAdmin.adm_password){
				bool validPass;
				do{
					validPass = true;
					cout<<"\nEnter new password (up to 8 characters, no spaces): ";
					cin >> newPass;
					inFile.close();
					if(newPass.length() > 8){
						cout<<"\nInvalid Password. Enter again: ";
						system("pause");
						validPass = false;
					}
					else{
						ofstream outFile("admin_user.txt",ios::out);
						outFile << storedId << ' ' << newPass;
						cout<<"\nPassword Changed Successfully.";
						system("pause");
						outFile.close();
					}
				}while(validPass==false);		
			}
			else{
				cout<<"Wrong Password! Try Again. ";
				system("pause");
				goto O;
			}
		}
	}
	else{
		cout<<"\nError opening file!";
		system("pause");
		return;
	}
	
}

void change_user_pass(){
	logo();
	
	Customer modifyCust;

    // Input username
    bool userExist;
    do {
        userExist = false; 
        cout << "\n\nEnter the username: ";
        cin >> modifyCust.id;

        ifstream inFile("customer_user.txt");

        if (inFile.is_open()) {
            string storedUsername, storedPassword;
            while (inFile >> storedUsername >> storedPassword) {
                if (storedUsername == modifyCust.id) {
                    userExist = true;
                    break;
                }
            }
            inFile.close();
            if (!userExist) {
                cout << "\nUser does not exist." << endl;
                system("pause");
            }
        } else {
            cout << "\nError opening file!" << endl;
            system("pause");
            return;
        }
    } while (!userExist);

    // Input new password
    bool validPass;
    do {
        validPass = true; 
        cout << "\nEnter new password (up to 8 characters, no spaces): ";
        cin >> modifyCust.password;

        if (modifyCust.password.length() > 8) {
            cout << "\nInvalid password. Enter again.\n";
            system("pause");
            validPass = false;
        }
    } while (!validPass);

    // Modify the password in the file
    ifstream inFile("customer_user.txt");
    if (inFile.is_open()) {
        ofstream outFile("temp.txt");

        string storedUser, storedPass;
        while (inFile >> storedUser >> storedPass) {
            if (storedUser != modifyCust.id) {
                outFile << storedUser << ' ' << storedPass << '\n';
            } else {
                outFile << modifyCust.id << ' ' << modifyCust.password << '\n';
            }
        }

        inFile.close();
        outFile.close();

        remove("customer_user.txt");
        rename("temp.txt", "customer_user.txt");

        cout << "User password modified successfully.\n";
        system("pause");
    } else {
        cout << "Error opening file." << endl;
        system("pause");
        return;
    }
}

void add_car(){
	
	Car* newCar = new Car;
	
	char addCar;
	cin.ignore();
	do{
		logo();
		addCar = 'y';
		cout << "\n\n\tEnter Company name: ";
        getline(cin, newCar->companyName);

        cout << "\n\tEnter model of car: ";
        getline(cin, newCar->model);

        cout << "\n\tEnter registration number of car: ";
        getline(cin, newCar->regNum);

        cout << "\n\tEnter rent of car (per 12 hr): ";
        cin >> newCar->rent_12_hr;

        cout << "\n\tEnter rent of car (per 24 hr): ";
        cin >> newCar->rent_24_hr;
		
		ofstream outFile("cars.txt", ios::app);
		if(outFile.is_open()){
			outFile << newCar->companyName <<';'<< newCar->model <<';'<< newCar->regNum <<';'<< newCar->rent_12_hr <<';'<< newCar->rent_24_hr <<'\n';  
			cout<<"\n\n\tCar Added Successfully to Database."<<endl;
			cout<<"\tDo you want to add more cars? (y/n): ";
			cin >> addCar;
			cin.ignore();
		}
		else{
			cout<<"Error opening file!"<<endl;
			system("pause");
			return;
		}
		
	}while((addCar =='y') || (addCar == 'Y'));
	
	delete newCar;	
}

void rem_car(){
	show_all_cars();
    Car* remCar = new Car;

    // Input registration number
    cout << "\n\nEnter the Car Registration No. to remove: ";
    cin >> remCar->regNum;

    ifstream inFile("cars.txt");

    if (inFile.is_open()) {
        ofstream outFile("temp.txt");

        string line;
        while (getline(inFile, line)) {
            istringstream iss(line);
            string company, model, regNo;
            double rent_12_hr, rent_24_hr;

            // Read data from the line
            getline(iss, company, ';');
            getline(iss, model, ';');
            getline(iss, regNo, ';');
            iss >> rent_12_hr;
            iss.ignore();
            iss >> rent_24_hr;

            if (regNo != remCar->regNum) {
                outFile << company << ';' << model << ';' << regNo << ';' << rent_12_hr << ';' << rent_24_hr << '\n';
            }
        }

        inFile.close();
        outFile.close();

        remove("cars.txt");
        rename("temp.txt", "cars.txt");

        cout << "\n\nCar Removed Successfully from Database."<<endl;
        system("pause");

    } else {
        cout << "Error opening file." << endl;
        system("pause");
        return;
    }

    delete remCar;
}

void show_all_cars(){
	logo();
	ifstream inFile("cars.txt");

    if (!inFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
	
	cout<<endl<<endl;
	cout << string(109, '-') << endl;
    
    cout << left << setw(10) << "| Sr. no#" << setw(20) << "| Company" << setw(20) << "| Model" 
         << setw(20) << "| Reg. no#" << setw(20) << "| Rent/12 hr (Rs)"
         << setw(20) << "| Rent/24 hr (Rs)" << "|" << endl;

    cout << string(109, '-') << endl; 

    string line;
    int serialNo = 1;
	
	Car* car = new Car;
	
    while (getline(inFile, line)) {
        istringstream iss(line);
       

        getline(iss, car->companyName, ';');
        getline(iss, car->model, ';');
        getline(iss, car->regNum, ';');
        iss >> car->rent_12_hr;
        iss.ignore();
        iss >> car->rent_24_hr;

        stringstream rent_12_hr_str, rent_24_hr_str;
        rent_12_hr_str << car->rent_12_hr;
        rent_24_hr_str << car->rent_24_hr;
        
        stringstream serialNoStr;
        serialNoStr << serialNo++;
        
        cout << left << setw(10) << "| " + serialNoStr.str() << setw(20) << "| " + car->companyName   << setw(20) << "| " + car->model
             << setw(20) << "| " + car->regNum << setw(20) << "| " + rent_12_hr_str.str() << setw(20) << "| " + rent_24_hr_str.str() << "|" << endl;
    
    	
	}
	cout << string(109, '-') << endl;
	
    inFile.close();
    delete car;
}

void available_cars(){
	logo();
	ifstream inFile("available_cars.txt");

    if (!inFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
	
	cout<<endl<<endl;
	cout << string(109, '-') << endl;
    
    cout << left << setw(10) << "| Sr. no#" << setw(20) << "| Company" << setw(20) << "| Model" 
         << setw(20) << "| Reg. no#" << setw(20) << "| Rent/12 hr (Rs)"
         << setw(20) << "| Rent/24 hr (Rs)" << "|" << endl;

    cout << string(109, '-') << endl; 

    string line;
    int serialNo = 1;
	
	Car* car = new Car;
	
    while (getline(inFile, line)) {
        istringstream iss(line);
       

        getline(iss, car->companyName, ';');
        getline(iss, car->model, ';');
        getline(iss, car->regNum, ';');
        iss >> car->rent_12_hr;
        iss.ignore();
        iss >> car->rent_24_hr;

        stringstream rent_12_hr_str, rent_24_hr_str;
        rent_12_hr_str << car->rent_12_hr;
        rent_24_hr_str << car->rent_24_hr;
        
        stringstream serialNoStr;
        serialNoStr << serialNo++;
        
        cout << left << setw(10) << "| " + serialNoStr.str()<< setw(20) << "| " + car->companyName  << setw(20) << "| " + car->model 
             << setw(20) << "| " + car->regNum << setw(20) << "| " + rent_12_hr_str.str() << setw(20) << "| " + rent_24_hr_str.str() << "|" << endl;
    
    	
	}
	cout << string(109, '-') << endl;
	
    inFile.close();
    delete car;
}

void rented_cars() {
    logo();
    ifstream inFile("rented_cars.txt");

    if (!inFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    cout << "\n\t Rented Cars";
    cout << endl << endl;

    cout << string(89, '-') << endl;
    cout << left << setw(10) << "| Sr. no#" << setw(20) << "| User" << setw(20) << "| Company"
         << setw(20) << "| Model" << setw(20) << "| Reg. no#" << "|" << endl;
    cout << string(89, '-') << endl;

    string line;
    int serialNo = 1;

    while (getline(inFile, line)) {
        istringstream iss(line);
        string username, company, model, regNo;

        getline(iss, username, ';');
        getline(iss, company, ';');
        getline(iss, model, ';');
        getline(iss, regNo, ';');

        stringstream serialNoStr;
        serialNoStr << serialNo++;
        
		if(currentUser=="admin"){	
        	cout << left << setw(10) << "| " + serialNoStr.str() << setw(20) << "| " + username 
			 	<< setw(20) << "| " + company << setw(20) << "| " + model << setw(20) << "| " + regNo << "|" << endl;
		}
		else if(username==currentUser){
			cout << left << setw(10) << "| " + serialNoStr.str() << setw(20) << "| " + username 
			 	<< setw(20) << "| " + company << setw(20) << "| " + model << setw(20) << "| " + regNo << "|" << endl;
		}
    }
    cout << string(89, '-') << endl;

    inFile.close();
}

void rent_car() {
    available_cars();

    Car* shiftCar = new Car;
    string regNo;
    int choice;
    bool inValid;
    
    string rentDuration;
    double rent;

    cout << "\n\n\t1. Rent a Car" << endl;
    cout << "\t2. Back" << endl;

    do {
        inValid = false;
        cout << "\nEnter option: ";
        cin >> choice;
        if (choice == 1) {
            system("cls");
            available_cars();

            bool invalidReg;

            do {
                invalidReg = false;

                cout << "\n\n\tEnter Reg. no# of car: ";
                cin >> regNo;

                ifstream availFile("available_cars.txt");
                ofstream rentFile("rented_cars.txt", ios::app);

                if (!availFile.is_open() || !rentFile.is_open()) {
                    cout << "\nError opening file." << endl;
                    system("pause");
                    return;
                }

                string line;
                ofstream tempFile("temp.txt");
                while (getline(availFile, line)) {
                    istringstream iss(line);

                    // Read data from the line
                    getline(iss, shiftCar->companyName, ';');
                    getline(iss, shiftCar->model, ';');
                    getline(iss, shiftCar->regNum, ';');
                    iss >> shiftCar->rent_12_hr;
                    iss.ignore();
                    iss >> shiftCar->rent_24_hr;

                    if (regNo == shiftCar->regNum) {
                        cout << "\n\n\tSelect Rental Duration:" << endl;
                        cout << "\t1. 12 hours" << endl;
                        cout << "\t2. 24 hours" << endl;
                        
                        int durationChoice;
                        cout << "\nEnter option: ";
                        cin >> durationChoice;

                        
                        if (durationChoice == 1) {
                            rentDuration = "12 hours";
							rent = shiftCar->rent_12_hr;
                        } else if (durationChoice == 2) {
                            rentDuration = "24 hours";
							rent = shiftCar->rent_12_hr;
                        } else {
                            cout << "\n\tInvalid Input!" << endl;
                            invalidReg = true;
                            continue;
                        }

                        rentFile << currentUser << ';' << shiftCar->companyName << ';' << shiftCar->model << ';' << shiftCar->regNum << '\n';
                        invalidReg = true;
                    } else {
                        tempFile << shiftCar->companyName << ';' << shiftCar->model << ';' << shiftCar->regNum << ';' << shiftCar->rent_12_hr << ';' << shiftCar->rent_24_hr << '\n';
                    }
                }
                rentFile.close();
                availFile.close();
                tempFile.close();

                remove("available_cars.txt");
                rename("temp.txt", "available_cars.txt");
                
                invoice(rentDuration, currentUser, rent);

                if (invalidReg == false) {
                    cout << "Please enter correct Reg. no# ...." << endl;
                }

            } while (invalidReg == false);
        } else if (choice == 2) {
            return;
        } else {
            cout << "\n\tInvalid Input!" << endl;
            inValid = true;
        }
    } while (inValid == true);

	
    cout << "\n\nCar Rented Successfully!" << endl;
    system("pause");

    delete shiftCar;
}

void return_car() {
	
    rented_cars(); 
    int choice;
    bool check;
	
	cout<<"\n\t1. Return Car"<<endl;
	cout<<"\t2. Back"<<endl;

	do{
		check=false;
		cout<<"\nChoose option: ";
		cin >> choice;
	if(choice==1){
		system("cls");
		rented_cars();
		
    	string regNumToReturn;
    	cout << "\nEnter the Reg. no# of the car: ";
    	cin >> regNumToReturn;

    	ifstream rentedFile("rented_cars.txt");
    	ofstream tempFile("temp.txt");
    	ofstream availableFile("available_cars.txt", ios::app);

    	if (!rentedFile.is_open() || !tempFile.is_open() || !availableFile.is_open()) {
        	cout << "Error opening files." << endl;
        	return;
    	}

    	string line;
    	bool carFound = false;

    	while (getline(rentedFile, line)) {
        	istringstream iss(line);
        	string regNum, username, rentalDuration, model, company;
        	double rent;

        	getline(iss, username, ';');
        	getline(iss, company, ';');
        	getline(iss, model, ';');
        	getline(iss, regNum, ';');

        	if (regNum == regNumToReturn && currentUser == username) {
            	carFound = true;
            	cout << "Car returned successfully." << endl;

            	// Get car data from "cars.txt" and add it back to "available_cars.txt"
            	ifstream carsFile("cars.txt");

            	if (carsFile.is_open()) {
                	while (getline(carsFile, line)) {
                    	istringstream carIss(line);
                    	string company, model, carRegNum;
                    	double rent_12_hr, rent_24_hr;

                    	getline(carIss, company, ';');
                    	getline(carIss, model, ';');
                    	getline(carIss, carRegNum, ';');
                    	carIss >> rent_12_hr;
						carIss.ignore();
						carIss >> rent_24_hr;

                    	if (carRegNum == regNumToReturn) {
                       	 	availableFile << company << ';' << model << ';' << regNumToReturn << ';'
                                       	  << rent_12_hr << ';' << rent_24_hr << '\n';

                        	break; // No need to continue searching after finding the car
                    	}
                	}
                	carsFile.close();
            	} else {
                	cout << "Error opening cars file." << endl;
            	}
        	} else {
            	tempFile << username << ';' << company << ';' << model << ';' << regNum << ';' << rentalDuration << '\n';
        	}
    	}
    	
    	if (!carFound) {
        cout << "Car with registration number " << regNumToReturn << " was not rented "
             << "or the username does not match the current user." << endl;
    	}
    	rentedFile.close();
    	tempFile.close();
    	availableFile.close();
    
   	 	remove("rented_cars.txt");
    	rename("temp.txt", "rented_cars.txt");
	}
	else if(choice==2){
		return;
	}
	else{
		cout<<"\n\tInvalid option!"<<endl;
		check = true;
	}
    
    
}while(check==true);


    system("pause");
}

void invoice(string& duration, string& currentUser, double& rent){
	system("cls");
	logo();
    // Fetch customer details
    ifstream detailsFile("customer_details.txt");
    if (!detailsFile.is_open()) {
        cout << "Error opening customer_details.txt." << endl;
        return;
    }

    string line;
    string name, address, phone, cnic;

    while (getline(detailsFile, line)) {
        istringstream iss(line);
        string username;
        getline(iss, username, ';');

        if (username == currentUser) {
            getline(iss, name, ';');
            getline(iss, cnic, ';');
            getline(iss, address, ';');
            getline(iss, phone, ';');
            break;
        }
    }

    detailsFile.close();

    // Fetch car details
    ifstream rentedFile("rented_cars.txt");
    if (!rentedFile.is_open()) {
        cout << "Error opening rented_cars.txt." << endl;
        return;
    }

    string company, model, regNo;
    while (getline(rentedFile, line)) {
        istringstream iss(line);
        string username;
        getline(iss, username, ';');

        if (username == currentUser) {
            getline(iss, company, ';');
            getline(iss, model, ';');
            getline(iss, regNo, ';');
            break;
        }
    }

    rentedFile.close();

    // Display the invoice
    cout << "\n\t\t\t\tInvoice" << endl;
    cout << "\t\t" << string(40, '-') << endl;

    cout << "\t\t" << left << setw(20) << "Customer Name: " << name << endl;
    cout << "\t\t" << left << setw(20) << "CNIC: " << cnic << endl;
    cout << "\t\t" << left << setw(20) << "Address: " << address << endl;
    cout << "\t\t" << left << setw(20) << "Phone: " << phone << endl;
    cout << "\t\t" << string(40, '-') << endl;
    cout << "\t\t" << left << setw(20) << "Car Company: " << company << endl;
    cout << "\t\t" << left << setw(20) << "Car Model: " << model << endl;
    cout << "\t\t" << left << setw(20) << "Reg. No#: " << regNo << endl;
    cout << "\t\t" << string(40, '-') << endl;
    cout << "\t\t" << left << setw(20) << "Rental Duration: " << duration << endl;
    cout << "\t\t" << left << setw(20) << "Total Rent (Rs.): " << rent << endl;
	cout << "\t\t" << string(40, '-') << endl;
	
    // Store the invoice
    ofstream invoiceFile("invoices.txt", ios::app);
    if (!invoiceFile.is_open()) {
        cout << "Error opening invoices.txt for writing." << endl;
        return;
    }

    // Write the invoice details to the file
    invoiceFile << currentUser <<endl;
    invoiceFile << name << endl;
    invoiceFile << cnic << endl;
    invoiceFile << address << endl;
    invoiceFile << phone << endl;
    invoiceFile << company << endl;
    invoiceFile << model << endl;
    invoiceFile << regNo << endl;
    invoiceFile << duration << endl;
    invoiceFile << rent << endl;
    invoiceFile << string(50, '-') << endl;

    invoiceFile.close();
}

void report_menu(){
	logo();
	cout<<"\n\tReport Generater"<<endl;
	bool isAdmin;
	if (currentUser=="admin") {
		isAdmin = true;
        string username;
        cout << "\n\n\tEnter the username for the report: ";
        cin >> username;
        gen_report(username, isAdmin);
    } else {
    	isAdmin = false;
        gen_report(currentUser, isAdmin);
    }
	
}

void gen_report(string& username, bool isAdmin) {
    
	system("cls");
    logo();
    
	ifstream invoicesFile("invoices.txt");

    if (!invoicesFile.is_open()) {
        cout << "Error opening invoices.txt!" << endl;
        return;
    }

    cout << "\n\t\tReport" << endl<<endl<<endl;

    string line;
    bool foundUser = false;
    bool anyUserFound = false;

    while (getline(invoicesFile, line)) {
        if (line == "--------------------------------------------------") {
            // Check for username
            if (foundUser) {
                cout << endl;
                cout << string(40, '-') << endl;
            }
            foundUser = false;
        } else {
            // Check if the current line contains the username
            if (line.find(username) != string::npos) {
                foundUser = true;
                anyUserFound = true;
            }
            else if(anyUserFound==true){
            	cout << line << endl;
			}
        }
    }

    if (anyUserFound == false) {
        cout << "\n\tUser not found in the report." << endl;
        system("pause");
        return;
    }
	
    invoicesFile.close();
    system("pause");
}




