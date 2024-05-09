#include<iostream>
#include<fstream>
using namespace std;
class User{
    public:
    long cnic, phone_no;
    string name, city, country, password, pass,account;
    int age,street,houseNo;

void registeration(){
    cout << "Welcome to our Flight Agency." << endl;
    cout << "Please Register your Account:\n";
    cout << "Account name: ";
    cin.ignore();
    getline(cin, account);
    cout << "Password: ";
    cin >> password;

    cout << "Confirm Password: ";
    cin >> pass;

    while (pass != password){
    cout << "Password did not match, please re-enter." << endl;
    cout << "Passowrd: ";
    cin >> pass; 
    }
    cout << "Password Matched" << endl;
    cout << "Please enter your personal information: " << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Age: ";
    cin >> age;
    cout << "CNIC: ";
    cin >> cnic;
    cout << "Phone number: ";
    cin >> phone_no;
    cout << "Please enter your address: " << endl;
    cout << "house no: ";
    cin >> houseNo;
    cout << "Street: " ;
    cin >> street ;
    cout<< "City: " ;
    cin >> city;
    cout << "Country: "; 
    cin >> country;

    ofstream myfile("User Registeration.txt");
    if(myfile.is_open()){
        myfile << "Account name: " << account << "Password: " << password << endl;
        myfile << "User name: " << name << endl;
        myfile << "Age: " << age << endl;
        myfile << "CNIC: " << cnic << endl;
        myfile << "Address: " << houseNo << "," << street << "," << city << "," << country << endl;  
        myfile.close();
    }
    else{
        cout << "Cannot open file" << endl;
    }
  }

void display(){
    char ans;
    cout << "            Your entered account information is            " << endl;
    cout << "---------------------User Information----------------------\n";
    cout << "Name: " << name << "   " << "Age: " << age << "   " << "CNIC: " << cnic << "   " << "Phone Number: " << phone_no << endl;  

    cout << "------------------------Address----------------------------\n";
    cout << "House Number: " << houseNo << "   " << "Street: " << street << "   " << "City: " << city << "   " << "Country: " << country << endl;  
}
void login(){
    cout << "Please enter your account number: ";
    cin >> account;
    cout << "Please enter your password: ";
    cin >> password;

}
};
int main(){
   User u1;
   u1.registeration();
   u1.display();
}