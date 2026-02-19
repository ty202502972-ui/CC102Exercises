#include <iostream>
using namespace std;

int main() {

    const int PRODUCTS = 5;
    const int SALESPERSONS = 4;

    double sales[PRODUCTS][SALESPERSONS] = {0};

    int salesperson, product;
    double amount;

    cout << "Enter sales data\n";
    cout << "Enter 0 for salesperson number to stop.\n";

    while (true) {

        cout << "\nSalesperson (1-4): ";
        cin >> salesperson;

        if (salesperson == 0)
            break;

        cout << "Product (1-5): ";
        cin >> product;

        cout << "Amount sold: ";
        cin >> amount;

        if (salesperson >= 1 && salesperson <= 4 &&
            product >= 1 && product <= 5) {

            sales[product - 1][salesperson - 1] += amount;

        } else {
            cout << "Invalid input. Try again.\n";
        }
    }

    cout << "\nMonthly Sales Summary\n";

    for (int i = 0; i < PRODUCTS; i++) {

        cout << "\nProduct " << i + 1 << ": ";
        double rowTotal = 0;

        for (int j = 0; j < SALESPERSONS; j++) {
            cout << sales[i][j] << " ";
            rowTotal += sales[i][j];
        }

        cout << " | Total: " << rowTotal;
    }

    cout << "\n\nSalesperson Totals:\n";

    for (int j = 0; j < SALESPERSONS; j++) {

        double colTotal = 0;

        for (int i = 0; i < PRODUCTS; i++) {
            colTotal += sales[i][j];
        }

        cout << "Salesperson " << j + 1 << ": " << colTotal << endl;
    }

    return 0;
}