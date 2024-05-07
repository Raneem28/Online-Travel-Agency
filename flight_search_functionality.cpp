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
        cout << "This flight is not available for " << date << endl;
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

int main() {
    Flight F;
    string inputDate, inputDest;
    cout << "Enter the date you want to travel on: ";
    getline(cin, inputDate);
    F.setDate(inputDate);

    F.searchDestination();

    cout << "Enter the destination you want to visit: ";
    getline(cin, inputDest);

    F.selectDestination(inputDest);

    cout<<"the price of your flight is Rs. "<<F.getPrice(inputDest)<<endl;

    Booking B(F);
    B.total_price(inputDest);

    return 0;
}
