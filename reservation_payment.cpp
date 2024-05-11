#include<iostream>
using namespace std;

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
        cout << "Available flights on " << date << endl;
        for (int i = 0; i < 5; ++i) {
            cout << destination[i] << endl;
        }
    }

    string selectDestination(string dest) {
        for (int i = 0; i < 5; ++i) {
            if (dest == destination[i]) {
                cout << "Thank you for choosing " << dest << ". Now let's proceed further."<<endl;
                return dest;
            }
            }
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
    Booking (Flight f) : flight(f){
    cout <<"Do you want the ticket for arriving , departure or both? "<<endl;
    cin>>choice;
    }
    void total_price(string dest){
        long flightPrice = flight.getPrice(dest);
        if(choice == "arriving"){
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
class Reservation {
private:
    Flight flight;
    Booking booking;

public:
    Reservation(Flight f, Booking b) : flight(f), booking(b) {
        string choice;
        cout << "Do you want to confirm your flight reservation (yes/no)? ";
        cin >> choice;
        if (choice == "yes") {
            cout << "Your booking has been confirmed. Thankyou for choosing us!" << endl;
        } else if (choice == "no") {
            cout << "Your booking has been cancelled. We hope to see you next time." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    }
};



int main() {
    Flight F;
    string inputDate, inputDest;
    char ch;
    cout << "Enter the date you want to travel on: ";
    getline (cin, inputDate);
    F.setDate(inputDate);

    F.searchDestination();

    cout << "Enter the destination you want to visit: ";
    getline(cin, inputDest);

    F.selectDestination(inputDest);

    cout<<"the price of your flight is Rs. "<<F.getPrice(inputDest)<<endl;
    Booking B(F);
    B.total_price(inputDest);

    cout<<"confirm your payment. Press 1 to confirm your payment and 2 to cancel: "<<endl;
    cin>>ch;
    if (ch == '1'){
        cout<<"your payment has been confirmed! "<<endl;
        Reservation R(F , B);
    }
    else if (ch == '2'){
        cout<<"your payment has been cancelled! "<<endl;
    }

    // Reservation R(F , B);

    return 0;
}
