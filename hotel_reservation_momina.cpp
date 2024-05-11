#include <iostream>
#include <vector>
using namespace std;

class Room {
protected:
    vector<int> room_numbers;

public:
    virtual void getRoomNumbers() = 0;
    virtual void getPrice() = 0;
       virtual int getPricePerDay() = 0; 
};
class SingleRoom : public Room {
public:
    SingleRoom() {
        room_numbers = {32, 42, 63, 108, 109, 115, 136, 145, 180, 198};
    }

   void getRoomNumbers() override {
    cout << "Following are the available single rooms:" << endl;
    for (auto it = room_numbers.begin(); it != room_numbers.end(); ++it) {
        cout << *it << endl;
    }
    cout << endl;
}


    void getPrice() override {
        cout << "The price of single room is Rs 5000/day." << endl;
    }
      int getPricePerDay() override {
        return 5000; // Return price per day for single room
    }
};

class DeluxeRoom : public Room {
public:
    DeluxeRoom() {
        room_numbers = {200, 205, 210, 225};
    }

    void getRoomNumbers() override {
        cout << "Following are the available deluxe rooms:" << endl;
        for (auto it = room_numbers.begin(); it != room_numbers.end(); ++it) {
        cout << *it << endl;
    }
        cout << endl;
    }

   void getPrice() override {
        cout << "The price of deluxe room is Rs 10000/day." << endl;
    }

    int getPricePerDay() override {
        return 10000; // Return price per day for deluxe room
    }
      
};

class SuiteRoom : public Room {
public:
    SuiteRoom() {
        room_numbers = {258, 261, 270};
    }

    void getRoomNumbers() override {
        cout << "Following are the available suite rooms:" << endl;
        for (auto it = room_numbers.begin(); it != room_numbers.end(); ++it) {
        cout << *it << endl;
    }
        cout << endl;
    }

   void getPrice() override {
        cout << "The price of suite room is Rs 17000/day." << endl;
    }

    int getPricePerDay() override {
        return 17000; // Return price per day for suite room
    }
};
int main() {
    SingleRoom singleRoom;
    DeluxeRoom deluxeRoom;
    SuiteRoom suiteRoom;

    cout << "Welcome to Hotel Reservation System!" << endl;

    // Display available rooms
    cout << "Single Room Details:" << endl;
    singleRoom.getRoomNumbers();
    singleRoom.getPrice();

    cout << "Deluxe Room Details:" << endl;
    deluxeRoom.getRoomNumbers();
    deluxeRoom.getPrice();

    cout << "Suite Room Details:" << endl;
    suiteRoom.getRoomNumbers();
    suiteRoom.getPrice();

    // Reservation
    cout << "\n\nPlease enter your room choice (Single/Deluxe/Suite) and quantity: ";
    string roomType;
    int quantity;
    cin >> roomType >> quantity;

    Room* selectedRoom = nullptr;
    int totalPrice = 0;

    // Assign selected room based on user input
    if (roomType == "Single")
        selectedRoom = &singleRoom;
    else if (roomType == "Deluxe")
        selectedRoom = &deluxeRoom;
    else if (roomType == "Suite")
        selectedRoom = &suiteRoom;

    if (selectedRoom) {
        // Check if user is a student
        cout << "Are you a student? (yes/no): ";
        string studentResponse;
        cin >> studentResponse;

        if (studentResponse == "yes") {
            // Ask for university email address
            string email;
            cout << "Please enter your university email address: "<<endl;
            cin >> email;

            // Apply 50% discount for students
            totalPrice = (selectedRoom->getPricePerDay() * quantity) / 2;
        } else {
            totalPrice = selectedRoom->getPricePerDay() * quantity;
        }

        // Display reservation details
        cout << "\n\nReservation Details:" << endl;
        cout << "Room Type: " << roomType << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Price: Rs " << totalPrice << endl;
    } else {
        cout << "Invalid room type!" << endl;
    }

    return 0;
}