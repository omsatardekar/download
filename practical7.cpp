#include <iostream>
using namespace std;

const int NUM_ROWS = 10;
const int SEATS_PER_ROW = 7;

struct Seat {
    char status;
    Seat* next;
    Seat* prev;
};

Seat* initializeRow() {
    Seat* head = nullptr;
    Seat* temp = nullptr;

    for (int i = 0; i < SEATS_PER_ROW; ++i) {
        Seat* newSeat = new Seat;
        newSeat->status = 'A';
        if (head == nullptr) {
            head = newSeat;
            temp = head;
        } else {
            temp->next = newSeat;
            newSeat->prev = temp;
            temp = newSeat;
        }
    }

    temp->next = head;
    head->prev = temp;
    return head;
}

void displayAvailableSeats(Seat* row) {
    Seat* temp = row;
    int seatNum = 1;

    do {
        cout << "Seat " << seatNum << ": " << (temp->status == 'A' ? "Available" : "Booked") << endl;
        temp = temp->next;
        seatNum++;
    } while (temp != row);
}

bool bookSeat(Seat* row, int seatNum) {
    Seat* temp = row;
    int count = 1;

    do {
        if (count == seatNum) {
            if (temp->status == 'A') {
                temp->status = 'B';
                return true;
            } else {
                return false;
            }
        }
        temp = temp->next;
        count++;
    } while (temp != row);

    return false;
}

bool cancelBooking(Seat* row, int seatNum) {
    Seat* temp = row;
    int count = 1;

    do {
        if (count == seatNum) {
            if (temp->status == 'B') {
                temp->status = 'A';
                return true;
            } else {
                return false;
            }
        }
        temp = temp->next;
        count++;
    } while (temp != row);

    return false;
}

int main() {
    Seat* rows[NUM_ROWS];

    for (int i = 0; i < NUM_ROWS; ++i) {
        rows[i] = initializeRow();
    }

    bookSeat(rows[0], 1);
    bookSeat(rows[2], 3);
    bookSeat(rows[5], 6);
    bookSeat(rows[9], 2);

    int choice, rowNum, seatNum;

    do {
        cout << "\nCinemax Theater Ticket Booking System\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book a Seat\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < NUM_ROWS; ++i) {
                    cout << "\nRow " << i + 1 << ":\n";
                    displayAvailableSeats(rows[i]);
                }
                break;
            case 2:
                cout << "Enter row number (1-10): ";
                cin >> rowNum;
                if (rowNum < 1 || rowNum > NUM_ROWS) {
                    break;
                }
                cout << "Enter seat number (1-7): ";
                cin >> seatNum;
                if (seatNum < 1 || seatNum > SEATS_PER_ROW) {
                    break;
                }
                if (bookSeat(rows[rowNum - 1], seatNum)) {
                    cout << "Seat " << seatNum << " in Row " << rowNum << " booked successfully!" << endl;
                }
                break;
            case 3:
                cout << "Enter row number (1-10): ";
                cin >> rowNum;
                if (rowNum < 1 || rowNum > NUM_ROWS) {
                    break;
                }
                cout << "Enter seat number (1-7): ";
                cin >> seatNum;
                if (seatNum < 1 || seatNum > SEATS_PER_ROW) {
                    break;
                }
                if (cancelBooking(rows[rowNum - 1], seatNum)) {
                    cout << "Booking for Seat " << seatNum << " in Row " << rowNum << " canceled successfully!" << endl;
                }
                break;
            case 4:
                break;
            default:
                break;
        }
    } while (choice != 4);

    return 0;
}
