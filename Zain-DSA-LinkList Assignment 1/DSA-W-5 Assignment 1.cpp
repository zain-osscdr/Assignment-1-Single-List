
#include <iostream>
using namespace std;
class Seat {
public:
    string name;
    string mobile;
    int seatNo;
    bool booked;
    Seat(int seatNumber) {
        this->seatNo = seatNumber;
        this->booked = false;
    }
    ~Seat() {

    }

};
class Node {
public:
    Seat* seat;
    Node* next;
    Node(Seat* seat) {
        this->seat = seat;
        next = nullptr;
    }
};
class SingleList {
public:
    Node* head;
    SingleList() {
        head = nullptr;
    }
    void addingSeats(int seat) {
        Seat* obj = new Seat(seat);
        Node* newNode = new Node(obj);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void bookingTicket(int s, const string& name, const string& ph) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->seat->seatNo == s) {
                if (!temp->seat->booked) {
                    temp->seat->booked = true;
                    temp->seat->name = name;
                    temp->seat->mobile = ph;
                    cout << "Thanks For Choosing Zain Travels :) , Wishing you Happy Travel " << endl;
                }
                else {
                    cout << "Oops! Sorry But Seat  :  " << s << " Has Been Booked By Somebody  :( " << endl;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "The Seat you Asked For : " << s << "  Is Not on The List  :( " << endl;

    }
    void cancelTicket(int s) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->seat->seatNo == s) {
                if (temp->seat->booked) {
                    temp->seat->booked = false;
                    temp->seat->name = "";
                    temp->seat->mobile = "";
                    cout << "Your Ticket Has Been Cancelled .  :( " << endl;
                }
                else {
                    cout << "The Seat  " << s << "  is still pending to be booked  " << endl;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Seat  : " << s << "  is Not There Available  " << endl;
    }
    void displayReservedSeats() {
        Node* temp = head;
        cout << "Reserved Seats Are " << endl;
        while (temp != nullptr) {
            if (temp->seat->booked) {
                cout << "Seat number " << temp->seat->seatNo << endl;
                cout << " Name  " << temp->seat->name << endl;
                cout << "Mobile  number " << temp->seat->mobile << endl;
            }
            temp = temp->next;
        }
    }
    void searchSeat(int s) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->seat->seatNo == s) {
                cout << "Seat number " << temp->seat->seatNo << endl;
                cout << "Passenger Name  " << temp->seat->name << endl;
                cout << "Phone number " << temp->seat->mobile << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Seat  : " << s << "  Is Not There :( " << endl;

    }
    void updateSeat(int s, const string& n, const string& ph) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->seat->seatNo == s) {
                if (temp->seat->booked) {
                    temp->seat->name = n;
                    temp->seat->mobile = ph;
                    cout << "The Details Has Been Udated   :) " << endl;

                }
                else {
                    cout << "Seat : " << s << " Is still to be booked " << endl;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Seat :     " << s << "  Is not There  :( " << endl;

    }

};

int main()
{
    SingleList zainTravels;
    for (int i = 1; i <= 10; i++) {
        zainTravels.addingSeats(i);
    }

    zainTravels.bookingTicket(1, "Muhammad Zain-ul-Abideen ", "F2023065161");
    zainTravels.bookingTicket(2, "Fawad Ahmed ", "F2023065170");
    zainTravels.bookingTicket(9, "Ahmed Raza", "F2023065172");
    zainTravels.bookingTicket(5, "Abdullah  ", "F2023065162");
    zainTravels.bookingTicket(2, "Bazil ", "F2023065186");
    zainTravels.bookingTicket(7, "Ali Shafique ", "F2023065263");
    zainTravels.bookingTicket(15, "Donald Trumph ", "2105950");
    cout << "Below the List of Reserved Ones " << endl;
    zainTravels.displayReservedSeats();
    cout << "Lets Search Some Seat nummber 9 : REsults Are" << endl;
    zainTravels.searchSeat(9);
    cout << "Lets Update Some Seat nummber 9 : REsults Are" << endl;
    zainTravels.updateSeat(9, "Ahmed Jutt", "54531");
    cout << "Lets Cancel Some One Ticket" << endl;
    zainTravels.cancelTicket(5);
    cout << "Displaying Again Reserved Tickets " << endl;
    zainTravels.displayReservedSeats();
}
