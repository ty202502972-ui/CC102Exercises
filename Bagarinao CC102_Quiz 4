#include <iostream>
using namespace std;

int main() {
    int shop[5][10] = {0}; // 2D array for computers
    int choice;

    do {
        cout << "\n===== COMPUTER SHOP RENTAL SYSTEM =====\n";
        cout << "1. View Computer Layout\n";
        cout << "2. Rent a Computer\n";
        cout << "3. Return a Computer\n";
        cout << "4. Reset Rental System\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "\nComputer Layout:\n";
            cout << "   ";
            for(int c=0;c<10;c++)
                cout << c+1 << " ";
            cout << endl;

            for(int r=0;r<5;r++) {
                char row = 'A' + r;
                cout << row << "  ";
                for(int c=0;c<10;c++) {
                    cout << shop[r][c] << " ";
                }
                cout << endl;
            }
        }

        else if(choice == 2) {
            int row, col, hours;

            cout << "Enter row (1-5): ";
            cin >> row;
            cout << "Enter column (1-10): ";
            cin >> col;
            cout << "Enter hours to rent: ";
            cin >> hours;

            if(row <1 || row>5 || col<1 || col>10) {
                cout << "Invalid location!\n";
            }
            else if(shop[row-1][col-1] > 0) {
                cout << "Computer unit already rented!\n";
            }
            else {
                shop[row-1][col-1] = hours;
                char r = 'A' + (row-1);
                cout << "Computer unit " << r << col
                     << " successfully rented for "
                     << hours << " hour(s).\n";
            }
        }

        else if(choice == 3) {
            int row, col;

            cout << "Enter row (1-5): ";
            cin >> row;
            cout << "Enter column (1-10): ";
            cin >> col;

            if(row <1 || row>5 || col<1 || col>10) {
                cout << "Invalid location!\n";
            }
            else if(shop[row-1][col-1] == 0) {
                cout << "Computer unit already available.\n";
            }
            else {
                int hours = shop[row-1][col-1];
                double sale = hours * 20.00;

                char r = 'A' + (row-1);

                cout << "Computer unit " << r << col << " returned.\n";
                cout << "Rental Sale: P" << sale << endl;

                shop[row-1][col-1] = 0;
            }
        }

        else if(choice == 4) {
            for(int r=0;r<5;r++) {
                for(int c=0;c<10;c++) {
                    shop[r][c] = 0;
                }
            }
            cout << "Rental system reset successfully!\n";
        }

    } while(choice != 5);

    cout << "Program ended.\n";
return 0;
}
