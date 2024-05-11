// #include<iostream>
// using namespace std;
// class Room{
//     int room_number[10];
//     string type[3];
//     int price;
//     public:
//     int getroom_type(){
//         cout<<"Following are the types of rooms available in our hotel: "<<endl;
//         string type[] = {"single" , "deluxe" , "suite"};
//         for (int i=0 ; i<3 ; i++){
//             cout<<type[i]<<endl;
//         }
//         cout<<endl;
//     }
//     int get_room_number_single(){
//         cout<<"Following are the availaible single rooms : "<<endl;
//         int room_number[] = {32 ,42 , 63 , 108 , 109 , 115 , 136 , 145 , 180 , 198} ;
//         for (int i=0;i<10;i++){
//             cout<<room_number[i]<<endl;
//         }
//         cout<<endl;
//         }
//     int get_room_number_deluxe(){
//         cout<<"Following are the availaible deluxe rooms : "<<endl;
//         int room_number[] = {200 , 205 , 210 , 225} ;
//         for (int i=0;i<4;i++){
//             cout<<room_number[i]<<endl;
//         }
//         cout<<endl;
//         } 
//     int get_room_number_suite(){
//         cout<<"Following are the availaible suite rooms : "<<endl;
//         int room_number[3] = {258 , 261 , 270} ;
//         for (int i=0;i<3;i++){
//             cout<<room_number[i]<<endl;
//         }
//         cout<<endl;
//         }  
//     int get_price(){
//         int single_room_price=5000;
//         int deluxe_room_price=10000;
//         int suite_room_price=17000;
//         cout<<"The price of single room is Rs "<<single_room_price<<"/day."<<endl;
//         cout<<"The price of deluxe room is Rs "<<deluxe_room_price<<"/day."<<endl;
//         cout<<"The price of suite room is Rs "<<suite_room_price<<"/day."<<endl;
//         } 
// };

// int main(){
//     Room r;
//     r.getroom_type();
//     r.get_room_number_single();
//     r.get_room_number_deluxe();
//     r.get_room_number_suite();
//     r.get_price();
//     return 0;
// }
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Room {
protected:
    vector<int> room_numbers;

public:
    virtual void getRoomNumbers() = 0;
    virtual void getPrice() = 0;
};

class SingleRoom : public Room {
public:
    SingleRoom() {
        room_numbers = {32, 42, 63, 108, 109, 115, 136, 145, 180, 198};
    }

    void getRoomNumbers() override {
        cout << "Following are the available single rooms:" << endl;
        for (int room_number : room_numbers) {
            cout << room_number << endl;
        }
        cout << endl;
    }

    void getPrice() override {
        cout << "The price of single room is Rs 5000/day." << endl;
    }
};

class DeluxeRoom : public Room {
public:
    DeluxeRoom() {
        room_numbers = {200, 205, 210, 225};
    }

    void getRoomNumbers() override {
        cout << "Following are the available deluxe rooms:" << endl;
        for (int room_number : room_numbers) {
            cout << room_number << endl;
        }
        cout << endl;
    }

    void getPrice() override {
        cout << "The price of deluxe room is Rs 10000/day." << endl;
    }
};

class SuiteRoom : public Room {
public:
    SuiteRoom() {
        room_numbers = {258, 261, 270};
    }

    void getRoomNumbers() override {
        cout << "Following are the available suite rooms:" << endl;
        for (int room_number : room_numbers) {
            cout << room_number << endl;
        }
        cout << endl;
    }

    void getPrice() override {
        cout << "The price of suite room is Rs 17000/day." << endl;
    }
};

int main() {
    SingleRoom singleRoom;
    DeluxeRoom deluxeRoom;
    SuiteRoom suiteRoom;

    cout << "Single Room Details:" << endl;
    singleRoom.getRoomNumbers();
    singleRoom.getPrice();

    cout << "Deluxe Room Details:" << endl;
    deluxeRoom.getRoomNumbers();
    deluxeRoom.getPrice();

    cout << "Suite Room Details:" << endl;
    suiteRoom.getRoomNumbers();
    suiteRoom.getPrice();

    return 0;
}