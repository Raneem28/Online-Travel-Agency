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
    cout << "            \nYour entered account information is            " << endl;
    cout << "---------------------User Information----------------------\n";
    cout << "Name: " << name << "   " << "Age: " << age << "   " << "CNIC: " << cnic << "   " << "Phone Number: " << phone_no << endl;  

    cout << "------------------------Address----------------------------\n";
    cout << "House Number: " << houseNo << "   " << "Street: " << street << "   " << "City: " << city << "   " << "Country: " << country << endl;  
}
void login(){
    cout << "\nPlease login to your account" << endl;
    cout << "Account name: ";
    cin >> account;
    cout << "password: ";
    cin >> pass;
    if (pass == password){
        cout << "Login Successful" << endl;
    }
    else{
        cout << "Login Failed." << endl;
    }
}
};
class Flight{
private:
    string destination[5] = {"Saudi Arabia", "Dubai", "Manchester", "Switzerland", "Houston"};
    string date;
    long price[5] = {150000, 100000, 175000, 150000, 200000};

public:
    void setDate(string d) {
        date = d;
    }

    void searchDestination() {
        cout << "\nAvailable flights on " << date << endl;
        for (int i = 0; i < 5; ++i) {
            cout << destination[i] << endl;
        }
    }

    string selectDestination(string dest) {
        for (int i = 0; i < 5; ++i) {
            if (dest == destination[i]) {
                cout << "\nThank you for choosing " << dest << ". Now let's proceed further."<<endl;
                return dest;
            }
        }
        cout << "\nThis flight is not available for " << date << endl;
        return "";
    }
    long getPrice(string dest) {
        for (int i = 0; i < 5; ++i) {
            if (dest == destination[i]) {
                return price[i];
            }
        }
    }
};
// to book a specific flight we are using inheritance
class Booking : public Flight{
    private:
    Flight flight;
    public:
    string choice;
    Booking() : flight(){};  //default Booking constructor
    Booking (Flight f) : flight(f){
    cout <<"\nDo you want the ticket for arrival , departure or both? "<<endl;
    cin>>choice;
    }
    void total_price(string dest){
        long flightPrice = flight.getPrice(dest);
        if(choice == "arrival"){
            cout<<"The total price is Rs. "<<flightPrice<<endl;
    }
    else if(choice == "departure"){
        cout<<"The total price is Rs. "<<flightPrice<<endl;
    }
    else if(choice == "both"){
        long price  = flightPrice*2;
        cout<<"The total price is Rs. "<<price<<endl;
    }

    }
};
class Seat: public Booking{
private:
    Booking booking;
    string departure_seats[10]= {"B30", "C67", "C45", "A1", "B19", "D189", "A19", "C90","A23", "B39"};
    string arrival_seats[7] = {"C45", "D50", "B19", "C30", "A19", "C90","A23"};
public:
    Seat(Booking B) : booking(B){}
    void available_seats()
    {
        if (booking.choice == "arrival" ){
            cout<<"\nThe seats available for arrival are: "<<endl;
            for (int i=0; i<7; i++){
                cout << arrival_seats[i] << " , ";
            }
        }
            else if(booking.choice == "departure"){
                cout << "\nThe seats available for departure are: " << endl;
                for(int i=0; i<10; i++){
                    cout << departure_seats[i] << " , ";
                }
            }
            else if(booking.choice == "both"){
                cout << "\nThe seats available for arrival and departure are: " << endl;
                cout << "For Departure: " << endl;
                for(int i=0; i<10; i++){
                    cout << departure_seats[i] << " , ";
            }
                cout << "\nFor arrival: " << endl;
                    for (int i=0; i<7; i++){
                        cout << arrival_seats[i] << " , ";
                    }
        }
            // ofstream seatsfile("Seats Availability.txt");
            // if(seatsfile.is_open()){
            //     // seatsfile << "Seat chosen for arrival: " << 
            // }

    }
 void choose_seat(string choice){
    bool seatFound = false;

    for (int i = 0; i < 7; i++) {
        if (choice == arrival_seats[i]) {
            seatFound = true;
            break;
        }
    }

    if (!seatFound) {
        for (int i = 0; i < 10; i++) {
            if (choice == departure_seats[i]) {
                seatFound = true;
                break;
            }
        }
    }

    if (seatFound) {
        char ans;
        cout << "Do you want to confirm the ticket?(y/n) " << endl;
        cin >> ans;
        if (ans == 'y' || ans == 'Y'){
        cout << "Thank you for choosing us. Have a safe journey!" << endl;
        }
        else if(ans == 'n'|| ans == 'N'){
            cout << "Your ticket has been canceled." << endl;
        }
    } else {
        cout << "Invalid seat choice. Please choose a valid seat." << endl;
    }
}
  
};

int main() {
       User u1;
   u1.registeration();
   u1.display();
   u1.login();
    Flight F;
    string inputDate, inputDest, choice;
    cout << "\nEnter the date you want to travel on: ";
    cin.ignore();
    getline(cin, inputDate);
    F.setDate(inputDate);

    F.searchDestination();

    cout << "\nEnter the destination you want to visit: ";
    getline(cin, inputDest);

    F.selectDestination(inputDest);

    cout<<"the price of your flight is Rs. "<<F.getPrice(inputDest)<<endl;

    Booking B(F);
    B.total_price(inputDest);

    Seat S(B);
    S.available_seats();

    cout << "\nEnter the seat you want to choose: " << endl;
    cin >> choice;
    S.choose_seat(choice);

    return 0;
}