#include <iostream>
#include <vector>
using namespace std;

const int MAX_SEATS = 50;

// Function to display the seating arrangement
void displaySeats(const vector<bool>& seats) {
    cout << "Seating Arrangement:" << endl;
    for (int i = 0; i < seats.size(); ++i) {
        cout << (seats[i] ? "X" : "O") << " ";
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
}

// Function to book a ticket
void bookTicket(vector<bool>& seats) {
    int seatNumber;
    cout << "Enter the seat number you want to book (1 - " << MAX_SEATS << "): ";
    cin >> seatNumber;

    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        cout << "Invalid seat number. Please try again." << endl;
        return;
    }

    if (seats[seatNumber - 1]) {
        cout << "Sorry, the seat is already booked. Please choose another seat." << endl;
    } else {
        seats[seatNumber - 1] = true;
        cout << "Seat " << seatNumber << " booked successfully!" << endl;
    }
}

int main() {
    vector<bool> seats(MAX_SEATS, false); // Initialize all seats as unbooked

    int choice;
    do {
        cout << "\n***** Movie Ticket Booking System *****" << endl;
        cout << "1. View available seats" << endl;
        cout << "2. Book a ticket" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeats(seats);
                break;
            case 2:
                bookTicket(seats);
                break;
            case 3:
                cout << "Thank you for using the Movie Ticket Booking System. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
